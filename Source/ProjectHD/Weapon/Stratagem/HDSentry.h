#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HDSentry.generated.h"

class UNiagaraSystem;

UCLASS()
class PROJECTHD_API AHDSentry : public AActor
{
    GENERATED_BODY()

public:
    AHDSentry();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    // --- 컴포넌트 ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
    class UStaticMeshComponent* BodyMesh;      // 지면에 박히는 베이스 (Root)

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
    class UStaticMeshComponent* PillarMesh;    // 위로 올라오는 기둥

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
    class USkeletalMeshComponent* TurretMesh;    // 회전하는 머리 및 총구

    // --- 설정 ---
    UPROPERTY(EditAnywhere, Category = "Sentry|Settings")
    float DetectionRadius = 4500.f;

    UPROPERTY(EditAnywhere, Category = "Sentry|Settings")
    float RotationSpeed = 5.0f;

    UPROPERTY(EditAnywhere, Category = "Sentry|Settings")
    float FireRate = 0.12f;
    
    UPROPERTY(EditAnywhere, Category = "Sentry|Settings")
    int32 MaxAmmo = 200; // 최대 탄약 수
    
    UPROPERTY(EditAnywhere, Category = "Sentry|Settings")
    float NoiseLoud = 0.6f; // 소음 크기

    int32 CurrentAmmo;

    bool bIsRetracting = false;

    UPROPERTY(EditAnywhere, Category = "Sentry|Settings")
    TSubclassOf<class AHDProjectile> ProjectileClass;

    // --- 사운드 ---
    UPROPERTY(EditAnywhere, Category = "Sentry|Sound")
    class USoundBase* ImpactSound;      // 지면 충돌 시
    
    UPROPERTY(EditAnywhere, Category = "Sentry|Sound")
    class USoundBase* DeploySound;      // 기둥 상승 시 (BP 애니메이션 연결용)

    UPROPERTY(EditAnywhere, Category = "Sentry|Sound")
    class USoundBase* RotationSound;    // 회전 중 (루프 권장)

    UPROPERTY(EditAnywhere, Category = "Sentry|Sound")
    class USoundBase* FireSound;        // 발사 시
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sentry|Sound")
    UNiagaraSystem* MuzzleFlashFX;

    // 전개 시작 이벤트
    UFUNCTION(BlueprintImplementableEvent)
    void StartDeploySequence();
    
    // 퇴각 애니메이션
    UFUNCTION(BlueprintImplementableEvent)
    void StartRetractSequence();

    // 퇴각이 끝났을 때 호출
    UFUNCTION(BlueprintCallable)
    void OnRetractFinished();
    
    void StopFiringAndRetract();

private:
    bool bIsDeployed = false;  // 사격 가능 상태
    bool bIsDeploying = false; // 기둥 올라오는 중
    
    UPROPERTY()
    AActor* CurrentTarget = nullptr;

    FTimerHandle FireTimerHandle;

    void FindNearestEnemy();
    void RotateToTarget(float DeltaTime);
    void Fire();

    // 블루프린트 애니메이션 끝날 때 호출 (전개 완료 처리)
    UFUNCTION(BlueprintCallable)
    void OnDeployFinished();
};