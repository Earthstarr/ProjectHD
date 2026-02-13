#include "PodActor.h"

#include "FPSCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"
#include "ProjectHD/Character/Enemy/EnemyBase.h"
#include "GameFramework/SpringArmComponent.h"

APodActor::APodActor()
{
	PrimaryActorTick.bCanEverTick = true;

	PodMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PodMesh"));
	RootComponent = PodMesh;

	// 물리 설정
	PodMesh->SetSimulatePhysics(false); // 초기엔 꺼둠
	PodMesh->SetEnableGravity(true);
	PodMesh->SetNotifyRigidBodyCollision(true);

	// 질량 먼저 설정
	PodMesh->SetMassOverrideInKg(NAME_None, 1000.0f, true);

	// 감쇠 설정
	PodMesh->SetLinearDamping(0.0f);
	PodMesh->SetAngularDamping(0.0f);

	// 콜리전 설정
	PodMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	PodMesh->SetCollisionObjectType(ECC_WorldDynamic);
	PodMesh->SetCollisionResponseToAllChannels(ECR_Block);
	PodMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);  // 적과 오버랩 감지
	PodMesh->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	PodMesh->SetGenerateOverlapEvents(true);

	InternalElevatorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InternalMesh"));
	InternalElevatorMesh->SetupAttachment(RootComponent);

	// 엘리베이터 - 오버랩만 감지
	InternalElevatorMesh->SetSimulatePhysics(false);
	InternalElevatorMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	InternalElevatorMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	InternalElevatorMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	InternalElevatorMesh->SetGenerateOverlapEvents(true);

	// 플레이어 부착점
	CharacterAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("CharacterAnchor"));
	CharacterAnchor->SetupAttachment(InternalElevatorMesh);
	CharacterAnchor->SetRelativeLocation(FVector(0.f, 0.f, 48.f));
}

void APodActor::BeginPlay()
{
	Super::BeginPlay();

	// 오버랩 이벤트 바인딩
	PodMesh->OnComponentBeginOverlap.AddDynamic(this, &APodActor::OnPodOverlap);
	InternalElevatorMesh->OnComponentBeginOverlap.AddDynamic(this, &APodActor::OnElevatorOverlap);

	if (RiseCurve)
	{
		FOnTimelineFloat ProgressFunction;
		ProgressFunction.BindUFunction(this, FName("HandleRiseProgress"));
		RiseTimeline.AddInterpFloat(RiseCurve, ProgressFunction);
	}

	if (FallingSound)
	{
		FallingSoundComponent = UGameplayStatics::SpawnSoundAttached(
			FallingSound,
			RootComponent,
			NAME_None,
			FVector::ZeroVector,
			EAttachLocation::KeepRelativeOffset,
			false, // bStopWhenAttachedToDestroyed
			1.0f, // Volume
			1.0f, // Pitch
			0.0f, // Start Time
			nullptr, // Attenuation
			nullptr, // Concurrency
			false // bAutoDestroy - 수동으로 관리
		);
	}
}

void APodActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RiseTimeline.TickTimeline(DeltaTime);

	// 낙하 중 바닥 감지 및 조종
	if (!bLanded && PodMesh && PodMesh->IsSimulatingPhysics())
	{
		// 플레이어 입력으로 Pod 조종
		TArray<AActor*> AttachedActors;
		GetAttachedActors(AttachedActors);

		for (AActor* Actor : AttachedActors)
		{
			AFPSCharacter* Player = Cast<AFPSCharacter>(Actor);
			if (Player && Player->bIsOnPod)
			{
				FVector2D MoveInput = Player->CurrentMoveInput;

				if (!MoveInput.IsNearlyZero())
				{
					// 카메라 방향 기준으로 이동
					if (APlayerController* PC = Cast<APlayerController>(Player->GetController()))
					{
						FRotator ControlRot = PC->GetControlRotation();
						FRotator YawRot(0.f, ControlRot.Yaw, 0.f);

						FVector ForwardDir = FRotationMatrix(YawRot).GetUnitAxis(EAxis::X);
						FVector RightDir = FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y);

						// MoveInput.Y = Forward, MoveInput.X = Right
						FVector MoveDir = (ForwardDir * MoveInput.Y + RightDir * MoveInput.X).GetSafeNormal();
						PodMesh->AddForce(MoveDir * PodSteerForce, NAME_None, true);
					}
				}
				else
				{
					// 입력 없으면 수평 속도 감쇠 (미끄러움 방지)
					FVector Vel = PodMesh->GetPhysicsLinearVelocity();
					Vel.X *= 0.9f;
					Vel.Y *= 0.9f;
					PodMesh->SetPhysicsLinearVelocity(Vel);
				}
				break;
			}
		}

		FVector Start = GetActorLocation();
		FVector Velocity = PodMesh->GetPhysicsLinearVelocity();

		// 속도에 맞게 트레이스 길이 조절
		float TraceLength = (Velocity.Size() * DeltaTime) + 100.f;
		FVector End = Start + (FVector::DownVector * TraceLength);

		FHitResult GroundHit;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);

		if (GetWorld()->LineTraceSingleByChannel(GroundHit, Start, End, ECC_Visibility, Params))
		{
			// 착지 전 카메라 붐을 현재 공중 위치에서 월드 좌표로 고정
			TArray<AActor*> AttachedForCamera;
			GetAttachedActors(AttachedForCamera);
			for (AActor* Actor : AttachedForCamera)
			{
				AFPSCharacter* Player = Cast<AFPSCharacter>(Actor);
				if (Player && Player->CameraBoom)
				{
					SavedBoomRelativeLocation = Player->CameraBoom->GetRelativeLocation();
					CameraLockedWorldPos = Player->CameraBoom->GetComponentLocation();
					Player->CameraBoom->SetAbsolute(true, false, false);
					Player->CameraBoom->SetRelativeLocation(CameraLockedWorldPos);
					bCameraLocked = true;

					// 보간 시작값 저장
					BlendStartArmLength = Player->CameraBoom->TargetArmLength;
					BlendStartSocketOffset = Player->CameraBoom->SocketOffset;
					if (APlayerController* PC = Cast<APlayerController>(Player->GetController()))
					{
						BlendStartPitch = PC->GetControlRotation().Pitch;
						if (BlendStartPitch > 180.f) BlendStartPitch -= 360.f;
					}
					break;
				}
			}

			OnPodLanded();

			// 박힐 때 위치 보정
			SetActorLocation(GroundHit.ImpactPoint + FVector(0.f, 0.f, -200.f));
		}
	}
}

void APodActor::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	// 지면에 닿았고 아직 착지 처리가 안 되었다면
	if (!bLanded && Hit.ImpactNormal.Z > 0.5f)
	{
		OnPodLanded();
	}
}

void APodActor::OnPodLanded()
{
	if (bLanded) return;
	bLanded = true;

	PodMesh->SetSimulatePhysics(false);
	// 박힌 후 회전값 정렬 (기울어짐 방지)
	SetActorRotation(FRotator(0.f, GetActorRotation().Yaw, 0.f));

	// 낙하 사운드 정지
	if (FallingSoundComponent)
	{
		FallingSoundComponent->Stop();
	}

	// 착지 사운드
	if (ImpactSound)
	{
		UGameplayStatics::PlaySoundAtLocation(
			this,
			ImpactSound,
			GetActorLocation(),
			1.0f,
			1.0f
		);
	}

	// 부착된 플레이어 처리
	TArray<AActor*> AttachedActors;
	GetAttachedActors(AttachedActors);

	for (AActor* Actor : AttachedActors)
	{
		AFPSCharacter* Player = Cast<AFPSCharacter>(Actor);
		if (Player)
		{
			Player->bIsOnPod = false;

			// 착지 후 캐릭터 보이게 (올라오는 연출에 필요)
			Player->SetActorHiddenInGame(false);
			Player->RetargetMesh->SetVisibility(true, true);
			Player->GetMesh()->SetVisibility(false);
		}
	}

	RiseTimeline.PlayFromStart();
}

