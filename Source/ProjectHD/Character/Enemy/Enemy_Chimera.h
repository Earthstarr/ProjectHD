// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectHD/Character/Enemy/EnemyBase.h"
#include "Components/BoxComponent.h"
#include "Enemy_Chimera.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTHD_API AEnemy_Chimera : public AEnemyBase
{
	GENERATED_BODY()
	
public:
	AEnemy_Chimera();
	
	virtual void InitEnemy() override;
	
protected:	
	virtual void BeginPlay() override;
	
	// 몸체 판정용 박스 2개
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	UBoxComponent* RightArmCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	UBoxComponent* LeftArmCollision;

	// 공격 판정용 히트박스
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	UBoxComponent* HitBoxCollision;
	
	// 플레이어 오버랩 이벤트
	UFUNCTION()
	void OnHitBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UPROPERTY(EditAnywhere, Category = "Combat")
	float AttackDamage = 45.0f;	
	
	
};
