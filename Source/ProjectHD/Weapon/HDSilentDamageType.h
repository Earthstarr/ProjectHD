#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"
#include "HDSilentDamageType.generated.h"

// 이 데미지 타입으로 적을 맞추면 소음을 퍼뜨리지 않음
UCLASS()
class PROJECTHD_API UHDSilentDamageType : public UDamageType
{
	GENERATED_BODY()
};
