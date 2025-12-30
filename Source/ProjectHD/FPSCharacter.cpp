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
#include "HDProjectile.h"
#include "NiagaraFunctionLibrary.h"
#include "StratagemBeacon.h"
#include "GameFramework/ProjectileMovementComponent.h"

AFPSCharacter::AFPSCharacter()
{
    // 1. 캡슐 크기 설정
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

    // 2. 캐릭터 회전 설정 (3인칭 정석)
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 300.0f, 0.0f);

    // 3. 스프링 암(CameraBoom) 설정 - 헬다이버즈 스타일 숄더 뷰
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
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -96.f));
    WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));

    // 블루프린트에서 설정한 소켓 이름(예: WeaponSocket)에 부착
    WeaponMesh->SetupAttachment(GetMesh(), TEXT("WeaponSocket"));
}

void AFPSCharacter::BeginPlay()
{
    Super::BeginPlay();
    
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

    // 폭탄
    FStratagemData Bomb;
    Bomb.Name = TEXT("500kg Bomb");
    Bomb.Command = { EStratagemDirection::Up, EStratagemDirection::Right, EStratagemDirection::Down, EStratagemDirection::Down, EStratagemDirection::Down };
    Bomb.BeaconColor = FLinearColor::Red;
    StratagemList.Add(Bomb);

    // 보급품 (파랑)
    FStratagemData Supply;  
    Supply.Name = TEXT("Supply Pod");
    Supply.Command = { EStratagemDirection::Down, EStratagemDirection::Down, EStratagemDirection::Up, EStratagemDirection::Right };
    Supply.BeaconColor = FLinearColor::Blue;
    StratagemList.Add(Supply);

    // 위젯 생성 및 화면 추가
    if (MainHUDWidgetClass)
    {
        MainHUDWidget = CreateWidget<UUserWidget>(GetWorld(), MainHUDWidgetClass);
        if (MainHUDWidget)
        {
            MainHUDWidget->AddToViewport();
        }
    }

    OnAmmoChanged.Broadcast(CurrentAmmo, CurrentMagCount, MaxMagCount);

    
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

        // Q 키 (메뉴 열기/닫기)
        EnhancedInputComponent->BindAction(StratagemMenuAction, ETriggerEvent::Started, this, &AFPSCharacter::OnStratagemMenuAction);
        //EnhancedInputComponent->BindAction(StratagemMenuAction, ETriggerEvent::Completed, this, &AFPSCharacter::OnStratagemMenuAction);

        // 방향 입력
        EnhancedInputComponent->BindAction(StratagemInputAction, ETriggerEvent::Started, this, &AFPSCharacter::OnStratagemInputAction);
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

void AFPSCharacter::OnFireStarted()
{
    bFireButtonDown = true;

    if (bIsStratagemReady)
    {
        ThrowBeacon();
        return;
    }

    if (!bIsAiming || bIsReloading) return;

    // 1. 회전 모드 전환 (복구 타이머 취소)
    GetWorldTimerManager().ClearTimer(TimerHandle_RotationReset);
    bUseControllerRotationYaw = true;
    GetCharacterMovement()->bOrientRotationToMovement = false;

    // 2. 연사 시작
    StartFiring();
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

    // 연사 타이머 중지
    StopFiring();

    // 일정 시간 뒤 회전 모드 복구 예약
    GetWorldTimerManager().SetTimer(
        TimerHandle_RotationReset,
        this,
        &AFPSCharacter::ResetRotationMode,
        AimRotationRecoveryTime,
        false
    );
}

void AFPSCharacter::StopFiring()
{
    GetWorldTimerManager().ClearTimer(TimerHandle_AutomaticFire);
}

void AFPSCharacter::Reload()
{
    if (CurrentAmmo >= MaxAmmoInMag || CurrentMagCount <= 0 || bIsReloading) return;

    bIsReloading = true;

    if (bIsAiming)
    {
        OnAimCompleted();
    }

    StopFiring();

    GetCharacterMovement()->MaxWalkSpeed = ReloadWalkSpeed;

    if (ReloadMontage)
    {
        if (ReloadSound)
        {
            UGameplayStatics::PlaySoundAtLocation(this, ReloadSound, GetActorLocation());
        }
        PlayAnimMontage(ReloadMontage);
    }
    else
    {
        FinishReload();
    }
}



void AFPSCharacter::FinishReload()
{
    bIsReloading = false;

    if (bIsAiming)
    {
        // 조준 속도 적용
        GetCharacterMovement()->MaxWalkSpeed = AimWalkSpeed;

        if (bFireButtonDown)
        {
            StartFiring();
        }
    }
    else
    {
        GetCharacterMovement()->MaxWalkSpeed = NormalWalkSpeed;
    }

    CurrentMagCount--;
    CurrentAmmo = MaxAmmoInMag;

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

    GetWorldTimerManager().ClearTimer(TimerHandle_RotationReset);
    bUseControllerRotationYaw = true;
    GetCharacterMovement()->bOrientRotationToMovement = false;

    bool bIsPlayingReload = GetMesh()->GetAnimInstance()->Montage_IsPlaying(ReloadMontage);
    if (bIsReloading || bIsPlayingReload) return;    
    
    GetCharacterMovement()->MaxWalkSpeed = AimWalkSpeed;
}

void AFPSCharacter::OnAimCompleted_Implementation()
{
    bAimButtonDown = false;
    bIsAiming = false;

    if (!bIsReloading)
    {
        GetCharacterMovement()->MaxWalkSpeed = NormalWalkSpeed;
    }    

    StopFiring();
    ResetRotationMode();

}

void AFPSCharacter::FireWeapon()
{
    // ThirdPersonCamera를 사격의 기준으로 사용
    if (!ThirdPersonCamera) return;
    if (CurrentAmmo <= 0 || bIsReloading)
    {
        StopFiring();
        return;
    }

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
        // 1. 위로 튀는 반동 (Pitch는 음수 값이 위로 올라감)
        AddControllerPitchInput(-RecoilPitch);

        // 2. 좌우로 무작위하게 흔들리는 반동 (선택 사항)
        // -RecoilYaw ~ RecoilYaw 사이의 랜덤한 값을 더해 좌우 반동 구현
        float RandomYaw = FMath::FRandRange(-RecoilYaw, RecoilYaw);
        AddControllerYawInput(RandomYaw);
    }

    if (ProjectileClass)
    {
        FVector MuzzleLocation = WeaponMesh->GetSocketLocation(TEXT("MuzzleSocket"));
        FRotator MuzzleRotation = WeaponMesh->GetSocketRotation(TEXT("MuzzleSocket"));

        // 1. 화면 정중앙(에임)이 가리키는 실제 월드 좌표를 찾기 위해 라인 트레이스 사용
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

        // 2. 총구에서 '에임이 가리키는 지점'을 바라보는 회전값 계산
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
            // 클라이언트의 카메라를 흔듭니다.
            PC->ClientStartCameraShake(FireCameraShakeClass);
        }

        // 최종 발사
        GetWorld()->SpawnActor<AHDProjectile>(ProjectileClass, MuzzleLocation, TargetRotation, ActorSpawnParams);

        CurrentAmmo--;

        OnAmmoChanged.Broadcast(CurrentAmmo, CurrentMagCount, MaxMagCount);
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
    CurrentCommandStep = 0;

    // UI 초기화 신호 (빈 스택 전송)
    OnStratagemStackUpdated.Broadcast(CurrentInputStack);
}

