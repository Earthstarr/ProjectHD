#pragma once

#include "CoreMinimal.h"
#include "HDProjectile.h" // 부모 클래스 헤더
#include "HDBombProjectile.generated.h"



UCLASS()
class PROJECTHD_API AHDBombProjectile : public AHDProjectile // 부모 상속
{
    GENERATED_BODY()

public:
    AHDBombProjectile();

protected:

    virtual void BeginPlay() override;

    // 부모의 OnHit을 덮어쓰기 위해 가상 함수(virtual)로 선언
    virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;

    UPROPERTY(EditAnywhere, Category = "Explosion")
    float ExplosionRadius = 800.f;
    
    // 땅에 부딪힐때 이펙트와 사운드
    UPROPERTY(EditDefaultsOnly, Category = "Effects")
    UNiagaraSystem* LandImpactEffect;

    UPROPERTY(EditDefaultsOnly, Category = "Effects")
    USoundBase* LandImpactSound;

    // 땅으로 떨어지는 소리
    UPROPERTY(VisibleAnywhere, Category = "Effects")
    class UAudioComponent* FallingAudioComp;

    UPROPERTY(EditAnywhere, Category = "Effects")
    class USoundBase* FallingSound;

    void Explode();

    // 카메라 흔들림
    UPROPERTY(EditAnywhere, Category = "Effects")
    TSubclassOf<class UCameraShakeBase> ExplosionShakeClass;

    // 흔들림이 전달될 최대 거리
    UPROPERTY(EditAnywhere, Category = "Effects")
    float ShakeInnerRadius = 500.f;

    UPROPERTY(EditAnywhere, Category = "Effects")
    float ShakeOuterRadius = 3000.f;

    // 지연 시간 설정 (0.5초)
    UPROPERTY(EditAnywhere, Category = "Combat")
    float ExplosionDelay = 0.5f;

    FTimerHandle ExplosionTimer;

    // 부딪힌 정보를 Explode 함수에서도 쓰기 위해 저장할 변수
    FHitResult SavedHit;

};