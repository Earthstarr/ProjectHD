#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectHD/InteractableInterface.h"
#include "ProjectHD/SubtitleTypes.h"
#include "DataLinkTerminal.generated.h"

class AFPSCharacter;
enum class EStratagemDirection : uint8;

UENUM(BlueprintType)
enum class EDataLinkTerminalState : uint8
{
	Idle,			// 대기 (E키로 상호작용 가능)
	InputPhase,		// 커맨드 입력 중
	Uploading,		// 게이지 진행 중
	Completed		// 완료
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDataLinkCompleted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDataLinkProgressChanged, float, CurrentProgress, float, MaxProgress);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDataLinkStateChanged, EDataLinkTerminalState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDataLinkInputUpdated, const TArray<EStratagemDirection>&, CurrentInput);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDataLinkArrowChanged, EStratagemDirection, CurrentArrow, int32, CurrentStep);

UCLASS()
class PROJECTHD_API ADataLinkTerminal : public AActor, public IInteractableInterface
{
	GENERATED_BODY()

public:
	ADataLinkTerminal();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* TerminalMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USphereComponent* InteractionSphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USphereComponent* ProgressZone;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UWidgetComponent* InteractionWidget;

	// 홀로그램 메쉬
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* HologramMesh;

	// 상태
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "DataLink")
	EDataLinkTerminalState TerminalState = EDataLinkTerminalState::Idle;

	// 입력 커맨드 설정
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataLink|Input")
	TArray<EStratagemDirection> RequiredCommand;

	// 현재 입력 스택
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "DataLink|Input")
	TArray<EStratagemDirection> CurrentInputStack;

	// 업로드 설정
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataLink|Upload")
	float UploadDuration = 60.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "DataLink|Upload")
	float CurrentProgress = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataLink|Upload")
	float ProgressZoneRadius = 5000.0f;

	// 플레이어 참조
	UPROPERTY()
	AFPSCharacter* InteractingPlayer;

	// UI 위젯 클래스
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataLink|UI")
	TSubclassOf<class UUserWidget> ArrowWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataLink|UI")
	TSubclassOf<class UUserWidget> ProgressWidgetClass;

	// 생성된 위젯 인스턴스
	UPROPERTY()
	class UUserWidget* ArrowWidgetInstance;

	UPROPERTY()
	class UUserWidget* ProgressWidgetInstance;

	// 위젯 생성/제거
	void CreateArrowWidget();
	void RemoveArrowWidget();
	void CreateProgressWidget();
	void RemoveProgressWidget();

	// 사운드
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataLink|Sound")
	class USoundBase* InputSuccessSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataLink|Sound")
	class USoundBase* InputErrorSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataLink|Sound")
	class USoundBase* InputCompleteSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataLink|Sound")
	class USoundBase* UploadCompleteSound;

	// 자막 키
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataLink|Sound")
	FName UploadCompleteSubtitleKey;

	// 인터페이스
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
	void StartInputPhase();
	void CancelInputPhase();
	void StartUploading();
	void InterruptUpload();
	void CompleteUpload();

	// 진행도 업데이트
	void UpdateProgress(float DeltaTime);
	bool IsPlayerInProgressZone() const;

public:
	// 입력 처리 (FPSCharacter에서 호출)
	UFUNCTION(BlueprintCallable, Category = "DataLink")
	void ProcessDirectionInput(EStratagemDirection Direction);

	// 델리게이트
	UPROPERTY(BlueprintAssignable, Category = "DataLink")
	FOnDataLinkCompleted OnDataLinkCompleted;

	UPROPERTY(BlueprintAssignable, Category = "DataLink")
	FOnDataLinkProgressChanged OnDataLinkProgressChanged;

	UPROPERTY(BlueprintAssignable, Category = "DataLink")
	FOnDataLinkStateChanged OnDataLinkStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "DataLink")
	FOnDataLinkInputUpdated OnDataLinkInputUpdated;

	// 현재 입력해야 할 화살표 변경 시 (UI용)
	UPROPERTY(BlueprintAssignable, Category = "DataLink")
	FOnDataLinkArrowChanged OnDataLinkArrowChanged;

	// 자막 출력용
	UPROPERTY(BlueprintAssignable, Category = "DataLink|Sound")
	FOnSoundPlayedSignature OnSoundPlayed;

	// Getter
	UFUNCTION(BlueprintPure, Category = "DataLink")
	EDataLinkTerminalState GetTerminalState() const { return TerminalState; }

	UFUNCTION(BlueprintPure, Category = "DataLink")
	float GetProgressPercent() const { return UploadDuration > 0.0f ? CurrentProgress / UploadDuration : 0.0f; }

	UFUNCTION(BlueprintPure, Category = "DataLink")
	const TArray<EStratagemDirection>& GetRequiredCommand() const { return RequiredCommand; }

	UFUNCTION(BlueprintPure, Category = "DataLink")
	const TArray<EStratagemDirection>& GetCurrentInput() const { return CurrentInputStack; }

	UFUNCTION(BlueprintPure, Category = "DataLink")
	int32 GetTotalSteps() const { return RequiredCommand.Num(); }
};
