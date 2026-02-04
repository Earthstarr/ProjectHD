#include "MissionManager.h"
#include "MissionBase.h"
#include "Kismet/GameplayStatics.h"

AMissionManager::AMissionManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMissionManager::BeginPlay()
{
	Super::BeginPlay();
}

void AMissionManager::RegisterMission(AMissionBase* Mission)
{
	if (Mission && !RegisteredMissions.Contains(Mission))
	{
		RegisteredMissions.Add(Mission);
		Mission->OnMissionStatusChanged.AddDynamic(this, &AMissionManager::OnMissionStatusChanged);
        
		// HUD 위젯이 WBP_MissionItem을 생성
		OnMissionRegistered.Broadcast(Mission);
	}
}

void AMissionManager::OnMissionStatusChanged(EMissionStatus NewStatus)
{
	if (NewStatus == EMissionStatus::Completed)
	{
		CheckAllMissionsCompleted();
	}
}

void AMissionManager::CheckAllMissionsCompleted()
{
	if (AreAllMissionsCompleted())
	{
		OnAllMissionsCompleted.Broadcast();
	}
}

bool AMissionManager::AreAllMissionsCompleted() const
{
	if (RegisteredMissions.Num() == 0)
	{
		return false;
	}

	for (AMissionBase* Mission : RegisteredMissions)
	{
		if (Mission && !Mission->IsCompleted())
		{
			return false;
		}
	}

	return true;
}

TArray<AMissionBase*> AMissionManager::GetActiveMissions() const
{
	TArray<AMissionBase*> ActiveMissions;

	for (AMissionBase* Mission : RegisteredMissions)
	{
		if (Mission && Mission->MissionStatus == EMissionStatus::InProgress)
		{
			ActiveMissions.Add(Mission);
		}
	}

	return ActiveMissions;
}

void AMissionManager::CompleteAllMissions()
{
	for (AMissionBase* Mission : RegisteredMissions)
	{
		if (Mission && !Mission->IsCompleted())
		{
			Mission->CompleteMission();
		}
	}
}