#include "MissionBase.h"
#include "MissionManager.h"
#include "Kismet/GameplayStatics.h"

AMissionBase::AMissionBase()
{
	PrimaryActorTick.bCanEverTick = false;
	MissionStatus = EMissionStatus::NotStarted;
}

void AMissionBase::BeginPlay()
{
	Super::BeginPlay();

	// MissionManager에 자동 등록
	if (AMissionManager* Manager = Cast<AMissionManager>(UGameplayStatics::GetActorOfClass(this, AMissionManager::StaticClass())))
	{
		Manager->RegisterMission(this);
	}
}

void AMissionBase::StartMission()
{
	if (MissionStatus == EMissionStatus::NotStarted)
	{
		MissionStatus = EMissionStatus::InProgress;
		OnMissionStatusChanged.Broadcast(MissionStatus);
	}
}

void AMissionBase::CompleteMission()
{
	if (MissionStatus != EMissionStatus::Completed)
	{
		MissionStatus = EMissionStatus::Completed;
		OnMissionStatusChanged.Broadcast(MissionStatus);

		// 미션 완료 사운드 및 자막
		if (MissionCompleteSound)
		{
			UGameplayStatics::PlaySound2D(this, MissionCompleteSound);
		}
		if (!MissionCompleteSubtitleKey.IsNone())
		{
			OnSoundPlayed.Broadcast(MissionCompleteSubtitleKey);
		}
	}
}

void AMissionBase::FailMission()
{
	if (MissionStatus != EMissionStatus::Failed)
	{
		MissionStatus = EMissionStatus::Failed;
		OnMissionStatusChanged.Broadcast(MissionStatus);
	}
}