#include "HDGrenadeProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"

AHDGrenadeProjectile::AHDGrenadeProjectile()
{
    ProjectileMovement->InitialSpeed = 3000.f;
    ProjectileMovement->MaxSpeed = 3000.f;
    ProjectileMovement->ProjectileGravityScale = 1.0f;

    DamageAmount = 200.f;
    ExplosionRadius = 450.f;
}

void AHDGrenadeProjectile::BeginPlay()
{
    Super::BeginPlay();

    if (TrailEffect)
    {
        UNiagaraFunctionLibrary::SpawnSystemAttached(
            TrailEffect, GetRootComponent(), NAME_None,
            FVector::ZeroVector, FRotator::ZeroRotator,
            EAttachLocation::SnapToTarget, true
        );
    }
}

void AHDGrenadeProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    Explode(Hit.ImpactPoint, Hit.ImpactNormal);
}

void AHDGrenadeProjectile::Explode(FVector Location, FVector ImpactNormal)
{
    FVector ExplosionOrigin = Location + (ImpactNormal * 20.0f);

    // 범위 데미지
    UGameplayStatics::ApplyRadialDamageWithFalloff(
        this, DamageAmount, 10.f, ExplosionOrigin,
        ExplosionRadius * 0.5f, ExplosionRadius, 1.f,
        UDamageType::StaticClass(), TArray<AActor*>(),
        this, GetInstigatorController(), ECC_Visibility
    );

    // 카메라 쉐이크
    if (ExplosionShakeClass)
    {
        UGameplayStatics::PlayWorldCameraShake(GetWorld(), ExplosionShakeClass, ExplosionOrigin, 0.f, ExplosionRadius * 2.f);
    }

    // 이펙트
    if (ImpactEffect)
    {
        UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ImpactEffect, ExplosionOrigin, ImpactNormal.Rotation());
    }

    // 사운드
    if (ImpactSound)
    {
        UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, ExplosionOrigin);
    }

    Destroy();
}
