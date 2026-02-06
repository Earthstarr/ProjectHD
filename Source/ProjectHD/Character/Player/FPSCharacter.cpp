#include "FPSCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Blueprint/UserWidget.h"
#include "ProjectHD/Weapon/Projectile/HDProjectile.h"
#include "NiagaraFunctionLibrary.h"
#include "ProjectHD/Weapon/Stratagem/StratagemBeacon.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "AbilitySystemComponent.h"
#include "PlayerAttributeSet.h"
#include "ProjectHD/Weapon/WeaponDataAsset.h"
#include "GameplayEffect.h"
#include "ProjectHD/InteractableInterface.h"
#include "Perception/AISense_Hearing.h"
#include "NavigationInvokerComponent.h"
#include "PodActor.h"
#include "ProjectHD/Mission/DataLinkTerminal.h"
#include "ProjectHD/Mission/ExtractionTerminal.h"
#include "ProjectHD/Mission/IntroCutsceneManager.h"
#include "ProjectHD/HDGameInstance.h"

AFPSCharacter::AFPSCharacter()
{
    // ASC 컴포넌트 생성
    AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

    // 서버/클라이언트 간 태그 복제 설정
    AbilitySystemComponent->SetIsReplicated(true);

    // 어빌리티 복제 모드 설정
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

    // 캡슐 크기 설정
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

    // 캐릭터 회전 설정 (3인칭 설정)
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 300.0f, 0.0f);

    // 스프링 암(CameraBoom) 설정
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 500.0f;
    CameraBoom->bUsePawnControlRotation = true;

    // 카메라 캐릭터 오른쪽 어깨 쪽으로 살짝 이동
    CameraBoom->SocketOffset = FVector(0.f, 120.f, 80.f);

    // 3인칭 카메라 설정
    ThirdPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
    ThirdPersonCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    ThirdPersonCamera->bUsePawnControlRotation = false;

    // 메시 및 총구 설정
    GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -96.f));
    WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));

    // 블루프린트에서 설정한 소켓 이름(예: WeaponSocket)에 부착
    WeaponMesh->SetupAttachment(GetMesh(), TEXT("WeaponSocket"));

    // 체력, 스태미나 관리용 AttributeSet
    AttributeSet = CreateDefaultSubobject<UPlayerAttributeSet>(TEXT("AttributeSet"));

    // 네비 인보커
    NavInvoker = CreateDefaultSubobject<UNavigationInvokerComponent>(TEXT("NavInvoker"));
    
    // 문제가 되는 물리 및 에셋 로드 관련 설정을 이 조건문 안에 넣기
    if (!HasAnyFlags(RF_ClassDefaultObject))
    {
        // 웨폰 메시의 물리 처리를 생성자 시점에서 하지 않도록 방어
        if (WeaponMesh)
        {
            WeaponMesh->bApplyImpulseOnDamage = false;
        }
    }
}

UAbilitySystemComponent* AFPSCharacter::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

float AFPSCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
    class AController* EventInstigator, AActor* DamageCauser)
{
    float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

    if (AttributeSet && ActualDamage > 0.0f)
    {
        float NewHealth = AttributeSet->GetHealth() - ActualDamage;
        AttributeSet->SetHealth(FMath::Max(NewHealth, 0.0f));
    }

    return ActualDamage;
}

