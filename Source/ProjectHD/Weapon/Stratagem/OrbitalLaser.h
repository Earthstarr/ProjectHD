#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OrbitalLaser.generated.h"

UCLASS()
class PROJECTHD_API AOrbitalLaser : public AActor
{
    GENERATED_BODY()
    
public:    
    AOrbitalLaser();

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void Tick(float DeltaTime) override;

    // --- 컴포넌트 ---
    UPROPERTY(VisibleAnywhere, Category = "Laser")
    class UNiagaraComponent* LaserFX; // 하늘에서 내려오는 레이저 본체
    
    UPROPERTY(VisibleAnywhere, Category = "Laser")
    class UNiagaraComponent* ImpactFX; // 지면 이펙트

    // --- 설정 ---
    UPROPERTY(EditAnywhere, Category = "Laser|Settings")
    float SearchRadius = 4500.f;      // 적 탐지 범위

    UPROPERTY(EditAnywhere, Category = "Laser|Settings")
    float MoveSpeed = 1000.f;          // 레이저 이동 속도

    UPROPERTY(EditAnywhere, Category = "Laser|Settings")
    float DamagePerSecond = 300.f;    // 초당 데미지

    UPROPERTY(EditAnywhere, Category = "Laser|Settings")
    float Duration = 31.8f;           // 레이저 지속 시간

    UPROPERTY(EditAnywhere, Category = "Laser|Visual")
    class UMaterialInterface* BurnDecal; // 지면이 타는 데칼 머티리얼

    UPROPERTY(EditAnywhere, Category = "Laser|Sound")
    class USoundBase* LaserLoopSound; // 레이저 작동 지속음

private:
    UPROPERTY()
    AActor* CurrentTarget;            // 현재 추격 중인 적

    FVector CurrentImpactPoint;       // 레이저가 지면에 닿는 현재 좌표
    
    UPROPERTY()
    class UAudioComponent* AudioComp;

    void FindNewTarget();             // 가장 가까운 적 찾기
    void UpdateLaserVisuals();        // 나이아가라 파티클 위치 갱신
    void ApplyLaserDamage();          // 범위 데미지 적용
    
    bool bIsLaserActive = false; // 레이저 활성화 여부
    void ActivateLaser();        // 1초 뒤 호출될 함수
    
    float delaytime = 1.2f;
    
    // 데미지 주기용 타이머 핸들
    FTimerHandle DamageTimerHandle;

    // 타겟 탐색 주기용 타이머 핸들 (탐색 렉 방지)
    FTimerHandle SearchTimerHandle;
    
    // 지면 체크 타이머 핸들
    FTimerHandle GroundCheckTimerHandle;

    // 타이머에 의해 호출될 데미지 함수
    void OnDamageTick();
    
    // 지면 높이 체크 함수
    void CheckGroundHeight();

    // FName 캐싱 (문자열 생성 렉 방지)
    const FName BeamStartName = FName("User_BeamStart");
    const FName BeamEndName = FName("User_BeamEnd");
    
    // 벡터 캐싱
    FVector CachedBeamEndOffset;
    
    // 히트 결과 재사용
    TArray<FHitResult> CachedHitResults;
};