
#include "EnemyBase.h"

#include "AIController.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Navigation/PathFollowingComponent.h"
#include "Perception/AISense_Damage.h"
#include "Perception/AISense_Hearing.h"
#include "ProjectHD/Spawn/EnemyPoolManager.h"
#include "Components/StateTreeAIComponent.h"
#include "ProjectHD/Character/Player/FPSCharacter.h"
#include "ProjectHD/HDGameInstance.h"
#include "NavigationInvokerComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"

AEnemyBase::AEnemyBase()
{
    CurrentHealth = MaxHealth;
    
    // 내비 인보커
    //NavInvoker = CreateDefaultSubobject<UNavigationInvokerComponent>(TEXT("NavInvoker"));    
    //NavInvoker->SetGenerationRadii(1000.f, 1500.f);
    
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;
    
    GetCharacterMovement()->bEnablePhysicsInteraction = false;
    GetCharacterMovement()->AvoidanceConsiderationRadius = 0.0f;
}

void AEnemyBase::BeginPlay()
{
    Super::BeginPlay();
    
    CachedPlayer = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

void AEnemyBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    if (bIsDead) return;
    
    // 1초마다 거리 체크
    LastDistanceCheckTime += DeltaTime;
    if (LastDistanceCheckTime >= TickDistanceCheckInterval)
    {
        LastDistanceCheckTime = 0.0f;
        UpdateTickRate();
    }
}

// 거리별로 틱 조정
void AEnemyBase::UpdateTickRate()
{
    if (!CachedPlayer) return;

    float Distance = FVector::Dist(GetActorLocation(), CachedPlayer->GetActorLocation());

    // 거리별 틱 간격 조정
    if (Distance < 1500.0f)
    {
        // 가까움: 매 프레임
        SetActorTickInterval(0.0f);
    }
    else if (Distance < 4000.0f)
    {
        // 중거리: 0.1초마다
        SetActorTickInterval(0.1f);
    }
    else if (Distance < 6000.0f)
    {
        // 원거리: 0.2초마다
        SetActorTickInterval(0.2f);
    }
    else
    {
        // 아주 멀리: 0.5초마다
        SetActorTickInterval(0.5f);
    }
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
        // 총알 통과
        Comp->SetCollisionResponseToAllChannels(ECR_Ignore);
        
        // 레그돌을 위해 남겨두기
        if (Comp != GetMesh())
        {
            Comp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        }
    }
        
    GetMesh()->SetCollisionResponseToAllChannels(ECR_Ignore);
    GetMesh()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
    
    // 땅과는 계속 충돌해야 애니메이션 발 위치 등이 정확할 수 있으므로 WorldStatic만 유지
    GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics); 
    GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Ignore);
    GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
    
    // AI 정지
    if (AAIController* AIC = Cast<AAIController>(GetController()))
    {
        // AIC 타이머 정리
        GetWorldTimerManager().ClearAllTimersForObject(AIC);
        
        // StateTree 먼저 정지
        if (UStateTreeAIComponent* STComp = AIC->FindComponentByClass<UStateTreeAIComponent>())
        {
            STComp->StopLogic("Die");
            STComp->SetComponentTickEnabled(false);
        }
        
        // Perception 정리
        if (UAIPerceptionComponent* PercComp = AIC->FindComponentByClass<UAIPerceptionComponent>())
        {
            PercComp->Deactivate();
            PercComp->ForgetAll();
        }
        
        AIC->StopMovement();
        //AIC->UnPossess();
    }

    // 사망 애니메이션이 있으면 재생, 없으면 바로 레그돌
    if (DeathMontage)
    {
        float DeathAnimDuration = PlayAnimMontage(DeathMontage);
        
        if (DeathAnimDuration > 0.f)
        {
            // 애니메이션이 끝나면 DisableMeshTick 호출
            GetWorldTimerManager().SetTimer(DisableTickTimerHandle, this, &AEnemyBase::DisableMeshTick, DeathAnimDuration, false);
        }
        else
        {
            DisableMeshTick();
        }
    }
    else
    {
        DisableMeshTick();    
    }
    
    // 플레이어 킬 콤보 델리게이트 연동
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (PlayerPawn)
    {
        AFPSCharacter* Player = Cast<AFPSCharacter>(PlayerPawn);
        if (Player)
        {
            Player->AddKillCombo();
        }
    }

    // 미션 결과에 킬 기록
    if (UHDGameInstance* GI = Cast<UHDGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
    {
        GI->AddEnemyKill(KillScoreValue);
    }
    
    // 내비 인보커 끄기
    if (NavInvoker)
    {
        NavInvoker->Deactivate();
    }
    
    // 오브젝트 풀링 타이머
    GetWorldTimerManager().SetTimer(PoolReturnTimerHandle, this, &AEnemyBase::ReturnToPool, ReturnToPoolTime, false);
}