void AFPSCharacter::BeginPlay()
{
    Super::BeginPlay();

    // 입력 모드 초기화 (레벨 전환 후 입력 복구)
    if (APlayerController* PC = Cast<APlayerController>(GetController()))
    {
        PC->EnableInput(PC);
        PC->bShowMouseCursor = false;
        PC->SetInputMode(FInputModeGameOnly());
    }

    // 네비 메시 생성 범위 설정
    if (NavInvoker)
    {
        // 첫 번째 인자: GenerationRadius, 두 번째 인자: RemovalRadius
        NavInvoker->SetGenerationRadii(10000.f, 12000.f);
    }

    if (AbilitySystemComponent)
    {
        // ASC 초기화, 서버에서만 어빌리티 부여
        AbilitySystemComponent->InitAbilityActorInfo(this, this);
    }

    // Attribute 설정
    if (AbilitySystemComponent && AttributeSet)
    {
        // Health 속성 변화 감지
        AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
            AttributeSet->GetHealthAttribute()).AddUObject(this, &AFPSCharacter::HandleHealthChanged);

        // Stamina 속성 변화 감지
        AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
            AttributeSet->GetStaminaAttribute()).AddUObject(this, &AFPSCharacter::HandleStaminaChanged);

        // 초기 UI 업데이트 위해 바로 호출
        OnHealthChanged.Broadcast(AttributeSet->GetHealth(), AttributeSet->GetMaxHealth());
        OnStaminaChanged.Broadcast(AttributeSet->GetStamina(), AttributeSet->GetMaxStamina());
    }

    if (HasAuthority())
    {
        // GAS: 무기 교체 능력
        if (WeaponChangeAbilityClass)
        {
            AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(WeaponChangeAbilityClass));
        }

        // GAS: 달리기 능력
        if (SprintAbilityClass)
        {
            AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(SprintAbilityClass, 1, static_cast<int32>(EAbilityInputID::Sprint)));
        }

        // GAS: 수류탄 던지기 능력
        if (GrenadeAbilityClass)
        {
            AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(GrenadeAbilityClass, 1, static_cast<int32>(EAbilityInputID::Grenade)));
        }
    }

    OnGrenadeChanged.Broadcast(CurrentGrenadeCount, MaxGrenadeCount);

    // 1, 2, 3번 무기 등록
    if (FirstWeaponData) WeaponInventory.Add(FWeaponInstance(FirstWeaponData));
    if (SecondWeaponData) WeaponInventory.Add(FWeaponInstance(SecondWeaponData));
    if (ThirdWeaponData) WeaponInventory.Add(FWeaponInstance(ThirdWeaponData));

    // 첫 번째 무기 장착
    if (WeaponInventory.Num() > 0)
    {
        EquipWeapon(WeaponInventory[0].WeaponData);
    }

    if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            Subsystem->AddMappingContext(DefaultMappingContext, 0);

            // 스트라타젬 컨텍스트 추가
            if (StratagemMappingContext)
            {
                Subsystem->AddMappingContext(StratagemMappingContext, 1); // 우선순위 1
            }
        }
    }

    // 500kg 폭탄
    FStratagemData Bomb;
    Bomb.Name = TEXT("500kg Bomb");
    Bomb.Command = { EStratagemDirection::Up, EStratagemDirection::Right, EStratagemDirection::Down, EStratagemDirection::Down, EStratagemDirection::Down };
    Bomb.BeaconColor = FLinearColor::Red;
    Bomb.MaxCooldown = 120.0f;
    Bomb.CurrentCooldown = 0.0f;
    Bomb.bUseStack = true;  // 스택 사용
    Bomb.MaxStack = 2;
    Bomb.CurrentStack = 2;
    Bomb.bIsOnCooldown = false;
    Bomb.Type = EStratagemType::Bomb500kg;

    // 이글 클러스터
    FStratagemData ClusterBomb;
    ClusterBomb.Name = TEXT("Eagle Cluster Bomb");
    ClusterBomb.Command = { EStratagemDirection::Up, EStratagemDirection::Right, EStratagemDirection::Down, EStratagemDirection::Down, EStratagemDirection::Right };
    ClusterBomb.BeaconColor = FLinearColor(1.0f, 0.5f, 0.0f); // 주황색
    ClusterBomb.MaxCooldown = 90.0f; // 이글은 쿨타임이 짧은 대신 사용 횟수 제한이 있는 경우가 많음
    ClusterBomb.CurrentCooldown = 0.0f;
    ClusterBomb.bUseStack = true;   // 스택 사용
    ClusterBomb.MaxStack = 3;
    ClusterBomb.CurrentStack = 3;
    ClusterBomb.bIsOnCooldown = false;
    ClusterBomb.Type = EStratagemType::EagleCluster;

    // 궤도 레이저
    FStratagemData OrbitalLaser;
    OrbitalLaser.Name = TEXT("Orbital Laser");
    OrbitalLaser.Command = {
        EStratagemDirection::Right,
        EStratagemDirection::Down,
        EStratagemDirection::Up,
        EStratagemDirection::Right,
        EStratagemDirection::Down
    };
    OrbitalLaser.BeaconColor = FLinearColor(0.5f, 0.0f, 1.0f);
    OrbitalLaser.MaxCooldown = 300.0f;
    OrbitalLaser.CurrentCooldown = 0.0f;
    OrbitalLaser.bIsOnCooldown = false;
    OrbitalLaser.Type = EStratagemType::OrbitalLaser;

    // 센트리
    FStratagemData Sentry;
    Sentry.Name = TEXT("Sentry");
    Sentry.Command = { EStratagemDirection::Down, EStratagemDirection::Up, EStratagemDirection::Right, EStratagemDirection::Left };
    Sentry.BeaconColor = FLinearColor::Green;
    Sentry.MaxCooldown = 180.0f;
    Sentry.CurrentCooldown = 0.0f;
    Sentry.bIsOnCooldown = false;
    Sentry.Type = EStratagemType::Sentry;

    // 보급품 (파랑)
    FStratagemData Supply;
    Supply.Name = TEXT("Supply Pod");
    Supply.Command = { EStratagemDirection::Down, EStratagemDirection::Down, EStratagemDirection::Up, EStratagemDirection::Right };
    Supply.BeaconColor = FLinearColor::Blue;
    Supply.MaxCooldown = 120.0f;
    Supply.CurrentCooldown = 0.0f;
    Supply.bIsOnCooldown = false;
    Supply.Type = EStratagemType::Supply;

    // 이글 재무장
    FStratagemData EagleRearm;
    EagleRearm.Name = TEXT("Eagle Rearm");
    EagleRearm.Command = { EStratagemDirection::Up,
        EStratagemDirection::Up,
        EStratagemDirection::Left,
        EStratagemDirection::Up,
        EStratagemDirection::Right
    };
    EagleRearm.Type = EStratagemType::Rearm; // 타입이 없으면 새 Enum 추가
    EagleRearm.bUseStack = false; // 재무장 자체는 일반 쿨타임 사용
    EagleRearm.MaxCooldown = 1.0f;
    EagleRearm.CurrentCooldown = 0.0f;

    // 메인 HUD 위젯 추가
    if (MainHUDWidgetClass)
    {
        MainHUDWidget = CreateWidget<UUserWidget>(GetWorld(), MainHUDWidgetClass);
        if (MainHUDWidget)
        {
            MainHUDWidget->AddToViewport();
        }
    }

    // 에디터에서 설정한 스트라타젬 스택을 다시 초기화
    for (FStratagemData& Data : StratagemList)
    {
        if (Data.bUseStack)
        {
            Data.CurrentStack = Data.MaxStack;
        }
    }

    // 미니맵 위젯 생성 (숨긴 상태로 시작)
    if (MinimapWidgetClass)
    {
        MinimapWidget = CreateWidget<UUserWidget>(GetWorld(), MinimapWidgetClass);
        if (MinimapWidget)
        {
            MinimapWidget->AddToViewport();
            MinimapWidget->SetVisibility(ESlateVisibility::Hidden);
        }
    }

    // 레벨 전환으로 들어왔으면 POD 강하로 스폰
    UHDGameInstance* GI = Cast<UHDGameInstance>(UGameplayStatics::GetGameInstance(this));
    if (GI)
    {
        // 현재 레벨이 미션 맵인지 확인
        FString CurrentLevelName = GetWorld()->GetMapName();
        CurrentLevelName.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);

        UE_LOG(LogTemp, Warning, TEXT("[MissionTimer] CurrentLevel: %s, MissionLevel: %s"), *CurrentLevelName, *GI->MissionLevelName.ToString());

        if (CurrentLevelName == GI->MissionLevelName.ToString())
        {
            // 미션 맵이면 타이머 리셋 및 시작
            GI->ResetMissionResult();
            GI->StartMissionTimer(this);
            UE_LOG(LogTemp, Warning, TEXT("[MissionTimer] Timer Started!"));
        }

        // IntroCutsceneManager가 없을 때만 자동 POD 스폰
        TArray<AActor*> FoundManagers;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), AIntroCutsceneManager::StaticClass(), FoundManagers);

        if (GI->bShouldSpawnWithPod && FoundManagers.Num() == 0)
        {
            GI->bShouldSpawnWithPod = false; // 플래그 리셋

            // 약간의 딜레이 후 POD 강하 시작 (레벨 로드 완료 대기)
            FTimerHandle SpawnPodHandle;
            GetWorldTimerManager().SetTimer(SpawnPodHandle, [this]() { SpawnWithPod(); }, 0.5f, false);
        }
    }
}

void AFPSCharacter::SwitchWeapon(int32 SlotIndex)
{
    // 재장전, 주사기 사용중이면 return
    if (bIsReloading || bIsUsingStim) return;

    // 해당 인덱스에 무기가 있는지 확인
    if (!WeaponInventory.IsValidIndex(SlotIndex) || WeaponInventory[SlotIndex].WeaponData == nullptr)
    {
        return;
    }

    // 이미 들고 있는 무기면 무시
    if (CurrentWeaponIndex == SlotIndex && CurrentWeaponData == WeaponInventory[SlotIndex].WeaponData)
    {
        return;
    }

    if (AbilitySystemComponent)
    {
        FGameplayEventData Payload;
        Payload.EventTag = FGameplayTag::RequestGameplayTag(FName("Event.Weapon.Swap"));

        // 슬롯 인덱스를 전달
        Payload.EventMagnitude = static_cast<float>(SlotIndex);

        AbilitySystemComponent->HandleGameplayEvent(Payload.EventTag, &Payload);
    }
}

void AFPSCharacter::ClearCurrentWeaponAbilities()
{
    if (!AbilitySystemComponent || !HasAuthority()) return;

    for (const FGameplayAbilitySpecHandle& Handle : CurrentWeaponAbilityHandles)
    {
        AbilitySystemComponent->ClearAbility(Handle);
    }
    CurrentWeaponAbilityHandles.Empty();
}

void AFPSCharacter::AddKillCombo()
{
    // 콤보 카운트 증가
    KillComboCount++;

    // UI 갱신용 델리게이트 호출
    OnComboChanged.Broadcast(KillComboCount);

    // 기존 타이머가 작동 중이면 초기화 (Refresh)
    GetWorldTimerManager().ClearTimer(ComboTimerHandle);

    // 일정 시간 후에 ResetKillCombo 함수 호출하도록 타이머 설정
    GetWorldTimerManager().SetTimer(ComboTimerHandle, this, &AFPSCharacter::ResetKillCombo, ComboExpireTime, false);
}

void AFPSCharacter::ResetKillCombo()
{
    KillComboCount = 0;
    OnComboChanged.Broadcast(KillComboCount);
}

void AFPSCharacter::UpdateAimOffset(float DeltaTime)
{
    // 컨트롤러의 회전값과 캐릭터의 회전값 비교
    FRotator ControlRotation = GetControlRotation();
    FRotator ActorRotation = GetActorRotation();

    // 두 회전값의 차이(Delta)를 정규화하여 저장
    FRotator Delta = (ControlRotation - ActorRotation).GetNormalized();

    // Pitch 값 보간
    AimPitch = FMath::FInterpTo(AimPitch, Delta.Pitch, DeltaTime, 15.0f);
}

bool AFPSCharacter::CanEagleRearm() const
{
    for (const FStratagemData& Data : StratagemList)
    {
        // 스택을 사용하는 스트라타젬(이글) 중 하나라도 풀스택이 아니면 재무장 가능
        if (Data.bUseStack && Data.CurrentStack < Data.MaxStack)
        {
           return true;
        }
    }
    return false;
}

void AFPSCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    UpdateAimOffset(DeltaTime);

    // 포드 안에 있을 때 시야를 맵 아래로 고정
    if (bIsOnPod && Controller)
    {
        FRotator CurrentRot = GetControlRotation();
        Controller->SetControlRotation(FRotator(-90.f, CurrentRot.Yaw, CurrentRot.Roll));
    }

    // 스트라타젬 쿨타임 업데이트
    for (FStratagemData& Data : StratagemList)
    {
        if (Data.bIsOnCooldown)
        {
            Data.CurrentCooldown -= DeltaTime;

            if (Data.CurrentCooldown <= 0.0f)
            {
                Data.CurrentCooldown = 0.0f;
                Data.bIsOnCooldown = false;

                // 재무장이 끝났다면 스택 복구
                if (Data.bUseStack && Data.bIsRearming)
                {
                    Data.CurrentStack = Data.MaxStack;
                    Data.bIsRearming = false;
                }
            }
        }
    }

    // 스프린트 토글: 움직일 때만 스태미나 소모
    if (bSprintButtonDown && AbilitySystemComponent && AttributeSet)
    {
        FVector Velocity = GetVelocity();
        float Speed = FVector(Velocity.X, Velocity.Y, 0.0f).Size(); // 수평 속도만 체크
        float CurrentStamina = AttributeSet->GetStamina();

        if (Speed > 10.0f && CurrentStamina > 0.0f) // 움직이고 있고 스태미나 있음
        {
            if (!bIsSprintActive && !bIsAiming && !bFireButtonDown)
            {
                // 회복 중이었다면 중단
                GetWorldTimerManager().ClearTimer(TimerHandle_StaminaRegen);
                AbilitySystemComponent->RemoveActiveGameplayEffectBySourceEffect(StaminaRegenEffectClass, AbilitySystemComponent);

                FGameplayTag ExhaustedTag = FGameplayTag::RequestGameplayTag(FName("State.Exhausted"));
                AbilitySystemComponent->RemoveLooseGameplayTag(ExhaustedTag);

                // 스프린트 어빌리티 활성화
                AbilitySystemComponent->AbilityLocalInputPressed(static_cast<int32>(EAbilityInputID::Sprint));
                bIsSprintActive = true;
            }
        }
        else if (bIsSprintActive) // 멈췄거나 스태미나 없음
        {
            // 스프린트 어빌리티 일시 정지 (토글은 유지)
            AbilitySystemComponent->AbilityLocalInputReleased(static_cast<int32>(EAbilityInputID::Sprint));
            bIsSprintActive = false;

            // 스태미나 회복 시작
            FGameplayTag ExhaustedTag = FGameplayTag::RequestGameplayTag(FName("State.Exhausted"));
            if (!AbilitySystemComponent->HasMatchingGameplayTag(ExhaustedTag))
            {
                AbilitySystemComponent->AddLooseGameplayTag(ExhaustedTag);
            }
            GetWorldTimerManager().SetTimer(TimerHandle_StaminaRegen, this, &AFPSCharacter::StartStaminaRegen, 2.0f, false);
        }
    }
}

void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
    {
        // 이동 및 시야 처리
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFPSCharacter::Move);
        EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFPSCharacter::Look);

        // 점프
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

        // 달리기 (토글)
        EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &AFPSCharacter::OnSprintToggle);

        // 수류탄 던지기
        EnhancedInputComponent->BindAction(GrenadeAction, ETriggerEvent::Started, this, &AFPSCharacter::OnGrenadeStart);

        // 주사기 사용
        EnhancedInputComponent->BindAction(StimAction, ETriggerEvent::Started, this, &AFPSCharacter::OnStimStart);

        // 사격 (FireWeapon 함수 연동)
        if (FireAction)
        {
            // 누를 때 OnFireStarted 호출
            EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Started, this, &AFPSCharacter::OnFireStarted);

            // 뗄 때 OnFireCompleted 호출
            EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Completed, this, &AFPSCharacter::OnFireCompleted);
        }

        if (AimAction)
        {
            EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Triggered, this, &AFPSCharacter::OnAimStarted);
            EnhancedInputComponent->BindAction(AimAction, ETriggerEvent::Completed, this, &AFPSCharacter::OnAimCompleted);
        }

        if (ReloadAction)
        {
            EnhancedInputComponent->BindAction(ReloadAction, ETriggerEvent::Started, this, &AFPSCharacter::Reload);
        }

        // 무기 슬롯 키 바인딩
        EnhancedInputComponent->BindAction(WeaponSlot1Action, ETriggerEvent::Started, this, &AFPSCharacter::OnSelectWeapon1);
        EnhancedInputComponent->BindAction(WeaponSlot2Action, ETriggerEvent::Started, this, &AFPSCharacter::OnSelectWeapon2);
        EnhancedInputComponent->BindAction(WeaponSlot3Action, ETriggerEvent::Started, this, &AFPSCharacter::OnSelectWeapon3);

        // Q 키 (메뉴 열기/닫기)
        EnhancedInputComponent->BindAction(StratagemMenuAction, ETriggerEvent::Started, this, &AFPSCharacter::OnStratagemMenuAction);

        // 스트라타젬 방향 입력
        EnhancedInputComponent->BindAction(StratagemInputAction, ETriggerEvent::Triggered, this, &AFPSCharacter::OnStratagemInputAction);

        // 상호작용 입력
        EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &AFPSCharacter::OnInteract);

        // 미니맵 토글
        if (MinimapToggleAction)
        {
            EnhancedInputComponent->BindAction(MinimapToggleAction, ETriggerEvent::Started, this, &AFPSCharacter::ToggleMinimap);
        }

        // 일시정지
        if (PauseAction)
        {
            EnhancedInputComponent->BindAction(PauseAction, ETriggerEvent::Started, this, &AFPSCharacter::TogglePause);
        }
    }
}

void AFPSCharacter::Move(const FInputActionValue& Value)
{
    if (bIsDead) return;

    FVector2D MovementVector = Value.Get<FVector2D>();
    CurrentMoveInput = MovementVector;  // Pod 조종용 저장

    if (Controller != nullptr)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);
        const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

        AddMovementInput(ForwardDirection, MovementVector.Y);
        AddMovementInput(RightDirection, MovementVector.X);
    }
}

void AFPSCharacter::Look(const FInputActionValue& Value)
{
    FVector2D LookAxisVector = Value.Get<FVector2D>();

    if (Controller != nullptr)
    {
        AddControllerYawInput(LookAxisVector.X * MouseSensitivity);
        AddControllerPitchInput(LookAxisVector.Y * MouseSensitivity);
    }
}

void AFPSCharacter::HandleHealthChanged(const FOnAttributeChangeData& Data)
{
    OnHealthChanged.Broadcast(Data.NewValue, AttributeSet->GetMaxHealth());

    if (Data.NewValue <= 0.0f)
    {
        Die();
    }
}

void AFPSCharacter::HandleStaminaChanged(const FOnAttributeChangeData& Data)
{
    float NewStamina = Data.NewValue;
    OnStaminaChanged.Broadcast(NewStamina, AttributeSet->GetMaxStamina());

    // 스태미나가 0 이하로 떨어지면 OnSprintCompleted 호출해 달리기 중지
    if (NewStamina <= 0.0f)
    {
        OnSprintCompleted();

        // GAS 내부적으로 Sprint 입력을 Release 처리해서 어빌리티 정상 종료
        if (AbilitySystemComponent)
        {
            AbilitySystemComponent->AbilityLocalInputReleased(static_cast<int32>(EAbilityInputID::Sprint));
        }
    }
}

