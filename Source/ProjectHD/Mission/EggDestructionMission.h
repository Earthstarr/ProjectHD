#pragma once

#include "CoreMinimal.h"
#include "MissionBase.h"
#include "EggDestructionMission.generated.h"

UCLASS()
class PROJECTHD_API AEggDestructionMission : public AMissionBase
{
	GENERATED_BODY()
    
public:
	AEggDestructionMission();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
	TArray<class AEggActor*> EggsToDestroy;

	UPROPERTY(BlueprintReadOnly, Category = "Mission")
	int32 TotalEggs;

	UPROPERTY(BlueprintReadOnly, Category = "Mission")
	int32 DestroyedEggs;

	UFUNCTION()
	void OnEggDestroyed(AEggActor* DestroyedEgg);

protected:
	virtual void BeginPlay() override;
    
private:
	void CheckMissionCompletion();
};