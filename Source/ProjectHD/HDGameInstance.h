#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "HDGameInstance.generated.h"

UCLASS()
class PROJECTHD_API UHDGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UHDGameInstance();

	// BGM 재생
	UFUNCTION(BlueprintCallable, Category = "Audio")
	void PlayBGM(USoundBase* Music, float FadeInDuration = 1.0f);

	// BGM 중지
	UFUNCTION(BlueprintCallable, Category = "Audio")
	void StopBGM(float FadeOutDuration = 1.0f);

	// BGM 볼륨 설정
	UFUNCTION(BlueprintCallable, Category = "Audio")
	void SetBGMVolume(float Volume);

	// 현재 BGM 가져오기
	UFUNCTION(BlueprintPure, Category = "Audio")
	USoundBase* GetCurrentBGM() const { return CurrentBGMSound; }

	// BGM 재생 중인지
	UFUNCTION(BlueprintPure, Category = "Audio")
	bool IsBGMPlaying() const;

protected:
	UPROPERTY()
	class UAudioComponent* BGMComponent;

	UPROPERTY()
	USoundBase* CurrentBGMSound;

	UPROPERTY(EditDefaultsOnly, Category = "Audio")
	float DefaultBGMVolume = 0.5f;
};
