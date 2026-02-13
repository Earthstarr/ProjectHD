#include "IntroCutsceneManager.h"
#include "CinematicPod.h"
#include "LevelSequence.h"
#include "LevelSequencePlayer.h"
#include "LevelSequenceActor.h"
#include "MovieScene.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "NiagaraSystem.h"
#include "Engine/AssetManager.h"
#include "Blueprint/UserWidget.h"
#include "ProjectHD/Character/Player/FPSCharacter.h"
#include "ProjectHD/HDGameInstance.h"

AIntroCutsceneManager::AIntroCutsceneManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AIntroCutsceneManager::BeginPlay()
{
	Super::BeginPlay();

	// 바로 플래그 끄기 (FPSCharacter보다 먼저 실행되도록)
	if (UHDGameInstance* GI = Cast<UHDGameInstance>(UGameplayStatics::GetGameInstance(this)))
	{
		GI->bShouldSpawnWithPod = false;
	}

	// 플레이어 입력 비활성화 및 숨기기 (프리로드 중에도)
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
	{
		PC->SetInputMode(FInputModeUIOnly());

		if (AFPSCharacter* Player = Cast<AFPSCharacter>(PC->GetPawn()))
		{
			Player->HideAllHUD();
			Player->SetActorHiddenInGame(true);
		}
	}

	// 로딩 화면 표시
	if (LoadingWidgetClass)
	{
		LoadingWidget = CreateWidget<UUserWidget>(GetWorld(), LoadingWidgetClass);
		if (LoadingWidget)
		{
			LoadingWidget->AddToViewport(100); // 높은 ZOrder로 맨 앞에 표시
		}
	}

	// 워밍업 즉시 시작 (로딩 중에 병렬로 처리)
	SpawnWarmupActors();

	// 비동기 프리로드 시작
	StartAsyncPreload();

	// 서브레벨 로드 시작 (완료되면 컷씬 시작)
	if (!SublevelToLoad.IsNone())
	{
		FLatentActionInfo LatentInfo;
		LatentInfo.CallbackTarget = this;
		LatentInfo.ExecutionFunction = FName("OnSublevelLoaded");
		LatentInfo.Linkage = 0;
		LatentInfo.UUID = 0;
		UGameplayStatics::LoadStreamLevel(this, SublevelToLoad, true, true, LatentInfo);
	}
	else
	{
		// 서브레벨 없으면 바로 완료 처리
		FTimerHandle TimerHandle;
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AIntroCutsceneManager::OnSublevelLoaded, 0.1f, false);
	}
}

void AIntroCutsceneManager::StartAsyncPreload()
{
	TArray<FSoftObjectPath> PathsToLoad;

	// 액터 클래스들
	for (const TSoftClassPtr<AActor>& SoftClass : PreloadActorClasses)
	{
		if (!SoftClass.IsNull())
		{
			PathsToLoad.Add(SoftClass.ToSoftObjectPath());
		}
	}

	// 나이아가라 시스템들
	for (const TSoftObjectPtr<UNiagaraSystem>& SoftPtr : PreloadNiagaraSystems)
	{
		if (!SoftPtr.IsNull())
		{
			PathsToLoad.Add(SoftPtr.ToSoftObjectPath());
		}
	}

	// 사운드들
	for (const TSoftObjectPtr<USoundBase>& SoftPtr : PreloadSounds)
	{
		if (!SoftPtr.IsNull())
		{
			PathsToLoad.Add(SoftPtr.ToSoftObjectPath());
		}
	}

	// 기타 에셋들
	for (const TSoftObjectPtr<UObject>& SoftPtr : PreloadMiscAssets)
	{
		if (!SoftPtr.IsNull())
		{
			PathsToLoad.Add(SoftPtr.ToSoftObjectPath());
		}
	}

	if (PathsToLoad.Num() > 0)
	{
		FStreamableManager& StreamableManager = UAssetManager::GetStreamableManager();
		PreloadHandle = StreamableManager.RequestAsyncLoad(
			PathsToLoad,
			FStreamableDelegate::CreateUObject(this, &AIntroCutsceneManager::OnPreloadComplete),
			FStreamableManager::AsyncLoadHighPriority
		);
	}
	else
	{
		// 프리로드할 에셋이 없으면 바로 완료 처리
		FTimerHandle StartTimerHandle;
		GetWorldTimerManager().SetTimer(StartTimerHandle, this, &AIntroCutsceneManager::OnPreloadComplete, 0.1f, false);
	}
}

void AIntroCutsceneManager::OnPreloadComplete()
{
	// 프리로드 핸들 해제
	if (PreloadHandle.IsValid())
	{
		PreloadHandle.Reset();
	}

	bPreloadComplete = true;
	// 프리로드 완료, 서브레벨 로드 완료를 기다림
}

void AIntroCutsceneManager::OnSublevelLoaded()
{
	// 서브레벨 로드 완료 후 약간 대기 (텍스처 스트리밍 등)
	FTimerHandle StartTimerHandle;
	GetWorldTimerManager().SetTimer(StartTimerHandle, [this]()
	{
		// 로딩 화면 숨기기
		if (LoadingWidget)
		{
			LoadingWidget->RemoveFromParent();
			LoadingWidget = nullptr;
		}

		StartCutscene();

	}, WarmupExtraDelay, false);
}