void AFPSCharacter::EquipWeapon(UWeaponDataAsset* NewWeaponData)
{
    if (!NewWeaponData || !AbilitySystemComponent) return;

    // 이미 무기를 들고 있는 경우에만 저장
    if (CurrentWeaponData && WeaponInventory.IsValidIndex(CurrentWeaponIndex))
    {
        WeaponInventory[CurrentWeaponIndex].CurrentAmmoCount = CurrentAmmo;
        WeaponInventory[CurrentWeaponIndex].CurrentMagCount = CurrentMagCount;
    }

    // 기존 무기 어빌리티 제거
    ClearCurrentWeaponAbilities();

    CurrentWeaponData = NewWeaponData;
    WeaponMesh->SetSkeletalMesh(CurrentWeaponData->WeaponMesh);

    // 무기 손 위치 설정
    WeaponMesh->SetRelativeLocation(NewWeaponData->GripLocationOffset);
    WeaponMesh->SetRelativeRotation(NewWeaponData->GripRotationOffset);

    // 인벤토리에서 새 무기 데이터를 찾아 캐릭터 데이터와 동기화
    bool bFound = false;

    for (int32 i = 0; i < WeaponInventory.Num(); ++i)
    {
        if (WeaponInventory[i].WeaponData == NewWeaponData)
        {
            CurrentAmmo = WeaponInventory[i].CurrentAmmoCount;
            CurrentMagCount = WeaponInventory[i].CurrentMagCount;
            MaxAmmoInMag = NewWeaponData->MaxAmmoInMag;
            MaxMagCount = NewWeaponData->MaxMag;
            CurrentWeaponIndex = i;
            bFound = true;
            break;
        }
    }

    // 인벤토리에 없는 새 무기면 추가
    if (!bFound)
    {
        FWeaponInstance NewInstance(NewWeaponData);
        int32 NewIdx = WeaponInventory.Add(NewInstance);
        CurrentAmmo = NewInstance.CurrentAmmoCount;
        CurrentMagCount = NewInstance.CurrentMagCount;
        MaxAmmoInMag = NewWeaponData->MaxAmmoInMag;
        MaxMagCount = NewWeaponData->MaxMag;
        CurrentWeaponIndex = NewIdx;
    }

    // 새 어빌리티 부여 및 핸들 저장
    if (HasAuthority())
    {
        if (CurrentWeaponData->FireAbility)
        {
            FGameplayAbilitySpecHandle Handle = AbilitySystemComponent->GiveAbility(
                FGameplayAbilitySpec(CurrentWeaponData->FireAbility, 1, static_cast<int32>(EAbilityInputID::Fire)));
            CurrentWeaponAbilityHandles.Add(Handle);
        }

        if (CurrentWeaponData->ReloadAbility)
        {
            FGameplayAbilitySpecHandle Handle = AbilitySystemComponent->GiveAbility(
                FGameplayAbilitySpec(CurrentWeaponData->ReloadAbility, 1, static_cast<int32>(EAbilityInputID::Reload)));
            CurrentWeaponAbilityHandles.Add(Handle);
        }

        if (CurrentWeaponData->AimAbility)
        {
            FGameplayAbilitySpecHandle Handle = AbilitySystemComponent->GiveAbility(
                FGameplayAbilitySpec(CurrentWeaponData->AimAbility, 1, static_cast<int32>(EAbilityInputID::Aim)));
            CurrentWeaponAbilityHandles.Add(Handle);
        }
    }

    // 애니메이션 레이어 교체
    if (UAnimInstance* AnimInst = GetMesh()->GetAnimInstance())
    {
        if (NewWeaponData->WeaponAnimLayer)
        {
            // 새로운 무기용 레이어를 현재 ABP에 링크
            AnimInst->LinkAnimClassLayers(NewWeaponData->WeaponAnimLayer);
        }
    }

    // 현재 무기에 맞는 몽타주 설정
    CurrentReloadMontage = NewWeaponData->ReloadMontage;

    // UI 갱신 델리게이트 호출
    OnAmmoChanged.Broadcast(CurrentAmmo, CurrentMagCount, MaxMagCount);
}

// GAS : 달리기
void AFPSCharacter::OnSprintStarted()
{
    // 토글 상태만 설정, 실제 스프린트 활성화는 Tick에서 속도 체크 후 처리
    bSprintButtonDown = true;
}

void AFPSCharacter::OnSprintCompleted()
{
    bSprintButtonDown = false;
    bIsSprintActive = false;

    if (AbilitySystemComponent)
    {
        AbilitySystemComponent->AbilityLocalInputReleased(static_cast<int32>(EAbilityInputID::Sprint));

        FGameplayTag ExhaustedTag = FGameplayTag::RequestGameplayTag(FName("State.Exhausted"));
        if (!AbilitySystemComponent->HasMatchingGameplayTag(ExhaustedTag))
        {
            AbilitySystemComponent->AddLooseGameplayTag(ExhaustedTag);
        }

        GetWorldTimerManager().SetTimer(TimerHandle_StaminaRegen, this, &AFPSCharacter::StartStaminaRegen, 2.0f, false);
    }
}

void AFPSCharacter::OnSprintToggle()
{
    if (bSprintButtonDown)
    {
        // 달리기 중이면 해제
        OnSprintCompleted();
    }
    else
    {
        // 달리기 시작
        OnSprintStarted();
    }
}

void AFPSCharacter::StartStaminaRegen()
{
    if (AbilitySystemComponent)
    {
        // 탈진 태그 제거
        FGameplayTag ExhaustedTag = FGameplayTag::RequestGameplayTag(FName("State.Exhausted"));
        AbilitySystemComponent->RemoveLooseGameplayTag(ExhaustedTag);

        // 스태미나 회복 GE 적용
        if (StaminaRegenEffectClass)
        {
            AbilitySystemComponent->RemoveActiveGameplayEffectBySourceEffect(StaminaRegenEffectClass, AbilitySystemComponent);

            FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
            EffectContext.AddSourceObject(this);
            FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(StaminaRegenEffectClass, 1.0f, EffectContext);

            if (SpecHandle.IsValid())
            {
                AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
            }
        }
    }
}

