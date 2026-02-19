#include "ExtractionTerminal.h"
#include "ExtractionShip.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "ProjectHD/Character/Player/FPSCharacter.h"
#include "ProjectHD/Weapon/WeaponDataAsset.h"
#include "ProjectHD/HDGameInstance.h"
#include "MissionManager.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

AExtractionTerminal::AExtractionTerminal()
{
	PrimaryActorTick.bCanEverTick = true;

	// 루트 컴포넌트로 터미널 메쉬 설정
	TerminalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TerminalMesh"));
	RootComponent = TerminalMesh;

	// 상호작용 범위 (E키 상호작용)
	InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSphere"));
	InteractionSphere->SetupAttachment(RootComponent);
	InteractionSphere->SetSphereRadius(200.0f);
	InteractionSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	// 상호작용 위젯 (E - 탈출)
	InteractionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InteractionWidget"));
	InteractionWidget->SetupAttachment(RootComponent);
	InteractionWidget->SetRelativeLocation(FVector(0.0f, 0.0f, 150.0f));
	InteractionWidget->SetWidgetSpace(EWidgetSpace::Screen);
	InteractionWidget->SetDrawSize(FVector2D(200.0f, 50.0f));
	InteractionWidget->SetVisibility(false);

	// 기본 커맨드 설정
	RequiredCommand = { EStratagemDirection::Up, EStratagemDirection::Down,
		EStratagemDirection::Left, EStratagemDirection::Right };
}

void AExtractionTerminal::BeginPlay()
{
	Super::BeginPlay();

	// 오버랩 이벤트 바인딩
	InteractionSphere->OnComponentBeginOverlap.AddDynamic(this, &AExtractionTerminal::HandleInteractionBeginOverlap);
	InteractionSphere->OnComponentEndOverlap.AddDynamic(this, &AExtractionTerminal::HandleInteractionEndOverlap);

	// 미션 매니저 찾기 및 바인딩
	TArray<AActor*> FoundManagers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMissionManager::StaticClass(), FoundManagers);
	if (FoundManagers.Num() > 0)
	{
		MissionManager = Cast<AMissionManager>(FoundManagers[0]);
		if (MissionManager)
		{
			MissionManager->OnAllMissionsCompleted.AddDynamic(this, &AExtractionTerminal::OnAllMissionsCompleted);

			// 이미 모든 미션이 완료되었는지 확인
			if (MissionManager->AreAllMissionsCompleted())
			{
				ActivateTerminal();
			}
		}
	}
}

void AExtractionTerminal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ExtractionState == EExtractionState::Defending)
	{
		RemainingDefenseTime -= DeltaTime;
		OnDefenseTimerUpdated.Broadcast(RemainingDefenseTime, DefenseTime);

		if (RemainingDefenseTime <= 0.0f)
		{
			RemainingDefenseTime = 0.0f;
			CompleteExtraction();
		}
	}
}

void AExtractionTerminal::HandleInteractionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AFPSCharacter* Player = Cast<AFPSCharacter>(OtherActor))
	{
		OnOverlapBegin();
	}
}

void AExtractionTerminal::HandleInteractionEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (AFPSCharacter* Player = Cast<AFPSCharacter>(OtherActor))
	{
		OnOverlapEnd();
	}
}

void AExtractionTerminal::Interact(AFPSCharacter* Interactor)
{
	if (!Interactor) return;

	if (ExtractionState == EExtractionState::Ready)
	{
		InteractingPlayer = Interactor;
		StartInputPhase();
	}
}

void AExtractionTerminal::OnOverlapBegin()
{
	// Ready 상태일 때만 상호작용 위젯 표시
	if (ExtractionState == EExtractionState::Ready)
	{
		InteractionWidget->SetVisibility(true);
	}
}

void AExtractionTerminal::OnOverlapEnd()
{
	InteractionWidget->SetVisibility(false);

	// InputPhase에서 범위 이탈 시 취소
	if (ExtractionState == EExtractionState::InputPhase)
	{
		CancelInputPhase();
	}
}

void AExtractionTerminal::OnAllMissionsCompleted()
{
	if (ExtractionState == EExtractionState::Inactive)
	{
		ActivateTerminal();
	}
}

void AExtractionTerminal::ActivateTerminal()
{
	ExtractionState = EExtractionState::Ready;

	// 빛기둥 생성
	SpawnBeamEffect();

	// 활성화 사운드
	if (ActivationSound)
	{
		UGameplayStatics::PlaySound2D(this, ActivationSound);		
	}

	OnExtractionStateChanged.Broadcast(ExtractionState);
}

