#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "BackgroundEagleSpawner.generated.h"

UCLASS()
class PROJECTHD_API ABackgroundEagleSpawner : public AActor
{
	GENERATED_BODY()

public:
	ABackgroundEagleSpawner();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UArrowComponent* ArrowComp;

	// 스폰할 이글 클래스 (배경용 BP 할당)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	TSubclassOf<class AEagle> EagleClass;

	// 스폰 간격 (초)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	float SpawnIntervalMin = 20.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	float SpawnIntervalMax = 60.0f;

	// 비행 반경 (스포너 중심에서 시작/끝 거리)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	float FlightRadius = 350000.0f;

	// 비행 시간
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	float FlightDuration = 8.0f;

	// 전방 기준 원뿔 반각 (도)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	float ConeHalfAngle = 15.0f;

private:
	FTimerHandle SpawnTimerHandle;

	void SpawnEagle();
	void ScheduleNextSpawn();
};
