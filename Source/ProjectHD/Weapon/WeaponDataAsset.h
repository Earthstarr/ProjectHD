// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WeaponDataAsset.generated.h"

class USkeletalMesh;
class UGameplayAbility;
class UNiagaraSystem;
class USoundBase;

/**
 * 
 */
UCLASS()
class PROJECTHD_API UWeaponDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
    // --- 비주얼 및 에셋 ---
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Visual")
    USkeletalMesh* WeaponMesh; // 무기 외형 메시

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Visual")
    UNiagaraSystem* MuzzleFlashFX; // 총구 화염

    // --- GAS 관련 ---
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS")
    TSubclassOf<UGameplayAbility> FireAbility; // 사격 어빌리티

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS")
    TSubclassOf<UGameplayAbility> ReloadAbility; // 리로드 어빌리티

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS")
    TSubclassOf<class UGameplayAbility> AimAbility; // 무기별 조준 어빌리티
    
    // --- 무기 스펙 ---
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
    float FireRate; // 연사 속도

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
    float RecoilPitch; // 위아래 반동 수치

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
    float RecoilYaw; // 좌우 반동 수치

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
    int32 MaxAmmoInMag; // 탄창 당 최대 총알 수

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
    int32 MaxMag; // 최대 탄창 수

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
    float AimFOV; // 이 무기를 조준했을 때의 시야각

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
    float AimWalkSpeed; // 조준 시 이동 속도

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
    TSubclassOf<class AHDProjectile> ProjectileClass; // 탄환 종류
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float SoundRadius = 1500.0f; // 무기 소음 반경
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ammo")
	int32 AmmoSuppliedPerBox = 2; // 보급시 보충되는 탄창 수
	
	// --- ABP ---
	UPROPERTY(EditAnywhere, Category = "Animation")
	TSubclassOf<UAnimInstance> WeaponAnimLayer; // 해당 무기 전용 레이어 ABP 클래스

	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimMontage* ReloadMontage; // 무기별 장전 몽타주
	
	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimMontage* FireMontage;
	
	// 총기 트랜스폼 조정
	UPROPERTY(EditAnywhere, Category = "Grip Correction")
	FVector GripLocationOffset; // 손잡이 위치 보정값

	UPROPERTY(EditAnywhere, Category = "Grip Correction")
	FRotator GripRotationOffset; // 총구 방향 보정값

    // --- 사운드 ---
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sound")
    USoundBase* FireSound; // 사격 소리
    
};
