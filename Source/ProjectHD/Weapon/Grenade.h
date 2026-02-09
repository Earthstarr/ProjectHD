// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile/HDProjectile.h"
#include "Components/BoxComponent.h"
#include "Grenade.generated.h"

class UNiagaraComponent;

/**
 * 
 */
UCLASS()
class PROJECTHD_API AGrenade : public AHDProjectile
{
	GENERATED_BODY()
	
public:
	AGrenade();

	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float TimeToExplode = 1.0f;

	void StartExplosionTimer(float Delay);

protected:
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void Explode();

	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;

	// 방어벽 콜리전
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ShieldWall")
	UBoxComponent* WallCollision;

	// 방어벽 비주얼 메시
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ShieldWall")
	UStaticMeshComponent* WallMesh;

	// 방어벽 크기 (Half Extent)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShieldWall")
	FVector WallExtent = FVector(15.f, 300.f, 150.f);

	// 방어벽 지속 시간
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShieldWall")
	float WallLifetime = 10.f;

	// 이펙트
	UPROPERTY(EditDefaultsOnly, Category = "ShieldWall")
	UNiagaraSystem* ShieldFX;

	UPROPERTY(EditDefaultsOnly, Category = "ShieldWall")
	USoundBase* ActivateSound;

	// 수류탄 트레일 이펙트
	UPROPERTY(EditDefaultsOnly, Category = "Effects")
	UNiagaraSystem* TrailEffect;

	UPROPERTY()
	UNiagaraComponent* TrailComp;

private:
	FTimerHandle ExplosionTimerHandle;
	
};
