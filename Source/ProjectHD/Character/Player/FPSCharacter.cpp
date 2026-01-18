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

AFPSCharacter::AFPSCharacter()
{
    //ASC 컴포넌트 생성
    AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

    // 서버/클라이언트 간 태그 복제 설정
    AbilitySystemComponent->SetIsReplicated(true);    

    // 헬다이버즈 상태 관리 복제 모드 설정
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

    // 캡슐 크기 설정
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

    // 캐릭터 회전 설정 (3인칭 정석)
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

    // 카메라를 캐릭터 오른쪽 어깨 쪽으로 살짝 옮김
    CameraBoom->SocketOffset = FVector(0.f, 120.f, 80.f);

    // 3인칭 카메라 설정
    ThirdPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
    ThirdPersonCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    ThirdPersonCamera->bUsePawnControlRotation = false;

    // 메시 및 총기 설정
    GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -96.f));
    WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));

    // 블루프린트에서 설정한 소켓 이름(예: WeaponSocket)에 부착
    WeaponMesh->SetupAttachment(GetMesh(), TEXT("WeaponSocket"));
    
    // 체력, 스테미나 관리용 AttributeSet
    AttributeSet = CreateDefaultSubobject<UPlayerAttributeSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* AFPSCharacter::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

float AFPSCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
    class AController* EventInstigator, AActor* DamageCauser)
{
    UE_LOG(LogTemp, Warning, TEXT("TakeDamage"));
    
    float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

    if (AttributeSet && ActualDamage > 0.0f)
    {
        float NewHealth = AttributeSet->GetHealth() - ActualDamage;        
        AttributeSet->SetHealth(FMath::Max(NewHealth, 0.0f));
        UE_LOG(LogTemp, Warning, TEXT("Health: %f"), AttributeSet->GetHealth());
    }

    return ActualDamage;
}

void AFPSCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (AbilitySystemComponent)
    {
        // ASC 초기화, 서버에서만 어빌리티 부여
        AbilitySystemComponent->InitAbilityActorInfo(this, this);        
    }
    
    // Attribute 세팅
    if (AbilitySystemComponent && AttributeSet)
    {
        // Health 속성 변화 감지
        AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
            AttributeSet->GetHealthAttribute()).AddUObject(this, &AFPSCharacter::HandleHealthChanged);

        // Stamina 속성 변화 감지
        AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
            AttributeSet->GetStaminaAttribute()).AddUObject(this, &AFPSCharacter::HandleStaminaChanged);
            
        // 초기 UI 셋팅을 위한 최초 호출
        OnHealthChanged.Broadcast(AttributeSet->GetHealth(), AttributeSet->GetMaxHealth());
        OnStaminaChanged.Broadcast(AttributeSet->GetStamina(), AttributeSet->GetMaxStamina());
    }   
        
    if (HasAuthority())
    {
        // GAS : 무기 교체 능력
        if (WeaponChangeAbilityClass)
        {
            AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(WeaponChangeAbilityClass));
        }
        
        // GAS : 달리기 능력 
        if (SprintAbilityClass)
        {
            AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(SprintAbilityClass, 1, static_cast<int32>(EAbilityInputID::Sprint)));
        }
        
        // GAS : 수류탄 던지기 능력
        if (GrenadeAbilityClass)
        {
            AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(GrenadeAbilityClass, 1, static_cast<int32>(EAbilityInputID::Grenade)));
        }
    }
    
    OnGrenadeChanged.Broadcast(CurrentGrenadeCount, MaxGrenadeCount);

    // 1, 2, 3번 무기 설정
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

            // 스트라타젬용 컨텍스트 등록 추가
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
    Bomb.bIsOnCooldown = false;
    Bomb.Type = EStratagemType::Bomb500kg;  
    
    // 이글 집속탄
    FStratagemData ClusterBomb;
    ClusterBomb.Name = TEXT("Eagle Cluster Bomb");
    ClusterBomb.Command = { EStratagemDirection::Up, EStratagemDirection::Right, EStratagemDirection::Down, EStratagemDirection::Down, EStratagemDirection::Right };
    ClusterBomb.BeaconColor = FLinearColor(1.0f, 0.5f, 0.0f); // 주황색
    ClusterBomb.MaxCooldown = 90.0f; // 이글은 쿨타임이 짧은 대신 사용 횟수 제한이 있는 경우가 많음
    ClusterBomb.CurrentCooldown = 0.0f;
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

    // 위젯 생성 및 화면 추가
    if (MainHUDWidgetClass)
    {
        MainHUDWidget = CreateWidget<UUserWidget>(GetWorld(), MainHUDWidgetClass);
        if (MainHUDWidget)
        {
            MainHUDWidget->AddToViewport();
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

    // 이미 들고 있는 무기라면 무시
    if (CurrentWeaponIndex == SlotIndex && CurrentWeaponData == WeaponInventory[SlotIndex].WeaponData)
    {
        return;
    }
    
    if (AbilitySystemComponent)
    {
        FGameplayEventData Payload;
        Payload.EventTag = FGameplayTag::RequestGameplayTag(FName("Event.Weapon.Swap"));
        
        // 슬롯 정보를 담아 보냄
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

void AFPSCharacter::UpdateAimOffset(float DeltaTime)
{
    // 컨트롤러의 회전값과 캐릭터의 회전값 차이
    FRotator ControlRotation = GetControlRotation();
    FRotator ActorRotation = GetActorRotation();
    
    // 두 회전값의 차이(Delta)를 정규화하여 추출
    FRotator Delta = (ControlRotation - ActorRotation).GetNormalized();

    // Pitch 값 저장
    AimPitch = FMath::FInterpTo(AimPitch, Delta.Pitch, DeltaTime, 15.0f);
}

void AFPSCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    UpdateAimOffset(DeltaTime);

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
            }
        }
    }
}

