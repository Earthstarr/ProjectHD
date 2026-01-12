#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableInterface.h"
#include "HDSupplyPod.generated.h"

UCLASS()
class PROJECTHD_API AHDSupplyPod : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	AHDSupplyPod();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// 루트: 땅에 박히는 본체
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* BodyMesh;

	// 위로 솟아오를 기둥 (BodyMesh 자식)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* PillarMesh;

	// 왼쪽 보급 상자 (PillarMesh 자식)
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UStaticMeshComponent* LeftSupplyMesh;

	// 오른쪽 보급 상자 (PillarMesh 자식)
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UStaticMeshComponent* RightSupplyMesh;
	
	// 상호작용 범위
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USphereComponent* InteractionSphere;
	
	// E - 재보급
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UWidgetComponent* InteractionWidget;

	// 남은 보급품 개수
	int32 RemainingSupplies = 2;

	// 애니메이션 완료 여부
	bool bIsDeployed = false;

	// 블루프린트에서 타임라인 연출을 하기 위한 이벤트
	UFUNCTION(BlueprintImplementableEvent)
	void StartDeploySequence();
	
	UFUNCTION(BlueprintImplementableEvent)
	void EndDeploySequence();
	
	// 보급 획득 사운드
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	class USoundBase* SupplyPickupSound;
	
	// 땅 충돌 사운드
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	class USoundBase* ImpactSound;

	// 인터페이스 함수 오버라이드
	virtual void Interact(AFPSCharacter* Interactor) override;
	virtual void OnOverlapBegin() override;
	virtual void OnOverlapEnd() override;
		
	// 실제 충돌 이벤트 함수
	UFUNCTION()
	void HandleSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void HandleSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};