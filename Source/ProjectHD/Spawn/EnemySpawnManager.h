#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawnManager.generated.h"

UCLASS()
class PROJECTHD_API AEnemySpawnManager : public AActor
{
	GENERATED_BODY()
    
public:
	AEnemySpawnManager();

	UPROPERTY(EditAnywhere, Category = "Patrol")
	float PatrolSpawnInterval = 30.0f; // 30초마다 정찰대

	UPROPERTY(EditAnywhere, Category = "Patrol")
	float PatrolSpawnDistance = 3000.0f; // 플레이어로부터 거리

	UPROPERTY(EditAnywhere, Category = "Patrol")
	TArray<TSubclassOf<class AEnemyBase>> PatrolEnemyTypes;

	UPROPERTY(EditAnywhere, Category = "Patrol")
	int32 PatrolSquadSize = 3; // 정찰대 크기

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

	// 미션 지역 유지
	void MaintainMissionZones();

	// 정찰대 스폰
	void SpawnPatrolSquad();

	// 플레이어 위치 가져오기
	FVector GetPlayerLocation() const;
};