void APodActor::HandleRiseProgress(float Value)
{
	// 엘리베이터 Z축 높이 조절
	float NewZ = FMath::Lerp(-100.f, 160.f, Value);
	InternalElevatorMesh->SetRelativeLocation(FVector(0.f, 0.f, NewZ));

	// EaseInOutCubic
	float T = Value;
	float EasedT = (T < 0.5f) ? 4.f * T * T * T : 1.f - FMath::Pow(-2.f * T + 2.f, 3.f) / 2.f;

	// 카메라 보간: 공중 고정 위치 → 플레이 카메라 위치 (RiseTimeline과 동기화)
	TArray<AActor*> Attached;
	GetAttachedActors(Attached);
	for (AActor* Actor : Attached)
	{
		AFPSCharacter* Player = Cast<AFPSCharacter>(Actor);
		if (Player && Player->CameraBoom)
		{
			// ArmLength, SocketOffset 보간
			Player->CameraBoom->TargetArmLength = FMath::Lerp(BlendStartArmLength, 500.f, EasedT);
			Player->CameraBoom->SocketOffset = FMath::Lerp(BlendStartSocketOffset, FVector(0.f, 120.f, 80.f), EasedT);

			// Pitch 보간
			if (APlayerController* PC = Cast<APlayerController>(Player->GetController()))
			{
				float NewPitch = FMath::Lerp(BlendStartPitch, -15.f, EasedT);
				FRotator Rot = PC->GetControlRotation();
				PC->SetControlRotation(FRotator(NewPitch, Rot.Yaw, 0.f));
			}

			// 카메라 붐 월드 위치 보간: 공중 → 캐릭터 기준 위치
			if (bCameraLocked)
			{
				FVector TargetWorldPos = Player->GetActorLocation() + SavedBoomRelativeLocation;
				FVector BlendedPos = FMath::Lerp(CameraLockedWorldPos, TargetWorldPos, EasedT);
				Player->CameraBoom->SetRelativeLocation(BlendedPos);
			}
		}
	}

	if (Value >= 1.0f)
	{
		OnRiseFinished();
	}
}

void APodActor::OnRiseFinished()
{
	TArray<AActor*> AttachedActors;
	GetAttachedActors(AttachedActors);

	for (AActor* Actor : AttachedActors)
	{
		AFPSCharacter* Player = Cast<AFPSCharacter>(Actor);
		if (Player)
		{
			// 부착 해제
			Player->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

			// 메시 회전 다시 확인
			Player->GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
			Player->GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -96.f));

			// 캐릭터를 지면 위로 약간 띄워서 안착
			FVector CurrentLoc = Player->GetActorLocation();
			Player->SetActorLocation(CurrentLoc + FVector(0, 0, 10.f));

			// 리전 및 중력 원복
			Player->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			Player->GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Block);
			Player->GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
			Player->GetCapsuleComponent()->SetEnableGravity(true);

			// 이동 모드 복구
			Player->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
			Player->GetCharacterMovement()->GravityScale = 1.0f;

			// 입력 활성화 및 카메라 최종 복구
			if (APlayerController* PC = Cast<APlayerController>(Player->GetController()))
			{
				Player->EnableInput(PC);

				// 카메라 붐을 relative로 복구 + 최종값 설정
				if (Player->CameraBoom)
				{
					Player->CameraBoom->SetAbsolute(false, false, false);
					Player->CameraBoom->SetRelativeLocation(SavedBoomRelativeLocation);
					Player->CameraBoom->TargetArmLength = 500.f;
					Player->CameraBoom->SocketOffset = FVector(0.f, 120.f, 80.f);
				}
				bCameraLocked = false;
			}

			// 회전 모드 복구
			Player->bUseControllerRotationPitch = false;
			Player->bUseControllerRotationYaw = false;
			Player->bUseControllerRotationRoll = false;
			Player->GetCharacterMovement()->bOrientRotationToMovement = true;
		}
	}

	// 포드 제거
	SetLifeSpan(10.0f);
}

void APodActor::OnPodOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 낙하 중일 때만 적 즉사
	if (bLanded) return;

	AEnemyBase* Enemy = Cast<AEnemyBase>(OtherActor);
	if (Enemy && !Enemy->bIsDead)
	{
		// 즉사 데미지
		UGameplayStatics::ApplyDamage(Enemy, 999999.f, nullptr, this, nullptr);
	}
}

void APodActor::OnElevatorOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 엘리베이터에 적이 닿으면 즉사
	AEnemyBase* Enemy = Cast<AEnemyBase>(OtherActor);
	if (Enemy && !Enemy->bIsDead)
	{
		UGameplayStatics::ApplyDamage(Enemy, 999999.f, nullptr, this, nullptr);
	}
}
