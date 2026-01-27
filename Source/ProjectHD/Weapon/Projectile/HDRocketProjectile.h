#pragma once

#include "CoreMinimal.h"
#include "HDProjectile.h"
#include "HDRocketProjectile.generated.h"

class AGrenade;

UCLASS()
class PROJECTHD_API AHDRocketProjectile : public AHDProjectile
{
    GENERATED_BODY()

public:
    AHDRocketProjectile();
    
    virtual void BeginPlay() override;

protected:    
    virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;

    UPROPERTY(EditAnywhere, Category = "Explosion")
    float ExplosionRadius = 500.f; // 폭발 범위

    UPROPERTY(EditAnywhere, Category = "Effects")
    TSubclassOf<class UCameraShakeBase> ExplosionShakeClass; // 폭발 시 카메라 흔들림    
    
    UPROPERTY(EditDefaultsOnly, Category = "Rocket | Shrapnel")
    TSubclassOf<AGrenade> ShrapnelGrenadeClass; // 뿌릴 자탄(수류탄) 클래스

    UPROPERTY(EditDefaultsOnly, Category = "Rocket | Shrapnel", meta=(ClampMin = "1", UIMin = "1"))
    int32 NumShrapnelGrenades = 8; // 뿌릴 자탄 개수

    UPROPERTY(EditDefaultsOnly, Category = "Rocket | Shrapnel")
    float ShrapnelSpawnRadius = 300.f; // 자탄이 퍼지는 반경

    UPROPERTY(EditDefaultsOnly, Category = "Rocket | Shrapnel")
    float ShrapnelLaunchSpeed = 2000.f; // 자탄의 초기 발사 속도

    UPROPERTY(EditDefaultsOnly, Category = "Rocket | Shrapnel")
    float ShrapnelExplodeDelay = 0.5f; // 자탄이 스폰 후 폭발하기까지의 시간
    
    // 적 감지 반경
    UPROPERTY(EditDefaultsOnly, Category = "Rocket | Proximity")
    float ProximityRadius = 500.f;
    
    UPROPERTY(EditDefaultsOnly, Category = "Rocket | Shrapnel")
    class UNiagaraSystem* ShrapnelTrailFX;    // 자탄 트레일

    // 감지 타이머 핸들
    FTimerHandle ProximityCheckTimerHandle;
    
    // 충돌 없으면 4초 뒤 폭발
    FTimerHandle ExplosionTimerHandle;

    // 감지 로직
    void CheckProximity();

    // OnHit과 공용으로 쓸 폭발 실행 함수
    void TriggerExplosion(FVector ExplosionLocation, FVector ImpactNormal);
    
       
};