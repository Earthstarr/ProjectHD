#include "BackgroundEagleSpawner.h"
#include "ProjectHD/Weapon/Stratagem/Eagle.h"

ABackgroundEagleSpawner::ABackgroundEagleSpawner()
{
	PrimaryActorTick.bCanEverTick = false;

	ArrowComp = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	RootComponent = ArrowComp;
	ArrowComp->ArrowSize = 3.0f;
}

void ABackgroundEagleSpawner::BeginPlay()
{
	Super::BeginPlay();
	ScheduleNextSpawn();
}

void ABackgroundEagleSpawner::ScheduleNextSpawn()
{
	float Delay = FMath::RandRange(SpawnIntervalMin, SpawnIntervalMax);
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ABackgroundEagleSpawner::SpawnEagle, Delay, false);
}

void ABackgroundEagleSpawner::SpawnEagle()
{
	if (EagleClass)
	{
		// 모래시계 범위: 전방 또는 후방 원뿔 내 랜덤 방향
		FVector Forward = GetActorForwardVector();
		if (FMath::RandBool())
		{
			Forward = -Forward;
		}
		FVector Direction = FMath::VRandCone(Forward, FMath::DegreesToRadians(ConeHalfAngle));
		Direction.Z = 0.0f;
		Direction.Normalize();

		FVector Center = GetActorLocation();
		FVector Start = Center - Direction * FlightRadius;
		FVector End = Center + Direction * FlightRadius;

		FActorSpawnParameters Params;
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		AEagle* Eagle = GetWorld()->SpawnActor<AEagle>(EagleClass, Start, FRotator::ZeroRotator, Params);
		if (Eagle)
		{
			// 비행 방향에 수직인 랜덤 곡선 축
			FVector FlightDir = Direction;
			FVector RandomPerp = FMath::VRand();
			RandomPerp = (RandomPerp - FlightDir * FVector::DotProduct(RandomPerp, FlightDir)).GetSafeNormal();
			Eagle->SetCurveAxis(RandomPerp);

			Eagle->InitEagle(Start, End, FlightDuration);
		}
	}

	ScheduleNextSpawn();
}