void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
    {
        // 이동 및 시선 처리
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFPSCharacter::Move);
        EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFPSCharacter::Look);

        // 점프
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
        EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

        // 달리기
        EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Triggered, this, &AFPSCharacter::OnSprintStarted);
        EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &AFPSCharacter::OnSprintCompleted);
        
        // 수류탄 던지기
        EnhancedInputComponent->BindAction(GrenadeAction, ETriggerEvent::Started, this, &AFPSCharacter::OnGrenadeStart);
        //EnhancedInputComponent->BindAction(GrenadeAction, ETriggerEvent::Completed, this, &AFPSCharacter::OnGrenadeCompleted);
        
        // 주사기 사용
        EnhancedInputComponent->BindAction(StimAction, ETriggerEvent::Started, this, &AFPSCharacter::OnStimStart);
        
        // 사격 (FireWeapon 함수 연결)
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

        // 무기 슬롯 선택 바인딩
        EnhancedInputComponent->BindAction(WeaponSlot1Action, ETriggerEvent::Started, this, &AFPSCharacter::OnSelectWeapon1);
        EnhancedInputComponent->BindAction(WeaponSlot2Action, ETriggerEvent::Started, this, &AFPSCharacter::OnSelectWeapon2);
        EnhancedInputComponent->BindAction(WeaponSlot3Action, ETriggerEvent::Started, this, &AFPSCharacter::OnSelectWeapon3);

        // Q 키 (메뉴 열기/닫기)
        EnhancedInputComponent->BindAction(StratagemMenuAction, ETriggerEvent::Started, this, &AFPSCharacter::OnStratagemMenuAction);
        //EnhancedInputComponent->BindAction(StratagemMenuAction, ETriggerEvent::Completed, this, &AFPSCharacter::OnStratagemMenuAction);

        // 스트라타젬 방향 입력
        EnhancedInputComponent->BindAction(StratagemInputAction, ETriggerEvent::Triggered, this, &AFPSCharacter::OnStratagemInputAction);
        
        // 상호작용 입력
        EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &AFPSCharacter::OnInteract);
    }
}

void AFPSCharacter::Move(const FInputActionValue& Value)
{
    FVector2D MovementVector = Value.Get<FVector2D>();

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
}

