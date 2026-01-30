#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "AbilitySystemInterface.h"
#include "GameplayAbilitySpec.h"
#include "ProjectHD/Weapon/WeaponDataAsset.h"
#include "ProjectHD/SubtitleTypes.h" // 자막

#include "FPSCharacter.generated.h"

class AHDProjectile;
class UNiagaraSystem;
class UGameplayEffect;

// 스트라타젬 입력 화살표 방향
UENUM(BlueprintType)
enum class EStratagemDirection : uint8
{
    None, Up, Down, Left, Right
};

// 스트라타젬 타입
UENUM(BlueprintType)
enum class EStratagemType : uint8
{
    Bomb500kg,
    Supply,
    EagleCluster,
    OrbitalLaser,
    Sentry,
    Rearm,
};

// 스트라타젬 데이터 구조체
USTRUCT(BlueprintType)
struct FStratagemData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;

    // 스트라타젬 아이콘 이미지
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stratagem")
    class UTexture2D* Icon;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<EStratagemDirection> Command;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLinearColor BeaconColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EStratagemType Type;

    // 쿨타임 설정 (총 시간)
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float MaxCooldown = 10.0f;

    // 현재 남은 쿨타임 시간
    UPROPERTY(BlueprintReadWrite)
    float CurrentCooldown = 0.0f;

    // 현재 쿨타임 중인지 여부
    UPROPERTY(BlueprintReadWrite)
    bool bIsOnCooldown = false;
    
    // 스택형 스트라타젬 (이글)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stratagem")
    bool bUseStack = false;          // 스택 시스템 사용 여부

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stratagem")
    int32 MaxStack = 1;              // 최대 사용 횟수

    UPROPERTY(BlueprintReadWrite, Category = "Stratagem")
    int32 CurrentStack = 1;          // 현재 남은 횟수

    UPROPERTY(BlueprintReadWrite, Category = "Stratagem")
    bool bIsRearming = false;        // 재무장(쿨타임) 중인지 여부
};

// 무기 구조체
USTRUCT(BlueprintType)
struct FWeaponInstance
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UWeaponDataAsset* WeaponData;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CurrentAmmoCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CurrentMagCount;

    FWeaponInstance() : WeaponData(nullptr), CurrentAmmoCount(0), CurrentMagCount(0) {}
    FWeaponInstance(UWeaponDataAsset* Data)
    {
        WeaponData = Data;
        CurrentAmmoCount = Data->MaxAmmoInMag;
        CurrentMagCount = Data->MaxMag;
    }
};

// GAS
UENUM(BlueprintType)
enum class EAbilityInputID : uint8
{
    None,
    Confirm,
    Cancel,
    Aim,
    Fire,       // 사격용 ID
    Reload,     // 재장전용 ID
    Jump,        // 점프용 ID
    Sprint,
    Grenade,
};

// 델리게이트 선언
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAmmoChangedSignature, int32, NewAmmo, int32, NewMag, int32, MaxMag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHitEnemySignature, bool, bIsHeadshot);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStratagemStepUpdated, int32, NewStep);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStratagemUpdate, int32, StratagemIndex, int32, CurrentStep);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStratagemStackUpdated, const TArray<EStratagemDirection>&, InputStack);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAttributeChanged, float, CurrentValue, float, MaxValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGrenadeChanged, int32, Current, int32, Max);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStimChanged, int32, CurrentCount, int32, MaxCount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnComboChanged, int32, NewCombo);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStratagemMenuOpened, bool, bCanRearm);

UCLASS()
class PROJECTHD_API AFPSCharacter : public ACharacter, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
    AFPSCharacter();

    // GAS
    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
    
    UPROPERTY(BlueprintAssignable, Category = "Attributes")
    FOnAttributeChanged OnHealthChanged;
    
    UPROPERTY(BlueprintAssignable, Category = "Attributes")
    FOnAttributeChanged OnStaminaChanged;
    
    TArray<FWeaponInstance>& GetWeaponInventory() { return WeaponInventory; }
    
    virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

