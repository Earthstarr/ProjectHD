#include "HDGameInstance.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Character/Player/FPSCharacter.h"
#include "Engine/Engine.h"

UHDGameInstance::UHDGameInstance()
{
	CurrentBGMSound = nullptr;
	BGMComponent = nullptr;
}

void UHDGameInstance::PlayBGM(USoundBase* Music, float FadeInDuration)
{
	if (!Music) return;

	// 같은 BGM이면 무시
	if (CurrentBGMSound == Music && IsBGMPlaying())
	{
		return;
	}

	// 기존 BGM 중지
	if (BGMComponent && BGMComponent->IsPlaying())
	{
		BGMComponent->FadeOut(FadeInDuration, 0.0f);
	}

	// 새 BGM 재생
	CurrentBGMSound = Music;
	BGMComponent = UGameplayStatics::SpawnSound2D(GetWorld(), Music, DefaultBGMVolume, 1.0f, 0.0f, nullptr, false, false);

	if (BGMComponent)
	{
		BGMComponent->FadeIn(FadeInDuration, DefaultBGMVolume);
	}
}

void UHDGameInstance::StopBGM(float FadeOutDuration)
{
	if (BGMComponent && BGMComponent->IsPlaying())
	{
		BGMComponent->FadeOut(FadeOutDuration, 0.0f);
	}
	CurrentBGMSound = nullptr;
}

void UHDGameInstance::SetBGMVolume(float Volume)
{
	DefaultBGMVolume = FMath::Clamp(Volume, 0.0f, 1.0f);

	if (BGMComponent)
	{
		BGMComponent->SetVolumeMultiplier(DefaultBGMVolume);
	}
}

bool UHDGameInstance::IsBGMPlaying() const
{
	return BGMComponent && BGMComponent->IsPlaying();
}

// ===== 미션 결과 시스템 =====

void UHDGameInstance::ResetMissionResult()
{
	MissionResult = FMissionResult();
	bMissionTimerRunning = false;
	MissionStartTime = 0.0f;
}

void UHDGameInstance::StartMissionTimer(UObject* WorldContextObject)
{
	if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		MissionStartTime = World->GetTimeSeconds();
		bMissionTimerRunning = true;
	}
}

void UHDGameInstance::StopMissionTimer(UObject* WorldContextObject)
{
	UE_LOG(LogTemp, Warning, TEXT("[MissionTimer] StopMissionTimer called, bRunning: %d"), bMissionTimerRunning);

	if (bMissionTimerRunning)
	{
		if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
		{
			MissionResult.MissionTime = World->GetTimeSeconds() - MissionStartTime;
			UE_LOG(LogTemp, Warning, TEXT("[MissionTimer] Timer Stopped! Time: %.2f"), MissionResult.MissionTime);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("[MissionTimer] World is NULL!"));
		}
		bMissionTimerRunning = false;
	}
}

void UHDGameInstance::AddEnemyKill(int32 ScoreValue)
{
	MissionResult.EnemiesKilled++;
	MissionResult.FinalScore += ScoreValue;
}

void UHDGameInstance::AddPlayerDeath()
{
	MissionResult.PlayerDeaths++;
	// 사망 시 점수 감소
	MissionResult.FinalScore = FMath::Max(0, MissionResult.FinalScore - DeathPenalty);
}

void UHDGameInstance::AddStratagemUsed(EStratagemType Type)
{
	switch (Type)
	{
	case EStratagemType::Bomb500kg:
		MissionResult.Bomb500kgUsed++;
		break;
	case EStratagemType::Supply:
		MissionResult.SupplyUsed++;
		break;
	case EStratagemType::EagleCluster:
		MissionResult.EagleClusterUsed++;
		break;
	case EStratagemType::OrbitalLaser:
		MissionResult.OrbitalLaserUsed++;
		break;
	case EStratagemType::Sentry:
		MissionResult.SentryUsed++;
		break;
	case EStratagemType::Rearm:
		MissionResult.RearmUsed++;
		break;
	default:
		break;
	}
}

void UHDGameInstance::CalculateFinalScore()
{
	// 기본 점수는 킬 수로 이미 누적
	// 추가 보너스/페널티 계산

	// 시간 보너스
	float TimeBonus = FMath::Max(0.0f, TimeBonusBaseSeconds - MissionResult.MissionTime) * TimeBonusMultiplier;
	MissionResult.FinalScore += FMath::RoundToInt(TimeBonus);

	// 무사망 보너스
	if (MissionResult.PlayerDeaths == 0)
	{
		MissionResult.FinalScore += NoDealthBonus;
	}
}

FString UHDGameInstance::GetMissionGrade() const
{
	int32 Score = MissionResult.FinalScore;

	if (Score >= 5000) return TEXT("SS");
	if (Score >= 4000) return TEXT("S");
	if (Score >= 3000) return TEXT("A");
	if (Score >= 2000) return TEXT("B");
	if (Score >= 1000) return TEXT("C");
	if (Score >= 500) return TEXT("D");
	return TEXT("F");
}

FString UHDGameInstance::GetFormattedMissionTime() const
{
	int32 TotalSeconds = FMath::RoundToInt(MissionResult.MissionTime);
	int32 Minutes = TotalSeconds / 60;
	int32 Seconds = TotalSeconds % 60;

	return FString::Printf(TEXT("%02d:%02d"), Minutes, Seconds);
}
