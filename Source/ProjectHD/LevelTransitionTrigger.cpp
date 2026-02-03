#include "LevelTransitionTrigger.h"
#include "HDGameInstance.h"
#include "Character/Player/FPSCharacter.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"

ALevelTransitionTrigger::ALevelTransitionTrigger()
{
	PrimaryActorTick.bCanEverTick = false;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	RootComponent = TriggerBox;

	TriggerBox->SetBoxExtent(FVector(200.f, 200.f, 100.f));
	TriggerBox->SetCollisionProfileName(TEXT("Trigger"));
	TriggerBox->SetGenerateOverlapEvents(true);
}

void ALevelTransitionTrigger::BeginPlay()
{
	Super::BeginPlay();

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ALevelTransitionTrigger::OnOverlapBegin);
}

void ALevelTransitionTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	AFPSCharacter* Player = Cast<AFPSCharacter>(OtherActor);
	if (!Player) return;

	// GameInstance에 POD 스폰 플래그 설정
	UHDGameInstance* GI = Cast<UHDGameInstance>(UGameplayStatics::GetGameInstance(this));
	if (GI)
	{
		GI->bShouldSpawnWithPod = true;
	}

	// 레벨 전환
	if (!TargetLevelName.IsNone())
	{
		UGameplayStatics::OpenLevel(this, TargetLevelName);
	}
}
