#include "StratagemBeacon.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "ProjectHD/Weapon/Projectile/HDProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Eagle.h"
#include "HDSentry.h"
#include "OrbitalLaser.h"
#include "ProjectHD/Weapon/Stratagem/HDSupplyPod.h"
#include "Math/Quat.h"

AStratagemBeacon::AStratagemBeacon()
{
    // 충돌체 설정
    CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
    CollisionComp->InitSphereRadius(10.0f);
    CollisionComp->SetCollisionProfileName(TEXT("Projectile"));

    CollisionComp->SetCollisionProfileName(TEXT("BlockAll")); // 혹은 "Custom"

    // 2. 물리적 충돌 신호(Simulation Generates Hit Events)를 확실히 켬
    CollisionComp->SetCanEverAffectNavigation(false);
    CollisionComp->bReturnMaterialOnMove = true;
    CollisionComp->SetNotifyRigidBodyCollision(true);

    // 부딪히면 OnHit 실행되도록 연결
    CollisionComp->OnComponentHit.AddDynamic(this, &AStratagemBeacon::OnHit);
    RootComponent = CollisionComp;

    // 외형 설정
    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
    MeshComp->SetupAttachment(RootComponent);

    // 투사체 설정 (수류탄 느낌)
    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
    ProjectileMovement->UpdatedComponent = CollisionComp;
    ProjectileMovement->InitialSpeed = 2000.f;
    ProjectileMovement->MaxSpeed = 2000.f;
    ProjectileMovement->bShouldBounce = true; // 바닥에서 살짝 튀게 설정
    ProjectileMovement->Bounciness = 0.3f;
}

void AStratagemBeacon::UpdateBeaconVisual(FLinearColor NewColor)
{
    PendingColor = NewColor; // 전달받은 색상을 저장해둠

    // 만약 이미 빔이 생성된 상태라면 즉시 적용
    if (SpawnedBeam)
    {
        SpawnedBeam->SetVariableLinearColor(FName("User.Color"), PendingColor);
    }
}

void AStratagemBeacon::BeginPlay()
{
    Super::BeginPlay();
}

void AStratagemBeacon::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    // 이미 안착했다면 무시 (여러 번 부딪히는 현상 방지)
    if (ProjectileMovement->Velocity.IsNearlyZero()) return;

    // 움직임 즉시 정지 및 물리 계산 끄기
    ProjectileMovement->StopMovementImmediately();
    ProjectileMovement->Deactivate();

    // 충돌 설정 변경 (더 이상 튕기지 않게)
    CollisionComp->SetSimulatePhysics(false);
    CollisionComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    if (BeaconActivateSound)
    {
        UGameplayStatics::PlaySound2D(this, BeaconActivateSound);
    }

    // 바닥에 달라붙기 (Attach)
    // 부딪힌 대상(OtherActor)이 있고, 움직이는 물체일 수도 있으므로 부착해줍니다.
    if (OtherActor)
    {
        FAttachmentTransformRules AttachRules(
            EAttachmentRule::KeepWorld,
            EAttachmentRule::KeepWorld,
            EAttachmentRule::KeepWorld,
            false
        );
        this->AttachToActor(OtherActor, AttachRules);
    }

    ActivateBeacon();

    // 타이머 시작
    FTimerHandle StrikeTimer;
    GetWorldTimerManager().SetTimer(StrikeTimer, this, &AStratagemBeacon::TriggerStrike, DelayToStrike, false);
}

