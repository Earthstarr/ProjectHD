#include "HDGameInstance.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Character/Player/FPSCharacter.h"
#include "Engine/Engine.h"
#include "HDSaveSettings.h"
#include "Sound/SoundMix.h"
#include "Sound/SoundClass.h"
#include "GameFramework/GameUserSettings.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"

static const FString SettingsSlotName = TEXT("HDSettings");

UHDGameInstance::UHDGameInstance()
{
	CurrentBGMSound = nullptr;
	BGMComponent = nullptr;
	CachedSettings = nullptr;
}

void UHDGameInstance::Init()
{
	Super::Init();
	LoadAndApplySettings();
}

// ===== 설정 저장/로드 =====

void UHDGameInstance::SaveSettings()
{
	if (CachedSettings)
	{
		UGameplayStatics::SaveGameToSlot(CachedSettings, SettingsSlotName, 0);
	}
}

void UHDGameInstance::LoadAndApplySettings()
{
	if (UGameplayStatics::DoesSaveGameExist(SettingsSlotName, 0))
	{
		CachedSettings = Cast<UHDSaveSettings>(UGameplayStatics::LoadGameFromSlot(SettingsSlotName, 0));
	}

	if (!CachedSettings)
	{
		CachedSettings = Cast<UHDSaveSettings>(UGameplayStatics::CreateSaveGameObject(UHDSaveSettings::StaticClass()));
	}

	// Audio 볼륨 적용
	if (MasterSoundMix)
	{
		UGameplayStatics::PushSoundMixModifier(GetWorld(), MasterSoundMix);
		ApplyAudioVolume(MasterSoundClass, CachedSettings->MasterVolume);
		ApplyAudioVolume(MusicSoundClass, CachedSettings->MusicVolume);
		ApplyAudioVolume(SFXSoundClass, CachedSettings->SFXVolume);
	}

	// Brightness 적용
	if (GEngine)
	{
		float Gamma = FMath::GetMappedRangeValueClamped(
			FVector2D(0.0f, 100.0f), FVector2D(1.5f, 3.0f), CachedSettings->Brightness);
		GEngine->DisplayGamma = Gamma;
	}
}

// ===== Audio 설정 =====

void UHDGameInstance::ApplyAudioVolume(USoundClass* SoundClass, float Volume)
{
	if (!MasterSoundMix || !SoundClass) return;

	UWorld* World = GetWorld();
	if (!World) return;

	UGameplayStatics::SetSoundMixClassOverride(World, MasterSoundMix, SoundClass,
		FMath::Clamp(Volume, 0.0f, 1.0f), 1.0f, 0.0f, true);
}

void UHDGameInstance::SetMasterVolume(float Volume)
{
	if (!CachedSettings) return;
	CachedSettings->MasterVolume = FMath::Clamp(Volume, 0.0f, 1.0f);
	ApplyAudioVolume(MasterSoundClass, CachedSettings->MasterVolume);
	SaveSettings();
}

float UHDGameInstance::GetMasterVolume() const
{
	return CachedSettings ? CachedSettings->MasterVolume : 1.0f;
}

void UHDGameInstance::SetMusicVolume(float Volume)
{
	if (!CachedSettings) return;
	CachedSettings->MusicVolume = FMath::Clamp(Volume, 0.0f, 1.0f);
	ApplyAudioVolume(MusicSoundClass, CachedSettings->MusicVolume);

	// BGM 볼륨도 연동
	SetBGMVolume(CachedSettings->MusicVolume);

	SaveSettings();
}

float UHDGameInstance::GetMusicVolume() const
{
	return CachedSettings ? CachedSettings->MusicVolume : 1.0f;
}

void UHDGameInstance::SetSFXVolume(float Volume)
{
	if (!CachedSettings) return;
	CachedSettings->SFXVolume = FMath::Clamp(Volume, 0.0f, 1.0f);
	ApplyAudioVolume(SFXSoundClass, CachedSettings->SFXVolume);
	SaveSettings();
}

float UHDGameInstance::GetSFXVolume() const
{
	return CachedSettings ? CachedSettings->SFXVolume : 1.0f;
}

// ===== Video 설정 =====

