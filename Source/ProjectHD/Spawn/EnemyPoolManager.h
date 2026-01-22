#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectHD/Character/Enemy/EnemyBase.h"
#include "EnemyPoolManager.generated.h"

// 클래스별로 적들을 담아둘 구조체
USTRUCT(BlueprintType)
struct FEnemyPoolArray
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<AEnemyBase*> InactivePool;
};

UCLASS()
class PROJECTHD_API AEnemyPoolManager : public AActor
{
	GENERATED_BODY()

public:
	AEnemyPoolManager();
	
	virtual void BeginPlay() override;
	
	// 풀에서 적을 가져오거나 새로 생성
	AEnemyBase* AcquireEnemy(TSubclassOf<AEnemyBase> EnemyClass, FVector Location, FRotator Rotation);

	// 사용이 끝난 적을 풀로 반환
	void ReleaseEnemy(AEnemyBase* Enemy);

private:
	// 클래스 타입을 키값으로 풀을 관리
	UPROPERTY()
	TMap<TSubclassOf<AEnemyBase>, FEnemyPoolArray> PoolMap;

	// 초기 스폰 시 성능 최적화(Warm up)를 원한다면 미리 생성하는 로직 추가 가능
};