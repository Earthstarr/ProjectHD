#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawnManager.generated.h"

// 적 종류별 스폰 정보 구조체
USTRUCT(BlueprintType)
struct FPatrolEnemySpawnInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	TSubclassOf<class AEnemyBase> EnemyClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	int32 SpawnCount = 1;

	FPatrolEnemySpawnInfo()
		: EnemyClass(nullptr), SpawnCount(1)
	{}
};

UCLASS()
class PROJECTHD_API AEnemySpawnManager : public AActor
{
	GENERATED_BODY()
    
public:
	AEnemySpawnManager();

	UPROPERTY(EditAnywhere, Category = "Patrol")
	float PatrolSpawnInterval = 30.0f; // 30초마다 정찰대

	UPROPERTY(EditAnywhere, Category = "Patrol")
	float PatrolSpawnDistance = 8000.0f; // 플레이어로부터 거리

	UPROPERTY(EditAnywhere, Category = "Patrol")
	TArray<FPatrolEnemySpawnInfo> PatrolEnemyTypes;


protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	class AEnemyPoolManager* PoolManager;

	UPROPERTY()
	TArray<class ASpawnZone*> MissionZones;

	FTimerHandle PatrolSpawnTimer;
	FTimerHandle MaintainTimer;
	FTimerHandle DespawnCheckTimer;
	
	// 정찰대 스폰
	void SpawnPatrolSquad();

	// 플레이어 위치 가져오기
	FVector GetPlayerLocation() const;
	
	// 플레이어와 이 거리 이상 멀어지면 풀로 반환
	UPROPERTY(EditAnywhere, Category = "Spawn")
	float DespawnDistance = 10000.0f; 

	// 거리 체크 주기
	UPROPERTY(EditAnywhere, Category = "Spawn")
	float DespawnCheckInterval = 2.0f;

	// 거리 체크 로직
	void CheckEnemyDistances();
};