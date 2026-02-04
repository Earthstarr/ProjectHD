#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectHD/SubtitleTypes.h" // �ڸ�

#include "Eagle.generated.h"


UCLASS()
class PROJECTHD_API AEagle : public AActor
{
    GENERATED_BODY()

public:
    AEagle();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // �������� ȣ���Ͽ� ���� ���� ������ �� ���� ����
    void InitEagle(FVector Start, FVector End, float Duration);
    
    UPROPERTY(BlueprintAssignable, Category = "Audio")
    FOnSoundPlayedSignature OnSoundPlayed;  // �ڸ�

private:
    
    UPROPERTY(VisibleAnywhere)
    class USceneComponent* SceneRoot;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* MeshComp;

    // 날개 트레일
    UPROPERTY(VisibleAnywhere, Category = "Effects")
    class UNiagaraComponent* LeftWingTrail;

    UPROPERTY(VisibleAnywhere, Category = "Effects")
    class UNiagaraComponent* RightWingTrail;

    UPROPERTY(EditAnywhere, Category = "Effects")
    class UNiagaraSystem* WingTrailTemplate;

    UPROPERTY(EditAnywhere, Category = "Effects")
    FVector LeftWingOffset = FVector(0.f, -300.f, 0.f);

    UPROPERTY(EditAnywhere, Category = "Effects")
    FVector RightWingOffset = FVector(0.f, 300.f, 0.f);

    UPROPERTY(EditAnywhere, Category = "Effects")
    class USoundBase* EagleVoice;
    
    UPROPERTY(EditAnywhere, Category = "Effects")
    class UNiagaraSystem* FlareTemplate;

    // �÷�� �Ѹ��� ������ ���� (0.0 ~ 1.0)
    UPROPERTY(EditAnywhere, Category = "Effects")
    float FlareAlpha1 = 0.4f;
        
    UPROPERTY(EditAnywhere, Category = "Effects")
    float FlareAlpha2 = 0.42f;
    
    UPROPERTY(EditAnywhere, Category = "Effects")
    float FlareAlpha3 = 0.45f;
    
    // �̱� ���̽� ����
    UPROPERTY(EditAnywhere, Category = "Effects")
    float VoiceStartAlpha = 0.2f;

    bool bVoicePlayed = false;
    bool bHasFiredFlare1 = false;
    bool bHasFiredFlare2 = false;
    bool bHasFiredFlare3 = false;
    
    FVector StartLoc;
    FVector EndLoc;
    float FlightDuration;
    float ElapsedTime;
    bool bIsFlying;
    
    // �÷��� �Լ�
    void SpawnFlareEffect();
};