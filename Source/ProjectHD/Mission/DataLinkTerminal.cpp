#include "DataLinkTerminal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "ProjectHD/Character/Player/FPSCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

ADataLinkTerminal::ADataLinkTerminal()
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

	// 업로드 유지 범위
	ProgressZone = CreateDefaultSubobject<USphereComponent>(TEXT("ProgressZone"));
	ProgressZone->SetupAttachment(RootComponent);
	ProgressZone->SetSphereRadius(ProgressZoneRadius);
	ProgressZone->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	ProgressZone->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	// 상호작용 위젯 (E - 활성화)
	InteractionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InteractionWidget"));
	InteractionWidget->SetupAttachment(RootComponent);
	InteractionWidget->SetRelativeLocation(FVector(0.0f, 0.0f, 150.0f));
	InteractionWidget->SetWidgetSpace(EWidgetSpace::Screen);
	InteractionWidget->SetDrawSize(FVector2D(200.0f, 50.0f));
	InteractionWidget->SetVisibility(false);

	// 기본 커맨드 설정 (↑↓←→)
	RequiredCommand = { EStratagemDirection::Up, EStratagemDirection::Down,
		EStratagemDirection::Left, EStratagemDirection::Right };
}

void ADataLinkTerminal::BeginPlay()
{
	Super::BeginPlay();

	// 오버랩 이벤트 바인딩
	InteractionSphere->OnComponentBeginOverlap.AddDynamic(this, &ADataLinkTerminal::HandleInteractionBeginOverlap);
	InteractionSphere->OnComponentEndOverlap.AddDynamic(this, &ADataLinkTerminal::HandleInteractionEndOverlap);

	// ProgressZone 반지름 설정
	ProgressZone->SetSphereRadius(ProgressZoneRadius);
}

void ADataLinkTerminal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TerminalState == EDataLinkTerminalState::Uploading)
	{
		UpdateProgress(DeltaTime);
	}
}

void ADataLinkTerminal::HandleInteractionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AFPSCharacter* Player = Cast<AFPSCharacter>(OtherActor))
	{
		OnOverlapBegin();
	}
}

void ADataLinkTerminal::HandleInteractionEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (AFPSCharacter* Player = Cast<AFPSCharacter>(OtherActor))
	{
		OnOverlapEnd();
	}
}

void ADataLinkTerminal::Interact(AFPSCharacter* Interactor)
{
	if (!Interactor) return;

	if (TerminalState == EDataLinkTerminalState::Idle)
	{
		InteractingPlayer = Interactor;
		StartInputPhase();
	}
}

void ADataLinkTerminal::OnOverlapBegin()
{
	if (TerminalState == EDataLinkTerminalState::Idle)
	{
		InteractionWidget->SetVisibility(true);
	}
}

void ADataLinkTerminal::OnOverlapEnd()
{
	InteractionWidget->SetVisibility(false);

	// InputPhase에서 범위 이탈 시 취소
	if (TerminalState == EDataLinkTerminalState::InputPhase)
	{
		CancelInputPhase();
	}
}

void ADataLinkTerminal::StartInputPhase()
{
	TerminalState = EDataLinkTerminalState::InputPhase;
	CurrentInputStack.Empty();

	// 플레이어에 활성 터미널 설정
	if (InteractingPlayer)
	{
		InteractingPlayer->ActiveDataLinkTerminal = this;
	}

	InteractionWidget->SetVisibility(false);

	// 화살표 위젯 생성
	CreateArrowWidget();

	OnDataLinkStateChanged.Broadcast(TerminalState);
	OnDataLinkInputUpdated.Broadcast(CurrentInputStack);

	// 첫 번째 화살표 표시
	if (RequiredCommand.Num() > 0)
	{
		OnDataLinkArrowChanged.Broadcast(RequiredCommand[0], 0);
	}
}

void ADataLinkTerminal::CancelInputPhase()
{
	TerminalState = EDataLinkTerminalState::Idle;
	CurrentInputStack.Empty();

	// 플레이어에서 활성 터미널 해제
	if (InteractingPlayer)
	{
		InteractingPlayer->ActiveDataLinkTerminal = nullptr;
		InteractingPlayer = nullptr;
	}

	// 화살표 위젯 제거
	RemoveArrowWidget();

	OnDataLinkStateChanged.Broadcast(TerminalState);
	OnDataLinkArrowChanged.Broadcast(EStratagemDirection::None, -1);
}

