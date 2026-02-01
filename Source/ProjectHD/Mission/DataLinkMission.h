#pragma once

#include "CoreMinimal.h"
#include "MissionBase.h"
#include "DataLinkMission.generated.h"

class ADataLinkTerminal;

UCLASS()
class PROJECTHD_API ADataLinkMission : public AMissionBase
{
	GENERATED_BODY()

public:
	ADataLinkMission();

protected:
	virtual void BeginPlay() override;

	// 이 미션에 연결된 터미널
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "DataLink Mission")
	ADataLinkTerminal* LinkedTerminal;

	// 터미널 완료 콜백
	UFUNCTION()
	void OnTerminalCompleted();
};