protected:
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    // 플레이어 AttributeSet
    UPROPERTY()
    class UPlayerAttributeSet* AttributeSet;
        
    // Health 속성이 변경될 때 ASC에 의해 호출될 콜백 함수
    void HandleHealthChanged(const FOnAttributeChangeData& Data);

    // Stamina 속성이 변경될 때 ASC에 의해 호출될 콜백 함수
    void HandleStaminaChanged(const FOnAttributeChangeData& Data);

    // GAS 컴포넌트
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
    class UAbilitySystemComponent* AbilitySystemComponent;

    // GAS 무기교체 능력 클래스
    UPROPERTY(EditAnywhere, Category = "GAS")
    TSubclassOf<UGameplayAbility> WeaponChangeAbilityClass;
    
    // GAS 수류탄 던지기 능력 클래스
    UPROPERTY(EditAnywhere, Category = "GAS")
    TSubclassOf<UGameplayAbility> GrenadeAbilityClass;
    
    // GAS 달리기 능력 클래스
    UPROPERTY(EditAnywhere, Category = "GAS")
    TSubclassOf<UGameplayAbility> SprintAbilityClass;
    
    // GAS 스태미나 리젠 능력 클래스
    UPROPERTY(EditAnywhere, Category = "GAS")
    TSubclassOf<UGameplayEffect> StaminaRegenEffectClass;
    
    void StartStaminaRegen();
    
    FTimerHandle TimerHandle_StaminaRegen;
    FTimerHandle ComboTimerHandle;
    
public:
    void OnSprintStarted();
    void OnSprintCompleted();    
    
    UPROPERTY(EditAnywhere, Category = "Design")
    TSubclassOf<class APodActor> PodClass;

    void Die();
    void RespawnWithPod();
    
    bool bIsDead = false;
    bool bIsOnPod = false;
    
protected:
    
    /* 입력 처리 함수들 */
    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);

    void OnFireStarted();
    void OnFireCompleted();
    void ResetRotationMode();
    void StartFiring();
    void StopFiring();
    void Reload();
    void OnGrenadeStart();
    void OnStimStart();
    void HandleStimMontageEnded(UAnimMontage* Montage, bool bInterrupted);
    void OnInteract();
    
    UFUNCTION(BlueprintCallable)
    void OnStimCompleted();
    
    UFUNCTION(BlueprintCallable)
    void ApplyStimEffect();
        
    UFUNCTION(BlueprintCallable)
    void OnGrenadeCompleted();

    // 무기 교체 함수
    void OnSelectWeapon1() { SwitchWeapon(0); }
    void OnSelectWeapon2() { SwitchWeapon(1); }
    void OnSelectWeapon3() { SwitchWeapon(2); }

    // 스트라타젬 함수
    void OnStratagemMenuAction(const struct FInputActionValue& Value);
    void OnStratagemInputAction(const struct FInputActionValue& Value);

    // 현재 장착 중인 무기의 데이터 에셋
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    class UWeaponDataAsset* CurrentWeaponData;

    // 무기 장착
    UFUNCTION(BlueprintCallable, Category = "Combat")
    void EquipWeapon(UWeaponDataAsset* NewWeaponData);

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat")
    class UWeaponDataAsset* FirstWeaponData;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat")
    class UWeaponDataAsset* SecondWeaponData;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat")
    class UWeaponDataAsset* ThirdWeaponData;

    // 무기 교체
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* WeaponSlot1Action;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* WeaponSlot2Action;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* WeaponSlot3Action;

    // 이동 속도
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float NormalWalkSpeed = 300.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float SprintWalkSpeed = 600.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float AimWalkSpeed = 200.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float ReloadWalkSpeed = 300.0f;

    UFUNCTION(BlueprintCallable, Category = "Combat")
    void FinishReload();

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat")
    bool bIsReloading = false;
    
    bool bSprintButtonDown = false;
    
    
    
    // 에임
    UFUNCTION(BlueprintNativeEvent, Category = "Combat")
    void OnAimStarted();
    virtual void OnAimStarted_Implementation();

    UFUNCTION(BlueprintNativeEvent, Category = "Combat")
    void OnAimCompleted();
    virtual void OnAimCompleted_Implementation();    

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat")
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

    // 미니맵
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
    TSubclassOf<class UUserWidget> MinimapWidgetClass;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
    class UUserWidget* MinimapWidget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    UNiagaraSystem* MuzzleFlashFX;
    
    UPROPERTY(VisibleAnywhere, Category = "Navigation")
    class UNavigationInvokerComponent* NavInvoker;

