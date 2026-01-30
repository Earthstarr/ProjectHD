#include "HDSentry.h"

#include "NiagaraFunctionLibrary.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "ProjectHD/Weapon/Projectile/HDProjectile.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Perception/AISense_Hearing.h"
#include "ProjectHD/Character/Enemy/EnemyBase.h"

AHDSentry::AHDSentry()
{
    PrimaryActorTick.bCanEverTick = true;

    // 본체 (Root)
    BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
    RootComponent = BodyMesh;
    BodyMesh->SetSimulatePhysics(true);
    BodyMesh->SetNotifyRigidBodyCollision(true);

    // 기둥
    PillarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PillarMesh"));
    PillarMesh->SetupAttachment(BodyMesh);

    // 터렛
    TurretMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TurretMesh"));
    TurretMesh->SetupAttachment(PillarMesh);

    // 히트 결과 배열 미리 할당
    CachedHitResults.Reserve(50);
}

void AHDSentry::BeginPlay()
{
    Super::BeginPlay();
    CurrentAmmo = MaxAmmo; // 탄약 초기화
}

void AHDSentry::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // 낙하 및 지면 박히기 로직 (보급 포드 방식)
    if (!bIsDeploying && !bIsDeployed && BodyMesh->IsSimulatingPhysics())
    {
        BodyMesh->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
                
        FVector Start = GetActorLocation() + (FVector::UpVector * 50.f);
        FVector Velocity = BodyMesh->GetPhysicsLinearVelocity();
        float TraceLength = (Velocity.Size() * DeltaTime) + 150.f;
        FVector End = Start + (FVector::UpVector * -TraceLength);
        
        FHitResult GroundHit;
        FCollisionQueryParams Params;
        Params.AddIgnoredActor(this);

        if (GetWorld()->LineTraceSingleByChannel(GroundHit, Start, End, ECC_Visibility, Params))
        {
            BodyMesh->SetSimulatePhysics(false);
            BodyMesh->PutRigidBodyToSleep();
            BodyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
                        
            // 땅에 고정
            SetActorLocation(GroundHit.ImpactPoint + FVector(0.f, 0.f, -100.f));
            
            BodyMesh->SetCollisionProfileName(TEXT("BlockAll"));
            PillarMesh->SetCollisionProfileName(TEXT("BlockAll"));
            //TurretMesh->SetCollisionProfileName(TEXT("BlockAll"));

            if (ImpactSound) UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation());

            bIsDeploying = true;
            StartDeploySequence(); // 블루프린트에서 기둥 올라오는 애니메이션 실행
            
            if (DeploySound) UGameplayStatics::PlaySoundAtLocation(this, DeploySound, GetActorLocation());
        }
    }

    // 전개 완료 후 적 추적 및 회전 (FindNearestEnemy는 타이머로 별도 호출)
    if (bIsDeployed)
    {
        if (CurrentTarget && !Cast<AEnemyBase>(CurrentTarget)->bIsDead)
        {
            RotateToTarget(DeltaTime);
        }
        else
        {
            // 타겟 없거나 죽었으면 사격 중지
            CurrentTarget = nullptr;
            GetWorldTimerManager().ClearTimer(FireTimerHandle);
        }
    }
}

// 시야에서 보이면서 가장 가까운 적 찾기
void AHDSentry::FindNearestEnemy()
{
    // 현재 타겟이 유효하고 살아있으면 유지
    if (IsValid(CurrentTarget))
    {
        if (AEnemyBase* Enemy = Cast<AEnemyBase>(CurrentTarget))
        {
            if (!Enemy->bIsDead)
            {
                float DistSquared = FVector::DistSquared(GetActorLocation(), Enemy->GetActorLocation());
                if (DistSquared < DetectionRadius * DetectionRadius)
                {
                    return; // 기존 타겟 유지
                }
            }
        }
    }

    // 새 타겟 찾기
    CachedHitResults.Reset();
    FVector MyLoc = GetActorLocation();
    FVector MuzzleLoc = TurretMesh->GetSocketLocation(TEXT("Muzzle"));
    FCollisionShape DetectionSphere = FCollisionShape::MakeSphere(DetectionRadius);

    FCollisionQueryParams QueryParams;
    QueryParams.AddIgnoredActor(this);

    // Pawn 채널에서 주변 모든 적 탐색
    bool bHit = GetWorld()->SweepMultiByChannel(CachedHitResults, MyLoc, MyLoc, FQuat::Identity, ECC_Pawn, DetectionSphere, QueryParams);

    AActor* BestTarget = nullptr;
    float MinDistSquared = DetectionRadius * DetectionRadius;

    if (bHit)
    {
        for (const FHitResult& Hit : CachedHitResults)
        {
            AEnemyBase* FoundActor = Cast<AEnemyBase>(Hit.GetActor());
            if (FoundActor && FoundActor->ActorHasTag(TEXT("Enemy")) && !FoundActor->bIsDead)
            {
                // 시야 체크
                FVector TargetLoc = FoundActor->GetActorLocation();
                FHitResult SightHit;
                FCollisionQueryParams SightParams;
                SightParams.AddIgnoredActor(this);
                SightParams.AddIgnoredActor(FoundActor);

                // 시야를 가리는 장애물이 있는지 확인
                bool bIsBlocked = GetWorld()->LineTraceSingleByChannel(SightHit, MuzzleLoc, TargetLoc, ECC_Visibility, SightParams);

                if (!bIsBlocked)
                {
                    float DistSquared = FVector::DistSquared(MyLoc, FoundActor->GetActorLocation());
                    if (DistSquared < MinDistSquared)
                    {
                        MinDistSquared = DistSquared;
                        BestTarget = FoundActor;
                    }
                }
            }
        }
    }
    CurrentTarget = BestTarget;
}

