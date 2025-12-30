#include "HDProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "FPSCharacter.h"

AHDProjectile::AHDProjectile()
{
	// 1. 충돌체 설정
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f); // 총알 크기
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile"); // 나중에 프로젝트 설정에서 설정 가능

	// 충돌 시 OnHit 함수가 실행되도록 연결
	CollisionComp->OnComponentHit.AddDynamic(this, &AHDProjectile::OnHit);

	// 플레이어가 자기 총알에 부딪히지 않게 설정
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	RootComponent = CollisionComp;

	// 2. 외형 설정
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	ProjectileMesh->SetupAttachment(RootComponent);

	// 3. 발사체 움직임 설정
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 15000.f;
	ProjectileMovement->MaxSpeed = 15000.f;
	ProjectileMovement->bRotationFollowsVelocity = true; // 날아가는 방향으로 회전
	ProjectileMovement->bShouldBounce = false;         // 튕기지 않고 바로 충돌 처리
	ProjectileMovement->ProjectileGravityScale = 0.f;   // 중력 영향 (0이면 직선, 높을수록 낙차 발생)

	CollisionComp->IgnoreActorWhenMoving(GetOwner(), true);

	// 5초 뒤에 자동으로 삭제 (메모리 관리)
	InitialLifeSpan = 3.0f;
}

void AHDProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void AHDProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		// ApplyDamage가 오버라이드 되어있지 않으면 DamageDealt는 0
		float DamageDealt = UGameplayStatics::ApplyDamage(
			OtherActor,
			DamageAmount,
			GetInstigatorController(),
			this,
			UDamageType::StaticClass()
		);

		if (DamageDealt > 0.f)
		{
			if (OtherActor->ActorHasTag(FName("Enemy")))
			{
				AFPSCharacter* Player = Cast<AFPSCharacter>(GetOwner());
				if (Player)
				{
					Player->OnHitEnemy.Broadcast(false);
				}
			}
		}

		// 이펙트 생성
		if (ImpactEffect)
		{
			// Hit.ImpactNormal을 이용해 부딪힌 표면의 각도에 맞춰 이펙트를 생성
			FRotator SpawnRotation = Hit.ImpactNormal.Rotation();			
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(
				GetWorld(),
				ImpactEffect,
				Hit.ImpactPoint,
				SpawnRotation				
			);
		}

		// 사운드 재생
		if (ImpactSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, Hit.ImpactPoint, 1.f, 1.f, 0.f, HitAttenuation);
		}

		// 총알 제거
		Destroy();
	}
}