void AEnemyBase::DisableMeshTick()
{
    // 중력과 낙하 로직을 다시 가동하기 위해 Tick 켜기
    SetActorTickEnabled(true);
    
    // 애니메이션이 끝났으니 중력의 영향을 받도록 설정
    if (UCharacterMovementComponent* MoveComp = GetCharacterMovement())
    {
        // 컨트롤러가 없어도 물리 연산을 수행하도록 설정
        MoveComp->bRunPhysicsWithNoController = true;        
        MoveComp->GravityScale = 1.0f;
        MoveComp->SetMovementMode(MOVE_Falling);
        
        // 캡슐의 충돌은 꺼져있지만, 무브먼트 컴포넌트가 바닥을 감지할 수 있게 최소한의 설정
        MoveComp->Velocity = FVector(0.f, 0.f, -10.f);
    }
        
    GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    GetCapsuleComponent()->SetCollisionObjectType(ECC_Pawn);
    GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Ignore);
    GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
    GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
    
    // 바닥에 닿았는지 체크 타이머 시작
    GetWorldTimerManager().SetTimer(LandedCheckTimerHandle, this, &AEnemyBase::CheckIfLanded, 0.1f, true);
}

void AEnemyBase::CheckIfLanded()
{
    // 이동 속도가 거의 0이라면
    if (GetVelocity().Size() < 10.0f)
    {
        GetWorldTimerManager().ClearTimer(LandedCheckTimerHandle);
        
        // 최종 프리즈
        SetActorTickEnabled(false);
        GetMesh()->SetComponentTickEnabled(false);
        GetMesh()->bNoSkeletonUpdate = true;
        
        if (GetCharacterMovement())
        {
            GetCharacterMovement()->DisableMovement();
            GetCharacterMovement()->StopMovementImmediately();
        }

        // 캡슐 콜리전도 꺼서 총알/이동 방해를 제거
        GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        
    }
}

void AEnemyBase::ForceDespawn()
{
    if (bIsDead) return; // 중복 실행 방지
    bIsDead = true;
    
    // 액터에 붙은 모든 컴포넌트를 순회하며 콜리전 정리
    TArray<UPrimitiveComponent*> VisualComponents;
    GetComponents<UPrimitiveComponent>(VisualComponents);

    for (UPrimitiveComponent* Comp : VisualComponents)
    {
        // 총알 통과
        Comp->SetCollisionResponseToAllChannels(ECR_Ignore);
        
        // 레그돌을 위해 남겨두기
        if (Comp != GetMesh())
        {
            Comp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        }
    }
        
    GetMesh()->SetCollisionResponseToAllChannels(ECR_Ignore);
    GetMesh()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
    
    // 땅과는 계속 충돌해야 애니메이션 발 위치 등이 정확할 수 있으므로 WorldStatic만 유지
    GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics); 
    GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Ignore);
    GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
    
    // AI 정지
    if (AAIController* AIC = Cast<AAIController>(GetController()))
    {
        // AIC 타이머 정리
        GetWorldTimerManager().ClearAllTimersForObject(AIC);

        // StateTree 정지
        if (UStateTreeAIComponent* STComp = AIC->FindComponentByClass<UStateTreeAIComponent>())
        {
            STComp->StopLogic("Die");
            STComp->SetComponentTickEnabled(false);
        }

        // Perception 정리
        if (UAIPerceptionComponent* PercComp = AIC->FindComponentByClass<UAIPerceptionComponent>())
        {
            PercComp->Deactivate();
            PercComp->ForgetAll();
        }
        
        AIC->StopMovement();
        // AIC->UnPossess();
    }   
    /*
    // 사망 애니메이션이 있으면 재생, 없으면 바로 레그돌
    if (DeathMontage)
    {
        float DeathAnimDuration = PlayAnimMontage(DeathMontage);
        
        if (DeathAnimDuration > 0.f)
        {
            // 애니메이션이 끝나면 DisableMeshTick 호출
            GetWorldTimerManager().SetTimer(DisableTickTimerHandle, this, &AEnemyBase::DisableMeshTick, DeathAnimDuration, false);
        }
        else
        {
            DisableMeshTick();
        }
    }
    else
    {
        DisableMeshTick();
    }
    */
    // 오브젝트 풀링 타이머 1초로
    GetWorldTimerManager().SetTimer(PoolReturnTimerHandle, this, &AEnemyBase::ReturnToPool, 1.0f, false);
}

