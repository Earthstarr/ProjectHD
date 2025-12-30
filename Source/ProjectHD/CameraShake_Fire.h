// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LegacyCameraShake.h"
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
    // 카메라 쉐이크 지속 시간 (초)
    UPROPERTY(EditDefaultsOnly, Category = "Shake")
    float ShakeDuration = 0.15f;

    // 카메라 쉐이크 빈도 (Hz)
    UPROPERTY(EditDefaultsOnly, Category = "Shake")
    float ShakeFrequency = 25.0f;

    // X, Y, Z축 이동 강도
    UPROPERTY(EditDefaultsOnly, Category = "Shake")
    float LocShakeIntensityX;

    UPROPERTY(EditDefaultsOnly, Category = "Shake")
    float LocShakeIntensityY;

    UPROPERTY(EditDefaultsOnly, Category = "Shake")
    float LocShakeIntensityZ;

    // Pitch, Yaw, Roll 회전 강도
    UPROPERTY(EditDefaultsOnly, Category = "Shake")
    float RotShakeIntensityPitch = 1.5f;

    UPROPERTY(EditDefaultsOnly, Category = "Shake")
    float RotShakeIntensityYaw = 0.8f;

    UPROPERTY(EditDefaultsOnly, Category = "Shake")
    float RotShakeIntensityRoll = 1.0f;
};