void AIntroCutsceneManager::StartCutscene()
{
	// 인트로 컷씬 사운드 재생
	if (IntroCutsceneSound)
	{
		UGameplayStatics::PlaySound2D(this, IntroCutsceneSound);
	}
	if (!IntroCutsceneSubtitleKey.IsNone())
	{
		OnSoundPlayed.Broadcast(IntroCutsceneSubtitleKey);
	}

	// 플레이어 HUD 숨기기 및 POD 강하 (FPSCharacter BeginPlay 이후이므로 여기서 다시 숨김)
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
	{
		if (AFPSCharacter* Player = Cast<AFPSCharacter>(PC->GetPawn()))
		{
			Player->HideAllHUD();
			Player->SetActorHiddenInGame(true);

			// 컷씬 중에 미리 POD 강하 (워밍업용 - 렉 방지, 소리 없음)
			Player->SpawnWithPod(false);
		}
	}

	// 시네마틱 포드 딜레이 후 스폰
	if (CinematicPodClass)
	{
		FTimerHandle PodTimerHandle;
		GetWorldTimerManager().SetTimer(PodTimerHandle, this, &AIntroCutsceneManager::SpawnCinematicPod, PodSpawnDelay, false);
	}
	
	// 시퀀서 재생
	if (IntroSequence)
	{
		// 오디오 클럭 소스로 설정 (오디오와 영상 동기화)
		if (UMovieScene* MovieScene = IntroSequence->GetMovieScene())
		{
			MovieScene->SetClockSource(EUpdateClockSource::Audio);
		}

		ALevelSequenceActor* SequenceActor;
		FMovieSceneSequencePlaybackSettings Settings;
		Settings.bPauseAtEnd = true;

		SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(
			GetWorld(), IntroSequence, Settings, SequenceActor);

		if (SequencePlayer)
		{
			SequencePlayer->OnFinished.AddDynamic(this, &AIntroCutsceneManager::OnSequenceFinished);
			SequencePlayer->Play();
		}
	}
	else
	{
		// 시퀀서 없으면 몇 초 후 바로 완료
		FTimerHandle TimerHandle;
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AIntroCutsceneManager::OnSequenceFinished, 5.0f, false);
	}
}

void AIntroCutsceneManager::SpawnCinematicPod()
{
	if (CinematicPodClass)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		GetWorld()->SpawnActor<ACinematicPod>(CinematicPodClass, PodSpawnLocation, FRotator::ZeroRotator, SpawnParams);
	}
}

void AIntroCutsceneManager::SpawnWarmupActors()
{
	// 액터 스폰
	for (TSubclassOf<AActor> ActorClass : WarmupActorClasses)
	{
		if (ActorClass)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorClass, WarmupSpawnLocation, FRotator::ZeroRotator, SpawnParams);

			if (SpawnedActor)
			{
				SpawnedActor->SetLifeSpan(3.0f);
			}
		}
	}

	// 나이아가라 이펙트 스폰
	for (UNiagaraSystem* NiagaraSystem : WarmupNiagaraSystems)
	{
		if (NiagaraSystem)
		{
			UNiagaraComponent* SpawnedFX = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
				GetWorld(), NiagaraSystem, WarmupSpawnLocation, FRotator::ZeroRotator,
				FVector(1.0f), true, true, ENCPoolMethod::None, true);

			// 3초 후 비활성화 (루핑 이펙트 대응)
			if (SpawnedFX)
			{
				FTimerHandle TimerHandle;
				TWeakObjectPtr<UNiagaraComponent> WeakFX = SpawnedFX;
				GetWorldTimerManager().SetTimer(TimerHandle, [WeakFX]()
				{
					if (WeakFX.IsValid())
					{
						WeakFX->Deactivate();
					}
				}, 3.0f, false);
			}
		}
	}

	// 사운드 프리로드 (볼륨 0으로 재생)
	for (USoundBase* Sound : WarmupSounds)
	{
		if (Sound)
		{
			UGameplayStatics::PlaySound2D(this, Sound, 0.0f);
		}
	}
}

void AIntroCutsceneManager::OnSequenceFinished()
{
	// 플레이어 입력 복구 및 강하 시작
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
	{
		PC->SetInputMode(FInputModeGameOnly());

		if (AFPSCharacter* Player = Cast<AFPSCharacter>(PC->GetPawn()))
		{
			Player->SetActorHiddenInGame(false);
			Player->RestorePlayerState();
			Player->SpawnWithPod();
		}
	}

	// BGM 재생 및 미션 타이머 시작
	if (UHDGameInstance* GI = Cast<UHDGameInstance>(UGameplayStatics::GetGameInstance(this)))
	{
		if (PostCutsceneBGM)
		{
			GI->PlayBGM(PostCutsceneBGM, BGMFadeInDuration);
		}
		GI->ResetMissionResult();
		GI->StartMissionTimer(this);
	}

	OnIntroCutsceneFinished.Broadcast();
}
