#pragma once

#include "CoreMinimal.h"
#include "HDProjectile.h"
#include "HDRocketProjectile.generated.h"

UCLASS()
class PROJECTHD_API AHDRocketProjectile : public AHDProjectile
{
    GENERATED_BODY()

public:
    AHDRocketProjectile();

protected:
    // 부모의 OnHit을 덮어써서 폭발 로직을 넣습니다.
    virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;

    UPROPERTY(EditAnywhere, Category = "Explosion")
    float ExplosionRadius = 500.f; // 폭발 범위

    UPROPERTY(EditAnywhere, Category = "Effects")
    TSubclassOf<class UCameraShakeBase> ExplosionShakeClass; // 폭발 시 카메라 흔들림
};