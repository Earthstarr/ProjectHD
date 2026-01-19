
#include "EnemyBase.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Perception/AISense_Damage.h"
#include "Perception/AISense_Hearing.h"

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
    bIsDead = true;
    // 랙돌 물리 적용 또는 사망 애니메이션 재생 로직
    GetMesh()->SetSimulatePhysics(true);
    GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    Destroy();
}