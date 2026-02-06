#include "ExtractionShip.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/AudioComponent.h"
#include "ProjectHD/Character/Player/FPSCharacter.h"
#include "ProjectHD/HDGameInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

AExtractionShip::AExtractionShip()
{
	PrimaryActorTick.bCanEverTick = true;

	// 루트 컴포넌트
	ShipRoot = CreateDefaultSubobject<USceneComponent>(TEXT("ShipRoot"));
	RootComponent = ShipRoot;

	// 쉽 메쉬 (블루프린트에서 회전 조정 가능)
	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	ShipMesh->SetupAttachment(RootComponent);
	ShipMesh->SetCollisionProfileName(TEXT("BlockAll"));

	// 탑승 구역
	BoardingZone = CreateDefaultSubobject<UBoxComponent>(TEXT("BoardingZone"));
	BoardingZone->SetupAttachment(RootComponent);
	BoardingZone->SetBoxExtent(FVector(300.0f, 200.0f, 150.0f));
	BoardingZone->SetRelativeLocation(FVector(-200.0f, 0.0f, 0.0f)); // 쉽 뒤쪽
	BoardingZone->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	// 트레일 컴포넌트 (비활성 상태로 시작)
	LeftTrail = CreateDefaultSubobject<UNiagaraComponent>(TEXT("LeftTrail"));
	LeftTrail->SetupAttachment(RootComponent);
	LeftTrail->SetRelativeLocation(LeftTrailOffset);
	LeftTrail->bAutoActivate = false;
	LeftTrail->SetAutoDestroy(false);

	RightTrail = CreateDefaultSubobject<UNiagaraComponent>(TEXT("RightTrail"));
	RightTrail->SetupAttachment(RootComponent);
	RightTrail->SetRelativeLocation(RightTrailOffset);
	RightTrail->bAutoActivate = false;
	RightTrail->SetAutoDestroy(false);
}

void AExtractionShip::BeginPlay()
{
	Super::BeginPlay();

	// 탑승 구역 오버랩 바인딩
	BoardingZone->OnComponentBeginOverlap.AddDynamic(this, &AExtractionShip::HandleBoardingBeginOverlap);

	// 트레일 이펙트 에셋 설정
	if (TrailEffect)
	{
		if (LeftTrail) LeftTrail->SetAsset(TrailEffect);
		if (RightTrail) RightTrail->SetAsset(TrailEffect);
	}

	// 엔진 사운드 루프
	if (EngineSound)
	{
		EngineSoundComponent = UGameplayStatics::SpawnSoundAttached(
			EngineSound,
			ShipMesh,
			NAME_None,
			FVector::ZeroVector,
			EAttachLocation::KeepRelativeOffset,
			false,
			1.0f,
			1.0f,
			0.0f,
			nullptr,
			nullptr,
			true
		);
	}
}

void AExtractionShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (ShipState)
	{
	case EShipState::Arriving:
		UpdateArrival(DeltaTime);
		break;
	case EShipState::Landing:
		UpdateLanding(DeltaTime);
		break;
	case EShipState::Departing:
		UpdateDeparture(DeltaTime);
		break;
	default:
		break;
	}
}

void AExtractionShip::StartArrival(const FVector& Destination)
{
	TargetLocation = Destination;

	// 시작 위치 (절대 좌표)
	FlightStartLocation = ArrivalLocation;
	FlightEndLocation = Destination + FVector(0.0f, 0.0f, HoverHeight); // 호버링 높이

	// 시작 회전 (목표를 향해)
	FVector Direction = (FlightEndLocation - FlightStartLocation).GetSafeNormal();
	FlightStartRotation = Direction.Rotation();
	FlightEndRotation = FRotator(0.0f, FlightStartRotation.Yaw, 0.0f); // 수평으로

	// 시작 위치로 이동
	SetActorLocation(FlightStartLocation);
	SetActorRotation(FlightStartRotation);

	FlightAlpha = 0.0f;
	ShipState = EShipState::Arriving;

	// 트레일 활성화
	if (LeftTrail) LeftTrail->Activate();
	if (RightTrail) RightTrail->Activate();

	OnShipStateChanged.Broadcast(ShipState);
	OnArrivalStarted();
}

void AExtractionShip::UpdateArrival(float DeltaTime)
{
	FlightAlpha += DeltaTime / ArrivalDuration;

	if (FlightAlpha >= 1.0f)
	{
		FlightAlpha = 1.0f;
		SetActorLocation(FlightEndLocation);
		SetActorRotation(FlightEndRotation);
		StartLanding();
		return;
	}

	float EasedAlpha = EaseInOutCubic(FlightAlpha);

	// 위치 보간
	FVector NewLocation = FMath::Lerp(FlightStartLocation, FlightEndLocation, EasedAlpha);
	SetActorLocation(NewLocation);

	// 회전 보간
	FRotator NewRotation = FMath::Lerp(FlightStartRotation, FlightEndRotation, EasedAlpha);
	SetActorRotation(NewRotation);
}

void AExtractionShip::StartLanding()
{
	ShipState = EShipState::Landing;
	FlightAlpha = 0.0f;

	FlightStartLocation = GetActorLocation();
	FlightEndLocation = TargetLocation; // 최종 착륙 위치	

	if (LandingSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, LandingSound, GetActorLocation());
	}

	OnShipStateChanged.Broadcast(ShipState);
	OnLandingStarted();
}

