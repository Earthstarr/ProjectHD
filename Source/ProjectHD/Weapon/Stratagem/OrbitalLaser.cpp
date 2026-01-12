#include "OrbitalLaser.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"

AOrbitalLaser::AOrbitalLaser()
{
    PrimaryActorTick.bCanEverTick = true;

    // 루트 설정
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

    // 레이저 나이아가라 컴포넌트
    LaserFX = CreateDefaultSubobject<UNiagaraComponent>(TEXT("LaserFX"));
    LaserFX->SetupAttachment(RootComponent);
}

void AOrbitalLaser::BeginPlay()
{
    Super::BeginPlay();

    CurrentImpactPoint = GetActorLocation();
    SetLifeSpan(Duration); // 설정된 시간 후 자동 파괴

    if (LaserLoopSound)
    {
        AudioComp = UGameplayStatics::SpawnSoundAtLocation(this, LaserLoopSound, GetActorLocation());
    }
}

void AOrbitalLaser::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // 타겟이 죽었거나 없으면 새 타겟 찾기
    if (!CurrentTarget || !IsValid(CurrentTarget))
    {
        FindNewTarget();
    }

    // 레이저 이동 목표 지점 설정 (타겟이 없으면 제자리 대기)
    FVector TargetLocation = CurrentTarget ? CurrentTarget->GetActorLocation() : GetActorLocation();
    
    // 추적
    CurrentImpactPoint = FMath::VInterpTo(CurrentImpactPoint, TargetLocation, DeltaTime, MoveSpeed / 100.f);

    // 지면 높이 보정 (고저차 대응)
    FHitResult GroundHit;
    FVector TraceStart = CurrentImpactPoint + FVector(0, 0, 2000);
    FVector TraceEnd = CurrentImpactPoint + FVector(0, 0, -2000);
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);

    if (GetWorld()->LineTraceSingleByChannel(GroundHit, TraceStart, TraceEnd, ECC_Visibility, Params))
    {
        CurrentImpactPoint.Z = GroundHit.ImpactPoint.Z;
    }

    // 나이아가라
    UpdateLaserVisuals();

    // 데미지 적용
    ApplyLaserDamage(DeltaTime);

    // 지면 연소 효과 (데칼 생성)
    if (BurnDecal)
    {
        UGameplayStatics::SpawnDecalAtLocation(GetWorld(), BurnDecal, FVector(100, 100, 100), 
            CurrentImpactPoint, FRotator(-90, 0, 0), 2.0f);
    }

    // 사운드
    if (AudioComp) AudioComp->SetWorldLocation(CurrentImpactPoint);
}

void AOrbitalLaser::FindNewTarget()
{
    TArray<FHitResult> OutHits;
    FCollisionShape Sphere = FCollisionShape::MakeSphere(SearchRadius);
    
    // 주변 적 탐색
    bool bHit = GetWorld()->SweepMultiByChannel(OutHits, CurrentImpactPoint, CurrentImpactPoint, 
        FQuat::Identity, ECC_Pawn, Sphere);

    AActor* ClosestEnemy = nullptr;
    float MinDist = SearchRadius;

    if (bHit)
    {
        for (auto& Hit : OutHits)
        {
            AActor* PotentialTarget = Hit.GetActor();
            if (PotentialTarget && PotentialTarget->ActorHasTag(TEXT("Enemy")))
            {
                float Dist = FVector::Dist(CurrentImpactPoint, PotentialTarget->GetActorLocation());
                if (Dist < MinDist)
                {
                    MinDist = Dist;
                    ClosestEnemy = PotentialTarget;
                }
            }
        }
    }
    CurrentTarget = ClosestEnemy;
}

void AOrbitalLaser::UpdateLaserVisuals()
{
    if (LaserFX)
    {
        // 나이아가라 시스템 내부의 파라미터 이름과 일치 (User.BeamEnd)
        LaserFX->SetNiagaraVariableVec3(FString("BeamEnd"), CurrentImpactPoint);
        LaserFX->SetNiagaraVariableVec3(FString("BeamStart"), CurrentImpactPoint + FVector(0, 0, 20000)); // 하늘 위 200m
    }
}

void AOrbitalLaser::ApplyLaserDamage(float DeltaTime)
{
    // 레이저 중심 반경 2m 내 적에게 지속 데미지
    UGameplayStatics::ApplyRadialDamage(GetWorld(), DamagePerSecond * DeltaTime, CurrentImpactPoint, 200.f, 
        UDamageType::StaticClass(), TArray<AActor*>(), this, GetInstigatorController());
}