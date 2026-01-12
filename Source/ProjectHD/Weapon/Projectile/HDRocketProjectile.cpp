#include "HDRocketProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"

AHDRocketProjectile::AHDRocketProjectile()
{
    // 1. 느린 비행 속도 설정 (예: 4000)
    ProjectileMovement->InitialSpeed = 4000.f;
    ProjectileMovement->MaxSpeed = 4000.f;

    // 2. 직선 비행을 위해 중력 영향 제거 (중력을 넣고 싶으면 0.1 정도로 설정)
    ProjectileMovement->ProjectileGravityScale = 0.1f;
}

void AHDRocketProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    // 부모의 OnHit을 호출하지 않고(단일 데미지 방지), 여기서 바로 폭발 로직 수행
    /*
    FVector ExplosionLocation = Hit.ImpactPoint;

    // 1. 범위 대미지 적용 (Radial Damage)
    UGameplayStatics::ApplyRadialDamage(
        this,
        DamageAmount,       // 기본 데미지
        ExplosionLocation,
        ExplosionRadius,
        UDamageType::StaticClass(),
        TArray<AActor*>(),  // 무시할 액터들
        this,
        GetInstigatorController(),
        true                // 가시성 체크 여부
    );
    */

    FVector ExplosionOrigin = Hit.ImpactPoint + (Hit.ImpactNormal * 20.0f);

    UGameplayStatics::ApplyRadialDamageWithFalloff(
        this, DamageAmount, 10.f, ExplosionOrigin,
        ExplosionRadius * 0.5f, ExplosionRadius, 1.f,
        UDamageType::StaticClass(), TArray<AActor*>(),
        this, GetInstigatorController(), ECC_Visibility
    );

    // 2. 카메라 흔들림 효과
    if (ExplosionShakeClass)
    {
        UGameplayStatics::PlayWorldCameraShake(GetWorld(), ExplosionShakeClass, ExplosionOrigin, 0.f, ExplosionRadius * 2.f);
    }

    // 3. 이펙트 및 사운드 재생 (AHDProjectile에 정의된 변수 재사용)
    if (ImpactEffect)
    {
        UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ImpactEffect, ExplosionOrigin, Hit.ImpactNormal.Rotation());
    }

    if (ImpactSound)
    {
        UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, ExplosionOrigin);
    }

    // 4. 즉시 제거
    Destroy();
}