void AExtractionShip::UpdateLanding(float DeltaTime)
{
	FlightAlpha += DeltaTime / LandingDuration;

	if (FlightAlpha >= 1.0f)
	{
		FlightAlpha = 1.0f;
		SetActorLocation(FlightEndLocation);
		CompleteLanding();
		return;
	}

	float EasedAlpha = EaseInOutCubic(FlightAlpha);

	// 수직 하강
	FVector NewLocation = FMath::Lerp(FlightStartLocation, FlightEndLocation, EasedAlpha);
	SetActorLocation(NewLocation);
}

void AExtractionShip::CompleteLanding()
{
	ShipState = EShipState::Waiting;
	
	// 트레일 비활성화
	if (LeftTrail) LeftTrail->Deactivate();
	if (RightTrail) RightTrail->Deactivate();

	OnShipStateChanged.Broadcast(ShipState);
	OnLandingCompleted();
}

void AExtractionShip::HandleBoardingBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Waiting 상태에서만 탑승 가능
	if (ShipState != EShipState::Waiting) return;

	AFPSCharacter* Player = Cast<AFPSCharacter>(OtherActor);
	if (!Player) return;

	BoardedPlayer = Player;

	if (BoardingSound)
	{
		UGameplayStatics::PlaySound2D(this, BoardingSound);
	}

	OnPlayerBoarded.Broadcast();
	OnPlayerBoardedShip();

	// 탑승 후 이륙 시작
	StartDeparture();
}

void AExtractionShip::StartDeparture()
{
	ShipState = EShipState::Departing;
	FlightAlpha = 0.0f;

	// 탈출 시작 사운드
	if (DepartureSound)
	{
		UGameplayStatics::PlaySound2D(this, DepartureSound);
	}

	// 트레일 재활성화
	if (LeftTrail) LeftTrail->Activate();
	if (RightTrail) RightTrail->Activate();

	FlightStartLocation = GetActorLocation();
	// 목적지 (절대 좌표)
	FlightEndLocation = DepartureLocation;

	FlightStartRotation = GetActorRotation();
	FVector Direction = (FlightEndLocation - FlightStartLocation).GetSafeNormal();
	FlightEndRotation = Direction.Rotation();

	// 플레이어 처리
	if (BoardedPlayer)
	{
		APlayerController* PC = Cast<APlayerController>(BoardedPlayer->GetController());
		if (PC)
		{
			// UI 입력 모드로 전환 (게임 입력 차단)
			PC->SetInputMode(FInputModeUIOnly());
		}

		// HUD 숨기기
		BoardedPlayer->HideAllHUD();

		// 플레이어 숨기기
		BoardedPlayer->SetActorHiddenInGame(true);
		BoardedPlayer->SetActorEnableCollision(false);

		// 캐릭터 무브먼트 비활성화
		if (UCharacterMovementComponent* Movement = BoardedPlayer->GetCharacterMovement())
		{
			Movement->StopMovementImmediately();
			Movement->DisableMovement();
		}
	}

	OnShipStateChanged.Broadcast(ShipState);
	OnDepartureStarted();	// 탈출 컷신 시작
}

void AExtractionShip::UpdateDeparture(float DeltaTime)
{
	FlightAlpha += DeltaTime / DepartureDuration;

	if (FlightAlpha >= 1.0f)
	{
		FlightAlpha = 1.0f;
		CompleteDeparture();
		return;
	}

	float EasedAlpha = EaseInOutCubic(FlightAlpha);

	// 위치 보간 (가속)
	FVector NewLocation = FMath::Lerp(FlightStartLocation, FlightEndLocation, EasedAlpha * EasedAlpha);
	SetActorLocation(NewLocation);

	// 회전 보간
	FRotator NewRotation = FMath::Lerp(FlightStartRotation, FlightEndRotation, FMath::Min(EasedAlpha * 2.0f, 1.0f));
	SetActorRotation(NewRotation);
}

void AExtractionShip::CompleteDeparture()
{
	ShipState = EShipState::Gone;

	// 탈출 완료 사운드
	if (ExtractionCompleteSound)
	{
		UGameplayStatics::PlaySound2D(this, ExtractionCompleteSound);
	}

	// 쉽 숨기기
	SetActorHiddenInGame(true);

	// 엔진 사운드 중지
	if (EngineSoundComponent)
	{
		EngineSoundComponent->Stop();
	}

	// 트레일 분리 (Eagle처럼 자연스럽게 사라지도록)
	if (LeftTrail)
	{
		LeftTrail->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
	}
	if (RightTrail)
	{
		RightTrail->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
	}

	// 마우스 커서 표시 및 플레이어 이동 (적 AI 인식 방지)
	if (BoardedPlayer)
	{
		if (APlayerController* PC = Cast<APlayerController>(BoardedPlayer->GetController()))
		{
			PC->bShowMouseCursor = true;
		}
		BoardedPlayer->SetActorLocation(FVector(0.0f, 0.0f, -10000.0f));
	}

	// 미션 타이머 정지 및 점수 계산
	if (UHDGameInstance* GI = Cast<UHDGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
	{
		GI->StopMissionTimer(this);
		GI->CalculateFinalScore();
	}

	OnShipStateChanged.Broadcast(ShipState);

	// 블루프린트 이벤트 (결과 위젯 표시용)
	OnDepartureCompletedBP();

	// 델리게이트 브로드캐스트
	OnDepartureCompleted.Broadcast();
}

float AExtractionShip::EaseInOutCubic(float t) const
{
	return t < 0.5f ? 4.0f * t * t * t : 1.0f - FMath::Pow(-2.0f * t + 2.0f, 3.0f) / 2.0f;
}
