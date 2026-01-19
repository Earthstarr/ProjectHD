// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile/HDProjectile.h"
#include "Grenade.generated.h"

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
	
	
protected:
	UFUNCTION(BlueprintCallable, Category = "Combat")
	void Explode();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float Damage = 100.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float ExplosionRadius = 1200.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float TimeToExplode = 2.5f;
	
	// 소음 범위
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float NoiseLoud = 1.0f;
	
	// 이펙트
	UPROPERTY(EditDefaultsOnly, Category = "Effects")
	UNiagaraSystem* ExplosionEffect;

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
	USoundBase* ExplosionSound;
	
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
	
	FVector ExplosionLocation;
	void ReportDelayedNoise();	// 소음 이벤트
	
private:
	FTimerHandle ExplosionTimerHandle;
	FTimerHandle NoiseTimerHandle;
	
};
