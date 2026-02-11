#include "Eagle.h"
#include "Components/AudioComponent.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

AEagle::AEagle()
{
    PrimaryActorTick.bCanEverTick = true;

    // SceneRoot 생성
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    RootComponent = SceneRoot;

    // MeshComp를 SceneRoot에 붙임
    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
    MeshComp->SetupAttachment(SceneRoot);

    // 날개 트레일 컴포넌트 생성
    LeftWingTrail = CreateDefaultSubobject<UNiagaraComponent>(TEXT("LeftWingTrail"));
    LeftWingTrail->SetupAttachment(SceneRoot);
    LeftWingTrail->bAutoActivate = true;
    LeftWingTrail->SetAutoDestroy(false);

    RightWingTrail = CreateDefaultSubobject<UNiagaraComponent>(TEXT("RightWingTrail"));
    RightWingTrail->SetupAttachment(SceneRoot);
    RightWingTrail->bAutoActivate = true;
    RightWingTrail->SetAutoDestroy(false);

    bIsFlying = false;
    ElapsedTime = 0.f;
}

void AEagle::BeginPlay()
{
    Super::BeginPlay();
}

void AEagle::InitEagle(FVector Start, FVector End, float Duration)
{
    StartLoc = Start;
    EndLoc = End;
    FlightDuration = Duration;
    bIsFlying = true;

    SetActorLocation(StartLoc);

    // 이글이 끝 위치를 향하도록 회전 설정
    FRotator LookAtRot = (EndLoc - StartLoc).Rotation();
    SetActorRotation(LookAtRot);
}

void AEagle::SpawnFlareEffect()
{
    if (FlareTemplate)
    {
        // 부착하지 않고 현재 위치에 월드 스폰하여 자연 소멸시킴
        UNiagaraFunctionLibrary::SpawnSystemAtLocation(
            GetWorld(),
            FlareTemplate,
            GetActorLocation(),
            (GetActorRotation() + FRotator(90.f, 0.f, 90.f))
        );
    }
}

void AEagle::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bIsFlying)
    {
        ElapsedTime += DeltaTime;
        float Alpha = ElapsedTime / FlightDuration;

        // 선형 이동 (직선 비행)
        FVector CurrentLocation = FMath::Lerp(StartLoc, EndLoc, Alpha);

        // 곡선 (CurveAxis 방향으로 Sin 곡선 적용)
        float CurveOffset = FMath::Sin(Alpha * PI) * CurveHeight;
        CurrentLocation += CurveAxis * CurveOffset;

        SetActorLocation(CurrentLocation);

        // 이동 방향에 따른 회전 (곡선의 접선 방향)
        FVector TangentDirection = EndLoc - StartLoc;
        TangentDirection += CurveAxis * CurveHeight * PI * FMath::Cos(Alpha * PI);
        SetActorRotation(TangentDirection.GetSafeNormal().Rotation());


        // 보이스
        if (!bVoicePlayed && Alpha >= VoiceStartAlpha)
        {
            if (EagleVoice)
            {
                UGameplayStatics::PlaySoundAtLocation(this, EagleVoice, GetActorLocation());
                OnSoundPlayed.Broadcast(FName("Eagle_Bomb")); // 자막
            }
            bVoicePlayed = true;
        }

        // 플레어 1차 발사
        if (!bHasFiredFlare1 && Alpha >= FlareAlpha1)
        {
            SpawnFlareEffect();
            bHasFiredFlare1 = true;
        }

        // 플레어 2차 발사
        if (!bHasFiredFlare2 && Alpha >= FlareAlpha2)
        {
            SpawnFlareEffect();
            bHasFiredFlare2 = true;
        }

        // 플레어 3차 발사
        if (!bHasFiredFlare3 && Alpha >= FlareAlpha3)
        {
            SpawnFlareEffect();
            bHasFiredFlare3 = true;
        }

        // 비행 완료 → 페이드아웃 시작
        if (Alpha >= 1.0f)
        {
            bIsFlying = false;
            bIsFadingOut = true;
            FadeOutElapsed = 0.0f;

            // 트레일 새 파티클 중단 (기존 파티클은 자연 소멸)
            if (LeftWingTrail) LeftWingTrail->Deactivate();
            if (RightWingTrail) RightWingTrail->Deactivate();

            MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        }
    }

    // 페이드아웃 (메쉬 스케일 축소)
    if (bIsFadingOut)
    {
        FadeOutElapsed += DeltaTime;
        float FadeAlpha = FMath::Clamp(1.0f - (FadeOutElapsed / FadeOutDuration), 0.0f, 1.0f);
        MeshComp->SetWorldScale3D(FVector(FadeAlpha));

        if (FadeOutElapsed >= FadeOutDuration)
        {
            MeshComp->SetVisibility(false);
        }

        // 트레일 자연 소멸 대기 후 액터 제거
        if (FadeOutElapsed >= FadeOutDuration + TrailLingerTime)
        {
            Destroy();
        }
    }
}
