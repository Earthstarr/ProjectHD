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

    // DrawDebugSphere(GetWorld(), CurrentImpactPoint, 100.f, 12, FColor::Red, false, -1.f);
    
    // 타겟이 죽었거나 없으면 새 타겟 찾기
    if (!CurrentTarget || !IsValid(CurrentTarget))
    {
        FindNewTarget();
    }

    // 레이저 이동 목표 지점 설정 (타겟이 없으면 제자리 대기)
    FVector TargetLocation = CurrentTarget ? CurrentTarget->GetActorLocation() : GetActorLocation();
    
    // 방향 계산
    FVector Direction = TargetLocation - CurrentImpactPoint;
    float DistanceToTarget = Direction.Size();

    if (DistanceToTarget > 5.0f)
    {
        Direction.Normalize();
        CurrentImpactPoint += Direction * MoveSpeed * DeltaTime;

        // 만약 이번 프레임에 이동할 거리가 남은 거리보다 멀면 목표 지점에 고정
        if ((MoveSpeed * DeltaTime) > DistanceToTarget)
        {
            CurrentImpactPoint = TargetLocation;
        }
    }

    // 지면 높이 보정
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
        LaserFX->SetNiagaraVariableVec3(FString("User_BeamStart"), CurrentImpactPoint + FVector(0, -10, -20));
        LaserFX->SetNiagaraVariableVec3(FString("User_BeamEnd"), CurrentImpactPoint + FVector(0, -10000, 20000)); // 대각선 하늘 위
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
            AActor* HitActor = Hit.GetActor();
            if (HitActor && HitActor->ActorHasTag(TEXT("Enemy")))
            {
                // 지속 데미지이므로 초당 데미지에 DeltaTime을 곱함
                UGameplayStatics::ApplyDamage(
                    HitActor, 
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
    
    if (LaserFX) LaserFX->Activate();
    if (ImpactFX) ImpactFX->Activate();
}