void AFPSCharacter::HandleStaminaChanged(const FOnAttributeChangeData& Data)
{
    float NewStamina = Data.NewValue;
    OnStaminaChanged.Broadcast(NewStamina, AttributeSet->GetMaxStamina());

    // 스테미나가 0 이하로 떨어지면 OnSprintCompleted를 호출해 2초 패널티 시작
    if (NewStamina <= 0.0f)
    {
        OnSprintCompleted(); 
        
        // GAS 내부적으로 Sprint 입력을 Release 처리해서 어빌리티를 강제 종료
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
    
    // 무기 별 위치 조정
    WeaponMesh->SetRelativeLocation(NewWeaponData->GripLocationOffset);
    WeaponMesh->SetRelativeRotation(NewWeaponData->GripRotationOffset);

    // 인벤토리에서 새 무기 정보를 찾아 캐릭터 변수에 동기화
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

    // 인벤토리에 없는 새 무기라면 추가
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
            // 새로운 무기의 레이어를 메인 ABP에 링크
            AnimInst->LinkAnimClassLayers(NewWeaponData->WeaponAnimLayer);
        }
    }

    // 현재 무기의 장전 몽타주 갱신
    CurrentReloadMontage = NewWeaponData->ReloadMontage;

    // UI 갱신 델리게이트 호출
    OnAmmoChanged.Broadcast(CurrentAmmo, CurrentMagCount, MaxMagCount);
}

// GAS : 달리기
void AFPSCharacter::OnSprintStarted()
{        
    bSprintButtonDown = true;
    
    // 조준 중이거나 사격 중이면 입력만 저장하고 리턴
    if (bIsAiming || bFireButtonDown) return;

    if (AbilitySystemComponent)
    {
        float CurrentStamina = AttributeSet->GetStamina();
        
        // 스테미나가 0보다 크다면, 2초 대기 중이라도 즉시 태그 제거
        if (CurrentStamina > 0.0f)
        {
            FGameplayTag ExhaustedTag = FGameplayTag::RequestGameplayTag(FName("State.Exhausted"));
            AbilitySystemComponent->RemoveLooseGameplayTag(ExhaustedTag);
            
            // 2초 회복 타이머 중단
            GetWorldTimerManager().ClearTimer(TimerHandle_StaminaRegen);
            
            // 기존 회복 효과 제거
            AbilitySystemComponent->RemoveActiveGameplayEffectBySourceEffect(StaminaRegenEffectClass, AbilitySystemComponent);

            // 달리기 실행
            AbilitySystemComponent->AbilityLocalInputPressed(static_cast<int32>(EAbilityInputID::Sprint));
        }
    }
}

