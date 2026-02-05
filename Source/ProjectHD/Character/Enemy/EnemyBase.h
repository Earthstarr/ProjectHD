// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
#include "EnemyBase.generated.h"

UCLASS()
class PROJECTHD_API AEnemyBase : public ACharacter, public IGenericTeamAgentInterface
{
    GENERATED_BODY()

    // 팀 설정 (적 = TeamId 1)
    FGenericTeamId TeamId = FGenericTeamId(1);

    virtual FGenericTeamId GetGenericTeamId() const override { return TeamId; }

public:
    AEnemyBase();
    
    virtual void Tick(float DeltaTime) override;
    virtual void BeginPlay() override;
    
protected:
    // 체력 시스템
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
    float MaxHealth = 50.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
    float NoiseLoud = 0.5f;

    // 처치 시 획득 점수
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
    int32 KillScoreValue = 10;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stat")
    float CurrentHealth;
    
    // 내비 인보커
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Navigation")
    class UNavigationInvokerComponent* NavInvoker;
    
    // 애니메이션
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
    class UAnimMontage* DeathMontage;

    // 대미지 처리
    virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

    // 사망 처리
    virtual void Die();
    
    // 틱 끄기
    virtual void DisableMeshTick();    
    
    FTimerHandle DisableTickTimerHandle;
    FTimerHandle LandedCheckTimerHandle;
    
    UPROPERTY(BlueprintReadOnly, Category = "AISense")
    FVector LastAttackerLocation;
    
    float ReturnToPoolTime = 15.0f;
    
    // 거리 기반 틱 최적화
    UPROPERTY()
    APawn* CachedPlayer;

    float TickDistanceCheckInterval = 1.0f;  // 거리 체크 주기
    float LastDistanceCheckTime = 0.0f;

    void UpdateTickRate();
            
public:
    UPROPERTY(BlueprintReadOnly, Category = "Stat")
    bool bIsDead = false;
    
    // 미션지점의 적들은 Idle 상태로 대기하기 위한 bool 값
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
    bool bIsIdle = false;
    
    // 스폰될 때 플레이어 근처로 이동하기 위한 좌표
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FVector TargetPatrolLocation;
    
    // 미션지점 스폰적 구분을 위한 bool 값 (플레이어와 거리가 멀어져도 사라지지 않음)
    bool bIsMissionSpawned = false;
    
    // 오브젝트 풀링
    UPROPERTY()
    class AEnemyPoolManager* PoolManager;
    
    FTimerHandle PoolReturnTimerHandle;
    
    void ReturnToPool();
    virtual void InitEnemy();
    void SetPoolManager(class AEnemyPoolManager* InManager) { PoolManager = InManager; }
    
    void CheckIfLanded();
    
    virtual void ForceDespawn();
    
    FORCEINLINE bool IsDead() const { return bIsDead; }
   
    
};
