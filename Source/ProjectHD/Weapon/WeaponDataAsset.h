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
    // --- ���־� �� ���� ---
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Visual")
    USkeletalMesh* WeaponMesh; // ���� ���� �޽�

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Visual")
    UNiagaraSystem* MuzzleFlashFX; // �ѱ� ȭ��

    // --- GAS ���� ---
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS")
    TSubclassOf<UGameplayAbility> FireAbility; // ��� �����Ƽ

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS")
    TSubclassOf<UGameplayAbility> ReloadAbility; // ���ε� �����Ƽ

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS")
    TSubclassOf<class UGameplayAbility> AimAbility; // ���⺰ ���� �����Ƽ
    
    // --- ���� ���� ---
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
    float FireRate; // ���� �ӵ�

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
    float RecoilPitch; // ���Ʒ� �ݵ� ��ġ

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
    float RecoilYaw; // �¿� �ݵ� ��ġ

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
    int32 MaxAmmoInMag; // źâ �� �ִ� �Ѿ� ��

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
    int32 MaxMag; // �ִ� źâ ��

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
    float AimFOV; // �� ���⸦ �������� ���� �þ߰�

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
    float AimWalkSpeed; // ���� �� �̵� �ӵ�

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
    TSubclassOf<class AHDProjectile> ProjectileClass; // źȯ ����
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float SoundRadius = 1500.0f; // ���� ���� �ݰ�
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float Loudness = 1.0f; // ���� ���� ũ��(AI Hearing)
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ammo")
	int32 AmmoSuppliedPerBox = 2; // ���޽� ����Ǵ� źâ ��
	
	// --- ABP ---
	UPROPERTY(EditAnywhere, Category = "Animation")
	TSubclassOf<UAnimInstance> WeaponAnimLayer; // �ش� ���� ���� ���̾� ABP Ŭ����

	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimMontage* ReloadMontage; // ���⺰ ���� ��Ÿ��
	
	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimMontage* FireMontage;
	
	// �ѱ� Ʈ������ ����
	UPROPERTY(EditAnywhere, Category = "Grip Correction")
	FVector GripLocationOffset; // ������ ��ġ ������

	UPROPERTY(EditAnywhere, Category = "Grip Correction")
	FRotator GripRotationOffset; // �ѱ� ���� ������

    // --- ���� ---
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sound")
    USoundBase* FireSound; // ��� �Ҹ�

	// --- 히트스캔 ---
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hitscan")
	bool bIsHitscan = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hitscan", meta = (EditCondition = "bIsHitscan"))
	float HitscanDamage = 2000.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hitscan", meta = (EditCondition = "bIsHitscan"))
	UNiagaraSystem* BeamFX = nullptr; // 빔 나이아가라 (User_BeamStart/User_BeamEnd)

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hitscan", meta = (EditCondition = "bIsHitscan"))
	UNiagaraSystem* HitscanImpactFX = nullptr; // 적 히트 이펙트

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hitscan", meta = (EditCondition = "bIsHitscan"))
	USoundBase* HitscanImpactSound = nullptr; // 적 히트 사운드
};