void AFPSCharacter::OnSprintCompleted()
{
    bSprintButtonDown = false;
    
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

void AFPSCharacter::StartStaminaRegen()
{
    if (AbilitySystemComponent)
    {
        // 탈진 태그 제거
        FGameplayTag ExhaustedTag = FGameplayTag::RequestGameplayTag(FName("State.Exhausted"));
        AbilitySystemComponent->RemoveLooseGameplayTag(ExhaustedTag);

        // 스테미나 회복 GE 적용
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

// 수류탄 던지기
void AFPSCharacter::OnGrenadeStart()
{
    if (bIsReloading || bIsUsingStim) return;
    
    // 수류탄이 0개보다 많을 때만 실행
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
    // 개수 및 상태 체크
    if (CurrentStimCount <= 0 || bIsReloading || bIsThrowingGrenade || bIsUsingStim) return;
        
    UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
    
    // 주사기 몽타주가 할당되어 있고 재생 가능한지 확인
    if (AnimInstance && StimMontage)
    {
        bIsUsingStim = true;
        
        // 주사기 애니메이션 재생
        AnimInstance->Montage_Play(StimMontage, 1.0f);
        
    }
}

void AFPSCharacter::OnInteract()
{
    FHitResult Hit;
    FVector Start = GetActorLocation()+ FVector(0, -30.f, 80.f);
    FVector Forward = ThirdPersonCamera->GetForwardVector();
    FVector End = Start + (Forward * 300.0f);

    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);

    // 구체 반지름
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
            // 탈진 상태 제거 및 GE 적용
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
    bFireButtonDown = true;
    
    if (!bIsAiming) return;
    
    if (bIsStratagemReady)
    {
        ThrowBeacon();
        return;
    }

    // GAS : 입력 ID를 통해 사격 어빌리티 실행
    if (AbilitySystemComponent)
    {
        AbilitySystemComponent->AbilityLocalInputPressed(static_cast<int32>(EAbilityInputID::Fire));
    }
}

void AFPSCharacter::StartFiring()
{
    // 첫 발 즉시 발사
    FireWeapon();

    // FireRate에 맞춰 반복 타이머 설정 (1.0 / 10.0 = 0.1초 간격)
    float TimeBetweenShots = 1.0f / FireRate;
    GetWorldTimerManager().SetTimer(TimerHandle_AutomaticFire, this, &AFPSCharacter::FireWeapon, TimeBetweenShots, true);
}

void AFPSCharacter::OnFireCompleted()
{
    bFireButtonDown = false;

    // GAS : 입력이 사라짐을 어빌리티에 알림
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
    if (CurrentAmmo >= MaxAmmoInMag || CurrentMagCount <= 0 || bIsReloading || bIsThrowingGrenade || bIsUsingStim) return;
    
    if (bSprintButtonDown)
    {
        GetCharacterMovement()->MaxWalkSpeed = SprintWalkSpeed;
    }
    
    bIsReloading = true;

    // GAS Reload
    if (AbilitySystemComponent)
    {
        // 입력 ID를 통한 실행 (미리 정의한 EAbilityInputID::Reload 사용)
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

        // 재장전이 끝날을 때 버튼 누르고있으면 바로 사격
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
    // 조준 중이 아니고 사격 버튼을 떼서 타이머가 끝난 시점일 때만 복구
    if (!bIsAiming)
    {
        bUseControllerRotationYaw = false;
        GetCharacterMovement()->bOrientRotationToMovement = true;
    }
}

void AFPSCharacter::OnAimStarted_Implementation()
{    
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
    // ThirdPersonCamera를 사격의 기준으로 사용
    if (!ThirdPersonCamera || !CurrentWeaponData) return;    

    FVector Start = ThirdPersonCamera->GetComponentLocation();
    FVector ForwardVector = ThirdPersonCamera->GetForwardVector();
    FVector End = Start + (ForwardVector * FireRange);

    FHitResult HitResult;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this); // 자신은 맞지 않음

    bool bHit = GetWorld()->LineTraceSingleByChannel(
        HitResult,
        Start,
        End,
        ECollisionChannel::ECC_Visibility,
        Params
    );

    if (APlayerController* PC = Cast<APlayerController>(GetController()))
    {
        // 위로 튀는 반동 (Pitch는 음수 값이 위로 올라감)
        AddControllerPitchInput(-RecoilPitch);

        // 좌우로 무작위하게 흔들리는 반동
        float RandomYaw = FMath::FRandRange(-RecoilYaw, RecoilYaw);
        AddControllerYawInput(RandomYaw);
    }

    if (CurrentWeaponData->ProjectileClass)
    {
        FVector MuzzleLocation = WeaponMesh->GetSocketLocation(TEXT("MuzzleSocket"));
        FRotator MuzzleRotation = WeaponMesh->GetSocketRotation(TEXT("MuzzleSocket"));

        // 화면 정중앙(에임)이 가리키는 실제 월드 좌표를 찾기 위해 라인 트레이스 사용
        FVector LookAtLocation;
        FVector CameraLocation = ThirdPersonCamera->GetComponentLocation();
        FVector CameraForward = ThirdPersonCamera->GetForwardVector();
        FVector TraceEnd = CameraLocation + (CameraForward * FireRange);

        FHitResult AimHitResult;
        FCollisionQueryParams QueryParams;
        QueryParams.AddIgnoredActor(this);

        // 카메라 정면으로 무엇이 있는지 확인
        if (GetWorld()->LineTraceSingleByChannel(AimHitResult, CameraLocation, TraceEnd, ECC_Visibility, QueryParams))
        {
            LookAtLocation = AimHitResult.ImpactPoint; // 부딪힌 곳
        }
        else
        {
            LookAtLocation = TraceEnd; // 허공일 경우 아주 먼 곳
        }

        // 총구에서 '에임이 가리키는 지점'을 바라보는 회전값 계산
        FRotator TargetRotation = (LookAtLocation - MuzzleLocation).Rotation();

        FActorSpawnParameters ActorSpawnParams;
        ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
        ActorSpawnParams.Owner = this;

        // 총구 화염 스폰
        if (MuzzleFlashFX)
        {
            UNiagaraFunctionLibrary::SpawnSystemAtLocation(
                GetWorld(),
                MuzzleFlashFX,
                MuzzleLocation,
                MuzzleRotation
            );
        }

        // 사격 사운드
        if (FireSound)
        {
            UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
        }

        APlayerController* PC = Cast<APlayerController>(GetController());
        if (PC && FireCameraShakeClass)
        {
            //카메라 흔들기
            PC->ClientStartCameraShake(FireCameraShakeClass);
        }
        
        // 현재 장착중인 무기에서 소음 반경 가져오기
        float CurrentSoundRadius = CurrentWeaponData->SoundRadius;
        //DrawDebugSphere(GetWorld(), GetActorLocation(), CurrentWeaponData->SoundRadius, 32, FColor::Yellow, false, 3.0f);
        
        // 사격 소음 전파
        TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
        ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));

        TArray<AActor*> OutActors;
        TArray<AActor*> ActorsToIgnore;
        ActorsToIgnore.Add(this);

        bool bHasOverlap = UKismetSystemLibrary::SphereOverlapActors(
            GetWorld(), 
            GetActorLocation(), 
            CurrentSoundRadius, 
            ObjectTypes, 
            ACharacter::StaticClass(), 
            ActorsToIgnore, 
            OutActors
        );

        if (bHasOverlap)
        {
            for (AActor* OverlappedActor : OutActors)
            {            
                // Enemy 태그를 가진 적들에게 소음 전달
                if (OverlappedActor && OverlappedActor->ActorHasTag(TEXT("Enemy")))
                {
                    UGameplayStatics::ApplyDamage(
                        OverlappedActor, 
                        0.01f,
                        GetController(),
                        this, 
                        UDamageType::StaticClass()
                    );
                }
            }
        }

        // 최종 발사
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

            // 몽타주의 실제 길이 가져오기
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
    if (!BeaconClass) return;

    FVector SpawnLocation = WeaponMesh->GetSocketLocation(TEXT("MuzzleSocket"));
    FRotator ControlRot = GetControlRotation();
    FRotator SpawnRotation = FRotator(0.f, ControlRot.Yaw, 0.f);

    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = this;
    SpawnParams.Instigator = GetInstigator();

    // 비컨 스폰
    AStratagemBeacon* SpawnedBeacon = GetWorld()->SpawnActor<AStratagemBeacon>(
        BeaconClass,
        SpawnLocation,
        SpawnRotation,
        SpawnParams
    );

    // 성공적으로 스폰되었다면 설정 적용
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

    // 상태 초기화
    CurrentInputStack.Empty();
    bIsStratagemReady = false;
    bIsSelectingStratagem = false;
    CurrentCommandStep = 0;

    // UI 초기화 신호 (빈 스택 전송)
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
    }
    else
    {
        // 메뉴를 닫을 때 입력 스택 초기화
        CurrentInputStack.Empty();
        bIsStratagemReady = false;

        // UI에 빈 스택을 보내서 화살표들을 다시 회색으로 만듦
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

    // 모두 쿨타임중이면 return
    if (!bAnyValidStratagemAvailable) return;

    FVector2D InputValue = Value.Get<FVector2D>();    
    
    EStratagemDirection DetectedDir = EStratagemDirection::None;

    // Vector2D 값을 분석하여 방향 결정
    if (InputValue.Y > 0.5f) DetectedDir = EStratagemDirection::Up;
    else if (InputValue.Y < -0.5f) DetectedDir = EStratagemDirection::Down;
    else if (InputValue.X < -0.5f) DetectedDir = EStratagemDirection::Left;
    else if (InputValue.X > 0.5f) DetectedDir = EStratagemDirection::Right;

    if (DetectedDir == EStratagemDirection::None) return;

    // 입력 스택에 추가
    CurrentInputStack.Add(DetectedDir);

    bool bAnyMatchFound = false;
    int32 CompletedIndex = -1;

    // 모든 스트라타젬 조사
    for (int32 i = 0; i < StratagemList.Num(); ++i)
    {
        // 쿨타임이면 continue
        if (StratagemList[i].bIsOnCooldown) continue;

        const TArray<EStratagemDirection>& TargetCommand = StratagemList[i].Command;
        bool bIsStillValid = true;

        // 입력한 길이만큼 대조
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
            // 완전히 끝까지 맞췄는지 확인
            if (CurrentInputStack.Num() == TargetCommand.Num())
            {
                CompletedIndex = i;
            }
        }
    }

    // 결과 처리
    if (CompletedIndex != -1) // 최종 완성
    {
        ActiveStratagemIndex = CompletedIndex;
        bIsStratagemReady = true;

        if (StratagemCompleteSound)
        {
            UGameplayStatics::PlaySound2D(this, StratagemCompleteSound);
        }

        //bIsSelectingStratagem = false;
    }
    else if (!bAnyMatchFound) // 하나라도 맞는 게 없으면 리셋
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