void AExtractionTerminal::StartInputPhase()
{
	ExtractionState = EExtractionState::InputPhase;
	CurrentInputStack.Empty();

	// 플레이어에 활성 터미널 설정
	if (InteractingPlayer)
	{
		InteractingPlayer->ActiveExtractionTerminal = this;
	}

	InteractionWidget->SetVisibility(false);

	// 화살표 위젯 생성
	CreateArrowWidget();

	OnExtractionStateChanged.Broadcast(ExtractionState);
	OnExtractionInputUpdated.Broadcast(CurrentInputStack);

	// 첫 번째 화살표 표시
	if (RequiredCommand.Num() > 0)
	{
		OnExtractionArrowChanged.Broadcast(RequiredCommand[0], 0);
	}
}

void AExtractionTerminal::CancelInputPhase()
{
	ExtractionState = EExtractionState::Ready;
	CurrentInputStack.Empty();

	// 플레이어에서 활성 터미널 해제
	if (InteractingPlayer)
	{
		InteractingPlayer->ActiveExtractionTerminal = nullptr;
		InteractingPlayer = nullptr;
	}

	// 화살표 위젯 제거
	RemoveArrowWidget();

	OnExtractionStateChanged.Broadcast(ExtractionState);
	OnExtractionArrowChanged.Broadcast(EStratagemDirection::None, -1);
}

void AExtractionTerminal::ProcessDirectionInput(EStratagemDirection Direction)
{
	if (ExtractionState != EExtractionState::InputPhase) return;
	if (Direction == EStratagemDirection::None) return;

	int32 CurrentIndex = CurrentInputStack.Num();

	// 현재 입력이 올바른지 확인
	if (CurrentIndex < RequiredCommand.Num() && RequiredCommand[CurrentIndex] == Direction)
	{
		// 올바른 입력
		CurrentInputStack.Add(Direction);

		if (InputSuccessSound)
		{
			UGameplayStatics::PlaySound2D(this, InputSuccessSound);
		}

		OnExtractionInputUpdated.Broadcast(CurrentInputStack);

		// 커맨드 완성 확인
		if (CurrentInputStack.Num() == RequiredCommand.Num())
		{
			if (InputCompleteSound)
			{
				UGameplayStatics::PlaySound2D(this, InputCompleteSound);
				OnSoundPlayed.Broadcast(FName("Extraction_Start")); // 자막
			}

			// 플레이어에서 터미널 연결 해제
			if (InteractingPlayer)
			{
				InteractingPlayer->ActiveExtractionTerminal = nullptr;
			}

			// 입력 완료 - None 전달
			OnExtractionArrowChanged.Broadcast(EStratagemDirection::None, CurrentInputStack.Num());

			// 화살표 위젯 제거
			RemoveArrowWidget();

			StartDefense();
		}
		else
		{
			// 다음 화살표 표시
			OnExtractionArrowChanged.Broadcast(RequiredCommand[CurrentInputStack.Num()], CurrentInputStack.Num());
		}
	}
	else
	{
		// 잘못된 입력 - 리셋
		CurrentInputStack.Empty();

		if (InputErrorSound)
		{
			UGameplayStatics::PlaySound2D(this, InputErrorSound);
		}

		OnExtractionInputUpdated.Broadcast(CurrentInputStack);

		// 첫 번째 화살표로 다시
		if (RequiredCommand.Num() > 0)
		{
			OnExtractionArrowChanged.Broadcast(RequiredCommand[0], 0);
		}
	}
}

void AExtractionTerminal::StartDefense()
{
	ExtractionState = EExtractionState::Defending;
	RemainingDefenseTime = DefenseTime;

	// 타이머 위젯 생성
	CreateTimerWidget();

	// 방어전 시작 사운드
	if (DefenseStartSound)
	{
		UGameplayStatics::PlaySound2D(this, DefenseStartSound);
	}

	OnExtractionStateChanged.Broadcast(ExtractionState);
	OnDefenseTimerUpdated.Broadcast(RemainingDefenseTime, DefenseTime);
}

void AExtractionTerminal::CompleteExtraction()
{
	// 타이머 위젯 제거
	RemoveTimerWidget();

	// 탈출 완료 사운드
	if (ExtractionCompleteSound)
	{
		UGameplayStatics::PlaySound2D(this, ExtractionCompleteSound);
		OnSoundPlayed.Broadcast(FName("Extraction_Complete")); // 자막
	}

	// 수송선 스폰
	SpawnExtractionShip();
}

