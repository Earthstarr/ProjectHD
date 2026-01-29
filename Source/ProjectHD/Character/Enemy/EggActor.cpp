#include "EggActor.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"

AEggActor::AEggActor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	MaxHealth = 50.f;
	CurrentHealth = MaxHealth;
	
	EggMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EggMesh"));
	RootComponent = EggMesh;
	
	UCapsuleComponent* ParentCapsule = GetCapsuleComponent();
	if (ParentCapsule)
	{
		// 충돌을 완전히 끔
		ParentCapsule->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		ParentCapsule->SetCollisionResponseToAllChannels(ECR_Ignore);
		// 물리 연산에서 제외
		ParentCapsule->SetCanEverAffectNavigation(false);
		// 에디터에서 안 보이게 아주 작게 만듦
		ParentCapsule->SetCapsuleSize(1.f, 1.f);
	}
	
	// 실제 피격 판정
	EggMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	EggMesh->SetCollisionResponseToAllChannels(ECR_Block);
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