void AFPSCharacter::Die()
{
    if (bIsDead) return;
    bIsDead = true;

    // 미션 결과에 사망 기록
    if (UHDGameInstance* GI = Cast<UHDGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
    {
        GI->AddPlayerDeath();
    }

    if (DeathVoiceSound)
    {
        UGameplayStatics::PlaySound2D(this, DeathVoiceSound);
        OnSoundPlayed.Broadcast(FName("DeathVoiceSound")); // 자막
    }

    // 모든 이동/입력 차단
    GetCharacterMovement()->StopMovementImmediately();
    GetCharacterMovement()->DisableMovement();
    GetCharacterMovement()->SetComponentTickEnabled(false);

    // 래그돌 활성화
    GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    GetMesh()->SetSimulatePhysics(true);
    GetMesh()->SetCollisionProfileName(TEXT("Ragdoll"));

    // 5초 후 부활 타이머
    FTimerHandle RespawnHandle;
    GetWorldTimerManager().SetTimer(RespawnHandle, this, &AFPSCharacter::RespawnWithPod, 5.0f, false);
}

void AFPSCharacter::RespawnWithPod()
{
    bIsDead = false;
    bIsOnPod = true;

    if (RespawnVoiceSound)
    {
        UGameplayStatics::PlaySound2D(this, RespawnVoiceSound);
        OnSoundPlayed.Broadcast(FName("RespawnVoiceSound")); // 자막
    }

    // 포드 탑승 중 캐릭터 외형 숨기기 (무기 메시 포함)
    GetMesh()->SetVisibility(false, true);

    // 체력 및 상태 초기화
    if (AttributeSet)
    {
        AttributeSet->SetHealth(AttributeSet->GetMaxHealth());
        AttributeSet->SetStamina(AttributeSet->GetMaxStamina());
        OnHealthChanged.Broadcast(AttributeSet->GetHealth(), AttributeSet->GetMaxHealth());
        OnStaminaChanged.Broadcast(AttributeSet->GetStamina(), AttributeSet->GetMaxStamina());
    }

    CurrentGrenadeCount = MaxGrenadeCount;
    CurrentStimCount = MaxStimCount;
    OnGrenadeChanged.Broadcast(CurrentGrenadeCount, MaxGrenadeCount);
    OnStimChanged.Broadcast(CurrentStimCount, MaxStimCount);

    for (FWeaponInstance& Weapon : WeaponInventory)
    {
        if (Weapon.WeaponData)
        {
            Weapon.CurrentAmmoCount = Weapon.WeaponData->MaxAmmoInMag;
            Weapon.CurrentMagCount = Weapon.WeaponData->MaxMag;
        }
    }

    if (CurrentWeaponData)
    {
        CurrentAmmo = CurrentWeaponData->MaxAmmoInMag;
        CurrentMagCount = CurrentWeaponData->MaxMag;
        OnAmmoChanged.Broadcast(CurrentAmmo, CurrentMagCount, MaxMagCount);
    }

    // 래그돌 해제
    GetMesh()->SetSimulatePhysics(false);
    GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -96.f));

    // CharacterMovement 다시 켜기
    GetCharacterMovement()->SetComponentTickEnabled(true);

    // 캐릭터를 일시적 비활성화
    GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    GetCapsuleComponent()->SetEnableGravity(false);
    GetCharacterMovement()->SetMovementMode(MOVE_None);
    GetCharacterMovement()->GravityScale = 0.0f;

    // 시야를 맵 아래로 고정 (-90도)
    if (APlayerController* PC = Cast<APlayerController>(GetController()))
    {
        FRotator CurrentRot = PC->GetControlRotation();
        PC->SetControlRotation(FRotator(-90.f, CurrentRot.Yaw, 0.f));
    }

    float RandomX = FMath::RandRange(-1500.f, 1500.f);
    float RandomY = FMath::RandRange(-1500.f, 1500.f);

    // 현재 위치에서 랜덤위치로 스폰
    FVector SpawnLoc = GetActorLocation() + FVector(RandomX, RandomY, 40000.f);

    if (PodClass)
    {
        APodActor* NewPod = GetWorld()->SpawnActor<APodActor>(PodClass, SpawnLoc, FRotator::ZeroRotator);
        if (NewPod && NewPod->PodMesh)
        {
            // Anchor 위치 가져오기
            FVector AnchorWorldLoc = NewPod->GetCharacterAnchor()->GetComponentLocation();

            // 캡슐 높이(48) 보정 후 Anchor에 맞추기
            AnchorWorldLoc.Z -= 48.f;

            SetActorLocation(AnchorWorldLoc);
            SetActorRotation(FRotator::ZeroRotator);

            // Pod physics
            UStaticMeshComponent* PodMeshComp = NewPod->PodMesh;
            PodMeshComp->SetSimulatePhysics(true);
            PodMeshComp->SetEnableGravity(true);
            PodMeshComp->WakeRigidBody();

            if (FBodyInstance* BodyInst = PodMeshComp->GetBodyInstance())
            {
                BodyInst->bLockXRotation = true;
                BodyInst->bLockYRotation = true;
            }

            PodMeshComp->SetPhysicsLinearVelocity(FVector(0, 0, -9000.f));

            // 1프레임 뒤에 붙이기
            GetWorldTimerManager().SetTimerForNextTick([this, NewPod]()
            {
                if (NewPod && NewPod->GetCharacterAnchor())
                {
                    AttachToComponent(
                        NewPod->GetCharacterAnchor(),
                        FAttachmentTransformRules::KeepWorldTransform
                    );

                    GetCapsuleComponent()->IgnoreActorWhenMoving(NewPod, true);
                    GetMesh()->IgnoreActorWhenMoving(NewPod, true);
                }
            });
        }
    }
}

void AFPSCharacter::SpawnWithPod(bool bPlaySound)
{
    // 이미 포드 스폰 중이면 무시 (중복 호출 방지)
    if (bIsOnPod)
    {
        return;
    }

    bIsOnPod = true;

    if (bPlaySound && SpawnVoiceSound)
    {
        UGameplayStatics::PlaySound2D(this, SpawnVoiceSound);
        OnSoundPlayed.Broadcast(FName("SpawnVoiceSound")); // 자막
    }

    // 포드 탑승 중 캐릭터 외형 숨기기 (무기 메시 포함)
    GetMesh()->SetVisibility(false, true);

    // 캐릭터 일시적 비활성화
    GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    GetCapsuleComponent()->SetEnableGravity(false);
    GetCharacterMovement()->SetMovementMode(MOVE_None);
    GetCharacterMovement()->GravityScale = 0.0f;

    // 시야를 맵 아래로 고정 (-90도)
    if (APlayerController* PC = Cast<APlayerController>(GetController()))
    {
        FRotator CurrentRot = PC->GetControlRotation();
        PC->SetControlRotation(FRotator(-90.f, CurrentRot.Yaw, 0.f));
    }

    // 현재 위치(PlayerStart 위치) 기준으로 상공에서 스폰
    FVector SpawnLoc = GetActorLocation() + FVector(0.f, 0.f, 40000.f);

    if (PodClass)
    {
        APodActor* NewPod = GetWorld()->SpawnActor<APodActor>(PodClass, SpawnLoc, FRotator::ZeroRotator);
        if (NewPod && NewPod->PodMesh)
        {
            // Anchor 위치 가져오기
            FVector AnchorWorldLoc = NewPod->GetCharacterAnchor()->GetComponentLocation();
            AnchorWorldLoc.Z -= 48.f;

            SetActorLocation(AnchorWorldLoc);
            SetActorRotation(FRotator::ZeroRotator);

            // Pod physics
            UStaticMeshComponent* PodMeshComp = NewPod->PodMesh;
            PodMeshComp->SetSimulatePhysics(true);
            PodMeshComp->SetEnableGravity(true);
            PodMeshComp->WakeRigidBody();

            if (FBodyInstance* BodyInst = PodMeshComp->GetBodyInstance())
            {
                BodyInst->bLockXRotation = true;
                BodyInst->bLockYRotation = true;
            }

            PodMeshComp->SetPhysicsLinearVelocity(FVector(0, 0, -9000.f));

            // 1프레임 뒤에 붙이기
            GetWorldTimerManager().SetTimerForNextTick([this, NewPod]()
            {
                if (NewPod && NewPod->GetCharacterAnchor())
                {
                    AttachToComponent(
                        NewPod->GetCharacterAnchor(),
                        FAttachmentTransformRules::KeepWorldTransform
                    );

                    GetCapsuleComponent()->IgnoreActorWhenMoving(NewPod, true);
                    GetMesh()->IgnoreActorWhenMoving(NewPod, true);
                }
            });
        }
    }
}

// 수류탄 던지기
void AFPSCharacter::OnGrenadeStart()
{
    if (bIsReloading || bIsUsingStim) return;

    // 수류탄이 0보다 많으면 던지기 시작
    if (!bIsThrowingGrenade && CurrentGrenadeCount > 0 && AbilitySystemComponent)
    {
        bIsThrowingGrenade = true;
        AbilitySystemComponent->AbilityLocalInputPressed(static_cast<int32>(EAbilityInputID::Grenade));

        // 개수 감소 및 UI 갱신
        CurrentGrenadeCount--;
        OnGrenadeChanged.Broadcast(CurrentGrenadeCount, MaxGrenadeCount);
    }
}

void AFPSCharacter::OnGrenadeCompleted()
{
    bIsThrowingGrenade = false;
}

void AFPSCharacter::OnStimStart()
{
    // 조건 및 상태 체크
    if (CurrentStimCount <= 0 || bIsReloading || bIsThrowingGrenade || bIsUsingStim) return;

    UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();

    // 주사기 몽타주가 할당되어 있고 재생 가능한지 확인
    if (AnimInstance && StimMontage)
    {
        bIsUsingStim = true;

        // 몽타주를 재생하고 반환된 시간 확인
        float Duration = AnimInstance->Montage_Play(StimMontage, 1.0f);

        if (Duration > 0.0f)
        {
            // 몽타주 종료/중단 시 호출될 함수를 바인딩
            FOnMontageEnded EndedDelegate;
            EndedDelegate.BindUObject(this, &AFPSCharacter::HandleStimMontageEnded);
            AnimInstance->Montage_SetEndDelegate(EndedDelegate, StimMontage);
        }
        else
        {
            // 재생 실패시 상태 플래그를 false
            bIsUsingStim = false;
        }
    }
}

