#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MissionManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAllMissionsCompleted);
// 미션 등록 시 알림을 위한 델리게이트
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMissionRegistered, AMissionBase*, NewMission);

UCLASS()
class PROJECTHD_API AMissionManager : public AActor
{
	GENERATED_BODY()
    
public:
	AMissionManager();

	UPROPERTY(BlueprintReadOnly, Category = "Mission")
	TArray<class AMissionBase*> RegisteredMissions;

	UPROPERTY(BlueprintAssignable, Category = "Mission")
	FOnAllMissionsCompleted OnAllMissionsCompleted;

	UFUNCTION(BlueprintCallable, Category = "Mission")
	void RegisterMission(AMissionBase* Mission);

	UFUNCTION(BlueprintPure, Category = "Mission")
	bool AreAllMissionsCompleted() const;

	UFUNCTION(BlueprintPure, Category = "Mission")
	TArray<AMissionBase*> GetActiveMissions() const;

	// 디버그용: 모든 미션 즉시 완료
	UFUNCTION(BlueprintCallable, Category = "Mission|Debug")
	void CompleteAllMissions();
	
	UPROPERTY(BlueprintAssignable, Category = "Mission")
	FOnMissionRegistered OnMissionRegistered;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnMissionStatusChanged(EMissionStatus NewStatus);
    
	void CheckAllMissionsCompleted();
};