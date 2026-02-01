#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectHD/SubtitleTypes.h"
#include "MissionBase.generated.h"

UENUM(BlueprintType)
enum class EMissionStatus : uint8
{
	NotStarted,
	InProgress,
	Completed,
	Failed
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMissionStatusChanged, EMissionStatus, NewStatus);

UCLASS(Abstract)
class PROJECTHD_API AMissionBase : public AActor
{
	GENERATED_BODY()
    
public:
	AMissionBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
	FText MissionName;	// 미션 이름
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
    class UTexture2D* MissionIcon;	// 미션 아이콘

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
	FText MissionDescription;

	UPROPERTY(BlueprintReadOnly, Category = "Mission")
	EMissionStatus MissionStatus;

	UPROPERTY(BlueprintAssignable, Category = "Mission")
	FOnMissionStatusChanged OnMissionStatusChanged;

	UFUNCTION(BlueprintCallable, Category = "Mission")
	virtual void StartMission();

	UFUNCTION(BlueprintCallable, Category = "Mission")
	virtual void CompleteMission();

	UFUNCTION(BlueprintCallable, Category = "Mission")
	virtual void FailMission();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
	int32 MissionIndex;

	UFUNCTION(BlueprintPure, Category = "Mission")
	bool IsCompleted() const { return MissionStatus == EMissionStatus::Completed; }

	// 미션 완료 시 사운드, 자막
	UPROPERTY(EditAnywhere, Category = "Mission|Sound")
	class USoundBase* MissionCompleteSound;

	UPROPERTY(EditAnywhere, Category = "Mission|Sound")
	FName MissionCompleteSubtitleKey;

	UPROPERTY(BlueprintAssignable, Category = "Mission|Sound")
	FOnSoundPlayedSignature OnSoundPlayed;	// 자막

protected:
	virtual void BeginPlay() override;
};