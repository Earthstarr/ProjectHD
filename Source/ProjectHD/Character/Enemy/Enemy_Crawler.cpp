// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Crawler.h"
#include "Components/StateTreeAIComponent.h"
#include "Components/StateTreeComponent.h"

AEnemy_Crawler::AEnemy_Crawler()
{
	StateTreeAIComponent = CreateDefaultSubobject<UStateTreeAIComponent>(TEXT("StateTreeAIComponent"));
	StateTreeAIComponent->PrimaryComponentTick.bCanEverTick = true;
	StateTreeAIComponent->bAutoActivate = true;
	
	StateTreeComponent = CreateDefaultSubobject<UStateTreeComponent>(TEXT("StateTreeComponent"));
	
	MaxHealth = 50.0f;
	CurrentHealth = MaxHealth;
}

void AEnemy_Crawler::BeginPlay()
{
	Super::BeginPlay();
	
}