void AFPSCharacter::HandleStimMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
    bIsUsingStim = false;
}

void AFPSCharacter::OnInteract()
{
    FHitResult Hit;
    FVector Start = GetActorLocation()+ FVector(0, -30.f, 80.f);
    FVector Forward = ThirdPersonCamera->GetForwardVector();
    FVector End = Start + (Forward * 300.0f);

    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);

    // 구체 스위프
    float SweepRadius = 50.0f;

    bool bHit = GetWorld()->SweepSingleByChannel(
        Hit,
        Start,
        End,
        FQuat::Identity,
        ECC_Visibility,
        FCollisionShape::MakeSphere(SweepRadius),
        Params
    );

    if (bHit)
    {
        IInteractableInterface* Interactable = Cast<IInteractableInterface>(Hit.GetActor());
        if (Interactable)
        {
            Interactable->Interact(this);
        }
    }

    //DrawDebugCapsule(GetWorld(), Start + (End - Start) * 0.5f, 150.f + SweepRadius, SweepRadius, FRotationMatrix::MakeFromZ(End - Start).ToQuat(), FColor::Green, false, 2.0f);
}

void AFPSCharacter::ApplyStimEffect()
{
    if (AbilitySystemComponent && StimEffectClass)
    {
        FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
        EffectContext.AddSourceObject(this);

        FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(StimEffectClass, 1.0f, EffectContext);
        if (SpecHandle.IsValid())
        {
            // 탈진 상태 해제 및 GE 적용
            FGameplayTag ExhaustedTag = FGameplayTag::RequestGameplayTag(FName("State.Exhausted"));
            AbilitySystemComponent->RemoveLooseGameplayTag(ExhaustedTag);

            AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());

            CurrentStimCount--;
            OnStimChanged.Broadcast(CurrentStimCount, MaxStimCount);

            // 주사기 효과음
            if (StimSound)
            {
                UGameplayStatics::PlaySoundAtLocation(this, StimSound, GetActorLocation());
            }
        }
    }

    OnStimChanged.Broadcast(CurrentStimCount, MaxStimCount);
}

void AFPSCharacter::OnStimCompleted()
{
    bIsUsingStim = false;
}

void AFPSCharacter::OnFireStarted()
{
    if (bIsDead) return;

    bFireButtonDown = true;

    if (!bIsAiming) return;

    if (bIsStratagemReady)
    {
        ThrowBeacon();
        return;
    }

    // GAS : 입력 ID에 따른 사격 어빌리티 시작
    if (AbilitySystemComponent)
    {
        AbilitySystemComponent->AbilityLocalInputPressed(static_cast<int32>(EAbilityInputID::Fire));
    }
}

void AFPSCharacter::StartFiring()
{
    // 첫 발 즉시 발사
    FireWeapon();

    // FireRate에 따른 반복 타이머 설정 (1.0 / 10.0 = 0.1초 간격)
    float TimeBetweenShots = 1.0f / FireRate;
    GetWorldTimerManager().SetTimer(TimerHandle_AutomaticFire, this, &AFPSCharacter::FireWeapon, TimeBetweenShots, true);
}

void AFPSCharacter::OnFireCompleted()
{
    bFireButtonDown = false;

    // GAS : 입력이 해제됐음을 어빌리티에 알림
    if (AbilitySystemComponent)
    {
        AbilitySystemComponent->AbilityLocalInputReleased(static_cast<int32>(EAbilityInputID::Fire));
    }

    if (bSprintButtonDown)
    {
        OnSprintStarted();
    }
}

void AFPSCharacter::StopFiring()
{
    GetWorldTimerManager().ClearTimer(TimerHandle_AutomaticFire);
}

void AFPSCharacter::Reload()
{
    if (bIsDead) return;

    if (CurrentAmmo >= MaxAmmoInMag || CurrentMagCount <= 0 || bIsReloading || bIsThrowingGrenade || bIsUsingStim) return;

    if (bSprintButtonDown)
    {
        GetCharacterMovement()->MaxWalkSpeed = SprintWalkSpeed;
    }

    bIsReloading = true;

    // GAS Reload
    if (AbilitySystemComponent)
    {
        // 입력 ID에 따른 시작 (미리 등록된 EAbilityInputID::Reload 사용)
        AbilitySystemComponent->AbilityLocalInputPressed(static_cast<int32>(EAbilityInputID::Reload));
    }
}

void AFPSCharacter::FinishReload()
{
    bIsReloading = false;

    if (bIsAiming)
    {
        // 조준 속도 적용
        GetCharacterMovement()->MaxWalkSpeed = AimWalkSpeed;

        // 재장전이 끝났을 때 버튼 눌려있으면 바로 사격
        if (bFireButtonDown && AbilitySystemComponent)
        {
            AbilitySystemComponent->AbilityLocalInputReleased(static_cast<int32>(EAbilityInputID::Fire));
            AbilitySystemComponent->AbilityLocalInputPressed(static_cast<int32>(EAbilityInputID::Fire));
        }
    }
    else if (bSprintButtonDown)
    {
        GetCharacterMovement()->MaxWalkSpeed = SprintWalkSpeed;
    }
    else
    {
        GetCharacterMovement()->MaxWalkSpeed = NormalWalkSpeed;
    }

    OnAmmoChanged.Broadcast(CurrentAmmo, CurrentMagCount, MaxMagCount);
}


void AFPSCharacter::ResetRotationMode()
{
    // 조준 상태 아니고 에임 버튼이 떨어진 타이밍에 회전 방식 복원
    if (!bIsAiming)
    {
        bUseControllerRotationYaw = false;
        GetCharacterMovement()->bOrientRotationToMovement = true;
    }
}

void AFPSCharacter::OnAimStarted_Implementation()
{
    if (bIsDead) return;

    bAimButtonDown = true;
    bIsAiming = true;

    // GAS Aim
    if (AbilitySystemComponent)
    {
        AbilitySystemComponent->AbilityLocalInputPressed(static_cast<int32>(EAbilityInputID::Aim));
    }
}

void AFPSCharacter::OnAimCompleted_Implementation()
{
    bAimButtonDown = false;
    bIsAiming = false;

    // GAS Aim
    if (AbilitySystemComponent)
    {
        AbilitySystemComponent->AbilityLocalInputReleased(static_cast<int32>(EAbilityInputID::Aim));
    }

    if (bSprintButtonDown)
    {
        OnSprintStarted();
    }
}