void AHDSentry::RotateToTarget(float DeltaTime)
{
    if (!CurrentTarget) return;

    // 타겟 방향 계산
    FVector TargetLoc = CurrentTarget->GetActorLocation();
    FVector MuzzleLoc = TurretMesh->GetSocketLocation(TEXT("Muzzle"));
    FRotator LookAtRot = UKismetMathLibrary::FindLookAtRotation(MuzzleLoc, TargetLoc);

    // 부드러운 회전 (RInterpTo)
    FRotator CurrentRot = TurretMesh->GetComponentRotation();
    FRotator NewRot = FMath::RInterpTo(CurrentRot, LookAtRot, DeltaTime, RotationSpeed);
    
    // 센트리는 Roll(기울기)은 회전하면 안되므로 0으로 고정
    NewRot.Roll = 0.f;
    TurretMesh->SetWorldRotation(NewRot);
    
    // 조준 정렬 확인
    FVector Forward = TurretMesh->GetForwardVector();
    FVector ToTarget = (TargetLoc - MuzzleLoc).GetSafeNormal();
    float Dot = FVector::DotProduct(Forward, ToTarget);

    // 0.7로 낮춰서 무자비한 사격느낌으로
    if (Dot > 0.7f)
    {
        if (!GetWorldTimerManager().IsTimerActive(FireTimerHandle))
        {
            GetWorldTimerManager().SetTimer(FireTimerHandle, this, &AHDSentry::Fire, FireRate, true);
        }
    }
    else
    {
        GetWorldTimerManager().ClearTimer(FireTimerHandle);
    }
}

void AHDSentry::Fire()
{
    if (!ProjectileClass) return;
    
    // 탄약이 없거나 이미 퇴각 중이면 발사 안 함
    if (CurrentAmmo <= 0 || bIsRetracting) 
    {
        GetWorldTimerManager().ClearTimer(FireTimerHandle);
        return;
    }

    // 총구 위치 소켓 이름: "Muzzle"
    FVector MuzzleLoc = TurretMesh->GetSocketLocation(TEXT("Muzzle"));
    FRotator MuzzleRot = TurretMesh->GetSocketRotation(TEXT("Muzzle"));
    
    // 랜덤 퍼짐 추가 (상하좌우 약 1도)
    //MuzzleRot.Pitch += FMath::FRandRange(-1.0f, 1.0f);
    //MuzzleRot.Yaw += FMath::FRandRange(-1.0f, 1.0f);

    FActorSpawnParameters Params;
    Params.Owner = this;
    
    GetWorld()->SpawnActor<AHDProjectile>(ProjectileClass, MuzzleLoc, MuzzleRot, Params);
    
    // 소음
    UAISense_Hearing::ReportNoiseEvent(
            GetWorld(), 
            GetActorLocation(), 
            NoiseLoud,
            this,
            0.0f,
            FName(TEXT("Noise"))
            );
    
    if (MuzzleFlashFX)
    {
        UNiagaraFunctionLibrary::SpawnSystemAtLocation(
            GetWorld(),
            MuzzleFlashFX,
            MuzzleLoc,
            MuzzleRot
        );
    }
    if (FireSound) UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
    
    CurrentAmmo--;

    if (CurrentAmmo <= 0)
    {
        StopFiringAndRetract();
    }
}

void AHDSentry::OnDeployFinished()
{
    bIsDeploying = false;
    bIsDeployed = true;

    // 0.25초마다 적 탐색 (매 틱 대신)
    GetWorldTimerManager().SetTimer(SearchTimerHandle, this, &AHDSentry::FindNearestEnemy, 0.25f, true);
    FindNearestEnemy(); // 첫 탐색 즉시 실행
}

void AHDSentry::StopFiringAndRetract()
{
    if (bIsRetracting) return;

    bIsRetracting = true;
    bIsDeployed = false; // 더 이상 적을 찾거나 회전하지 않음

    // 타이머 중지
    GetWorldTimerManager().ClearTimer(FireTimerHandle);
    GetWorldTimerManager().ClearTimer(SearchTimerHandle);

    // 블루프린트에 퇴각 애니메이션 시작 알림
    StartRetractSequence();
}

void AHDSentry::OnRetractFinished()
{
    // 땅속으로 다 들어갔으면 액터 파괴
    Destroy();
}