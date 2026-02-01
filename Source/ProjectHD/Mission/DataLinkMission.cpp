#include "DataLinkMission.h"
#include "DataLinkTerminal.h"

ADataLinkMission::ADataLinkMission()
{
	MissionName = FText::FromString(TEXT("Data Link"));
	MissionDescription = FText::FromString(TEXT("Activate and defend the data link terminal."));
}

void ADataLinkMission::BeginPlay()
{
	Super::BeginPlay();

	// 터미널 완료 이벤트 바인딩
	if (LinkedTerminal)
	{
		LinkedTerminal->OnDataLinkCompleted.AddDynamic(this, &ADataLinkMission::OnTerminalCompleted);
	}

	// 미션 시작
	StartMission();
}

void ADataLinkMission::OnTerminalCompleted()
{
	CompleteMission();
}
