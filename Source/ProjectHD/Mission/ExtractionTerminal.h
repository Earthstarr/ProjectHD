#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectHD/InteractableInterface.h"
#include "ExtractionTerminal.generated.h"

class AFPSCharacter;
class AMissionManager;
class UNiagaraSystem;
class UNiagaraComponent;
class AExtractionShip;
enum class EStratagemDirection : uint8;

UENUM(BlueprintType)
enum class EExtractionState : uint8
{
	Inactive,		// 미션 미완료 - 비활성
	Ready,			// 모든 미션 완료 - 빛기둥 표시, 상호작용 가능
	InputPhase,		// 커맨드 입력 중
	Defending,		// 방어전 진행 중 (3분 타이머)
	Completed		// 탈출 완료
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnExtractionStateChanged, EExtractionState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDefenseTimerUpdated, float, RemainingTime, float, TotalTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnExtractionCompleted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnExtractionInputUpdated, const TArray<EStratagemDirection>&, CurrentInput);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnExtractionArrowChanged, EStratagemDirection, CurrentArrow, int32, CurrentStep);

UCLASS()
class PROJECTHD_API AExtractionTerminal : public AActor, public IInteractableInterface
{
	GENERATED_BODY()

public:
	AExtractionTerminal();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* TerminalMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USphereComponent* InteractionSphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UWidgetComponent* InteractionWidget;

	// 상태
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Extraction")
	EExtractionState ExtractionState = EExtractionState::Inactive;

	// 방어전 시간 설정
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extraction")
	float DefenseTime = 150.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Extraction")
	float RemainingDefenseTime = 0.0f;

	// 입력 커맨드 설정
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extraction|Input")
	TArray<EStratagemDirection> RequiredCommand;

	// 현재 입력 스택
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Extraction|Input")
	TArray<EStratagemDirection> CurrentInputStack;

	// 플레이어 참조
	UPROPERTY()
	AFPSCharacter* InteractingPlayer;

	// 미션 매니저 참조
	UPROPERTY()
	AMissionManager* MissionManager;

	// 빛기둥 이펙트
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extraction|Effects")
	UNiagaraSystem* BeamEffect;

	UPROPERTY()
	UNiagaraComponent* SpawnedBeam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extraction|Effects")
	FLinearColor BeamColor = FLinearColor(0.0f, 1.0f, 0.5f, 1.0f); // 초록색

	// UI 위젯 클래스
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extraction|UI")
	TSubclassOf<class UUserWidget> ArrowWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extraction|UI")
	TSubclassOf<class UUserWidget> TimerWidgetClass;

	UPROPERTY()
	class UUserWidget* ArrowWidgetInstance;

	UPROPERTY()
	class UUserWidget* TimerWidgetInstance;

	// 사운드
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extraction|Sound")
	class USoundBase* ActivationSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extraction|Sound")
	class USoundBase* InputSuccessSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extraction|Sound")
	class USoundBase* InputErrorSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extraction|Sound")
	class USoundBase* InputCompleteSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extraction|Sound")
	class USoundBase* DefenseStartSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extraction|Sound")
	class USoundBase* ExtractionCompleteSound;

	// 수송선 설정
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extraction|Ship")
	TSubclassOf<AExtractionShip> ExtractionShipClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Extraction|Ship")
	FVector ShipLandingOffset = FVector(500.0f, 0.0f, 0.0f); // 터미널 기준 착륙 위치

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Extraction|Ship")
	AExtractionShip* SpawnedShip;

	// IInteractableInterface 구현
	virtual void Interact(AFPSCharacter* Interactor) override;
	virtual void OnOverlapBegin() override;
	virtual void OnOverlapEnd() override;

	// 오버랩 이벤트
	UFUNCTION()
	void HandleInteractionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void HandleInteractionEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// 상태 전환 함수
	void ActivateTerminal();
	void StartInputPhase();
	void CancelInputPhase();
	void StartDefense();
	void CompleteExtraction();

	// 빛기둥 생성/제거
	void SpawnBeamEffect();
	void RemoveBeamEffect();

	// 위젯 생성/제거
	void CreateArrowWidget();
	void RemoveArrowWidget();
	void CreateTimerWidget();
	void RemoveTimerWidget();

	// 미션 완료 콜백
	UFUNCTION()
	void OnAllMissionsCompleted();

	// 수송선 스폰
	void SpawnExtractionShip();

	// 수송선 이벤트 콜백
	UFUNCTION()
	void OnShipDepartureCompleted();

public:
	// 입력 처리 (FPSCharacter에서 호출)
	UFUNCTION(BlueprintCallable, Category = "Extraction")
	void ProcessDirectionInput(EStratagemDirection Direction);

	// 델리게이트
	UPROPERTY(BlueprintAssignable, Category = "Extraction")
	FOnExtractionStateChanged OnExtractionStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "Extraction")
	FOnDefenseTimerUpdated OnDefenseTimerUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Extraction")
	FOnExtractionCompleted OnExtractionCompleted;

	UPROPERTY(BlueprintAssignable, Category = "Extraction")
	FOnExtractionInputUpdated OnExtractionInputUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Extraction")
	FOnExtractionArrowChanged OnExtractionArrowChanged;

	// Getter
	UFUNCTION(BlueprintPure, Category = "Extraction")
	EExtractionState GetExtractionState() const { return ExtractionState; }

	UFUNCTION(BlueprintPure, Category = "Extraction")
	float GetRemainingTime() const { return RemainingDefenseTime; }

	UFUNCTION(BlueprintPure, Category = "Extraction")
	float GetTotalDefenseTime() const { return DefenseTime; }

	UFUNCTION(BlueprintPure, Category = "Extraction")
	float GetProgressPercent() const { return DefenseTime > 0.0f ? (DefenseTime - RemainingDefenseTime) / DefenseTime : 0.0f; }

	UFUNCTION(BlueprintPure, Category = "Extraction")
	const TArray<EStratagemDirection>& GetRequiredCommand() const { return RequiredCommand; }

	UFUNCTION(BlueprintPure, Category = "Extraction")
	const TArray<EStratagemDirection>& GetCurrentInput() const { return CurrentInputStack; }

	UFUNCTION(BlueprintPure, Category = "Extraction")
	int32 GetTotalSteps() const { return RequiredCommand.Num(); }
};
