#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "HDSaveSettings.generated.h"

UCLASS()
class PROJECTHD_API UHDSaveSettings : public USaveGame
{
	GENERATED_BODY()

public:
	// Audio
	UPROPERTY(BlueprintReadWrite, Category = "Audio")
	float MasterVolume = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Audio")
	float MusicVolume = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Audio")
	float SFXVolume = 1.0f;

	// Key Bindings (ActionName -> Key)
	UPROPERTY(BlueprintReadWrite, Category = "Input")
	TMap<FName, FKey> KeyBindings;

	// Mouse
	UPROPERTY(BlueprintReadWrite, Category = "Input")
	float MouseSensitivity = 0.3f;

	// Brightness (UGameUserSettings에 없어서 별도 저장)
	UPROPERTY(BlueprintReadWrite, Category = "Video")
	float Brightness = 50.0f;
};
