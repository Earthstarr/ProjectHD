#pragma once

#include "CoreMinimal.h"
#include "SubtitleTypes.generated.h"

// 더미 구조체 (UCLASS/USTRUCT가 최소 하나는 있어야 .generated.h가 생성됨)
USTRUCT(BlueprintType)
struct FSubtitleDummy
{
	GENERATED_BODY()
};

// 델리게이트 선언은 USTRUCT 아래에
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSoundPlayedSignature, FName, SubtitleKey);