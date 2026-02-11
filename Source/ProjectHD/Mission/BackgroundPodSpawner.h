#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BackgroundPodSpawner.generated.h"

UCLASS()
class PROJECTHD_API ABackgroundPodSpawner : public AActor
{
	GENERATED_BODY()

public:
	ABackgroundPodSpawner();

protected:
	virtual void BeginPlay() override;

	// 스폰 간격 (초)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	float SpawnIntervalMin = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	float SpawnIntervalMax = 30.0f;

	// 포드 자동 파괴 시간 (초)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	float PodLifetime = 15.0f;

	// 스폰할 포드 클래스 (기본: ACinematicPod, BP 교체 가능)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	TSubclassOf<AActor> PodClass;

private:
	FTimerHandle SpawnTimerHandle;

	void SpawnPod();
	void ScheduleNextSpawn();
};
