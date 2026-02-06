#include "IntroCutsceneManager.h"
#include "CinematicPod.h"
#include "LevelSequence.h"
#include "LevelSequencePlayer.h"
#include "LevelSequenceActor.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
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

	// 약간의 딜레이 후 컷씬 시작 (플레이어 초기화 대기)
	FTimerHandle StartTimerHandle;
	GetWorldTimerManager().SetTimer(StartTimerHandle, this, &AIntroCutsceneManager::StartCutscene, 0.1f, false);
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

	// 플레이어 입력 비활성화 및 HUD 숨기기
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
	{
		PC->SetInputMode(FInputModeUIOnly());

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

	// 워밍업 액터들 스폰
	SpawnWarmupActors();

	// 시퀀서 재생
	if (IntroSequence)
	{
		ALevelSequenceActor* SequenceActor;
		FMovieSceneSequencePlaybackSettings Settings;
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

	OnIntroCutsceneFinished.Broadcast();
}