void UHDGameInstance::SetWindowMode(int32 Mode)
{
	UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings();
	if (!Settings) return;

	EWindowMode::Type WinMode;
	switch (Mode)
	{
	case 0: WinMode = EWindowMode::Fullscreen; break;
	case 1: WinMode = EWindowMode::WindowedFullscreen; break;
	case 2: WinMode = EWindowMode::Windowed; break;
	default: WinMode = EWindowMode::WindowedFullscreen; break;
	}

	Settings->SetFullscreenMode(WinMode);

	// Fullscreen 모드는 데스크탑 해상도와 일치해야 정상 작동
	if (WinMode == EWindowMode::Fullscreen)
	{
		Settings->SetScreenResolution(Settings->GetDesktopResolution());
	}
}

int32 UHDGameInstance::GetWindowMode() const
{
	UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings();
	if (!Settings) return 1;

	switch (Settings->GetFullscreenMode())
	{
	case EWindowMode::Fullscreen: return 0;
	case EWindowMode::WindowedFullscreen: return 1;
	case EWindowMode::Windowed: return 2;
	default: return 1;
	}
}

TArray<FIntPoint> UHDGameInstance::GetSupportedResolutions() const
{
	UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings();
	FIntPoint DesktopRes = Settings ? Settings->GetDesktopResolution() : FIntPoint(1920, 1080);

	// 고정 해상도 목록 (16:9, 큰 순서)
	const TArray<FIntPoint> AllResolutions = {
		FIntPoint(3840, 2160),
		FIntPoint(2560, 1440),
		FIntPoint(1920, 1080),
		FIntPoint(1600, 900),
		FIntPoint(1280, 720)
	};

	TArray<FIntPoint> Resolutions;
	for (const FIntPoint& Res : AllResolutions)
	{
		if (Res.X <= DesktopRes.X && Res.Y <= DesktopRes.Y)
		{
			Resolutions.Add(Res);
		}
	}

	return Resolutions;
}

void UHDGameInstance::SetResolution(FIntPoint Resolution)
{
	UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings();
	if (!Settings) return;

	Settings->SetScreenResolution(Resolution);
}

FIntPoint UHDGameInstance::GetCurrentResolution() const
{
	UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings();
	if (!Settings) return FIntPoint(1920, 1080);

	return Settings->GetScreenResolution();
}

FString UHDGameInstance::FormatResolution(FIntPoint Resolution)
{
	return FString::Printf(TEXT("%d x %d"), Resolution.X, Resolution.Y);
}

void UHDGameInstance::SetBrightness(float Value)
{
	if (!CachedSettings) return;
	CachedSettings->Brightness = FMath::Clamp(Value, 0.0f, 100.0f);

	if (GEngine)
	{
		float Gamma = FMath::GetMappedRangeValueClamped(
			FVector2D(0.0f, 100.0f), FVector2D(1.5f, 3.0f), CachedSettings->Brightness);
		GEngine->DisplayGamma = Gamma;
	}

	SaveSettings();
}

float UHDGameInstance::GetBrightness() const
{
	return CachedSettings ? CachedSettings->Brightness : 50.0f;
}

void UHDGameInstance::SetOverallQuality(int32 Level)
{
	UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings();
	if (!Settings) return;
	Settings->SetOverallScalabilityLevel(Level);
}

int32 UHDGameInstance::GetOverallQuality() const
{
	UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings();
	return Settings ? Settings->GetOverallScalabilityLevel() : 3;
}

void UHDGameInstance::SetShadowQuality(int32 Level)
{
	UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings();
	if (Settings) Settings->SetShadowQuality(Level);
}

int32 UHDGameInstance::GetShadowQuality() const
{
	UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings();
	return Settings ? Settings->GetShadowQuality() : 3;
}

void UHDGameInstance::SetAntiAliasingQuality(int32 Level)
{
	UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings();
	if (Settings) Settings->SetAntiAliasingQuality(Level);
}

int32 UHDGameInstance::GetAntiAliasingQuality() const
{
	UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings();
	return Settings ? Settings->GetAntiAliasingQuality() : 3;
}

void UHDGameInstance::SetTextureQuality(int32 Level)
{
	UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings();
	if (Settings) Settings->SetTextureQuality(Level);
}

int32 UHDGameInstance::GetTextureQuality() const
{
	UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings();
	return Settings ? Settings->GetTextureQuality() : 3;
}

