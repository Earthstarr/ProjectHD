#pragma once

#include "CoreMinimal.h"
#include "HDProjectile.h"
#include "HDRailgunProjectile.generated.h"

class UNiagaraComponent;

UCLASS()
class PROJECTHD_API AHDRailgunProjectile : public AHDProjectile
{
    GENERATED_BODY()

public:
    AHDRailgunProjectile();

protected:
    virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;

    // 이미 데미지를 준 액터 목록 (중복 데미지 방지)
    UPROPERTY()
    TArray<AActor*> HitActors;

    // 트레일 이펙트
    UPROPERTY(EditDefaultsOnly, Category = "Effects")
    class UNiagaraSystem* TrailEffect;

    virtual void BeginPlay() override;
};
