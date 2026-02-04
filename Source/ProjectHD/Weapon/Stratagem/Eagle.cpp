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

    // ����� �Ӹ��� ���� ������ ���ϵ��� ȸ�� ����
    FRotator LookAtRot = (EndLoc - StartLoc).Rotation();
    SetActorRotation(LookAtRot);        
}

void AEagle::SpawnFlareEffect()
{
    if (FlareTemplate)
    {
        // �������� �ʰ� ���� ��ġ�� ���忡 �����Ͽ� ���� �ı��� �����ϰ� ������Ŵ
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

        // ���� �̵� (���� ����)
        FVector CurrentLocation = FMath::Lerp(StartLoc, EndLoc, Alpha);

        // ���� � (������ ���� - Sin �Լ� Ȱ��)
        float CurveHeight = FMath::Sin(Alpha * PI) * -135000.f; // -���̸� �Ʒ��� ������ �
        CurrentLocation.Z += CurveHeight;

        SetActorLocation(CurrentLocation);

        // ���̽�
        if (!bVoicePlayed && Alpha >= VoiceStartAlpha)
        {
            if (EagleVoice)
            {
                UGameplayStatics::PlaySoundAtLocation(this, EagleVoice, GetActorLocation());
                OnSoundPlayed.Broadcast(FName("Eagle_Bomb")); // �ڸ�
            }
            bVoicePlayed = true;
        }

        // �÷��� 1�� ����
        if (!bHasFiredFlare1 && Alpha >= FlareAlpha1)
        {
            SpawnFlareEffect();
            bHasFiredFlare1 = true;
        }
        
        // �÷��� 2�� ����
        if (!bHasFiredFlare2 && Alpha >= FlareAlpha2)
        {
            SpawnFlareEffect();
            bHasFiredFlare2 = true;
        }    
        
        // �÷��� 3�� ����
        if (!bHasFiredFlare3 && Alpha >= FlareAlpha3)
        {
            SpawnFlareEffect();
            bHasFiredFlare3 = true;
        }       

        // ���� �Ϸ� �� ����
        if (Alpha >= 1.0f)
        {
            bIsFlying = false;
           
            if (LeftWingTrail) 
            { 
                LeftWingTrail->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
                //LeftWingTrail->Deactivate(); // 새로운 입자 생성만 중단
            }
            if (RightWingTrail) 
            { 
                RightWingTrail->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
                //RightWingTrail->Deactivate(); 
            }
            
            MeshComp->SetVisibility(false);
            MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
            
            Destroy();
        }
    }
}
