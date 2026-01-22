#include "ProjectHD/Spawn/SpawnZone.h"
#include "ProjectHD/Spawn/EnemyPoolManager.h"
#include "ProjectHD/Character/Enemy/EnemyBase.h"
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
	// 이미 스폰했으면 무시
	if (bHasSpawned)
	{
		return;
	}

	if (!PoolManager || EnemyTypes.Num() == 0) return;

	// 각 종류별로 지정된 수만큼 스폰
	for (const FEnemySpawnInfo& SpawnInfo : EnemyTypes)
	{
		if (!SpawnInfo.EnemyClass) continue;

		int32 SpawnCount = FMath::RandRange(SpawnInfo.MinCount, SpawnInfo.MaxCount);

		for (int32 i = 0; i < SpawnCount; ++i)
		{
			FVector SpawnLoc = GetRandomSpawnLocation();
			FRotator SpawnRot = FRotator(0, FMath::RandRange(0.f, 360.f), 0);

			AEnemyBase* Enemy = PoolManager->AcquireEnemy(SpawnInfo.EnemyClass, SpawnLoc, SpawnRot);
			
			// 미션 지역 생성적은 움직이지 않고 플레이어 거리와 상관없이 존재함
			if (Enemy)
			{
				Enemy->bIsIdle = true;
				Enemy->bIsMissionSpawned = true;
			}
		}
	}

	bHasSpawned = true;
}