void AFPSCharacter::OnStratagemMenuAction(const FInputActionValue& Value)
{
    bIsSelectingStratagem = !bIsSelectingStratagem;

    if (bIsSelectingStratagem)
    {
        CurrentCommandStep = 0;   
        OnStratagemStepUpdated.Broadcast(CurrentCommandStep);
    }
    else
    {
        // 2. 메뉴를 닫을 때 입력 스택 초기화
        CurrentInputStack.Empty();
        bIsStratagemReady = false;

        // 3. UI에 빈 스택을 보내서 화살표들을 다시 회색으로 만듦
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

    FVector2D InputValue = Value.Get<FVector2D>();
    EStratagemDirection DetectedDir = EStratagemDirection::None;

    // Vector2D 값을 분석하여 방향 결정
    if (InputValue.Y > 0.5f) DetectedDir = EStratagemDirection::Up;
    else if (InputValue.Y < -0.5f) DetectedDir = EStratagemDirection::Down;
    else if (InputValue.X < -0.5f) DetectedDir = EStratagemDirection::Left;
    else if (InputValue.X > 0.5f) DetectedDir = EStratagemDirection::Right;

    if (DetectedDir == EStratagemDirection::None) return;

    // 2. 입력 스택에 추가
    CurrentInputStack.Add(DetectedDir);

    bool bAnyMatchFound = false;
    int32 CompletedIndex = -1;

    // 3. 모든 스트라타젬 전수 조사
    for (int32 i = 0; i < StratagemList.Num(); ++i)
    {
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

    // 4. 결과 처리
    if (CompletedIndex != -1) // 최종 완성
    {
        ActiveStratagemIndex = CompletedIndex;
        bIsStratagemReady = true;
        //bIsSelectingStratagem = false;
        UE_LOG(LogTemp, Warning, TEXT("%s Complete!"), *StratagemList[CompletedIndex].Name);
    }
    else if (!bAnyMatchFound) // 하나라도 맞는 게 없으면 리셋
    {
        CurrentInputStack.Empty();
        UE_LOG(LogTemp, Error, TEXT("Error"));
    }

    // UI에 현재 입력 상태 전달
    OnStratagemStackUpdated.Broadcast(CurrentInputStack);
}