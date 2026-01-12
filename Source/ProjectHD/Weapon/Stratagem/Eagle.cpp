#include "Eagle.h"
#include "Components/AudioComponent.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

AEagle::AEagle()
{
    PrimaryActorTick.bCanEverTick = true;
    
    // SceneRoot를 생성하고 루트로 설정
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    RootComponent = SceneRoot;

    // MeshComp를 SceneRoot에 부착
    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
    MeshComp->SetupAttachment(SceneRoot);

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

    // 비행기 머리가 진행 방향을 향하도록 회전 설정
    FRotator LookAtRot = (EndLoc - StartLoc).Rotation();
    SetActorRotation(LookAtRot);
        
}

void AEagle::SpawnFlareEffect()
{
    if (FlareTemplate)
    {
        // 부착하지 않고 현재 위치의 월드에 스폰하여 액터 파괴와 무관하게 유지시킴
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

        // 가로 이동 (선형 보간)
        FVector CurrentLocation = FMath::Lerp(StartLoc, EndLoc, Alpha);

        // 세로 곡선 (포물선 느낌 - Sin 함수 활용)
        float CurveHeight = FMath::Sin(Alpha * PI) * -4000.f; // -값이면 아래로 오목한 곡선
        CurrentLocation.Z += CurveHeight;

        SetActorLocation(CurrentLocation);

        // 보이스
        if (!bVoicePlayed && Alpha >= VoiceStartAlpha)
        {
            if (EagleVoice)
            {
                UGameplayStatics::PlaySoundAtLocation(this, EagleVoice, GetActorLocation());
            }
            bVoicePlayed = true;
        }

        // 플레어 1번 스폰
        if (!bHasFiredFlare1 && Alpha >= FlareAlpha1)
        {
            SpawnFlareEffect();
            bHasFiredFlare1 = true;
        }
        
        // 플레어 2번 스폰
        if (!bHasFiredFlare2 && Alpha >= FlareAlpha2)
        {
            SpawnFlareEffect();
            bHasFiredFlare2 = true;
        }
        
        // 플레어 3번 스폰
        if (!bHasFiredFlare3 && Alpha >= FlareAlpha3)
        {
            SpawnFlareEffect();
            bHasFiredFlare3 = true;
        }

        // 비행 완료 시 제거
        if (Alpha >= 1.0f)
        {
            Destroy();
        }
    }
}
