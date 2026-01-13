// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Crawler.h"

AEnemy_Crawler::AEnemy_Crawler()
{
	MaxHealth = 50.0f;
	CurrentHealth = MaxHealth;
}

void AEnemy_Crawler::BeginPlay()
{
	Super::BeginPlay();
}
