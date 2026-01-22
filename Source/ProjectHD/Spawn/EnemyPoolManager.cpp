#include "EnemyPoolManager.h"

#include "ProjectHD/Character/Enemy/EnemyBase.h"
#include "Kismet/GameplayStatics.h"

AEnemyPoolManager::AEnemyPoolManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AEnemyPoolManager::BeginPlay()
{
	Super::BeginPlay();
	
	// 월드에 미리 배치된 모든 적 찾기
	TArray<AActor*> FoundEnemies;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyBase::StaticClass(), FoundEnemies);

	for (AActor* Actor : FoundEnemies)
	{
		AEnemyBase* Enemy = Cast<AEnemyBase>(Actor);
		if (Enemy)
		{			
			Enemy->SetPoolManager(this);            
		}
	}
}

AEnemyBase* AEnemyPoolManager::AcquireEnemy(TSubclassOf<AEnemyBase> EnemyClass, FVector Location, FRotator Rotation)
{
	if (!EnemyClass) return nullptr;
	
	// 지형 감지 로직
	FVector TraceStart = Location + FVector(0.f, 0.f, 2000.f); // 하늘 위 20m 지점
	FVector TraceEnd = Location + FVector(0.f, 0.f, -1000.f);  // 바닥 아래 10m 지점
	FHitResult HitResult;
	FCollisionQueryParams Params;
	
	// 매니저 자신이나 이미 배치된 적들과의 충돌을 피하기 위해 설정
	Params.AddIgnoredActor(this);
	
	// 지형 찾기
	if (GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_Visibility, Params))
	{
		// 지면에 닿은 위치로 Location 수정
		Location = HitResult.ImpactPoint + FVector(0.f, 0.f, 10.f); 
	}

	AEnemyBase* EnemyToUse = nullptr;
	FEnemyPoolArray& Pool = PoolMap.FindOrAdd(EnemyClass);

	if (Pool.InactivePool.Num() > 0)
	{
		// 비활성화된 적이 있으면 꺼내기
		EnemyToUse = Pool.InactivePool.Pop();
	}
	else
	{
		// 풀이 비어있으면 새로 생성
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		EnemyToUse = GetWorld()->SpawnActor<AEnemyBase>(EnemyClass, Location, Rotation, SpawnParams);
        
		// 매니저를 알 수 있게 설정 (반환 시 필요)
		EnemyToUse->SetPoolManager(this); 
	}

	if (EnemyToUse)
	{
		EnemyToUse->SetActorLocationAndRotation(Location, Rotation);
    
		// AI 컨트롤러가 없다면 새로 생성하고 빙의
		if (EnemyToUse->GetController() == nullptr)
		{
			EnemyToUse->SpawnDefaultController();
		}		
	}

	// 모든 상태 초기화
	EnemyToUse->InitEnemy();
	
	return EnemyToUse;
}

void AEnemyPoolManager::ReleaseEnemy(AEnemyBase* Enemy)
{
	if (!Enemy) return;

	// 시각적/물리적 비활성화
	Enemy->SetActorHiddenInGame(true);
    
	// 풀 배열에 추가
	PoolMap.FindOrAdd(Enemy->GetClass()).InactivePool.Push(Enemy);
}