void UHDGameInstance::SetViewDistanceQuality(int32 Level)
{
	UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings();
	if (Settings) Settings->SetViewDistanceQuality(Level);
}

int32 UHDGameInstance::GetViewDistanceQuality() const
{
	UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings();
	return Settings ? Settings->GetViewDistanceQuality() : 3;
}

void UHDGameInstance::SetEffectsQuality(int32 Level)
{
	UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings();
	if (Settings) Settings->SetVisualEffectQuality(Level);
}

int32 UHDGameInstance::GetEffectsQuality() const
{
	UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings();
	return Settings ? Settings->GetVisualEffectQuality() : 3;
}

void UHDGameInstance::ApplyVideoSettings()
{
	UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings();
	if (!Settings) return;

	Settings->ApplySettings(false);
	Settings->SaveSettings();
}

// ===== Key Binding =====

void UHDGameInstance::RemapKey(UInputMappingContext* Context, UInputAction* Action, FKey NewKey)
{
	if (!Context || !Action) return;

	// 기존 키 찾아서 제거
	FKey OldKey = GetKeyForAction(Context, Action);
	if (OldKey.IsValid())
	{
		Context->UnmapKey(Action, OldKey);
	}

	// 새 키 매핑
	Context->MapKey(Action, NewKey);

	// 입력 시스템 리빌드
	UWorld* World = GetWorld();
	if (World)
	{
		APlayerController* PC = World->GetFirstPlayerController();
		if (PC)
		{
			if (auto* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
			{
				Subsystem->RequestRebuildControlMappings();
			}
		}
	}

	// 저장
	if (CachedSettings)
	{
		CachedSettings->KeyBindings.Add(Action->GetFName(), NewKey);
		SaveSettings();
	}
}

FKey UHDGameInstance::GetKeyForAction(UInputMappingContext* Context, UInputAction* Action) const
{
	if (!Context || !Action) return EKeys::Invalid;

	for (const FEnhancedActionKeyMapping& Mapping : Context->GetMappings())
	{
		if (Mapping.Action == Action)
		{
			return Mapping.Key;
		}
	}

	return EKeys::Invalid;
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

	if (Score >= 8000) return TEXT("SS");
	if (Score >= 6000) return TEXT("S");
	if (Score >= 5000) return TEXT("A");
	if (Score >= 4000) return TEXT("B");
	if (Score >= 3000) return TEXT("C");
	if (Score >= 2000) return TEXT("D");
	return TEXT("F");
}

FLinearColor UHDGameInstance::GetMissionGradeColor() const
{
	FString Grade = GetMissionGrade();

	if (Grade == TEXT("SS")) return FLinearColor(1.0f, 0.85f, 0.0f);   // 금색
	if (Grade == TEXT("S"))  return FLinearColor(1.0f, 0.5f, 0.0f);    // 주황
	if (Grade == TEXT("A"))  return FLinearColor(0.0f, 1.0f, 0.2f);    // 초록
	if (Grade == TEXT("B"))  return FLinearColor(0.3f, 0.7f, 1.0f);    // 하늘
	if (Grade == TEXT("C"))  return FLinearColor(0.7f, 0.7f, 0.7f);    // 회색
	if (Grade == TEXT("D"))  return FLinearColor(0.8f, 0.4f, 0.2f);    // 갈색
	return FLinearColor(1.0f, 0.1f, 0.1f);                             // 빨강 (F)
}

FString UHDGameInstance::GetFormattedMissionTime() const
{
	int32 TotalSeconds = FMath::RoundToInt(MissionResult.MissionTime);
	int32 Minutes = TotalSeconds / 60;
	int32 Seconds = TotalSeconds % 60;

	return FString::Printf(TEXT("%02d:%02d"), Minutes, Seconds);
}

FString UHDGameInstance::GetElapsedTimeFormatted(UObject* WorldContextObject) const
{
	if (!bMissionTimerRunning)
	{
		return GetFormattedMissionTime();
	}

	if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		float Elapsed = World->GetTimeSeconds() - MissionStartTime;
		int32 TotalSeconds = FMath::RoundToInt(Elapsed);
		int32 Minutes = TotalSeconds / 60;
		int32 Seconds = TotalSeconds % 60;
		return FString::Printf(TEXT("%02d:%02d"), Minutes, Seconds);
	}

	return TEXT("00:00");
}
