#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "FPSCharacter.generated.h"

class AHDProjectile;
class UNiagaraSystem;

// 1. 방향 열거형
UENUM(BlueprintType)
enum class EStratagemDirection : uint8
{
    None, Up, Down, Left, Right
};

// 2. 타입 열거형 (구조체에서 사용해야 하므로 구조체보다 위에 있어야 합니다)
UENUM(BlueprintType)
enum class EStratagemType : uint8
{
    Bomb500kg,
    Supply
};

// 3. 스트라타젬 데이터 구조체
USTRUCT(BlueprintType)
struct FStratagemData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<EStratagemDirection> Command;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLinearColor BeaconColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EStratagemType Type;
};

// 4. 델리게이트 선언 (구조체와 열거형 정의가 끝난 후 선언)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAmmoChangedSignature, int32, NewAmmo, int32, NewMag, int32, MaxMag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHitEnemySignature, bool, bIsHeadshot);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStratagemStepUpdated, int32, NewStep);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStratagemUpdate, int32, StratagemIndex, int32, CurrentStep);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStratagemStackUpdated, const TArray<EStratagemDirection>&, InputStack);

UCLASS()
class PROJECTHD_API AFPSCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AFPSCharacter();

protected:
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    /* 입력 처리 함수들 */
    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);

    void OnFireStarted();
    void OnFireCompleted();
    void ResetRotationMode();
    void StartFiring();
    void StopFiring();
    void Reload();

    void OnStratagemMenuAction(const struct FInputActionValue& Value);
    void OnStratagemInputAction(const struct FInputActionValue& Value);

    // 이동 속도 관련
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float NormalWalkSpeed = 600.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float AimWalkSpeed = 400.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float ReloadWalkSpeed = 350.0f;

    UFUNCTION(BlueprintCallable, Category = "Combat")
    void FinishReload();

    bool bIsReloading = false;

    UFUNCTION(BlueprintNativeEvent, Category = "Combat")
    void OnAimStarted();
    virtual void OnAimStarted_Implementation();

    UFUNCTION(BlueprintNativeEvent, Category = "Combat")
    void OnAimCompleted();
    virtual void OnAimCompleted_Implementation();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
    bool bIsAiming = false;

    FTimerHandle TimerHandle_RotationReset;

    UPROPERTY(EditAnywhere, Category = "Combat")
    float AimRotationRecoveryTime = 0.3f;

    UFUNCTION(BlueprintCallable, Category = "Combat")
    void FireWeapon();

    FTimerHandle TimerHandle_AutomaticFire;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float FireRate = 10.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float RecoilPitch = 0.1f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float RecoilYaw = 0.03f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    TSubclassOf<class UCameraShakeBase> FireCameraShakeClass;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
    TSubclassOf<class UUserWidget> MainHUDWidgetClass;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
    class UUserWidget* MainHUDWidget;

    UPROPERTY(EditDefaultsOnly, Category = "Combat")
    TSubclassOf<AHDProjectile> ProjectileClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    UNiagaraSystem* MuzzleFlashFX;

    // 탄약 시스템
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    int32 MaxAmmoInMag = 30;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    int32 CurrentAmmo = 30;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    int32 CurrentMagCount = 8;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    int32 MaxMagCount = 8;

    FTimerHandle TimerHandle_Reload;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
    class UAnimMontage* ReloadMontage;

    UPROPERTY(BlueprintReadOnly, Category = "Animation")
    float AimPitch;

    void UpdateAimOffset(float DeltaTime);

    bool bAimButtonDown = false;
    bool bFireButtonDown = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    class USoundBase* FireSound;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    class USoundBase* ReloadSound;

    // ----------------스트라타젬---------------------
    UPROPERTY(EditAnywhere, Category = "Stratagem")
    TSubclassOf<class AStratagemBeacon> BeaconClass;

    void ThrowBeacon(); // 기존 ThrowBeacon에서 이름 변경 권장

    UPROPERTY(EditAnywhere, Category = "Stratagem")
    float ThrowForce = 3000.0f;

    int32 CurrentCommandStep = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stratagem")
    bool bIsSelectingStratagem = false;

    bool bIsStratagemReady = false;

    // 중복 및 이름 오류 수정: StratagemList는 FStratagemData 타입을 사용합니다.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stratagem")
    TArray<FStratagemData> StratagemList;

    int32 ActiveStratagemIndex = 0;

    TArray<EStratagemDirection> CurrentInputStack;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    class USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    class UCameraComponent* ThirdPersonCamera;

    // 입력 시스템
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputMappingContext* DefaultMappingContext;
    UPROPERTY(EditAnywhere, Category = "Input")
    class UInputMappingContext* StratagemMappingContext;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* MoveAction;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* LookAction;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* JumpAction;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* FireAction;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* AimAction;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* ReloadAction;
    UPROPERTY(EditAnywhere, Category = "Input")
    class UInputAction* StratagemMenuAction;
    UPROPERTY(EditAnywhere, Category = "Input")
    class UInputAction* StratagemInputAction;

    // 이벤트 델리게이트
    UPROPERTY(BlueprintAssignable, Category = "Stratagem")
    FOnStratagemStepUpdated OnStratagemStepUpdated;
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnAmmoChangedSignature OnAmmoChanged;
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnHitEnemySignature OnHitEnemy;
    UPROPERTY(BlueprintAssignable, Category = "Stratagem")
    FOnStratagemUpdate OnStratagemUpdate;
    UPROPERTY(BlueprintAssignable, Category = "Stratagem")
    FOnStratagemStackUpdated OnStratagemStackUpdated;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    float MouseSensitivity = 0.3f;

protected:
    UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
    class USkeletalMeshComponent* WeaponMesh;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float FireRange = 10000.0f;
};