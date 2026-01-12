// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LegacyCameraShake.h"
#include "Camera/CameraShakeBase.h"
#include "CameraShake_Fire.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTHD_API UCameraShake_Fire : public ULegacyCameraShake
{
	GENERATED_BODY()

public:
    UCameraShake_Fire();

protected:
   
    UPROPERTY(EditDefaultsOnly, Category = "Shake")
    float ShakeDuration = 0.15f;

    UPROPERTY(EditDefaultsOnly, Category = "Shake")
    float ShakeFrequency = 25.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Shake")
    float LocShakeIntensityX;

    UPROPERTY(EditDefaultsOnly, Category = "Shake")
    float LocShakeIntensityY;

    UPROPERTY(EditDefaultsOnly, Category = "Shake")
    float LocShakeIntensityZ;

    UPROPERTY(EditDefaultsOnly, Category = "Shake")
    float RotShakeIntensityPitch = 1.5f;

    UPROPERTY(EditDefaultsOnly, Category = "Shake")
    float RotShakeIntensityYaw = 0.8f;

    UPROPERTY(EditDefaultsOnly, Category = "Shake")
    float RotShakeIntensityRoll = 1.0f;
};
