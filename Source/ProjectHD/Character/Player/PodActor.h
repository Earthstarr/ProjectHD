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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundBase* FallingSound; // 낙하 사운드

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundBase* ImpactSound; // 착지 사운드

	// 낙하 중 조종 힘 (방향키로 이동)
	UPROPERTY(EditAnywhere, Category = "Movement")
	float PodSteerForce = 500000.f;

	FORCEINLINE class UStaticMeshComponent* GetInternalElevatorMesh() const { return InternalElevatorMesh; }
	FORCEINLINE USceneComponent* GetCharacterAnchor() const { return CharacterAnchor; }

protected:
	virtual void BeginPlay() override;
	virtual void Tick( float DeltaTime ) override;

	UFUNCTION()
	void HandleRiseProgress(float Value);

	UFUNCTION()
	void OnPodLanded();

	// 착지 감지를 위한 라인트레이스 혹은 OnHit
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	// 적 즉사 처리
	UFUNCTION()
	void OnPodOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnElevatorOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	bool bLanded = false;

	void OnRiseFinished();

	UPROPERTY()
	UAudioComponent* FallingSoundComponent;

	// 착지 시 카메라 붐 고정용
	FVector SavedBoomRelativeLocation;
	bool bCameraLocked = false;
	FVector CameraLockedWorldPos;  // 착지 순간 카메라 붐 월드 위치 (공중)

	// 카메라 보간용 (RiseTimeline 동기화)
	float BlendStartArmLength = 0.f;
	FVector BlendStartSocketOffset = FVector::ZeroVector;
	float BlendStartPitch = 0.f;
};
