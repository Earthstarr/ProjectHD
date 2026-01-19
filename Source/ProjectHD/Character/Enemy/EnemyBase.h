// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyBase.generated.h"

UCLASS()
class PROJECTHD_API AEnemyBase : public ACharacter
{
    GENERATED_BODY()

public:
    AEnemyBase();

protected:
    // 체력 시스템
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
    float MaxHealth = 50.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
    float NoiseLoud = 0.8f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stat")
    float CurrentHealth;

    // 대미지 처리 (언리얼 표준 함수 오버라이드)
    virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

    // 사망 처리
    virtual void Die();

    UPROPERTY(BlueprintReadOnly, Category = "Stat")
    bool bIsDead = false;
    
    UPROPERTY(BlueprintReadOnly, Category = "AISense")
    FVector LastAttackerLocation;
};
