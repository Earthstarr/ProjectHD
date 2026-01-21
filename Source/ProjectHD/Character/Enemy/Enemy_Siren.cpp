// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectHD/Character/Enemy/Enemy_Siren.h"

#include "Kismet/GameplayStatics.h"
#include "ProjectHD/Character/Player/FPSCharacter.h"


AEnemy_Siren::AEnemy_Siren()
{
	MaxHealth = 30.0f;
	CurrentHealth = MaxHealth;
	
	BodyCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BodyCollision"));
	BodyCollision->SetupAttachment(GetMesh()); 
	BodyCollision->SetCollisionProfileName(TEXT("CharacterMesh"));
	
	HeadCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("HeadCollision"));
	HeadCollision->SetupAttachment(GetMesh()); 
	HeadCollision->SetCollisionProfileName(TEXT("CharacterMesh"));

	HitBoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBoxCollision"));
	HitBoxCollision->SetupAttachment(GetMesh());
	HitBoxCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	HitBoxCollision->SetGenerateOverlapEvents(true);
    
	BodyCollision->IgnoreActorWhenMoving(this, true);
	BodyCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	HitBoxCollision->IgnoreActorWhenMoving(this, true);
	HitBoxCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AEnemy_Siren::BeginPlay()
{
	Super::BeginPlay();
	
	HitBoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AEnemy_Siren::OnHitBoxOverlap);
}

void AEnemy_Siren::OnHitBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{     
		AFPSCharacter* TargetPlayer = Cast<AFPSCharacter>(OtherActor);
		if (TargetPlayer)
		{        
			UGameplayStatics::ApplyDamage(TargetPlayer, AttackDamage, GetController(), this, nullptr);   
			HitBoxCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
	}
}
