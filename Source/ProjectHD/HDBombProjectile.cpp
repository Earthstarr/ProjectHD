#include "HDBombProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

AHDBombProjectile::AHDBombProjectile()
{    
    ProjectileMovement->InitialSpeed = 10000.f;
    ProjectileMovement->MaxSpeed = 10000.f;
    ProjectileMovement->ProjectileGravityScale = 1.0f;
}

void AHDBombProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    // 이미 충돌해서 타이머가 돌고 있다면 무시
    if (GetWorldTimerManager().IsTimerActive(ExplosionTimer)) return;

    if (LandImpactEffect)
    {
        UNiagaraFunctionLibrary::SpawnSystemAtLocation(
            GetWorld(),
            LandImpactEffect,
            Hit.ImpactPoint,
            Hit.ImpactNormal.Rotation()
        );
    }
    
    if (LandImpactSound)
    {
        UGameplayStatics::PlaySoundAtLocation(this, LandImpactSound, Hit.ImpactPoint);
    }

    // 움직임 정지
    ProjectileMovement->StopMovementImmediately();
    ProjectileMovement->Deactivate();

    // 바닥에 고정
    CollisionComp->SetSimulatePhysics(false);
    CollisionComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    // 히트 결과 저장
    SavedHit = Hit;

    if (ProjectileMesh)
    {
        ProjectileMesh->SetVisibility(false);
    }

    // 0.5초 뒤에 Explode 함수 호출
    GetWorldTimerManager().SetTimer(ExplosionTimer, this, &AHDBombProjectile::Explode, ExplosionDelay, false);   
}

void AHDBombProjectile::Explode()
{
    FVector ExplosionOrigin = SavedHit.ImpactPoint + (SavedHit.ImpactNormal * 20.0f);

    UGameplayStatics::ApplyRadialDamageWithFalloff(
        this, DamageAmount, 10.f, ExplosionOrigin,
        ExplosionRadius * 0.5f, ExplosionRadius, 1.f,
        UDamageType::StaticClass(), TArray<AActor*>(),
        this, GetInstigatorController(), ECC_Visibility
    );

    if (ImpactEffect)
    {
        UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ImpactEffect, SavedHit.ImpactPoint, SavedHit.ImpactNormal.Rotation());
    }

    if (ImpactSound)
    {
        UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, SavedHit.ImpactPoint);
    }

    if (ExplosionShakeClass)
    {
        UGameplayStatics::PlayWorldCameraShake(GetWorld(), ExplosionShakeClass, SavedHit.ImpactPoint, 0.f, 2000.f);
    }

    Destroy();
}
