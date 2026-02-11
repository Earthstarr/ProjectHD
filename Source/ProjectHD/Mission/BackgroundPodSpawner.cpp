#include "BackgroundPodSpawner.h"
#include "CinematicPod.h"

ABackgroundPodSpawner::ABackgroundPodSpawner()
{
	PrimaryActorTick.bCanEverTick = false;
	PodClass = ACinematicPod::StaticClass();
}

void ABackgroundPodSpawner::BeginPlay()
{
	Super::BeginPlay();
	ScheduleNextSpawn();
}

void ABackgroundPodSpawner::ScheduleNextSpawn()
{
	float Delay = FMath::RandRange(SpawnIntervalMin, SpawnIntervalMax);
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ABackgroundPodSpawner::SpawnPod, Delay, false);
}

void ABackgroundPodSpawner::SpawnPod()
{
	if (PodClass)
	{
		FActorSpawnParameters Params;
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		AActor* Pod = GetWorld()->SpawnActor<AActor>(PodClass, GetActorLocation(), GetActorRotation(), Params);
		if (Pod)
		{
			Pod->SetLifeSpan(PodLifetime);
		}
	}

	ScheduleNextSpawn();
}
