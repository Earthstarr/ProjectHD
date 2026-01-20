
#include "EnemyBase.h"

#include "AIController.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Perception/AISense_Damage.h"
#include "Perception/AISense_Hearing.h"
#include "ProjectHD/EnemyPoolManager.h"

AEnemyBase::AEnemyBase()
{
    CurrentHealth = MaxHealth;
}

float AEnemyBase::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
    if (bIsDead) return 0.0f;

    float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

    CurrentHealth -= ActualDamage;
        
    // 데미지를 입으면 주변 적에게 소음 알림
    if (ActualDamage > 0.0f && DamageCauser)
    {
        
        AActor* RealAttacker = DamageCauser;  // 기본값은 DamageCauser
    
        // 1순위: Instigator (플레이어 같은 Pawn)
        if (APawn* InstigatorPawn = DamageCauser->GetInstigator())
        {
            RealAttacker = InstigatorPawn;
        }
        // 2순위: Owner (센트리 같은 AActor)
        else if (AActor* OwnerActor = DamageCauser->GetOwner())
        {
            RealAttacker = OwnerActor;
        }
    
        LastAttackerLocation = RealAttacker->GetActorLocation();    
        
        //DrawDebugSphere(GetWorld(), GetActorLocation(), 500.0f, 32, FColor::Red, false, 5.0f);
    
        UAISense_Hearing::ReportNoiseEvent(
            GetWorld(),
            GetActorLocation(),
            NoiseLoud,
            this,
            0.0f,
            FName(TEXT("HelpNoise")) // 태그
        );
    }   
    
    if (CurrentHealth <= 0.0f)
    {
        Die();
    }

    return ActualDamage;
}

void AEnemyBase::Die()
{
    if (bIsDead) return; // 중복 실행 방지
    bIsDead = true;
    
    // 액터에 붙은 모든 컴포넌트를 순회하며 콜리전 정리
    TArray<UPrimitiveComponent*> VisualComponents;
    GetComponents<UPrimitiveComponent>(VisualComponents);

    for (UPrimitiveComponent* Comp : VisualComponents)
    {
        // 모든 채널 무시 및 콜리전 비활성화
        Comp->SetCollisionResponseToAllChannels(ECR_Ignore);
        Comp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    }
    
    // AI 정지 및 캡슐 충돌 제거
    GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    if (AAIController* AIC = Cast<AAIController>(GetController()))
    {
        AIC->StopMovement();
        AIC->UnPossess();
    }
    SetActorTickEnabled(false);

    // 사망 애니메이션 재생
    float DeathAnimDuration = 0.f;
    
    if (DeathMontage)
    {
        DeathAnimDuration = PlayAnimMontage(DeathMontage);
    }

    if (DeathAnimDuration > 0.f)
    {
        // 애니메이션이 끝나는 시점에 지면 체크 및 틱 종료 판단
        GetWorldTimerManager().SetTimer(DisableTickTimerHandle, this, &AEnemyBase::DisableMeshTick, DeathAnimDuration, false);
    }
    else
    {
        // 몽타주가 없으면 즉시 체크
        DisableMeshTick();
    }
}

void AEnemyBase::DisableMeshTick()
{
    // 애니메이션이 끝난 시점에서 지면 확인
    FHitResult GroundHit;
    FVector Start = GetActorLocation();
    FVector End = Start + (FVector::UpVector * -100.0f);
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);

    bool bOnGround = GetWorld()->LineTraceSingleByChannel(GroundHit, Start, End, ECC_Visibility, Params);

    if (bOnGround)
    {
        // 틱 끄고 고정
        GetMesh()->SetComponentTickEnabled(false);
        GetMesh()->bNoSkeletonUpdate = true;
        GetMesh()->SetSimulatePhysics(false);
        GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        GetMesh()->SetCollisionResponseToAllChannels(ECR_Ignore);
    }
    else
    {
        // 땅에 닿을 때까지 물리 적용
        ActivateRagdoll();
    }
    
    // 오브젝트 풀링
    GetWorldTimerManager().SetTimer(PoolReturnTimerHandle, this, &AEnemyBase::ReturnToPool, 10.0f, false);
}

void AEnemyBase::ActivateRagdoll()
{
    // 레그돌을 위한 물리 켜기
    GetMesh()->SetCollisionProfileName(TEXT("Ragdoll"));
    GetMesh()->SetSimulatePhysics(true);
    GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    
    GetMesh()->SetCollisionResponseToAllChannels(ECR_Ignore);   // 총알 통과
    GetMesh()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
    GetMesh()->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
    
    // 바닥 착지 감지 타이머 시작
    GetWorldTimerManager().SetTimer(LandedCheckTimerHandle, this, &AEnemyBase::CheckIfLanded, 0.2f, true);
}

void AEnemyBase::CheckIfLanded()
{
    // 물리 속도가 충분히 줄어들면 착지로 간주
    if (GetMesh()->GetPhysicsLinearVelocity().Size() < 10.0f)
    {
        GetWorldTimerManager().ClearTimer(LandedCheckTimerHandle);
        
        // 물리 끄고 현재 포즈로 고정
        GetMesh()->SetSimulatePhysics(false);
        GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        
        // 최종적으로 최적화 수행
        GetMesh()->SetComponentTickEnabled(false);
        GetMesh()->bNoSkeletonUpdate = true;
    }
}

// 초기화
void AEnemyBase::InitEnemy()
{
    bIsDead = false;
    CurrentHealth = MaxHealth;
    SetActorHiddenInGame(false);

    // 모든 컴포넌트 콜리전 복구
    TArray<UPrimitiveComponent*> VisualComponents;
    GetComponents<UPrimitiveComponent>(VisualComponents);
    
    for (UPrimitiveComponent* Comp : VisualComponents)
    {    
        Comp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
        Comp->SetCollisionResponseToAllChannels(ECR_Block); // 기본값 복구
    }

    // 틱 및 스켈레톤 업데이트 복구
    SetActorTickEnabled(true);
    GetMesh()->SetComponentTickEnabled(true);
    GetMesh()->bNoSkeletonUpdate = false;
    GetMesh()->SetSimulatePhysics(false);

    // 모든 타이머 초기화
    GetWorldTimerManager().ClearAllTimersForObject(this);
}

void AEnemyBase::ReturnToPool()
{
    if (PoolManager)
    {
        PoolManager->ReleaseEnemy(this);
    }
}