#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnZone.generated.h"

UENUM(BlueprintType)
enum class ESpawnZoneType : uint8
{
	MissionArea,    // 미션 지역 (항상 유지)
	PatrolRoute     // 정찰대 루트
};

UCLASS()
class PROJECTHD_API ASpawnZone : public AActor
{
	GENERATED_BODY()
    
public:
	ASpawnZone();

	UPROPERTY(EditAnywhere, Category = "Spawn")
	ESpawnZoneType ZoneType;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	TArray<TSubclassOf<class AEnemyBase>> EnemyTypes;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	int32 MinEnemies = 3;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	int32 MaxEnemies = 8;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	float SpawnRadius = 1000.0f;

	// 현재 스폰된 적들
	UPROPERTY()
	TArray<AEnemyBase*> SpawnedEnemies;

	// 스폰 실행
	void SpawnEnemies(class AEnemyPoolManager* PoolManager);
    
	// 죽은 적 제거하고 부족하면 리스폰
	void MaintainEnemyCount(class AEnemyPoolManager* PoolManager);

	// 랜덤 위치 반환
	FVector GetRandomSpawnLocation() const;

protected:
	virtual void BeginPlay() override;
};