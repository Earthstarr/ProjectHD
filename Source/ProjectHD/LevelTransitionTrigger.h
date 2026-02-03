#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "LevelTransitionTrigger.generated.h"

UCLASS()
class PROJECTHD_API ALevelTransitionTrigger : public AActor
{
	GENERATED_BODY()

public:
	ALevelTransitionTrigger();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Trigger")
	UBoxComponent* TriggerBox;

	// 전환할 레벨 이름
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level")
	FName TargetLevelName;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);
};
