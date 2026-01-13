// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
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
	
	UPROPERTY(EditAnywhere, Category = "Combat")
	float pouncingSpeed = 800.0f;
};