void AFPSCharacter::FireWeapon()
{
    // ThirdPersonCamera를 기반으로 라인트레이스 시작
    if (!ThirdPersonCamera || !CurrentWeaponData) return;

    FVector Start = ThirdPersonCamera->GetComponentLocation();
    FVector ForwardVector = ThirdPersonCamera->GetForwardVector();
    FVector End = Start + (ForwardVector * FireRange);

    FHitResult HitResult;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this); // 자신은 무시 처리

    bool bHit = GetWorld()->LineTraceSingleByChannel(
        HitResult,
        Start,
        End,
        ECollisionChannel::ECC_Visibility,
        Params
    );

    if (APlayerController* PC = Cast<APlayerController>(GetController()))
    {
        // 위로 튀는 반동 (Pitch가 음수면 화면이 위로 올라감)
        AddControllerPitchInput(-RecoilPitch);

        // 좌우로 랜덤하게 흔들리는 반동
        float RandomYaw = FMath::FRandRange(-RecoilYaw, RecoilYaw);
        AddControllerYawInput(RandomYaw);
    }

    if (CurrentWeaponData->ProjectileClass)
    {
        FVector MuzzleLocation = WeaponMesh->GetSocketLocation(TEXT("MuzzleSocket"));
        FRotator MuzzleRotation = WeaponMesh->GetSocketRotation(TEXT("MuzzleSocket"));

        // 화면 정중앙(조준점)이 가리키는 월드 좌표를 찾기 위해 라인 트레이스 사용
        FVector LookAtLocation;
        FVector CameraLocation = ThirdPersonCamera->GetComponentLocation();
        FVector CameraForward = ThirdPersonCamera->GetForwardVector();
        FVector TraceEnd = CameraLocation + (CameraForward * FireRange);

        FHitResult AimHitResult;
        FCollisionQueryParams QueryParams;
        QueryParams.AddIgnoredActor(this);

        // 카메라 방향으로 물체가 있는지 확인
        if (GetWorld()->LineTraceSingleByChannel(AimHitResult, CameraLocation, TraceEnd, ECC_Visibility, QueryParams))
        {
            LookAtLocation = AimHitResult.ImpactPoint; // 부딪힌 점
        }
        else
        {
            LookAtLocation = TraceEnd; // 없으면 최대 사정거리 끝 점
        }

        // 총구에서 '조준점이 가리키는 위치'를 바라보는 회전값 계산
        FRotator TargetRotation = (LookAtLocation - MuzzleLocation).Rotation();

        FActorSpawnParameters ActorSpawnParams;
        ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
        ActorSpawnParams.Owner = this;
        ActorSpawnParams.Instigator = this;

        // 총구 화염 생성
        if (MuzzleFlashFX)
        {
            UNiagaraFunctionLibrary::SpawnSystemAtLocation(
                GetWorld(),
                MuzzleFlashFX,
                MuzzleLocation,
                MuzzleRotation
            );
        }

        // 발사 사운드
        if (CurrentWeaponData->FireSound)
        {
            UGameplayStatics::PlaySoundAtLocation(this, CurrentWeaponData->FireSound, GetActorLocation());
        }

        APlayerController* PC = Cast<APlayerController>(GetController());
        if (PC && FireCameraShakeClass)
        {
            // 카메라 셰이크
            PC->ClientStartCameraShake(FireCameraShakeClass);
        }

        // 소음
        if (CurrentWeaponData)
        {
            UAISense_Hearing::ReportNoiseEvent(
                GetWorld(),
                GetActorLocation(),
                CurrentWeaponData->Loudness,
                this,
                0.0f,
                FName(TEXT("Noise"))
            );
        }

        // 투사체 발사
        GetWorld()->SpawnActor<AHDProjectile>(CurrentWeaponData->ProjectileClass, MuzzleLocation, TargetRotation, ActorSpawnParams);

        CurrentAmmo--;

        OnAmmoChanged.Broadcast(CurrentAmmo, CurrentMagCount, MaxMagCount);
    }

    // Fire 애니메이션 재생 로직 추가
    if (CurrentWeaponData && CurrentWeaponData->FireMontage)
    {
        UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
        if (AnimInstance)
        {
            // 발사 간격 계산
            float FireInterval = 1.0f / FireRate;

            // 몽타주의 원래 길이 가져오기
            float MontageLength = CurrentWeaponData->FireMontage->GetPlayLength();

            // 재생 속도(PlayRate) 계산
            float CalculatedPlayRate = MontageLength / FireInterval;

            // 계산된 속도로 재생
            AnimInstance->Montage_Play(CurrentWeaponData->FireMontage, CalculatedPlayRate);
        }
    }
}

void AFPSCharacter::ThrowBeacon()
{
    if (!BeaconClass || !StratagemList.IsValidIndex(ActiveStratagemIndex)) return;

    FStratagemData& ActiveData = StratagemList[ActiveStratagemIndex];

    // 스택방식일 때 체크
    if (ActiveData.bUseStack)
    {
        if (ActiveData.CurrentStack > 0)
        {
            ActiveData.CurrentStack--;

            // 마지막 스택을 쓴 경우 다음 쿨타임은 자동으로 재무장 시작
            if (ActiveData.CurrentStack <= 0)
            {
                ActiveData.bIsOnCooldown = true;
                ActiveData.bIsRearming = true;
                ActiveData.CurrentCooldown = ActiveData.MaxCooldown;
            }
            else
            {
                // 스택이 남아있으면 쿨타임은 적용하지 않음
                ActiveData.bIsOnCooldown = false;
                ActiveData.CurrentCooldown = 0.0f;
            }
        }
    }
    else // 일반 스트라타젬
    {
        ActiveData.bIsOnCooldown = true;
        ActiveData.CurrentCooldown = ActiveData.MaxCooldown;
    }

    FVector SpawnLocation = WeaponMesh->GetSocketLocation(TEXT("MuzzleSocket"));
    FRotator ControlRot = GetControlRotation();
    FRotator SpawnRotation = FRotator(0.f, ControlRot.Yaw, 0.f);

    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = this;
    SpawnParams.Instigator = GetInstigator();

    // 비콘 생성
    AStratagemBeacon* SpawnedBeacon = GetWorld()->SpawnActor<AStratagemBeacon>(
        BeaconClass,
        SpawnLocation,
        SpawnRotation,
        SpawnParams
    );
    /*
    // 정상적으로 생성되었다면 쿨타임 시작
    if (SpawnedBeacon && StratagemList.IsValidIndex(ActiveStratagemIndex))
    {
        StratagemList[ActiveStratagemIndex].bIsOnCooldown = true;
        StratagemList[ActiveStratagemIndex].CurrentCooldown = StratagemList[ActiveStratagemIndex].MaxCooldown;

        SpawnedBeacon->MyStratagemType = StratagemList[ActiveStratagemIndex].Type;
        SpawnedBeacon->UpdateBeaconVisual(StratagemList[ActiveStratagemIndex].BeaconColor);

        UProjectileMovementComponent* ProjectileComp = SpawnedBeacon->FindComponentByClass<UProjectileMovementComponent>();
        if (ProjectileComp)
        {
            FVector LaunchDirection = ControlRot.Vector();
            ProjectileComp->Velocity = LaunchDirection * ThrowForce;
        }
    }
    */
    if (SpawnedBeacon)
    {
        SpawnedBeacon->MyStratagemType = ActiveData.Type;
        SpawnedBeacon->UpdateBeaconVisual(ActiveData.BeaconColor);

        UProjectileMovementComponent* ProjectileComp = SpawnedBeacon->FindComponentByClass<UProjectileMovementComponent>();
        if (ProjectileComp)
        {
            ProjectileComp->Velocity = ControlRot.Vector() * ThrowForce;
        }

        // 미션 결과에 스트라타젬 사용 기록
        if (UHDGameInstance* GI = Cast<UHDGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())))
        {
            GI->AddStratagemUsed(ActiveData.Type);
        }
    }

    // 상태 초기화
    CurrentInputStack.Empty();
    bIsStratagemReady = false;
    bIsSelectingStratagem = false;
    //CurrentCommandStep = 0;

    // UI 초기화 신호 (빈 스택 전달)
    OnStratagemStackUpdated.Broadcast(CurrentInputStack);
}

void AFPSCharacter::OnStratagemMenuAction(const FInputActionValue& Value)
{
    if (bIsThrowingGrenade || bIsUsingStim) return;

    bIsSelectingStratagem = !bIsSelectingStratagem;

    if (bIsSelectingStratagem)
    {
        CurrentCommandStep = 0;
        OnStratagemStepUpdated.Broadcast(CurrentCommandStep);
        OnStratagemMenuOpened.Broadcast(CanEagleRearm());
    }
    else
    {
        // 메뉴가 닫힐 때 입력 상태 초기화
        CurrentInputStack.Empty();
        bIsStratagemReady = false;

        // UI에 빈 스택을 전달해 화살표들이 다시 회색으로 변경
        OnStratagemStackUpdated.Broadcast(CurrentInputStack);

        if (!bIsStratagemReady)
        {
            CurrentCommandStep = 0;
            OnStratagemStepUpdated.Broadcast(CurrentCommandStep);
        }
    }
}

