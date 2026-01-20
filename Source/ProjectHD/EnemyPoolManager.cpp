#include "EnemyPoolManager.h"

#include "Character/Enemy/EnemyBase.h"
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
		FActorSpawnParameters Params;
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		EnemyToUse = GetWorld()->SpawnActor<AEnemyBase>(EnemyClass, Location, Rotation, Params);
        
		// 매니저를 알 수 있게 설정 (반환 시 필요)
		// EnemyToUse->SetPoolManager(this); 
	}

	if (EnemyToUse)
	{
		EnemyToUse->SetActorLocationAndRotation(Location, Rotation);
		// 모든 상태 초기화
		EnemyToUse->InitEnemy(); 
	}

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