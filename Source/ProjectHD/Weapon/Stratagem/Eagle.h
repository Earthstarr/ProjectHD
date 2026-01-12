#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

    // 비컨에서 호출하여 비행 시작 지점과 끝 지점 설정
    void InitEagle(FVector Start, FVector End, float Duration);

private:
    
    UPROPERTY(VisibleAnywhere)
    class USceneComponent* SceneRoot;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* MeshComp;

    UPROPERTY(EditAnywhere, Category = "Effects")
    class USoundBase* EagleVoice;
    
    UPROPERTY(EditAnywhere, Category = "Effects")
    class UNiagaraSystem* FlareTemplate;

    // 플레어를 뿌리기 시작할 시점 (0.0 ~ 1.0)
    UPROPERTY(EditAnywhere, Category = "Effects")
    float FlareAlpha1 = 0.5f;
        
    UPROPERTY(EditAnywhere, Category = "Effects")
    float FlareAlpha2 = 0.55f;
    
    UPROPERTY(EditAnywhere, Category = "Effects")
    float FlareAlpha3 = 0.7f;
    
    // 이글 보이스 시점
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
    
    // 플레어 함수
    void SpawnFlareEffect();
};