void ADataLinkTerminal::ProcessDirectionInput(EStratagemDirection Direction)
{
	if (TerminalState != EDataLinkTerminalState::InputPhase) return;
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

		OnDataLinkInputUpdated.Broadcast(CurrentInputStack);

		// 커맨드 완성 확인
		if (CurrentInputStack.Num() == RequiredCommand.Num())
		{
			if (InputCompleteSound)
			{
				UGameplayStatics::PlaySound2D(this, InputCompleteSound);
			}

			// 플레이어에서 터미널 연결 해제
			if (InteractingPlayer)
			{
				InteractingPlayer->ActiveDataLinkTerminal = nullptr;
			}

			// 입력 완료 - None 전달
			OnDataLinkArrowChanged.Broadcast(EStratagemDirection::None, CurrentInputStack.Num());

			StartUploading();
		}
		else
		{
			// 다음 화살표 표시
			OnDataLinkArrowChanged.Broadcast(RequiredCommand[CurrentInputStack.Num()], CurrentInputStack.Num());
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

		OnDataLinkInputUpdated.Broadcast(CurrentInputStack);

		// 첫 번째 화살표로 다시
		if (RequiredCommand.Num() > 0)
		{
			OnDataLinkArrowChanged.Broadcast(RequiredCommand[0], 0);
		}
	}
}

void ADataLinkTerminal::StartUploading()
{
	TerminalState = EDataLinkTerminalState::Uploading;
	CurrentProgress = 0.0f;

	// 화살표 위젯 제거, 진행도 위젯 생성
	RemoveArrowWidget();
	CreateProgressWidget();

	OnDataLinkStateChanged.Broadcast(TerminalState);
	OnDataLinkProgressChanged.Broadcast(CurrentProgress, UploadDuration);
}

void ADataLinkTerminal::UpdateProgress(float DeltaTime)
{
	if (!IsPlayerInProgressZone())
	{
		InterruptUpload();
		return;
	}

	CurrentProgress += DeltaTime;
	OnDataLinkProgressChanged.Broadcast(CurrentProgress, UploadDuration);

	// 완료 체크
	if (CurrentProgress >= UploadDuration)
	{
		CompleteUpload();
	}
}

bool ADataLinkTerminal::IsPlayerInProgressZone() const
{
	AFPSCharacter* Player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	if (!Player) return false;

	float Distance = FVector::Dist(GetActorLocation(), Player->GetActorLocation());
	return Distance <= ProgressZoneRadius;
}

void ADataLinkTerminal::InterruptUpload()
{
	// 업로드 중단 - Idle로 리셋
	TerminalState = EDataLinkTerminalState::Idle;
	CurrentProgress = 0.0f;
	CurrentInputStack.Empty();
	InteractingPlayer = nullptr;

	// 진행도 위젯 제거
	RemoveProgressWidget();

	OnDataLinkStateChanged.Broadcast(TerminalState);
	OnDataLinkProgressChanged.Broadcast(0.0f, UploadDuration);

	// 플레이어가 근처에 있으면 위젯 표시
	if (IsPlayerInProgressZone())
	{
		InteractionWidget->SetVisibility(true);
	}
}

void ADataLinkTerminal::CompleteUpload()
{
	TerminalState = EDataLinkTerminalState::Completed;
	InteractingPlayer = nullptr;

	RemoveProgressWidget();

	// 사운드 및 자막
	if (UploadCompleteSound)
	{
		UGameplayStatics::PlaySound2D(this, UploadCompleteSound);
	}
	if (!UploadCompleteSubtitleKey.IsNone())
	{
		OnSoundPlayed.Broadcast(UploadCompleteSubtitleKey);
	}

	OnDataLinkStateChanged.Broadcast(TerminalState);
	OnDataLinkCompleted.Broadcast();
}

void ADataLinkTerminal::CreateArrowWidget()
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

void ADataLinkTerminal::RemoveArrowWidget()
{
	if (ArrowWidgetInstance)
	{
		ArrowWidgetInstance->RemoveFromParent();
		ArrowWidgetInstance = nullptr;
	}
}

void ADataLinkTerminal::CreateProgressWidget()
{
	if (!ProgressWidgetClass) return;
	if (ProgressWidgetInstance) return;

	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	if (PC)
	{
		ProgressWidgetInstance = CreateWidget<UUserWidget>(PC, ProgressWidgetClass);
		if (ProgressWidgetInstance)
		{
			// 위젯에 터미널 참조 전달
			FName PropertyName = FName(TEXT("OwningTerminal"));
			if (FObjectProperty* Prop = FindFProperty<FObjectProperty>(ProgressWidgetInstance->GetClass(), PropertyName))
			{
				Prop->SetObjectPropertyValue_InContainer(ProgressWidgetInstance, this);
			}
			ProgressWidgetInstance->AddToViewport();
		}
	}
}

void ADataLinkTerminal::RemoveProgressWidget()
{
	if (ProgressWidgetInstance)
	{
		ProgressWidgetInstance->RemoveFromParent();
		ProgressWidgetInstance = nullptr;
	}
}
