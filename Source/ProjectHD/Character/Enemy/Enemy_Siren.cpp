// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectHD/Character/Enemy/Enemy_Siren.h"

#include "NavigationSystem.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "ProjectHD/Character/Player/FPSCharacter.h"
#include "ProjectHD/Spawn/EnemyPoolManager.h"

AEnemy_Siren::AEnemy_Siren()
{
	MaxHealth = 30.0f;
	CurrentHealth = MaxHealth;
	ReturnToPoolTime = 5.0f;
	
	BodyCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BodyCollision"));
	BodyCollision->SetupAttachment(GetMesh()); 
	BodyCollision->SetCollisionProfileName(TEXT("CharacterMesh"));
	BodyCollision->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	
	HeadCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("HeadCollision"));
	HeadCollision->SetupAttachment(GetMesh()); 
	HeadCollision->SetCollisionProfileName(TEXT("CharacterMesh"));
	HeadCollision->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);

	HitBoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBoxCollision"));
	HitBoxCollision->SetupAttachment(GetMesh());
	HitBoxCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	HitBoxCollision->SetGenerateOverlapEvents(true);
	HitBoxCollision->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
    
	BodyCollision->IgnoreActorWhenMoving(this, true);
	BodyCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BodyCollision->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	
	HitBoxCollision->IgnoreActorWhenMoving(this, true);
	HitBoxCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AEnemy_Siren::BeginPlay()
{
	Super::BeginPlay();
	
	HitBoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AEnemy_Siren::OnHitBoxOverlap);
}

void AEnemy_Siren::InitEnemy()
{
	Super::InitEnemy();
    
	if (BodyCollision)
	{
		BodyCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		BodyCollision->SetCollisionResponseToAllChannels(ECR_Block);
		BodyCollision->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	}
    
	if (HeadCollision)
	{
		HeadCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		HeadCollision->SetCollisionResponseToAllChannels(ECR_Block);
		HeadCollision->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	}
    
	if (HitBoxCollision)
	{
		HitBoxCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	// 오브젝트 풀에서 꺼낼 때 증원 상태 초기화
	CleanupReinforcement();
	bIsCoolingDown = false;
	bIsReinforcing = false;
}

void AEnemy_Siren::OnHitBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{     
		AFPSCharacter* TargetPlayer = Cast<AFPSCharacter>(OtherActor);
		if (TargetPlayer)
		{        
			UGameplayStatics::ApplyDamage(TargetPlayer, AttackDamage, GetController(), this, nullptr);   
			HitBoxCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
	}
}

void AEnemy_Siren::StartReinforce()
{
	if (bIsCoolingDown || bIsDead) return;

	bIsCoolingDown = true;
	bIsReinforcing = true;  // 증원 중 플래그
	ReinforceLocation = GetActorLocation();
	ReinforceStartTime = GetWorld()->GetTimeSeconds();


	// 연기 나이아가라
	if (ReinforceFX)
	{
		SpawnedReinforceFX = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ReinforceFX, ReinforceLocation);
	}

	// 일정 시간 동안 반복 스폰 타이머 시작
	GetWorldTimerManager().SetTimer(
		SpawnTimerHandle, 
		this, 
		&AEnemy_Siren::SpawnWave, 
		SpawnInterval,
		true, 
		7.0f
	);

	// 50초 후 증원 종료 타이머
	GetWorldTimerManager().SetTimer(ReinforceTimerHandle, this, &AEnemy_Siren::StopReinforce, ReinforceDuration, false);

	// 3분 쿨타임 타이머
	GetWorldTimerManager().SetTimer(
		CooldownTimerHandle, 
		this, 
		&AEnemy_Siren::ResetCooldown, 
		ReinforceCooldown, 
		false
	);
}

void AEnemy_Siren::SpawnWave()
{
    if (!PoolManager) return;

    // 플레이어 위치 가져오기
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (!PlayerPawn) return;
    
    FVector PlayerLoc = PlayerPawn->GetActorLocation();
    UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());

    for (const FReinforcementWave& Wave : WaveConfigs)
    {
       if (!Wave.EnemyClass) continue;
       
       int32 RandomSpawnCount = FMath::RandRange(Wave.MinSpawnCount, Wave.MaxSpawnCount);

       for (int32 i = 0; i < RandomSpawnCount; ++i)
       {
          // 기준 반경 이내 랜덤 스폰 위치
          FVector RandomOffset = FVector(FMath::RandRange(-800.f, 800.f), FMath::RandRange(-800.f, 800.f), 100.f);
          FVector SpawnLoc = ReinforceLocation + RandomOffset;
          FRotator SpawnRot = FRotator(0, FMath::RandRange(0.f, 360.f), 0);

          // 적 스폰
          AEnemyBase* SpawnedEnemy = PoolManager->AcquireEnemy(Wave.EnemyClass, SpawnLoc, SpawnRot);
          
          if (SpawnedEnemy)
          {
             // 캡슐 끼임 방지 (FindTeleportSpot)
             FVector SafeLocation = SpawnedEnemy->GetActorLocation();
             FRotator SafeRotation = SpawnedEnemy->GetActorRotation();

             if (GetWorld()->FindTeleportSpot(SpawnedEnemy, SafeLocation, SafeRotation))
             {
                SpawnedEnemy->SetActorLocation(SafeLocation, false, nullptr, ETeleportType::TeleportPhysics);
             }

             // 목적지 설정
             FVector ToPlayerDir = FVector(FMath::RandRange(-1.f, 1.f), FMath::RandRange(-1.f, 1.f), 0).GetSafeNormal();
             
             // 사이렌 증원군은 좀 더 플레이어에게 가깝게 붙도록 설정
             float RandomDist = FMath::FRandRange(500.f, 1500.f); 
             FVector RawTarget = PlayerLoc + (ToPlayerDir * RandomDist);
             
             FNavLocation ProjectedLocation;
             if (NavSys && NavSys->ProjectPointToNavigation(RawTarget, ProjectedLocation, FVector(500.f, 500.f, 500.f)))
             {
                SpawnedEnemy->TargetPatrolLocation = ProjectedLocation.Location;
             }
             else
             {
                // 네비메시 실패 시 플레이어 발밑으로 설정
                SpawnedEnemy->TargetPatrolLocation = PlayerLoc;
             }
          }
       }
    }
}

