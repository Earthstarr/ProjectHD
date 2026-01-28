#include "EggDestructionMission.h"
#include "ProjectHD/Character/Enemy/EggActor.h"
#include "Kismet/GameplayStatics.h"

AEggDestructionMission::AEggDestructionMission()
{
	MissionName = FText::FromString("Destroy Eggs");
	MissionDescription = FText::FromString("Destroy all bug eggs");
    
	TotalEggs = 0;
	DestroyedEggs = 0;
}

void AEggDestructionMission::BeginPlay()
{
	Super::BeginPlay();

	// 월드에서 EggActor 자동 찾기
	if (EggsToDestroy.Num() == 0)
	{
		TArray<AActor*> FoundEggs;
		UGameplayStatics::GetAllActorsOfClass(this, AEggActor::StaticClass(), FoundEggs);
        
		for (AActor* Actor : FoundEggs)
		{
			if (AEggActor* Egg = Cast<AEggActor>(Actor))
			{
				// 이 미션에 속한 알만 (태그로 구분 가능)
				if (Egg->ActorHasTag(FName(*GetName())))
				{
					EggsToDestroy.Add(Egg);
				}
			}
		}
	}

	TotalEggs = EggsToDestroy.Num();

	// 각 알의 파괴 이벤트 구독
	for (AEggActor* Egg : EggsToDestroy)
	{
		if (Egg)
		{
			Egg->OnEggDestroyed.AddDynamic(this, &AEggDestructionMission::OnEggDestroyed);
		}
	}

	StartMission();
}

void AEggDestructionMission::OnEggDestroyed(AEggActor* DestroyedEgg)
{
	DestroyedEggs++;
	CheckMissionCompletion();
}

void AEggDestructionMission::CheckMissionCompletion()
{
	if (DestroyedEggs >= TotalEggs)
	{
		CompleteMission();
	}
}