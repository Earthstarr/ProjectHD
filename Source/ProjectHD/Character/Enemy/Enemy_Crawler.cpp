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
	
	// 앞몸체 박스 설정
	BodyCollisionFront = CreateDefaultSubobject<UBoxComponent>(TEXT("BodyCollisionFront"));
	BodyCollisionFront->SetupAttachment(GetMesh());
	BodyCollisionFront->SetCollisionProfileName(TEXT("CharacterMesh")); // 총알에 맞도록 설정

	// 뒷몸체 박스 설정
	BodyCollisionBack = CreateDefaultSubobject<UBoxComponent>(TEXT("BodyCollisionBack"));
	BodyCollisionBack->SetupAttachment(GetMesh());
	BodyCollisionBack->SetCollisionProfileName(TEXT("CharacterMesh"));

	// 공격 박스 설정
	MouthCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("MouthCollision"));
	MouthCollision->SetupAttachment(GetMesh());
	MouthCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	MouthCollision->SetGenerateOverlapEvents(true);
	
	// 자기 자신과는 충돌 무시
	MouthCollision->IgnoreActorWhenMoving(this, true);
    
	// 충돌 비활성화
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
	// 1. OtherActor가 null이 아니고, 나 자신이 아닐 때만 로그를 찍고 진행
	if (OtherActor && OtherActor != this)
	{
		// 이제 여기서는 플레이어나 다른 액터 이름만 찍힙니다.
		UE_LOG(LogTemp, Warning, TEXT("Something Hit: %s"), *OtherActor->GetName());
       
		AFPSCharacter* TargetPlayer = Cast<AFPSCharacter>(OtherActor);
		if (TargetPlayer)
		{
			UE_LOG(LogTemp, Error, TEXT("!!! PLAYER HIT SUCCESS !!!"));
			UGameplayStatics::ApplyDamage(TargetPlayer, AttackDamage, GetController(), this, nullptr);   
			MouthCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
	}
}
