#include "HDRailgunProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "ProjectHD/Character/Player/FPSCharacter.h"

AHDRailgunProjectile::AHDRailgunProjectile()
{
    // 높은 속도 (관통탄)
    ProjectileMovement->InitialSpeed = 50000.f;
    ProjectileMovement->MaxSpeed = 50000.f;
    ProjectileMovement->ProjectileGravityScale = 0.f;

    DamageAmount = 2000.f;

    InitialLifeSpan = 3.0f;
}

void AHDRailgunProjectile::BeginPlay()
{
    Super::BeginPlay();

    // 트레일 이펙트 부착
    if (TrailEffect)
    {
        UNiagaraFunctionLibrary::SpawnSystemAttached(
            TrailEffect,
            GetRootComponent(),
            NAME_None,
            FVector::ZeroVector,
            FRotator::ZeroRotator,
            EAttachLocation::SnapToTarget,
            true
        );
    }
}

void AHDRailgunProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (!OtherActor || OtherActor == this || !OtherComp) return;

    // 적(Enemy 태그)에 맞은 경우: 데미지만 주고 관통
    if (OtherActor->ActorHasTag(FName("Enemy")))
    {
        // 중복 데미지 방지
        if (HitActors.Contains(OtherActor)) return;
        HitActors.Add(OtherActor);

        float DamageDealt = UGameplayStatics::ApplyDamage(
            OtherActor,
            DamageAmount,
            GetInstigatorController(),
            GetOwner(),
            UDamageType::StaticClass()
        );

        if (DamageDealt > 0.f)
        {
            AFPSCharacter* Player = Cast<AFPSCharacter>(GetOwner());
            if (Player)
            {
                Player->OnHitEnemy.Broadcast(false);
            }
        }

        // 히트 이펙트 (관통하면서도 이펙트는 표시)
        if (ImpactEffect)
        {
            UNiagaraFunctionLibrary::SpawnSystemAtLocation(
                GetWorld(),
                ImpactEffect,
                Hit.ImpactPoint,
                Hit.ImpactNormal.Rotation()
            );
        }

        if (ImpactSound)
        {
            UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, Hit.ImpactPoint, 1.f, 1.f, 0.f, HitAttenuation);
        }

        // Destroy하지 않음 - 관통!
        return;
    }

    // 적이 아닌 대상(벽, 바닥 등)에 맞으면 기본 동작 (이펙트 + 파괴)
    Super::OnHit(HitComp, OtherActor, OtherComp, NormalImpulse, Hit);
}