void AExtractionTerminal::SpawnExtractionShip()
{
	if (!ExtractionShipClass) return;
	if (SpawnedShip) return; // 이미 스폰됨 - 중복 방지

	// 상태 변경하여 Tick에서 다시 호출되지 않도록
	ExtractionState = EExtractionState::Completed;
	
	// 착륙 위치 계산
	FVector LandingLocation = GetActorLocation() + ShipLandingOffset;

	// 수송선 스폰
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	SpawnedShip = GetWorld()->SpawnActor<AExtractionShip>(
		ExtractionShipClass,
		LandingLocation + FVector(0.0f, 0.0f, 10000.0f), // 임시 스폰 위치 (StartArrival에서 재설정)
		FRotator::ZeroRotator,
		SpawnParams
	);

	if (SpawnedShip)
	{
		// 수송선 이벤트 바인딩
		SpawnedShip->OnDepartureCompleted.AddDynamic(this, &AExtractionTerminal::OnShipDepartureCompleted);

		// 비행 시작
		SpawnedShip->StartArrival(LandingLocation);
	}
}

void AExtractionTerminal::OnShipDepartureCompleted()
{
	ExtractionState = EExtractionState::Completed;

	// 빛기둥 제거
	RemoveBeamEffect();

	OnExtractionStateChanged.Broadcast(ExtractionState);
	OnExtractionCompleted.Broadcast();
}

void AExtractionTerminal::SpawnBeamEffect()
{
	if (BeamEffect)
	{
		SpawnedBeam = UNiagaraFunctionLibrary::SpawnSystemAttached(
			BeamEffect,
			RootComponent,
			NAME_None,
			FVector::ZeroVector,
			FRotator::ZeroRotator,
			EAttachLocation::KeepRelativeOffset,
			true
		);

		if (SpawnedBeam)
		{
			SpawnedBeam->SetVariableLinearColor(FName("User.Color"), BeamColor);
			SpawnedBeam->SetWorldRotation(FRotator(0.f, 0.f, 0.f));
		}
	}
}

void AExtractionTerminal::RemoveBeamEffect()
{
	if (SpawnedBeam)
	{
		SpawnedBeam->Deactivate();
		SpawnedBeam = nullptr;
	}
}

void AExtractionTerminal::CreateArrowWidget()
{
	if (!ArrowWidgetClass) return;
	if (ArrowWidgetInstance) return;

	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	if (PC)
	{
		ArrowWidgetInstance = CreateWidget<UUserWidget>(PC, ArrowWidgetClass);
		if (ArrowWidgetInstance)
		{
			// 위젯에 터미널 참조 전달
			FName PropertyName = FName(TEXT("OwningTerminal"));
			if (FObjectProperty* Prop = FindFProperty<FObjectProperty>(ArrowWidgetInstance->GetClass(), PropertyName))
			{
				Prop->SetObjectPropertyValue_InContainer(ArrowWidgetInstance, this);
			}
			ArrowWidgetInstance->AddToViewport();
		}
	}
}

void AExtractionTerminal::RemoveArrowWidget()
{
	if (ArrowWidgetInstance)
	{
		ArrowWidgetInstance->RemoveFromParent();
		ArrowWidgetInstance = nullptr;
	}
}

void AExtractionTerminal::CreateTimerWidget()
{
	if (!TimerWidgetClass) return;
	if (TimerWidgetInstance) return;

	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	if (PC)
	{
		TimerWidgetInstance = CreateWidget<UUserWidget>(PC, TimerWidgetClass);
		if (TimerWidgetInstance)
		{
			// 위젯에 터미널 참조 전달
			FName PropertyName = FName(TEXT("OwningTerminal"));
			if (FObjectProperty* Prop = FindFProperty<FObjectProperty>(TimerWidgetInstance->GetClass(), PropertyName))
			{
				Prop->SetObjectPropertyValue_InContainer(TimerWidgetInstance, this);
			}
			TimerWidgetInstance->AddToViewport();
		}
	}
}

void AExtractionTerminal::RemoveTimerWidget()
{
	if (TimerWidgetInstance)
	{
		TimerWidgetInstance->RemoveFromParent();
		TimerWidgetInstance = nullptr;
	}
}