void AStratagemBeacon::TriggerStrike()
{        
    // 폭격 지점 및 발사 지점 계산
    FVector TargetLocation = GetActorLocation();
    
    // 500kg 폭탄
    if (MyStratagemType == EStratagemType::Bomb500kg)
    {
        // --- 500kg 폭탄 투하 ---
        FVector LaunchLocation = TargetLocation + FVector(0.f, 0.f, 10000.f);
        FRotator LaunchRotation = FRotator(-90.f, 0.f, 0.f);

        if (Eagle500kgProjectileClass)
        {
            AHDProjectile* LargeShell = GetWorld()->SpawnActor<AHDProjectile>(Eagle500kgProjectileClass, LaunchLocation, LaunchRotation);

            if (LargeShell)
            {
                // 포탄 속도
                UProjectileMovementComponent* ProjComp = LargeShell->FindComponentByClass<UProjectileMovementComponent>();
                if (ProjComp)
                {
                    ProjComp->InitialSpeed = 10000.f;
                    ProjComp->MaxSpeed = 10000.f;
                    ProjComp->Velocity = FVector(0.f, 0.f, -10000.f);
                }
            }
        }
    }
    // 보급품
    else if (MyStratagemType == EStratagemType::Supply)
    {        
        // --- 보급품 투하 ---
        FVector LaunchLocation = TargetLocation + FVector(0.f, 0.f, 10000.f);
        FRotator LaunchRotation = FRotator::ZeroRotator;
        
        AHDSupplyPod* SpawnedPod = GetWorld()->SpawnActor<AHDSupplyPod>(SupplyClass, LaunchLocation, LaunchRotation);
        
        if (SpawnedPod)
        {            
            UStaticMeshComponent* PodMesh = Cast<UStaticMeshComponent>(SpawnedPod->GetRootComponent());
        
            if (PodMesh)
            {               
                PodMesh->SetSimulatePhysics(true);
            
                // 아래 방향으로 Impulse
                FVector Impulse = FVector(0.f, 0.f, -10000.f); 
                PodMesh->AddImpulse(Impulse, NAME_None, true); // true: 질량 무시하고 속도 즉시 적용
            }
        }
    }
    // 집속탄
    else if (MyStratagemType == EStratagemType::EagleCluster)
    {
        FVector RightVector = GetActorRightVector();    
        FVector ForwardVector = GetActorForwardVector();
    
        // 높이를 충분히 줘서 위아래 모두 커버
        TArray<FHitResult> BaseHits;
        FVector BoxHalfSize = FVector(ClusterDepth, ClusterWidth, 1000.f); // 높이를 10m로 확장
        FCollisionShape BoxShape = FCollisionShape::MakeBox(BoxHalfSize);
        FQuat Rotation = GetActorRotation().Quaternion();
        
        /*
        // 범위에 전체 데미지
        GetWorld()->SweepMultiByChannel(BaseHits, TargetLocation, TargetLocation, Rotation, ECC_Pawn, BoxShape);
        for (auto& Hit : BaseHits)
        {
            UGameplayStatics::ApplyDamage(Hit.GetActor(), 30.f, GetInstigatorController(), this, UDamageType::StaticClass());
        }
        */
    
        // 지형 높이 감지
        for (int32 i = 0; i < ClusterCount; ++i)
        {
            float RandRight = FMath::FRandRange(-ClusterWidth, ClusterWidth);
            float RandForward = FMath::FRandRange(-ClusterDepth, ClusterDepth);
            
            // 평면상의 위치
            FVector HorizontalPos = TargetLocation + (RightVector * RandRight) + (ForwardVector * RandForward);
            
            // 폭탄들 랜덤 시간
            float Delay = FMath::FRandRange(0.5f, 3.0f);
            
            FTimerHandle TempHandle;
            GetWorldTimerManager().SetTimer(TempHandle, [this, HorizontalPos]()
            {
                // 지형 높이 찾기
                FVector TraceStart = HorizontalPos + FVector(0.f, 0.f, 2000.f); // 해당 위치 20m 위에서
                FVector TraceEnd = HorizontalPos + FVector(0.f, 0.f, -2000.f);  // 20m 아래로 쏨
                
                FHitResult TerrainHit;
                FCollisionQueryParams Params;
                Params.AddIgnoredActor(this);
    
                FVector FinalExplosionPos = HorizontalPos; // 기본값
    
                if (GetWorld()->LineTraceSingleByChannel(TerrainHit, TraceStart, TraceEnd, ECC_Visibility, Params))
                {
                    // 라인 트레이스가 닿은 곳이 실제 폭발 위치
                    FinalExplosionPos = TerrainHit.ImpactPoint;
                }
                // -----------------------------
    
                // 시각 효과 및 지점 데미지
                if (ClusterExplosionFX)
                {
                    UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ClusterExplosionFX, FinalExplosionPos);
                }
                
                if (ClusterExplosionSound)
                {
                    UGameplayStatics::PlaySoundAtLocation(this, ClusterExplosionSound, FinalExplosionPos, 
                        FMath::FRandRange(0.4f, 0.6f), FMath::FRandRange(0.8f, 1.2f));
                }
                
                //이펙트 터진곳 데미지
                TArray<FHitResult> PointHits;
                FCollisionShape SphereShape = FCollisionShape::MakeSphere(250.f);
                if (GetWorld()->SweepMultiByChannel(PointHits, FinalExplosionPos, FinalExplosionPos, FQuat::Identity, ECC_Pawn, SphereShape))
                {
                    for (auto& PHit : PointHits)
                    {
                        UGameplayStatics::ApplyPointDamage(PHit.GetActor(), 50.f, FinalExplosionPos - PHit.ImpactPoint, PHit, GetInstigatorController(), this, UDamageType::StaticClass());
                    }
                }
            }, Delay, false);
        }
    }
    // 센트리
    else if (MyStratagemType == EStratagemType::Sentry)
    {
        // --- 센트리 투하 ---
        FVector LaunchLocation = TargetLocation + FVector(0.f, 0.f, 10000.f);
        FRotator LaunchRotation = FRotator::ZeroRotator;
        
        AHDSentry* SpawnedSentry = GetWorld()->SpawnActor<AHDSentry>(SentryClass, LaunchLocation, LaunchRotation);
        
        if (SpawnedSentry)
        {            
            UStaticMeshComponent* PodMesh = Cast<UStaticMeshComponent>(SpawnedSentry->GetRootComponent());
        
            if (PodMesh)
            {               
                PodMesh->SetSimulatePhysics(true);
            
                // 아래 방향으로 Impulse
                FVector Impulse = FVector(0.f, 0.f, -10000.f); 
                PodMesh->AddImpulse(Impulse, NAME_None, true); // true: 질량 무시하고 속도 즉시 적용
            }
        }
    }
    // 궤도 레이저
    else if (MyStratagemType == EStratagemType::OrbitalLaser)
    {
        // 소환 파라미터 설정
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;
        SpawnParams.Instigator = GetInstigator(); // 플레이어 컨트롤러 정보를 레이저에 전달
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        // 레이저 액터 소환
        if (OrbitalLaserClass)
        {
            FVector SpawnLocation = GetActorLocation();
            FRotator SpawnRotation = FRotator::ZeroRotator;

            AOrbitalLaser* LaserActor = GetWorld()->SpawnActor<AOrbitalLaser>(
                OrbitalLaserClass, 
                SpawnLocation, 
                SpawnRotation, 
                SpawnParams
            );

            if (LaserActor)
            {
                 // LaserActor->InitLaser(Duration, MoveSpeed);
            }
        }
    }
    
    MeshComp->SetVisibility(false);
    if (SpawnedBeam) SpawnedBeam->Deactivate();
    CollisionComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    
    SetLifeSpan(5.0f);    
}

