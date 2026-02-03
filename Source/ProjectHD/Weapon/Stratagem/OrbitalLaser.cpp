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

    // 배열 미리 할당
    CachedHitResults.Reserve(50);
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
        AudioComp = UGameplayStatics::SpawnSoundAttached(
            LaserLoopSound,
            RootComponent,
            NAME_None,
            FVector::ZeroVector,
            EAttachLocation::KeepRelativeOffset,
            true,
            1.0f,
            1.0f,
            0.0f,
            nullptr,
            nullptr,
            false  // bAutoDestroy: false로 변경 - 가상화 시 파괴 방지
        );
    }
    
    // delaytime 뒤에 시작
    FTimerHandle TimerHandle;
    GetWorldTimerManager().SetTimer(TimerHandle, this, &AOrbitalLaser::ActivateLaser, delaytime, false);
}

void AOrbitalLaser::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    // 타이머 정리
    GetWorldTimerManager().ClearTimer(DamageTimerHandle);
    GetWorldTimerManager().ClearTimer(SearchTimerHandle);
    GetWorldTimerManager().ClearTimer(GroundCheckTimerHandle);
    
    // 오디오 정리
    if (AudioComp && AudioComp->IsPlaying())
    {
        AudioComp->Stop();
    }
    
    Super::EndPlay(EndPlayReason);
}

void AOrbitalLaser::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (!bIsLaserActive) return;

    // 이동
    if (IsValid(CurrentTarget))
    {
        FVector TargetLocation = CurrentTarget->GetActorLocation();
        FVector Direction = TargetLocation - CurrentImpactPoint;
        float DistanceToTarget = Direction.Size();

        if (DistanceToTarget > 5.0f)
        {
            Direction.Normalize();
            CurrentImpactPoint += Direction * MoveSpeed * DeltaTime;
        }
    }

    // 비주얼 갱신
    if (LaserFX)
    {
        LaserFX->SetVectorParameter(BeamStartName, CurrentImpactPoint + FVector(0, -10, -20));
        FVector SkyPoint = bUseWorldBeamOrigin ? BeamSkyOrigin : (CurrentImpactPoint + BeamEndOffset);
        LaserFX->SetVectorParameter(BeamEndName, SkyPoint);
    }
    if (ImpactFX) ImpactFX->SetWorldLocation(CurrentImpactPoint + FVector(0, 0, 20.f));
    if (IsValid(AudioComp)) AudioComp->SetWorldLocation(CurrentImpactPoint);
}

void AOrbitalLaser::CheckGroundHeight()
{
    // 높이 보정 (LineTrace)
    FHitResult GroundHit;
    FVector TraceStart = CurrentImpactPoint + FVector(0, 0, 2000);
    FVector TraceEnd = CurrentImpactPoint + FVector(0, 0, -2000);
    
    FCollisionQueryParams QueryParams;
    QueryParams.AddIgnoredActor(this);
    
    if (GetWorld()->LineTraceSingleByChannel(GroundHit, TraceStart, TraceEnd, ECC_Visibility, QueryParams))
    {
        CurrentImpactPoint.Z = GroundHit.ImpactPoint.Z;
    }
}

void AOrbitalLaser::FindNewTarget()
{
    // 현재 타겟이 유효하고 살아있으면 유지
    if (IsValid(CurrentTarget))
    {
        if (AEnemyBase* Enemy = Cast<AEnemyBase>(CurrentTarget))
        {
            if (!Enemy->bIsDead)
            {
                float DistanceSquared = FVector::DistSquared(CurrentImpactPoint, Enemy->GetActorLocation());
                if (DistanceSquared < SearchRadius * SearchRadius * 2.25f)
                {
                    return;
                }
            }
        }
    }

    // 새 타겟 찾기
    CachedHitResults.Reset();
    FCollisionShape Sphere = FCollisionShape::MakeSphere(SearchRadius);
    FCollisionQueryParams QueryParams;
    QueryParams.AddIgnoredActor(this);
    
    bool bHit = GetWorld()->SweepMultiByChannel(
        CachedHitResults,
        CurrentImpactPoint,
        CurrentImpactPoint, 
        FQuat::Identity,
        ECC_Pawn,
        Sphere,
        QueryParams
    );

    AActor* ClosestEnemy = nullptr;
    float MinDistSquared = SearchRadius * SearchRadius;

    if (bHit)
    {
        for (const FHitResult& Hit : CachedHitResults)
        {
            AEnemyBase* PotentialTarget = Cast<AEnemyBase>(Hit.GetActor());
            
            if (PotentialTarget && PotentialTarget->ActorHasTag(TEXT("Enemy")) && !PotentialTarget->bIsDead)
            {
                float DistSquared = FVector::DistSquared(CurrentImpactPoint, PotentialTarget->GetActorLocation());
                if (DistSquared < MinDistSquared)
                {
                    MinDistSquared = DistSquared;
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
        LaserFX->SetVectorParameter(BeamStartName, CurrentImpactPoint + FVector(0, -10, -20));
        FVector SkyPoint = bUseWorldBeamOrigin ? BeamSkyOrigin : (CurrentImpactPoint + BeamEndOffset);
        LaserFX->SetVectorParameter(BeamEndName, SkyPoint);
    }
    
    if (ImpactFX)
    {        
        FVector VisualLocation = CurrentImpactPoint + FVector(0, 0, 20.f);
        ImpactFX->SetWorldLocation(VisualLocation);
    }
}

void AOrbitalLaser::ApplyLaserDamage()
{
    CachedHitResults.Reset();
    
    // 데미지 반경 설정
    static const float DamageRadius = 250.f;
    FCollisionShape SphereShape = FCollisionShape::MakeSphere(DamageRadius);
    FCollisionQueryParams QueryParams;
    QueryParams.AddIgnoredActor(this);
    
    // 구체 범위 내의 모든 적 검출
    bool bHit = GetWorld()->SweepMultiByChannel(
        CachedHitResults, 
        CurrentImpactPoint, 
        CurrentImpactPoint, 
        FQuat::Identity, 
        ECC_Pawn, // 적이 Pawn 채널인 경우
        SphereShape,
        QueryParams
    );

    if (bHit)
    {
        // 0.5초마다 호출되므로 0.5초 분량의 데미지
        float DamageAmount = DamagePerSecond * 0.5f;
        
        for (const FHitResult& Hit : CachedHitResults)
        {
            AEnemyBase* HitEnemy = Cast<AEnemyBase>(Hit.GetActor());
            
            if (HitEnemy && HitEnemy->ActorHasTag(TEXT("Enemy")) && !HitEnemy->bIsDead)
            {
                // 지속 데미지
                UGameplayStatics::ApplyDamage(
                    HitEnemy, 
                    DamageAmount, 
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
    
    // 0.5초마다 데미지 판정 실행
    GetWorldTimerManager().SetTimer(DamageTimerHandle, this, &AOrbitalLaser::OnDamageTick, 0.5f, true);
    
    // 타겟 탐색 1초마다
    GetWorldTimerManager().SetTimer(SearchTimerHandle, this, &AOrbitalLaser::FindNewTarget, 1.0f, true);
    
    // 지면 체크 0.5초마다
    GetWorldTimerManager().SetTimer(GroundCheckTimerHandle, this, &AOrbitalLaser::CheckGroundHeight, 0.5f, true);
    
    // 첫 실행
    FindNewTarget();
}

void AOrbitalLaser::OnDamageTick()
{
    if (!bIsLaserActive) return;

    // 데미지 적용
    ApplyLaserDamage();
}