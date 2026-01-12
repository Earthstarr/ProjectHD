#include "HDBombProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/AudioComponent.h"

AHDBombProjectile::AHDBombProjectile()
{    
    ProjectileMovement->InitialSpeed = 10000.f;
    ProjectileMovement->MaxSpeed = 10000.f;
    ProjectileMovement->ProjectileGravityScale = 1.0f;

    FallingAudioComp = CreateDefaultSubobject<UAudioComponent>(TEXT("FallingAudio"));
    FallingAudioComp->SetupAttachment(RootComponent);
    FallingAudioComp->bAutoActivate = false; // 스폰 시 바로 재생되지 않게 설정
}

void AHDBombProjectile::BeginPlay()
{
    Super::BeginPlay();
    if (FallingSound)
    {
        FallingAudioComp->SetSound(FallingSound);
        FallingAudioComp->Play();
    }
}

void AHDBombProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    // 이미 충돌해서 타이머가 돌고 있다면 무시
    if (GetWorldTimerManager().IsTimerActive(ExplosionTimer)) return;

    if (FallingAudioComp && FallingAudioComp->IsPlaying())
    {
        FallingAudioComp->Stop(); // 땅에 닿으면 낙하음 중지
    }

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

    // 카메라 흔들림
    if (ExplosionShakeClass)
    {
        // PlayWorldCameraShake를 사용하면 폭발 위치에 따라 플레이어와의 거리를 계산해 
        // 멀리 있으면 적게 흔들리고, 가까이 있으면 세게 흔들리는 효과
        UGameplayStatics::PlayWorldCameraShake(
            GetWorld(),
            ExplosionShakeClass,
            ExplosionOrigin,      // 폭발 중심지
            ShakeInnerRadius,     // 100% 강도로 흔들리는 거리
            ShakeOuterRadius,     // 흔들림이 완전히 사라지는 거리
            1.0f                  // 전체적인 강도 배수
        );
    }

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
