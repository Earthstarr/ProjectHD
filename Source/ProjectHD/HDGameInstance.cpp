#include "HDGameInstance.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"

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