// 다시 스폰시 초기화
void AEnemyBase::InitEnemy()
{
      bIsDead = false;
      bIsMissionSpawned = false;
      bIsIdle = false;
      CurrentHealth = MaxHealth;

      // 먼저 타이머 정리
      GetWorldTimerManager().ClearAllTimersForObject(this);

      // 틱/스켈레톤 복구
      SetActorTickEnabled(true);
      SetActorTickInterval(0.0f);
      LastDistanceCheckTime = 0.0f;
      CachedPlayer = UGameplayStatics::GetPlayerPawn(this, 0);

      GetMesh()->SetComponentTickEnabled(true);
      GetMesh()->bNoSkeletonUpdate = false;
      GetMesh()->SetSimulatePhysics(false);
    
    // CharacterMovement 재활성화 (공중 사망적은 checkiflanded에서 비활성화됨)
    if (UCharacterMovementComponent* MoveComp = GetCharacterMovement())
    {
        MoveComp->SetMovementMode(MOVE_Walking);
        MoveComp->SetComponentTickEnabled(true);
    }
    
    // 캡슐 컴포넌트 콜리전 복구
    GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

    // 애니메이션 초기화
    if (UAnimInstance* AnimInst = GetMesh()->GetAnimInstance())
    {
        AnimInst->Montage_Stop(0.0f);
    }

      // 콜리전 복구
      TArray<UPrimitiveComponent*> VisualComponents;
      GetComponents<UPrimitiveComponent>(VisualComponents);

      for (UPrimitiveComponent* Comp : VisualComponents)
      {
          FString CompName = Comp->GetName();
          if (CompName.Contains("HitBox") || CompName.Contains("Mouth"))
          {
              Comp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
              Comp->SetCollisionResponseToAllChannels(ECR_Overlap);
              Comp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
              continue;
          }

          Comp->SetCollisionResponseToAllChannels(ECR_Block);
          Comp->SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECR_Ignore);
          Comp->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
      }

      // 내비 인보커
      if (NavInvoker)
      {
          NavInvoker->Activate(true);
          NavInvoker->SetGenerationRadii(1000.f, 1500.f);
      }    

      // AI 초기화 (타이머는 ClearAll 이후에 설정)
      if (AAIController* AIC = Cast<AAIController>(GetController()))
      {
          SetInstigator(this);

          // 이전 타겟/이동 상태 클리어
          AIC->ClearFocus(EAIFocusPriority::Gameplay);
          AIC->StopMovement();

          if (UAIPerceptionComponent* PercComp = AIC->FindComponentByClass<UAIPerceptionComponent>())
          {
              PercComp->Deactivate();
              PercComp->ForgetAll();

              // 감각 강제 리셋
              PercComp->SetSenseEnabled(UAISense_Sight::StaticClass(), false);
              PercComp->SetSenseEnabled(UAISense_Hearing::StaticClass(), false);
          }

          if (UStateTreeAIComponent* STComp = AIC->FindComponentByClass<UStateTreeAIComponent>())
          {
              STComp->SetComponentTickEnabled(false);
              STComp->StopLogic("Pool Reset");
          }

          // 딜레이 후 Perception + StateTree 함께 시작
          FTimerHandle AIResetHandle;
          GetWorldTimerManager().SetTimer(AIResetHandle, [this, AIC]()
          {
              if (!IsValid(this) || !IsValid(AIC)) return;

              if (UAIPerceptionComponent* PercComp = AIC->FindComponentByClass<UAIPerceptionComponent>())
              {
                  // 감각 다시 활성화
                  PercComp->SetSenseEnabled(UAISense_Sight::StaticClass(), true);
                  PercComp->SetSenseEnabled(UAISense_Hearing::StaticClass(), true);
                  PercComp->Activate();
                  PercComp->RequestStimuliListenerUpdate();
              }

              if (UStateTreeAIComponent* STComp = AIC->FindComponentByClass<UStateTreeAIComponent>())
              {
                  STComp->SetComponentTickEnabled(true);
                  STComp->RestartLogic();
              }

              SetActorHiddenInGame(false);

          }, 0.5f, false);
      }

      SetActorHiddenInGame(true);  // 딜레이 동안 숨김
}

void AEnemyBase::ReturnToPool()
{
    if (AAIController* AIC = Cast<AAIController>(GetController()))
    {
        //AIC->UnPossess();
    }

    if (PoolManager)
    {        
        PoolManager->ReleaseEnemy(this);
    }
}