void AFPSCharacter::OnStratagemInputAction(const FInputActionValue& Value)
{
    FVector2D InputValue = Value.Get<FVector2D>();

    EStratagemDirection DetectedDir = EStratagemDirection::None;

    // Vector2D 값을 분석하여 방향 판단
    if (InputValue.Y > 0.5f) DetectedDir = EStratagemDirection::Up;
    else if (InputValue.Y < -0.5f) DetectedDir = EStratagemDirection::Down;
    else if (InputValue.X < -0.5f) DetectedDir = EStratagemDirection::Left;
    else if (InputValue.X > 0.5f) DetectedDir = EStratagemDirection::Right;

    if (DetectedDir == EStratagemDirection::None) return;

    // 데이터 링크 터미널 입력 처리
    if (ActiveDataLinkTerminal)
    {
        ActiveDataLinkTerminal->ProcessDirectionInput(DetectedDir);
        return;
    }

    // 탈출 터미널 입력 처리
    if (ActiveExtractionTerminal)
    {
        ActiveExtractionTerminal->ProcessDirectionInput(DetectedDir);
        return;
    }

    if (!bIsSelectingStratagem || bIsStratagemReady) return;

    bool bAnyValidStratagemAvailable = false;
    for (const FStratagemData& Data : StratagemList)
    {
        if (!Data.bIsOnCooldown)
        {
            bAnyValidStratagemAvailable = true;
            break;
        }
    }

    // 모두 쿨타임이면 return
    if (!bAnyValidStratagemAvailable) return;

    // 입력 스택에 추가
    CurrentInputStack.Add(DetectedDir);

    bool bAnyMatchFound = false;
    int32 CompletedIndex = -1;

    // 모든 스트라타젬 순회
    for (int32 i = 0; i < StratagemList.Num(); ++i)
    {
        // 쿨타임이면 continue
        if (StratagemList[i].bIsOnCooldown) continue;

        const TArray<EStratagemDirection>& TargetCommand = StratagemList[i].Command;
        bool bIsStillValid = true;

        // 입력된 길이만큼 비교
        for (int32 j = 0; j < CurrentInputStack.Num(); ++j)
        {
            if (j >= TargetCommand.Num() || CurrentInputStack[j] != TargetCommand[j])
            {
                bIsStillValid = false;
                break;
            }
        }

        if (bIsStillValid)
        {
            bAnyMatchFound = true;
            // 완전히 일치하는 커맨드인지 확인
            if (CurrentInputStack.Num() == TargetCommand.Num())
            {
                CompletedIndex = i;
            }
        }
    }

    // 결과 처리
    if (CompletedIndex != -1) // 커맨드 완성
    {
        FStratagemData& Selected = StratagemList[CompletedIndex];

        // 재무장 커맨드일 경우
        if (Selected.Type == EStratagemType::Rearm)
        {
            if (CanEagleRearm())
            {
                // 스택을 쓰는 스트라타젬 스택을 0으로 바꾸고 쿨다운상태로
                for (FStratagemData& Data : StratagemList)
                {
                    if (Data.bUseStack && Data.CurrentStack < Data.MaxStack && Data.CurrentStack != 0)
                    {
                        Data.CurrentStack = 0;
                        Data.bIsOnCooldown = true;
                        Data.bIsRearming = true;
                        Data.CurrentCooldown = Data.MaxCooldown;
                        if (StratagemCompleteSound) UGameplayStatics::PlaySound2D(this, StratagemCompleteSound);

                        // 이글 재무장 보이스
                        if (EagleRearmSound)
                        {
                            UGameplayStatics::PlaySoundAtLocation(this, EagleRearmSound, GetActorLocation());
                            OnSoundPlayed.Broadcast(FName("Eagle_Rearm")); // 자막
                        }
                    }
                }
                // 재무장 완료시 상태 정리 처리
                CurrentInputStack.Empty();
                bIsSelectingStratagem = false;
                bIsSelectingStratagem = false;

                OnStratagemStackUpdated.Broadcast(CurrentInputStack);
                return;
            }
            else
            {
                // 재무장 할 수 없으면 무입력 처리하거나 무시
                CurrentInputStack.Empty();
                if (StratagemErrorSound) UGameplayStatics::PlaySound2D(this, StratagemErrorSound);
            }
        }
        else
        {
            // 일반 스트라타젬
            if (StratagemCompleteSound) UGameplayStatics::PlaySound2D(this, StratagemCompleteSound);
            ActiveStratagemIndex = CompletedIndex;
            bIsStratagemReady = true;

        }
    }
    else if (!bAnyMatchFound) // 하나도 맞는 게 없으면 초기화
    {
        CurrentInputStack.Empty();

        if (StratagemErrorSound)
        {
            UGameplayStatics::PlaySound2D(this, StratagemErrorSound);
        }
    }
    else
    {
        if (StratagemInputSound)
        {
            UGameplayStatics::PlaySound2D(this, StratagemInputSound);
        }
    }

    // UI에 현재 입력 상태 전달
    OnStratagemStackUpdated.Broadcast(CurrentInputStack);
}

void AFPSCharacter::ToggleMinimap()
{
    if (!MinimapWidget) return;

    if (MinimapWidget->GetVisibility() == ESlateVisibility::Visible)
    {
        MinimapWidget->SetVisibility(ESlateVisibility::Hidden);
    }
    else
    {
        MinimapWidget->SetVisibility(ESlateVisibility::Visible);
    }
}

void AFPSCharacter::TogglePause()
{
    APlayerController* PC = Cast<APlayerController>(GetController());
    if (!PC) return;

    bool bIsPaused = UGameplayStatics::IsGamePaused(GetWorld());

    if (bIsPaused)
    {
        // 게임 재개
        if (PauseWidget)
        {
            PauseWidget->RemoveFromParent();
            PauseWidget = nullptr;
        }
        UGameplayStatics::SetGamePaused(GetWorld(), false);
        PC->bShowMouseCursor = false;
        PC->SetInputMode(FInputModeGameOnly());
    }
    else
    {
        // 게임 일시정지
        if (PauseWidgetClass)
        {
            PauseWidget = CreateWidget<UUserWidget>(PC, PauseWidgetClass);
            if (PauseWidget)
            {
                PauseWidget->AddToViewport(100); // 높은 Z-Order
            }
        }
        UGameplayStatics::SetGamePaused(GetWorld(), true);
        PC->bShowMouseCursor = true;
        PC->SetInputMode(FInputModeUIOnly());
    }
}

void AFPSCharacter::HideAllHUD()
{
    if (MainHUDWidget)
    {        
        MainHUDWidget->SetVisibility(ESlateVisibility::Hidden);
    }
    if (MinimapWidget)
    {
        MinimapWidget->SetVisibility(ESlateVisibility::Hidden);
    }
}

void AFPSCharacter::RestorePlayerState()
{
    // HUD 다시 표시
    if (MainHUDWidget)
    {
        MainHUDWidget->SetVisibility(ESlateVisibility::Visible);
    }
    if (MinimapWidget)
    {
        MinimapWidget->SetVisibility(ESlateVisibility::Hidden); // 기본 숨김 상태 유지
    }

    // 플레이어 보이기
    SetActorHiddenInGame(false);
    SetActorEnableCollision(true);

    // 캐릭터 무브먼트 활성화
    if (UCharacterMovementComponent* Movement = GetCharacterMovement())
    {
        Movement->SetMovementMode(MOVE_Walking);
    }

    // 입력 및 커서 복구
    if (APlayerController* PC = Cast<APlayerController>(GetController()))
    {
        PC->EnableInput(PC);
        PC->bShowMouseCursor = false;
        PC->SetInputMode(FInputModeGameOnly());
    }
}
