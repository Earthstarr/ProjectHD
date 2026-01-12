
#include "Grenade.h"

#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"

AGrenade::AGrenade()
{
	// 수류탄에 맞게 물리 설정 변경
	ProjectileMovement->InitialSpeed = 2000.f;  // 투척 속도
	ProjectileMovement->MaxSpeed = 2000.f;
	ProjectileMovement->bShouldBounce = true;   // 튕기기 활성화
	ProjectileMovement->Bounciness = 0.3f;      // 탄성
	ProjectileMovement->ProjectileGravityScale = 1.0f; // 중력 적용
    
	ProjectileMovement->bRotationFollowsVelocity = false; // 수류탄은 날아가면서 회전해야 하므로 false
	
	// 마찰력 설정
	ProjectileMovement->bIsHomingProjectile = false;
	ProjectileMovement->Friction = 0.3f; // 기본값보다 높게 설정 (0.0 ~ 10.0+)
    
	// 튕길 때 속도 감소
	ProjectileMovement->Bounciness = 0.3f; // 너무 높으면 계속 튀고, 낮으면 바로 멈춤
    
	// 미끄러짐 방지
	ProjectileMovement->bBounceAngleAffectsFriction = true;
}

void AGrenade::BeginPlay()
{
	Super::BeginPlay();
    
	// 3초 뒤 폭발 타이머
	GetWorldTimerManager().SetTimer(ExplosionTimerHandle, this, &AGrenade::Explode, 3.0f, false);
}

void AGrenade::Explode()
{
	// 범위 데미지
	UGameplayStatics::ApplyRadialDamage(
		this, Damage, (GetActorLocation() + FVector(0.f, 0.f, 50.f)) , ExplosionRadius, 
		UDamageType::StaticClass(), TArray<AActor*>(), this, GetInstigatorController()
	);

	// 폭발 이펙트 및 사운드
	if (ExplosionEffect)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ExplosionEffect, GetActorLocation());
	}

	if (ExplosionSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ExplosionSound, GetActorLocation());
	}

	Destroy();
}

void AGrenade::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if (ImpactSound && NormalImpulse.Size() > 100.f)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation());
	}
}
