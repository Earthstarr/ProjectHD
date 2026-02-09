
#include "Grenade.h"

#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"

AGrenade::AGrenade()
{
	// 수류탄에 맞게 물리 설정 변경
	ProjectileMovement->InitialSpeed = 2000.f;
	ProjectileMovement->MaxSpeed = 2000.f;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 0.3f;
	ProjectileMovement->ProjectileGravityScale = 1.0f;
	ProjectileMovement->bRotationFollowsVelocity = false;
	ProjectileMovement->bIsHomingProjectile = false;
	ProjectileMovement->Friction = 0.5f;
	ProjectileMovement->bBounceAngleAffectsFriction = true;

	// 방어벽 콜리전 (초기 비활성화)
	WallCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("WallCollision"));
	WallCollision->SetupAttachment(RootComponent);
	WallCollision->SetBoxExtent(WallExtent);
	WallCollision->SetRelativeLocation(FVector(0.f, 0.f, 150.f));
	WallCollision->SetCollisionProfileName(TEXT("ShieldWall"));
	WallCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WallCollision->SetVisibility(false);

	// 방어벽 메시 (초기 비활성화, BP에서 메시 설정)
	WallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallMesh"));
	WallMesh->SetupAttachment(WallCollision);
	WallMesh->SetRelativeScale3D(FVector(0.3f, 6.f, 3.f));
	WallMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WallMesh->SetVisibility(false);
}

void AGrenade::BeginPlay()
{
	Super::BeginPlay();

	// 트레일 이펙트
	if (TrailEffect)
	{
		TrailComp = UNiagaraFunctionLibrary::SpawnSystemAttached(
			TrailEffect, CollisionComp, NAME_None,
			FVector::ZeroVector, FRotator::ZeroRotator,
			EAttachLocation::SnapToTarget, true
		);
	}

}

void AGrenade::StartExplosionTimer(float Delay)
{
	float FinalDelay = (Delay > 0.f) ? Delay : TimeToExplode;
	GetWorldTimerManager().SetTimer(ExplosionTimerHandle, this, &AGrenade::Explode, FinalDelay, false);
}

void AGrenade::Explode()
{
	// 수류탄 물리 정지
	ProjectileMovement->StopMovementImmediately();
	ProjectileMovement->SetActive(false);

	// 수류탄 메시 숨기기
	ProjectileMesh->SetHiddenInGame(true);
	CollisionComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// 트레일 이펙트 종료
	if (TrailComp)
	{
		TrailComp->Deactivate();
	}

	// 방어벽 활성화
	WallCollision->SetBoxExtent(WallExtent);
	WallCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	WallCollision->SetVisibility(true);
	WallMesh->SetVisibility(true);

	// 이펙트
	if (ShieldFX)
	{
		UNiagaraFunctionLibrary::SpawnSystemAttached(
			ShieldFX, WallCollision, NAME_None,
			FVector::ZeroVector, FRotator::ZeroRotator,
			EAttachLocation::KeepRelativeOffset, true
		);
	}

	// 사운드
	if (ActivateSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ActivateSound, GetActorLocation());
	}

	// 지속 시간 후 소멸
	SetLifeSpan(WallLifetime);
}

void AGrenade::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	Explode();
}
