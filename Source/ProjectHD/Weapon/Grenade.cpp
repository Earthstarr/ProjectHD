
#include "Grenade.h"

#include "NiagaraFunctionLibrary.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Perception/AISense_Hearing.h"

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
	ProjectileMovement->Friction = 0.5f; // 기본값보다 높게 설정
    
	// 튕길 때 속도 감소
	ProjectileMovement->Bounciness = 0.3f; // 너무 높으면 계속 튀고, 낮으면 바로 멈춤
    
	// 미끄러짐 방지
	ProjectileMovement->bBounceAngleAffectsFriction = true;
}

void AGrenade::BeginPlay()
{
	Super::BeginPlay();
	
	FTimerHandle TempHandle;
	GetWorldTimerManager().SetTimer(TempHandle, [this]()
	{
		// 이미 외부(로켓)에서 타이머를 켰다면 중복 실행 방지
		if (!GetWorldTimerManager().IsTimerActive(ExplosionTimerHandle))
		{
			StartExplosionTimer(TimeToExplode);
		}
	}, 0.1f, false);
}

void AGrenade::StartExplosionTimer(float Delay)
{
	float FinalDelay = (Delay > 0.f) ? Delay : TimeToExplode;
	GetWorldTimerManager().SetTimer(ExplosionTimerHandle, this, &AGrenade::Explode, FinalDelay, false);
}

void AGrenade::Explode()
{
	// 터지면서 사라져 GetActorLocation 오류가 발생하므로 위치 정보 미리 저장
	ExplosionLocation = GetActorLocation() + FVector(0.f, 0.f, 50.f);
	
	/*
	// 범위 데미지	
	UGameplayStatics::ApplyRadialDamage(
		this, Damage, ExplosionLocation , ExplosionRadius, 
		UDamageType::StaticClass(), TArray<AActor*>(), this, GetInstigatorController()
	);
	*/
	
	UGameplayStatics::ApplyRadialDamageWithFalloff(
	this, Damage, Damage * 0.5f, ExplosionLocation,
	ExplosionRadius * 0.8f, ExplosionRadius, 1.f,
	UDamageType::StaticClass(), TArray<AActor*>(),
	this, GetInstigatorController(), ECC_WorldDynamic // 채널 변경 시도
);
	
	// 타이머 안쓰면 EnemyBase의 TakeDamage의 Help 신호와 겹쳐서 오류남
	// 폭발 소음은 0.1초 뒤에 발생
	GetWorldTimerManager().SetTimer(
		NoiseTimerHandle,
		this,
		&AGrenade::ReportDelayedNoise,
		0.1f, 
		false
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
	
	// 타이머를 돌리기 위해 Destroy 지연
	ProjectileMesh->SetHiddenInGame(true);
	ProjectileMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SetLifeSpan(1.0f);
}

void AGrenade::ReportDelayedNoise()
{
	UAISense_Hearing::ReportNoiseEvent(
		GetWorld(), 
		ExplosionLocation,
		NoiseLoud,
		this,
		0.0f,
		FName(TEXT("Noise"))
	);
}

void AGrenade::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if (ImpactSound && NormalImpulse.Size() > 100.f)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation());
	}
}
