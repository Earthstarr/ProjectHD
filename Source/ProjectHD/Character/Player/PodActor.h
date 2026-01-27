#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "PodActor.generated.h"

UCLASS()
class PROJECTHD_API APodActor : public AActor
{
	GENERATED_BODY()

public:
	APodActor();
	
	FORCEINLINE class UStaticMeshComponent* GetInternalElevatorMesh() const { return InternalElevatorMesh; }
	FORCEINLINE USceneComponent* GetCharacterAnchor() const { return CharacterAnchor; }

protected:
	virtual void BeginPlay() override;
	virtual void Tick( float DeltaTime ) override;

	// 포드 몸체 메쉬
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* PodMesh;

	// 캐릭터가 서 있을 내부 발판 혹은 캐릭터가 올라올 메쉬
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* InternalElevatorMesh;
	
	// 캐릭터가 실제로 붙을 위치
	UPROPERTY(VisibleAnywhere, Category = "Pod")
	class USceneComponent* CharacterAnchor;

	// 올라오는 연출을 위한 타임라인
	FTimeline RiseTimeline;

	UPROPERTY(EditAnywhere, Category = "Movement")
	class UCurveFloat* RiseCurve;

	UFUNCTION()
	void HandleRiseProgress(float Value);

	UFUNCTION()
	void OnPodLanded();

	// 착지 감지를 위한 라인트레이스 혹은 OnHit
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

private:
	bool bLanded = false;
	
	void OnRiseFinished();
};