void AStratagemBeacon::ActivateBeacon()
{
    if (BeamEffect)
    {
        // 비컨 위치에서 하늘 방향으로 나이아가라 스폰        
        SpawnedBeam = UNiagaraFunctionLibrary::SpawnSystemAttached(
            BeamEffect,
            RootComponent,
            NAME_None,
            FVector::ZeroVector,
            FRotator::ZeroRotator,
            EAttachLocation::KeepRelativeOffset,
            true
        );

        if (SpawnedBeam)
        {
            SpawnedBeam->SetVariableLinearColor(FName("User.Color"), PendingColor);
            SpawnedBeam->SetWorldRotation(FRotator(0.f, 0.f, 0.f));
        }

        if ((MyStratagemType == EStratagemType::Bomb500kg || MyStratagemType == EStratagemType::EagleCluster) && FighterSound && EagleClass)
        {            
            FVector BeaconLoc = GetActorLocation();

            FVector Forward = GetActorForwardVector();
            FVector Right = GetActorRightVector();
            FVector Up = FVector::UpVector;

            // 시작점: 비컨 위치로부터 뒤로 500m, 왼쪽으로 120m, 위로 200m
            FVector FlyStart = BeaconLoc + (Forward * -50000.f) + (Right * -12000.f) + (Up * 20000.f);

            // 도착점: 비컨 위치로부터 앞으로 800m, 오른쪽으로 120m, 위로 80m
            FVector FlyEnd = BeaconLoc + (Forward * 80000.f) + (Right * 12000.f) + (Up * 8000.f);


            FActorSpawnParameters SpawnParams;
            AEagle* Eagle = GetWorld()->SpawnActor<AEagle>(EagleClass, FlyStart, FRotator::ZeroRotator, SpawnParams);

            float FlightTime = DelayToStrike + 2.5f;

            if (Eagle)
            {
                Eagle->InitEagle(FlyStart, FlyEnd, FlightTime);
            }

            UGameplayStatics::PlaySoundAtLocation(this, FighterSound, GetActorLocation());
        }
        else if ((MyStratagemType == EStratagemType::Sentry || MyStratagemType == EStratagemType::Supply) && FallingSound)
        {
            UGameplayStatics::PlaySoundAtLocation(this, FallingSound, GetActorLocation());
        }
    }
}
