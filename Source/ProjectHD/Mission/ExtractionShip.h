#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExtractionShip.generated.h"

class AFPSCharacter;
class UNiagaraSystem;
class UNiagaraComponent;

UENUM(BlueprintType)
enum class EShipState : uint8
{
	Arriving,		// 전함에서 날아오는 중
	Landing,		// 착륙
	Waiting,		// 플레이어 대기 중
	Departing,		// 이륙
	Gone			// 떠남
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShipStateChanged, EShipState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerBoarded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShipDepartureCompleted);

UCLASS()
class PROJECTHD_API AExtractionShip : public AActor
{
	GENERATED_BODY()

public:
	AExtractionShip();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USceneComponent* ShipRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* ShipMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UBoxComponent* BoardingZone;

	// 엔진 이펙트 위치
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USceneComponent* EngineEffectPoint;


	// 상태
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ship")
	EShipState ShipState = EShipState::Arriving;

	// 비행 설정 - 절대 월드 좌표 (뷰포트에서 액터 위치 복사해서 붙여넣기)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Flight")
	FVector ArrivalLocation = FVector(5000.0f, 2000.0f, 8000.0f); // 쉽이 날아오는 시작 위치

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Flight")
	FVector DepartureLocation = FVector(3000.0f, 1000.0f, 10000.0f); // 쉽이 날아가는 목적지

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Flight")
	float ArrivalDuration = 8.0f; // 도착까지 걸리는 시간

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Flight")
	float LandingDuration = 3.0f; // 착륙 시간

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Flight")
	float DepartureDuration = 5.0f; // 이륙 시간

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Flight")
	float HoverHeight = 500.0f; // 착륙 전 호버링 높이


	// 목표 위치 (ExtractionTerminal에서 설정)
	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	FVector TargetLocation;

	// 비행 진행도
	float FlightAlpha = 0.0f;
	FVector FlightStartLocation;
	FVector FlightEndLocation;
	FRotator FlightStartRotation;
	FRotator FlightEndRotation;

	// 이펙트
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Effects")
	UNiagaraSystem* EngineEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Effects")
	UNiagaraSystem* ThrusterEffect;

	UPROPERTY()
	UNiagaraComponent* SpawnedEngineEffect;

	// 사운드
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Sound")
	class USoundBase* EngineSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Sound")
	class USoundBase* LandingSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Sound")
	class USoundBase* BoardingSound;

	UPROPERTY()
	class UAudioComponent* EngineSoundComponent;

	// 플레이어 탑승 처리
	UPROPERTY()
	AFPSCharacter* BoardedPlayer;


	// 오버랩 이벤트
	UFUNCTION()
	void HandleBoardingBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// 비행 상태 업데이트
	void UpdateArrival(float DeltaTime);
	void UpdateLanding(float DeltaTime);
	void UpdateDeparture(float DeltaTime);

	// 상태 전환
	void StartLanding();
	void CompleteLanding();
	void StartDeparture();
	void CompleteDeparture();

	// Easing 함수
	float EaseInOutCubic(float t) const;

public:
	// 비행 시작 (ExtractionTerminal에서 호출)
	UFUNCTION(BlueprintCallable, Category = "Ship")
	void StartArrival(const FVector& Destination);

	// 델리게이트
	UPROPERTY(BlueprintAssignable, Category = "Ship")
	FOnShipStateChanged OnShipStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ship")
	FOnPlayerBoarded OnPlayerBoarded;

	UPROPERTY(BlueprintAssignable, Category = "Ship")
	FOnShipDepartureCompleted OnDepartureCompleted;

	// Getter
	UFUNCTION(BlueprintPure, Category = "Ship")
	EShipState GetShipState() const { return ShipState; }

	UFUNCTION(BlueprintPure, Category = "Ship")
	bool IsWaitingForPlayer() const { return ShipState == EShipState::Waiting; }

	// 블루프린트 이벤트 (컷씬 등 연출용)
	UFUNCTION(BlueprintImplementableEvent, Category = "Ship")
	void OnArrivalStarted();

	UFUNCTION(BlueprintImplementableEvent, Category = "Ship")
	void OnLandingStarted();

	UFUNCTION(BlueprintImplementableEvent, Category = "Ship")
	void OnLandingCompleted();

	UFUNCTION(BlueprintImplementableEvent, Category = "Ship")
	void OnPlayerBoardedShip();

	UFUNCTION(BlueprintImplementableEvent, Category = "Ship")
	void OnDepartureStarted();

	UFUNCTION(BlueprintImplementableEvent, Category = "Ship")
	void OnDepartureCompletedBP();
};
