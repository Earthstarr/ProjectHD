// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Crawler.h"
#include "ProjectHD/Character/Player/FPSCharacter.h"
#include "AbilitySystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ProjectHD/Character/Player/FPSCharacter.h"

AEnemy_Crawler::AEnemy_Crawler()
{   
	MaxHealth = 50.0f;
	CurrentHealth = MaxHealth;
    	
	BodyCollisionFront = CreateDefaultSubobject<UBoxComponent>(TEXT("BodyCollisionFront"));
	BodyCollisionFront->SetupAttachment(GetMesh()); 
	BodyCollisionFront->SetCollisionProfileName(TEXT("CharacterMesh"));

	BodyCollisionBack = CreateDefaultSubobject<UBoxComponent>(TEXT("BodyCollisionBack"));
	BodyCollisionBack->SetupAttachment(GetMesh());
	BodyCollisionBack->SetCollisionProfileName(TEXT("CharacterMesh"));

	MouthCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("MouthCollision"));
	MouthCollision->SetupAttachment(GetMesh());
	MouthCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	MouthCollision->SetGenerateOverlapEvents(true);
    
	MouthCollision->IgnoreActorWhenMoving(this, true);
	MouthCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AEnemy_Crawler::BeginPlay()
{
	Super::BeginPlay();
	
	MouthCollision->OnComponentBeginOverlap.AddDynamic(this, &AEnemy_Crawler::OnMouthOverlap);
}

void AEnemy_Crawler::OnMouthOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{		
	if (OtherActor && OtherActor != this)
	{		
		AFPSCharacter* TargetPlayer = Cast<AFPSCharacter>(OtherActor);
		if (TargetPlayer)
		{			
			UGameplayStatics::ApplyDamage(TargetPlayer, AttackDamage, GetController(), this, nullptr);   
			MouthCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
	}
}
