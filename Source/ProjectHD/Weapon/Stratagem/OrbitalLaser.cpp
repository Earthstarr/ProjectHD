#include "OrbitalLaser.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"
#include "ProjectHD/Character/Enemy/EnemyBase.h"

AOrbitalLaser::AOrbitalLaser()
{
    PrimaryActorTick.bCanEverTick = true;

    // 루트 설정
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

    // 레이저 나이아가라 컴포넌트
    LaserFX = CreateDefaultSubobject<UNiagaraComponent>(TEXT("LaserFX"));
    LaserFX->SetupAttachment(RootComponent);
    
    // 지면 이펙트
    ImpactFX = CreateDefaultSubobject<UNiagaraComponent>(TEXT("ImpactFX"));
    ImpactFX->SetupAttachment(RootComponent);
}

void AOrbitalLaser::BeginPlay()
{
    Super::BeginPlay();

    CurrentImpactPoint = GetActorLocation();
    SetLifeSpan(Duration + delaytime);
    
    if (LaserFX) LaserFX->Deactivate();
    if (ImpactFX) ImpactFX->Deactivate();

    if (LaserLoopSound)
    {
        AudioComp = UGameplayStatics::SpawnSoundAtLocation(this, LaserLoopSound, GetActorLocation());
    }
    
    // delaytime 뒤에 시작
    FTimerHandle TimerHandle;
    GetWorldTimerManager().SetTimer(TimerHandle, this, &AOrbitalLaser::ActivateLaser, delaytime, false);
}

void AOrbitalLaser::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (!bIsLaserActive) return;

    // 이동
    FVector TargetLocation = CurrentTarget ? CurrentTarget->GetActorLocation() : GetActorLocation();
    FVector Direction = TargetLocation - CurrentImpactPoint;
    float DistanceToTarget = Direction.Size();

    if (DistanceToTarget > 5.0f)
    {
        Direction.Normalize();
        CurrentImpactPoint += Direction * MoveSpeed * DeltaTime;
    }

    // 높이 보정 (LineTrace)
    FHitResult GroundHit;
    if (GetWorld()->LineTraceSingleByChannel(GroundHit, CurrentImpactPoint + FVector(0,0,2000), CurrentImpactPoint + FVector(0,0,-2000), ECC_Visibility))
    {
        CurrentImpactPoint.Z = GroundHit.ImpactPoint.Z;
    }

    // 비주얼 갱신 (캐싱된 FName 사용)
    if (LaserFX)
    {
        LaserFX->SetVariableVec3(BeamStartName, CurrentImpactPoint + FVector(0, -10, -20));
        LaserFX->SetVariableVec3(BeamEndName, CurrentImpactPoint + FVector(0, -20000, 100000));
    }
    if (ImpactFX) ImpactFX->SetWorldLocation(CurrentImpactPoint + FVector(0, 0, 20.f));
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
            AEnemyBase* PotentialTarget = Cast<AEnemyBase>(Hit.GetActor());
            
            if (PotentialTarget && PotentialTarget->ActorHasTag(TEXT("Enemy")) && !PotentialTarget->bIsDead)
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
        LaserFX->SetVariableVec3(FName("User_BeamStart"), CurrentImpactPoint + FVector(0, -10, -20));
        LaserFX->SetVariableVec3(FName("User_BeamEnd"), CurrentImpactPoint + FVector(-0, -20000, 100000)); // 대각선 하늘 위
    }
    
    if (ImpactFX)
    {        
        FVector VisualLocation = CurrentImpactPoint + FVector(0, 0, 20.f);
        ImpactFX->SetWorldLocation(VisualLocation);
    }
}

void AOrbitalLaser::ApplyLaserDamage(float DeltaTime)
{
    TArray<FHitResult> HitResults;
    FVector StartLocation = CurrentImpactPoint;
    FVector EndLocation = CurrentImpactPoint; // 시작과 끝을 같게 하면 구체 판정
    
    // 데미지 반경 설정
    float DamageRadius = 250.f;
    FCollisionShape SphereShape = FCollisionShape::MakeSphere(DamageRadius);
    
    // 디버그용 구체 
    //DrawDebugSphere(GetWorld(), CurrentImpactPoint, DamageRadius, 12, FColor::Yellow, false, 0.1f);

    // 구체 범위 내의 모든 적 검출
    bool bHit = GetWorld()->SweepMultiByChannel(
        HitResults, 
        StartLocation, 
        EndLocation, 
        FQuat::Identity, 
        ECC_Pawn, // 적이 Pawn 채널인 경우
        SphereShape
    );

    if (bHit)
    {
        for (const FHitResult& Hit : HitResults)
        {
            AEnemyBase* HitEnemy = Cast<AEnemyBase>(Hit.GetActor());
            
            if (HitEnemy && HitEnemy->ActorHasTag(TEXT("Enemy")) && !HitEnemy->bIsDead)
            {
                // 지속 데미지이므로 초당 데미지에 DeltaTime을 곱함
                UGameplayStatics::ApplyDamage(
                    HitEnemy, 
                    DamagePerSecond * DeltaTime, 
                    GetInstigatorController(), 
                    this, 
                    UDamageType::StaticClass()
                );
            }
        }
    }
}

void AOrbitalLaser::ActivateLaser()
{
    bIsLaserActive = true;
    
    UpdateLaserVisuals();
    
    if (LaserFX) LaserFX->Activate();
    if (ImpactFX) ImpactFX->Activate();
    
    // 0.2초마다 데미지 판정 실행
    GetWorldTimerManager().SetTimer(DamageTimerHandle, this, &AOrbitalLaser::OnDamageTick, 0.2f, true);
    
    // 타겟 탐색 0.5초마다
    GetWorldTimerManager().SetTimer(SearchTimerHandle, this, &AOrbitalLaser::FindNewTarget, 0.5f, true);
}

void AOrbitalLaser::OnDamageTick()
{
    if (!bIsLaserActive) return;

    // 0.2초 분량의 데미지를 한 번에 입힘
    ApplyLaserDamage(0.2f);
}
