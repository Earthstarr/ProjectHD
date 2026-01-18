
#include "EnemyBase.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Perception/AISense_Damage.h"

AEnemyBase::AEnemyBase()
{
    CurrentHealth = MaxHealth;
}

float AEnemyBase::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
    if (bIsDead) return 0.0f;

    float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

    CurrentHealth -= ActualDamage;
    
    // 데미지를 입을 시 주변의 적에게 0.01의 데미지를 줘서 AI 활성화
    if (DamageAmount > 0.01f)
    {
        TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
        ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));

        TArray<AActor*> OutActors;
        TArray<AActor*> ActorsToIgnore;
        ActorsToIgnore.Add(this);
        
        //DrawDebugSphere(GetWorld(), GetActorLocation(), AlarmRadius, 32, FColor::Red, false, 3.0f);
        
        bool bHasOverlap = UKismetSystemLibrary::SphereOverlapActors(
            GetWorld(), GetActorLocation(), AlarmRadius, ObjectTypes,
            ACharacter::StaticClass(), ActorsToIgnore, OutActors
        );

        if (bHasOverlap)
        {
            for (AActor* OverlappedActor : OutActors)
            {            
                if (OverlappedActor && OverlappedActor->ActorHasTag(TEXT("Enemy")))
                {
                    UGameplayStatics::ApplyDamage(
                        OverlappedActor, 0.01f, EventInstigator, DamageCauser, UDamageType::StaticClass() // DamageCauser를 그대로 다시 넘겨줌
                    );
                }
            }
        }
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