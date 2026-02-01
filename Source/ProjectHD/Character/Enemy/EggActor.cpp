#include "EggActor.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"

AEggActor::AEggActor()
{
	PrimaryActorTick.bCanEverTick = false;

	MaxHealth = 10.f;
	CurrentHealth = MaxHealth;

	// EggMesh를 CapsuleComponent에 붙임
	EggMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EggMesh"));
	EggMesh->SetupAttachment(GetCapsuleComponent());

	// 캡슐 크기 설정 (에그 크기에 맞게 조정)
	GetCapsuleComponent()->InitCapsuleSize(50.f, 50.f);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Block);

	// EggMesh 콜리전은 끄고 캡슐로 판정
	EggMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// ACharacter 기본 SkeletalMesh 숨기기
	GetMesh()->SetVisibility(false);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AEggActor::BeginPlay()
{
	Super::BeginPlay();	
}

float AEggActor::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	CurrentHealth -= ActualDamage;

	if (CurrentHealth <= 0.f)
	{
		DestroyEgg();
	}

	return ActualDamage;
}

void AEggActor::DestroyEgg()
{
	// 파괴 이벤트 브로드캐스트
	OnEggDestroyed.Broadcast(this);

	// 이펙트
	if (DestroyEffect)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DestroyEffect, GetActorLocation());
	}

	// 사운드
	if (DestroySound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, DestroySound, GetActorLocation());
	}

	Destroy();
}