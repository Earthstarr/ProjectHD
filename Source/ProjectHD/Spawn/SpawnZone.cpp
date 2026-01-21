
#include "ProjectHD/Spawn/SpawnZone.h"
#include "ProjectHD/Spawn/EnemyPoolManager.h"
#include "ProjectHD/Character/Enemy/EnemyBase.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

ASpawnZone::ASpawnZone()
{
 	
	PrimaryActorTick.bCanEverTick = false;

}

void ASpawnZone::BeginPlay()
{
	Super::BeginPlay();
	
}

FVector ASpawnZone::GetRandomSpawnLocation() const
{
	FVector RandomOffset = UKismetMathLibrary::RandomUnitVector() * FMath::RandRange(0.f, SpawnRadius);
	RandomOffset.Z = 0; // 수평만
	return GetActorLocation() + RandomOffset;
}

void ASpawnZone::SpawnEnemies(class AEnemyPoolManager* PoolManager)
{
	if (!PoolManager || EnemyTypes.Num() == 0) return;

	int32 SpawnCount = FMath::RandRange(MinEnemies, MaxEnemies);

	for (int32 i = 0; i < SpawnCount; ++i)
	{
		TSubclassOf<AEnemyBase> RandomClass = EnemyTypes[FMath::RandRange(0, EnemyTypes.Num() - 1)];
		FVector SpawnLoc = GetRandomSpawnLocation();
		FRotator SpawnRot = FRotator(0, FMath::RandRange(0.f, 360.f), 0);

		AEnemyBase* Enemy = PoolManager->AcquireEnemy(RandomClass, SpawnLoc, SpawnRot);
		if (Enemy)
		{
			SpawnedEnemies.Add(Enemy);
		}
	}
}

void ASpawnZone::MaintainEnemyCount(class AEnemyPoolManager* PoolManager)
{
	// 죽은 적 제거
	SpawnedEnemies.RemoveAll([](AEnemyBase* Enemy) {
		return !Enemy || Enemy->IsDead();
	});

	// 부족하면 리스폰
	int32 CurrentCount = SpawnedEnemies.Num();
	if (CurrentCount < MinEnemies)
	{
		int32 ToSpawn = FMath::RandRange(1, MaxEnemies - CurrentCount);
        
		for (int32 i = 0; i < ToSpawn; ++i)
		{
			TSubclassOf<AEnemyBase> RandomClass = EnemyTypes[FMath::RandRange(0, EnemyTypes.Num() - 1)];
			FVector SpawnLoc = GetRandomSpawnLocation();
			FRotator SpawnRot = FRotator(0, FMath::RandRange(0.f, 360.f), 0);

			AEnemyBase* Enemy = PoolManager->AcquireEnemy(RandomClass, SpawnLoc, SpawnRot);
			if (Enemy)
			{
				SpawnedEnemies.Add(Enemy);
			}
		}
	}
}




