#pragma once

#include "CoreMinimal.h"
#include "HDProjectile.h"
#include "HDGrenadeProjectile.generated.h"

UCLASS()
class PROJECTHD_API AHDGrenadeProjectile : public AHDProjectile
{
    GENERATED_BODY()

public:
    AHDGrenadeProjectile();

    virtual void BeginPlay() override;

protected:
    virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;

    UPROPERTY(EditAnywhere, Category = "Explosion")
    float ExplosionRadius = 450.f;

    UPROPERTY(EditAnywhere, Category = "Effects")
    TSubclassOf<class UCameraShakeBase> ExplosionShakeClass;

    // 트레일 이펙트
    UPROPERTY(EditDefaultsOnly, Category = "Effects")
    class UNiagaraSystem* TrailEffect;

private:
    void Explode(FVector Location, FVector ImpactNormal);
};
