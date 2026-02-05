#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CinematicPod.generated.h"

UCLASS()
class PROJECTHD_API ACinematicPod : public AActor
{
	GENERATED_BODY()

public:
	ACinematicPod();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void Destroyed() override;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* CubeMesh;

	// 나이아가라 궤적 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Effects")
	class UNiagaraComponent* TrailComponent;

	// 낙하 속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drop")
	float FallSpeed = 5000.0f;
};
