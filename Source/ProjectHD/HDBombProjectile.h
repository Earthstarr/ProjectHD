#pragma once

#include "CoreMinimal.h"
#include "HDProjectile.h" // 부모 클래스 헤더 포함 필수
#include "HDBombProjectile.generated.h"

UCLASS()
class PROJECTHD_API AHDBombProjectile : public AHDProjectile // 부모 상속
{
    GENERATED_BODY()

public:
    AHDBombProjectile();

protected:
    // 부모의 OnHit을 덮어쓰기 위해 가상 함수(virtual)로 선언
    virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;

    UPROPERTY(EditAnywhere, Category = "Explosion")
    float ExplosionRadius = 800.f;

    UPROPERTY(EditAnywhere, Category = "Explosion")
    TSubclassOf<class UCameraShakeBase> ExplosionShakeClass;

    // 땅에 부딪힐때 이펙트와 사운드
    UPROPERTY(EditDefaultsOnly, Category = "Effects")
    UNiagaraSystem* LandImpactEffect;

    UPROPERTY(EditDefaultsOnly, Category = "Effects")
    USoundBase* LandImpactSound;

    void Explode();

    // 지연 시간 설정 (0.5초)
    UPROPERTY(EditAnywhere, Category = "Combat")
    float ExplosionDelay = 0.5f;

    FTimerHandle ExplosionTimer;

    // 부딪힌 정보를 Explode 함수에서도 쓰기 위해 저장할 변수
    FHitResult SavedHit;
};