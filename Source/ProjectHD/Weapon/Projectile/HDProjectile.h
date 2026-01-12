#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HDProjectile.generated.h"

// 클래스 전방 선언 (컴파일 속도 향상)
class USphereComponent;
class UProjectileMovementComponent;
class UStaticMeshComponent;
class UParticleSystem;
class UNiagaraSystem;

UCLASS()
class PROJECTHD_API AHDProjectile : public AActor
{
	GENERATED_BODY()

public:
	AHDProjectile();

protected:
	virtual void BeginPlay() override;

	// 충돌체
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
	USphereComponent* CollisionComp;

	// 발사체 움직임 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	UProjectileMovementComponent* ProjectileMovement;

	// 총알 외형
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float DamageAmount = 20.f;

	// 부딪혔을 때 터질 이펙트 에셋
	UPROPERTY(EditDefaultsOnly, Category = "Effects")
	UNiagaraSystem* ImpactEffect;

	// 사운드
	UPROPERTY(EditDefaultsOnly, Category = "Effects")
	class USoundBase* ImpactSound;

	// 사운드 감쇠
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	class USoundAttenuation* HitAttenuation;

public:
	// 충돌 시 호출될 함수
	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	// Getter 함수 (외부에서 속도 조절 등을 할 때 필요)
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};