void AEnemy_Siren::StopReinforce()
{
	GetWorldTimerManager().ClearTimer(SpawnTimerHandle);
	
	// 나이아가라 완전히 제거
	if (SpawnedReinforceFX)
	{		
		SpawnedReinforceFX->DeactivateImmediate();
		SpawnedReinforceFX->DestroyComponent();
		SpawnedReinforceFX = nullptr;
	}	
}

void AEnemy_Siren::ResetCooldown()
{
	bIsCoolingDown = false;
}

void AEnemy_Siren::CleanupReinforcement()
{
	// 모든 증원 관련 타이머 정리
	GetWorldTimerManager().ClearTimer(SpawnTimerHandle);
	GetWorldTimerManager().ClearTimer(ReinforceTimerHandle);
	GetWorldTimerManager().ClearTimer(CooldownTimerHandle);
	
	// 나이아가라 이펙트 완전히 제거
	if (SpawnedReinforceFX)
	{
		SpawnedReinforceFX->DeactivateImmediate();
		SpawnedReinforceFX->DestroyComponent();
		SpawnedReinforceFX = nullptr;
	}
}

void AEnemy_Siren::Die()
{	
	// 증원 중이었는지 체크 & 남은 시간 계산
	if (bIsReinforcing)
	{
		float CurrentTime = GetWorld()->GetTimeSeconds();
		float ElapsedTime = CurrentTime - ReinforceStartTime;
		float RemainingSpawnTime = ReinforceDuration - ElapsedTime;
		float RemainingCooldownTime = ReinforceCooldown - ElapsedTime;
		
		// 부모 Die 호출 (여기서 ClearAllTimers)
		Super::Die();
		
		// 타이머 재설정 (남은 시간만큼)
		if (RemainingSpawnTime > 0)
		{
			// SpawnWave 타이머 재설정
			float NextSpawnDelay = SpawnInterval - FMath::Fmod(ElapsedTime - 7.0f, SpawnInterval);
			if (NextSpawnDelay > 0 && NextSpawnDelay <= SpawnInterval)
			{
				GetWorldTimerManager().SetTimer(
					SpawnTimerHandle,
					this,
					&AEnemy_Siren::SpawnWave,
					SpawnInterval,
					true,
					NextSpawnDelay
				);
			}
			
			// StopReinforce 타이머 재설정
			GetWorldTimerManager().SetTimer(
				ReinforceTimerHandle,
				this,
				&AEnemy_Siren::StopReinforce,
				RemainingSpawnTime,
				false
			);
		}
		
		// 쿨타임 타이머 재설정
		if (RemainingCooldownTime > 0)
		{
			GetWorldTimerManager().SetTimer(
				CooldownTimerHandle,
				this,
				&AEnemy_Siren::ResetCooldown,
				RemainingCooldownTime,
				false
			);
		}
	}
	else
	{
		// 증원 중이 아니면 그냥 부모 Die 호출
		Super::Die();
	}
}

void AEnemy_Siren::ForceDespawn()
{
	// 증원 중이었는지 체크 & 남은 시간 계산
	if (bIsReinforcing)
	{
		float CurrentTime = GetWorld()->GetTimeSeconds();
		float ElapsedTime = CurrentTime - ReinforceStartTime;
		float RemainingSpawnTime = ReinforceDuration - ElapsedTime;
		float RemainingCooldownTime = ReinforceCooldown - ElapsedTime;
		
		// 부모 ForceDespawn 호출
		Super::ForceDespawn();
		
		// 타이머 재설정 (남은 시간만큼)
		if (RemainingSpawnTime > 0)
		{
			// SpawnWave 타이머 재설정
			float NextSpawnDelay = SpawnInterval - FMath::Fmod(ElapsedTime - 7.0f, SpawnInterval);
			if (NextSpawnDelay > 0 && NextSpawnDelay <= SpawnInterval)
			{
				GetWorldTimerManager().SetTimer(
					SpawnTimerHandle,
					this,
					&AEnemy_Siren::SpawnWave,
					SpawnInterval,
					true,
					NextSpawnDelay
				);
			}
			
			// StopReinforce 타이머 재설정
			GetWorldTimerManager().SetTimer(
				ReinforceTimerHandle,
				this,
				&AEnemy_Siren::StopReinforce,
				RemainingSpawnTime,
				false
			);
		}
		
		// 쿨타임 타이머 재설정
		if (RemainingCooldownTime > 0)
		{
			GetWorldTimerManager().SetTimer(
				CooldownTimerHandle,
				this,
				&AEnemy_Siren::ResetCooldown,
				RemainingCooldownTime,
				false
			);
		}
	}
	else
	{
		// 증원 중이 아니면 그냥 부모 ForceDespawn 호출
		Super::ForceDespawn();
	}
}