public:
    // 탄약 시스템
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    int32 MaxAmmoInMag = 30;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    int32 CurrentAmmo = 30;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    int32 CurrentMagCount = 8;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    int32 MaxMagCount = 8;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    int32 CurrentGrenadeCount = 5;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    int32 MaxGrenadeCount = 5;
        
    bool bIsThrowingGrenade = false;
    
    // 주사기 개수 관리
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    int32 CurrentStimCount = 4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    int32 MaxStimCount = 4;
        
    // 회복용 Gameplay Effect 클래스
    UPROPERTY(EditAnywhere, Category = "GAS")
    TSubclassOf<class UGameplayEffect> StimEffectClass;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
    bool bIsUsingStim = false;
    
    // 주사기 사운드
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    class USoundBase* StimSound;
    
    // 무기 교체 시스템
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Inventory")
    TArray<FWeaponInstance> WeaponInventory;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Inventory")
    int32 CurrentWeaponIndex = 0;

    UFUNCTION(BlueprintCallable)
    void SwitchWeapon(int32 SlotIndex);

    // 현재 장착된 무기가 부여한 어빌리티 핸들들을 저장 (지우기 용도)
    UPROPERTY()
    TArray<FGameplayAbilitySpecHandle> CurrentWeaponAbilityHandles;

    // 어빌리티를 깔끔하게 제거하는 헬퍼 함수
    void ClearCurrentWeaponAbilities();

    FTimerHandle TimerHandle_Reload;
    
    // 콤보 증가 및 타이머 갱신
    void AddKillCombo();

    // 콤보 리셋
    void ResetKillCombo();
    
protected:
    
    // 애니메이션    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
    class UAnimMontage* StimMontage;

    UPROPERTY(BlueprintReadOnly, Category = "Animation")
    float AimPitch;

    void UpdateAimOffset(float DeltaTime);

    bool bAimButtonDown = false;
    bool bFireButtonDown = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    class USoundBase* FireSound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    class USoundBase* ReloadSound;
    
    UPROPERTY(BlueprintReadWrite)
    UAnimMontage* CurrentReloadMontage;

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
    float ComboExpireTime = 7.0f;

    // --- 스트라타젬 사운드 ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stratagem")
    class USoundBase* StratagemInputSound;    // 입력 성공 (소리 1)

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stratagem")
    class USoundBase* StratagemErrorSound;    // 입력 실패 (소리 2)

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stratagem")
    class USoundBase* StratagemCompleteSound; // 입력 완료 (소리 3)
    
    UPROPERTY(EditAnywhere, Category = "Stratagem")
    class USoundBase* EagleRearmSound;

    // 중복 및 이름 오류 수정: StratagemList는 FStratagemData 타입을 사용합니다.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stratagem")
    TArray<FStratagemData> StratagemList;
    
    UPROPERTY(VisibleAnywhere, Category = "Stat")
    int32 KillComboCount = 0;

    int32 ActiveStratagemIndex = 0;

    TArray<EStratagemDirection> CurrentInputStack;   
    
    UPROPERTY(EditAnywhere, Category = "Audio")
    USoundBase* DeathVoiceSound;    // 사망시 보이스
    
    UPROPERTY(EditAnywhere, Category = "Audio")
    USoundBase* RespawnVoiceSound;  // 재투입시 보이스

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
    class UInputAction* SprintAction;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* GrenadeAction;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    class UInputAction* StimAction;

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
    
    UPROPERTY(EditAnywhere, Category = "Input")
    class UInputAction* InteractAction;

    UPROPERTY(EditAnywhere, Category = "Input")
    class UInputAction* MinimapToggleAction;

    void ToggleMinimap();

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
    
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnGrenadeChanged OnGrenadeChanged;
    
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnStimChanged OnStimChanged;
    
    UPROPERTY(BlueprintAssignable, Category = "HUD")
    FOnComboChanged OnComboChanged;
    
    UPROPERTY(BlueprintAssignable, Category = "Stratagem")
    FOnStratagemMenuOpened OnStratagemMenuOpened;
    
    UPROPERTY(BlueprintAssignable, Category = "Audio")
    FOnSoundPlayedSignature  OnSoundPlayed;  // 자막

    // 재무장 가능 여부 판단 함수
    UFUNCTION(BlueprintCallable, Category = "Stratagem")
    bool CanEagleRearm() const;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    float MouseSensitivity = 0.3f;
    
protected:
    UPROPERTY(BlueprintReadWrite, Category = "Mesh")
    class USkeletalMeshComponent* WeaponMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    float FireRange = 12000.0f;
};