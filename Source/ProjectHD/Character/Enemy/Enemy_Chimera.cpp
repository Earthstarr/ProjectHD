// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectHD/Character/Enemy/Enemy_Chimera.h"

#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ProjectHD/Character/Player/FPSCharacter.h"


AEnemy_Chimera::AEnemy_Chimera()
{
	MaxHealth = 2000.0f;
	CurrentHealth = MaxHealth;
    
	RightArmCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("RightArmCollision"));
	RightArmCollision->SetupAttachment(GetMesh()); 
	RightArmCollision->SetCollisionProfileName(TEXT("CharacterMesh"));

	LeftArmCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("LeftArmCollision"));
	LeftArmCollision->SetupAttachment(GetMesh());
	LeftArmCollision->SetCollisionProfileName(TEXT("CharacterMesh"));

	HitBoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBoxCollision"));
	HitBoxCollision->SetupAttachment(GetMesh());
	HitBoxCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	HitBoxCollision->SetGenerateOverlapEvents(true);
    
	HitBoxCollision->IgnoreActorWhenMoving(this, true);
	HitBoxCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AEnemy_Chimera::BeginPlay()
{
	Super::BeginPlay();
    
	HitBoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AEnemy_Chimera::OnHitBoxOverlap);
}

void AEnemy_Chimera::OnHitBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
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