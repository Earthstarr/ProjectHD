#include "StratagemBeacon.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "HDProjectile.h"

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

    if (MyStratagemType == EStratagemType::Bomb500kg)
    {
        // --- 500kg 폭탄 투하 로직 (기존 코드 유지) ---
        FVector LaunchLocation = TargetLocation + FVector(0.f, 0.f, 10000.f);
        FRotator LaunchRotation = FRotator(-90.f, 0.f, 0.f);

        if (ProjectileClass)
        {
            AHDProjectile* LargeShell = GetWorld()->SpawnActor<AHDProjectile>(ProjectileClass, LaunchLocation, LaunchRotation);

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
    else if (MyStratagemType == EStratagemType::Supply)
    {
        // --- 보급품 투하 로직 (새로운 클래스 소환 가능) ---
        // 예: GetWorld()->SpawnActor<ASupplyPod>(SupplyClass, TargetLocation, FRotator::ZeroRotator);
        UE_LOG(LogTemp, Warning, TEXT("보급품이 투하되었습니다!"));
    }

    Destroy();
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
    }
}
