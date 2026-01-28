#include "HDRocketProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "ProjectHD/Weapon/Grenade.h"
#include "Engine/OverlapResult.h"

AHDRocketProjectile::AHDRocketProjectile()
{    
    PrimaryActorTick.bCanEverTick = true;

    ProjectileMovement->InitialSpeed = 6000.f;
    ProjectileMovement->MaxSpeed = 6000.f;    
    ProjectileMovement->ProjectileGravityScale = 0.03f;
    
    // 부모 변수 초기화
    DamageAmount = 50.f;
    ExplosionRadius = 450.f;
}

void AHDRocketProjectile::BeginPlay()
{
    Super::BeginPlay();

    // 0.1초마다 적 감지
    GetWorldTimerManager().SetTimer(ProximityCheckTimerHandle, this, &AHDRocketProjectile::CheckProximity, 0.1f, true, 0.3f);
    
    // 4초 뒤에 폭발
    GetWorldTimerManager().SetTimer(
        ExplosionTimerHandle, 
        FTimerDelegate::CreateUObject(this, &AHDRocketProjectile::TriggerExplosion, FVector::ZeroVector, FVector::UpVector), 
        4.0f, 
        false
    );
}

void AHDRocketProjectile::CheckProximity()
{
    FVector CurrentLoc = GetActorLocation();
    TArray<FOverlapResult> OverlapResults;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);
    Params.AddIgnoredActor(GetOwner());

    // 주변 Pawn 채널을 대상으로 범위 검사
    bool bHit = GetWorld()->OverlapMultiByChannel(
        OverlapResults,
        CurrentLoc,
        FQuat::Identity,
        ECC_Pawn,
        FCollisionShape::MakeSphere(ProximityRadius),
        Params
    );

    if (bHit)
    {
        for (const FOverlapResult& Result : OverlapResults)
        {
            AActor* OverlapActor = Result.GetActor();
            // 적 태그("Enemy") 확인
            if (OverlapActor && OverlapActor->ActorHasTag(TEXT("Enemy")))
            {
                // 적 발견 시 타이머 중지                
                GetWorldTimerManager().ClearTimer(ProximityCheckTimerHandle);
                
                // 0.2초 후에 폭발
                GetWorldTimerManager().SetTimer(
                    DelayedExplosionTimerHandle,
                    FTimerDelegate::CreateUObject(this, &AHDRocketProjectile::TriggerExplosion, CurrentLoc, FVector::UpVector),
                    0.2f,
                    false
                );
                return;
            }
        }
    }
}

void AHDRocketProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    // 벽이나 지면에 직접 닿았을 때도 폭발
    GetWorldTimerManager().ClearTimer(ProximityCheckTimerHandle);
    GetWorldTimerManager().ClearTimer(DelayedExplosionTimerHandle);
    TriggerExplosion(Hit.ImpactPoint, Hit.ImpactNormal);
}

void AHDRocketProjectile::TriggerExplosion(FVector ExplosionLocation, FVector ImpactNormal)
{
    // 타이머 클리어 (중복 방지)
    GetWorldTimerManager().ClearTimer(ProximityCheckTimerHandle);
    GetWorldTimerManager().ClearTimer(ExplosionTimerHandle);
    GetWorldTimerManager().ClearTimer(DelayedExplosionTimerHandle);
    
    // 만약 인자로 들어온 위치가 ZeroVector(자폭 타이머 호출)라면 현재 내 위치를 사용
    FVector FinalLocation = ExplosionLocation.IsZero() ? GetActorLocation() : ExplosionLocation;
    
    FVector ExplosionOrigin = FinalLocation + (ImpactNormal * 20.0f);

    // 메인 로켓 범위 대미지
    UGameplayStatics::ApplyRadialDamageWithFalloff(
        this, DamageAmount, 10.f, ExplosionOrigin,
        ExplosionRadius * 0.5f, ExplosionRadius, 1.f,
        UDamageType::StaticClass(), TArray<AActor*>(),
        this, GetInstigatorController(), ECC_Visibility
    );

    // 카메라 흔들림
    if (ExplosionShakeClass)
    {
        UGameplayStatics::PlayWorldCameraShake(GetWorld(), ExplosionShakeClass, ExplosionOrigin, 0.f, ExplosionRadius * 2.f);
    }

    // 이펙트
    if (ImpactEffect)
    {
        UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ImpactEffect, ExplosionOrigin, ImpactNormal.Rotation());
    }
    if (ImpactSound)
    {
        UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, ExplosionOrigin);
    }
    
    // 자탄(수류탄) 스폰
    if (ShrapnelGrenadeClass)
    {
        for (int32 i = 0; i < NumShrapnelGrenades; ++i)
        {
            FVector RandomDir = FMath::VRand();
            // 지면으로 바로 박히지 않게 위쪽 방향으로 가중치 부여
            if (RandomDir.Z < 0.f) RandomDir.Z *= -0.3f; 

            FVector ShrapnelSpawnLocation = ExplosionOrigin + (RandomDir * ShrapnelSpawnRadius);
            
            FActorSpawnParameters SpawnParams;
            SpawnParams.Owner = GetOwner();
            SpawnParams.Instigator = GetInstigator();
            SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

            AGrenade* Shrapnel = GetWorld()->SpawnActor<AGrenade>(ShrapnelGrenadeClass, ShrapnelSpawnLocation, RandomDir.Rotation(), SpawnParams);
            
            if (Shrapnel)
            {
                // 자탄 트레일
                UNiagaraComponent* TrailComp = UNiagaraFunctionLibrary::SpawnSystemAttached(
                ShrapnelTrailFX, 
                Shrapnel->GetRootComponent(), 
                NAME_None, 
                FVector::ZeroVector, 
                FRotator::ZeroRotator, 
                EAttachLocation::SnapToTarget, 
                true
                );
                
                // 랜덤 폭발 지연
                float RandomDelay = FMath::FRandRange(ShrapnelExplodeDelay * 0.5f, ShrapnelExplodeDelay * 2.0f);
                Shrapnel->TimeToExplode = RandomDelay;
                Shrapnel->StartExplosionTimer(RandomDelay);
                Shrapnel->ProjectileMovement->ProjectileGravityScale = 5.0f;    // 중력 무겁게

                if (Shrapnel->ProjectileMovement)
                {
                    // 관성: 랜덤 비사 방향 속도 + 로켓이 날아가던 방향의 30% 속도 유지
                    Shrapnel->ProjectileMovement->Velocity = (RandomDir * ShrapnelLaunchSpeed) + (GetVelocity() * 0.3f);
                }
            }
        }
    }
    
    Destroy();
}