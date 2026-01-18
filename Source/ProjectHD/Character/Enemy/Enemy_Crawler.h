// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "Components/BoxComponent.h"

#include "Enemy_Crawler.generated.h"

/**
 * 
 */

UCLASS()
class PROJECTHD_API AEnemy_Crawler : public AEnemyBase
{
	GENERATED_BODY()
	
public:
	AEnemy_Crawler();
		
protected:
	virtual void BeginPlay() override;
		
	// 몸체 판정용 박스 2개
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	UBoxComponent* BodyCollisionFront;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	UBoxComponent* BodyCollisionBack;

	// 공격 판정용 입 박스
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	UBoxComponent* MouthCollision;

	// 플레이어 오버랩 이벤트
	UFUNCTION()
	void OnMouthOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, Category = "Combat")
	float AttackDamage = 10.0f;
};
