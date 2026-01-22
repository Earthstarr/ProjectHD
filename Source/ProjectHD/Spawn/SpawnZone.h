#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnZone.generated.h"

UENUM(BlueprintType)
enum class ESpawnZoneType : uint8
{
	MissionArea,    // 미션 지역 (처음 한번만 스폰)
	PatrolRoute     // 정찰대 루트
};

// 적 종류별 스폰 정보 구조체
USTRUCT(BlueprintType)
struct FEnemySpawnInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	TSubclassOf<class AEnemyBase> EnemyClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn", meta = (ClampMin = "0"))
	int32 MinCount = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn", meta = (ClampMin = "0"))
	int32 MaxCount = 3;

	FEnemySpawnInfo()
		: EnemyClass(nullptr), MinCount(1), MaxCount(3)
	{}
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
	TArray<FEnemySpawnInfo> EnemyTypes;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	float SpawnRadius = 1000.0f;

	// 스폰 실행 (처음 한번만)
	void SpawnEnemies(class AEnemyPoolManager* PoolManager);

	// 랜덤 위치 반환
	FVector GetRandomSpawnLocation() const;

protected:
	virtual void BeginPlay() override;

private:
	// 이미 스폰했는지 체크
	bool bHasSpawned = false;
};