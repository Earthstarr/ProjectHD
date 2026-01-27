#include "PodActor.h"

#include "FPSCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

APodActor::APodActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// ★★★ PodMesh (외부 껍데기) ★★★
	PodMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PodMesh"));
	RootComponent = PodMesh;
    
	// 물리 시뮬레이션 설정
	PodMesh->SetSimulatePhysics(false); // BeginPlay에서 켜짐
	PodMesh->SetNotifyRigidBodyCollision(true);
	PodMesh->SetLinearDamping(0.0f);
    
	// 콜리전 설정
	PodMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	PodMesh->SetCollisionObjectType(ECC_WorldDynamic);
	PodMesh->SetCollisionResponseToAllChannels(ECR_Block);
	PodMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore); // 플레이어 무시
	PodMesh->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore); // 카메라 무시

	// ★★★ InternalElevatorMesh (내부 승강기) ★★★
	InternalElevatorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InternalMesh"));
	InternalElevatorMesh->SetupAttachment(RootComponent);
    
	// 콜리전 완전히 끔 (순수 비주얼용)
	InternalElevatorMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	InternalElevatorMesh->SetCollisionResponseToAllChannels(ECR_Ignore);

	// ★★★ CharacterAnchor (플레이어 부착점) ★★★
	CharacterAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("CharacterAnchor"));
	CharacterAnchor->SetupAttachment(InternalElevatorMesh);
	CharacterAnchor->SetRelativeLocation(FVector(0.f, 0.f, 48.f)); // 캡슐 절반 높이
}

void APodActor::BeginPlay()
{
	Super::BeginPlay();

	if (RiseCurve)
	{
		FOnTimelineFloat ProgressFunction;
		ProgressFunction.BindUFunction(this, FName("HandleRiseProgress"));
		RiseTimeline.AddInterpFloat(RiseCurve, ProgressFunction);
	}
}

void APodActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RiseTimeline.TickTimeline(DeltaTime);

	// 낙하 중 바닥 감지
	if (!bLanded && PodMesh && PodMesh->IsSimulatingPhysics())
	{
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
			OnPodLanded();
			// 공급 포드처럼 바닥에 살짝 박히는 느낌을 주려면 위치 보정
			SetActorLocation(GroundHit.ImpactPoint + FVector(0.f, 0.f, -50.f));
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
    
	RiseTimeline.PlayFromStart();
}

void APodActor::HandleRiseProgress(float Value)
{
	// 0에서 1로 변하는 Value값을 이용해 내부 메쉬의 Z축 높이 조절
	float NewZ = FMath::Lerp(-200.f, 0.f, Value);
	InternalElevatorMesh->SetRelativeLocation(FVector(0.f, 0.f, NewZ));
	
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
			// 1. 부착 해제
			Player->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
            
			// ★★★ 2. 메시 회전 다시 확인 (레그돌 이후 이상해질 수 있음) ★★★
			Player->GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
			Player->GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -96.f));
            
			// ★★★ 3. 캐릭터를 지면 위로 약간 띄워서 안착 (땅 뚫림 방지) ★★★
			FVector CurrentLoc = Player->GetActorLocation();
			Player->SetActorLocation(CurrentLoc + FVector(0, 0, 10.f));
            
			// 4. 콜리전 및 중력 원복
			Player->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
			Player->GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Block);
			Player->GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
			Player->GetCapsuleComponent()->SetEnableGravity(true);
            
			// 5. 이동 모드 복구
			Player->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
			Player->GetCharacterMovement()->GravityScale = 1.0f;
            
			// 6. 입력 활성화
			if (APlayerController* PC = Cast<APlayerController>(Player->GetController()))
			{
				Player->EnableInput(PC);
			}
            
			// ★★★ 7. 회전 모드 복구 ★★★
			Player->bUseControllerRotationPitch = false;
			Player->bUseControllerRotationYaw = false;
			Player->bUseControllerRotationRoll = false;
			Player->GetCharacterMovement()->bOrientRotationToMovement = true;
		}
	}
    
	// 포드 제거 (선택사항)
	// SetLifeSpan(2.0f); // 2초 후 자동 삭제
}