// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectHD/Character/Enemy/EnemyBase.h"
#include "Components/BoxComponent.h"
#include "Enemy_Siren.generated.h"

/**
 * 
 */

// 적 종류와 마리수를 정의하는 구조체
USTRUCT(BlueprintType)
struct FReinforcementWave
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<class AEnemyBase> EnemyClass;

	// 최소 스폰 마릿수
	UPROPERTY(EditAnywhere, Category = "Spawn")
	int32 MinSpawnCount = 1;

	// 최대 스폰 마릿수
	UPROPERTY(EditAnywhere, Category = "Spawn")
	int32 MaxSpawnCount = 3;
};

UCLASS()
class PROJECTHD_API AEnemy_Siren : public AEnemyBase
{
	GENERATED_BODY()
	
public:
	AEnemy_Siren();
	
	virtual void BeginPlay() override;	
	virtual void InitEnemy() override;
	
protected:
	
	// 몸체 판정용 박스
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	UBoxComponent* BodyCollision;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	UBoxComponent* HeadCollision;
		
	// 공격 판정용 히트박스
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	UBoxComponent* HitBoxCollision;
			
	// 플레이어 오버랩 이벤트
	UFUNCTION()
	void OnHitBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
			
	UPROPERTY(EditAnywhere, Category = "Combat")
	float AttackDamage = 10.0f;	
	
	UPROPERTY(EditAnywhere, Category = "Siren|Reinforcement")
	class UNiagaraSystem* ReinforceFX; // 증원 나이아가라

	UPROPERTY(EditAnywhere, Category = "Siren|Reinforcement")
	TArray<FReinforcementWave> WaveConfigs; // 소환할 적 구조체 배열

	UPROPERTY(EditAnywhere, Category = "Siren|Reinforcement")
	float ReinforceDuration = 50.0f; // 증원 유지 시간

	UPROPERTY(EditAnywhere, Category = "Siren|Reinforcement")
	float SpawnInterval = 10.0f; // 적 스폰 간격

	UPROPERTY(EditAnywhere, Category = "Siren|Reinforcement")
	float ReinforceCooldown = 180.0f; // 쿨타임
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Siren|Reinforcement")
	bool bIsCoolingDown = false;
	
	UFUNCTION(BlueprintCallable, Category = "Siren|Reinforcement")
	void StartReinforce();	// 증원 시작
	
private:
	FTimerHandle ReinforceTimerHandle;
	FTimerHandle SpawnTimerHandle;
	FTimerHandle CooldownTimerHandle;
	
	// 증원 신호 위치 저장
	FVector ReinforceLocation;
	
	void StopReinforce();  // 증원 종료
	void SpawnWave(); // 적 스폰
	
	UFUNCTION()
	void ResetCooldown(); // 쿨타임 초기화
	
	UPROPERTY()
	class UNiagaraComponent* SpawnedReinforceFX;
		
};
