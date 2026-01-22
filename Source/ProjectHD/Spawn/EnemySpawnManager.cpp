#include "EnemySpawnManager.h"
#include "ProjectHD/Spawn/EnemyPoolManager.h"
#include "SpawnZone.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

AEnemySpawnManager::AEnemySpawnManager()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AEnemySpawnManager::BeginPlay()
{
    Super::BeginPlay();

    // 풀 매니저 찾기
    PoolManager = Cast<AEnemyPoolManager>(
        UGameplayStatics::GetActorOfClass(GetWorld(), AEnemyPoolManager::StaticClass())
    );

    // 모든 미션 존 찾기
    TArray<AActor*> FoundZones;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnZone::StaticClass(), FoundZones);
    
    for (AActor* Actor : FoundZones)
    {
        ASpawnZone* Zone = Cast<ASpawnZone>(Actor);
        if (Zone && Zone->ZoneType == ESpawnZoneType::MissionArea)
        {
            MissionZones.Add(Zone);
            // 초기 스폰
            Zone->SpawnEnemies(PoolManager);
        }
    }

    // 타이머 시작
    GetWorldTimerManager().SetTimer(PatrolSpawnTimer, this, &AEnemySpawnManager::SpawnPatrolSquad, PatrolSpawnInterval, true);
    GetWorldTimerManager().SetTimer(DespawnCheckTimer, this, &AEnemySpawnManager::CheckEnemyDistances, DespawnCheckInterval, true);
}

void AEnemySpawnManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AEnemySpawnManager::SpawnPatrolSquad()
{
    if (!PoolManager || PatrolEnemyTypes.Num() == 0) return;

    FVector PlayerLoc = GetPlayerLocation();
    
    // 플레이어 주변 랜덤 위치
    FVector RandomDirection = FVector(FMath::RandRange(-1.f, 1.f), FMath::RandRange(-1.f, 1.f), 0).GetSafeNormal();
    FVector SpawnCenter = PlayerLoc + RandomDirection * PatrolSpawnDistance;

    // 정찰대 스폰
    for (const FPatrolEnemySpawnInfo& SpawnInfo : PatrolEnemyTypes)
    {
        if (!SpawnInfo.EnemyClass) continue;

        for (int32 i = 0; i < SpawnInfo.SpawnCount; ++i)
        {
            FVector Offset = FVector(FMath::RandRange(-1000.f, 1000.f), FMath::RandRange(-1000.f, 1000.f), 500.f);
            FVector SpawnLoc = SpawnCenter + Offset;
            FRotator SpawnRot = FRotator(0, FMath::RandRange(0.f, 360.f), 0);

            PoolManager->AcquireEnemy(SpawnInfo.EnemyClass, SpawnLoc, SpawnRot);
        }
    }
}

FVector AEnemySpawnManager::GetPlayerLocation() const
{
    ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    return Player ? Player->GetActorLocation() : FVector::ZeroVector;
}

void AEnemySpawnManager::CheckEnemyDistances()
{
    if (!PoolManager) return;

    FVector PlayerLoc = GetPlayerLocation();
    
    // 월드에 존재하는 모든 EnemyBase를 찾기
    TArray<AActor*> ActiveEnemies;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyBase::StaticClass(), ActiveEnemies);

    for (AActor* Actor : ActiveEnemies)
    {
        AEnemyBase* Enemy = Cast<AEnemyBase>(Actor);
        
        // 이미 죽었거나 비활성화된 적은 무시
        if (!Enemy || Enemy->IsHidden() || Enemy->IsDead()) continue;
        
        // 미션 지역 적은 무시
        if (Enemy->bIsMissionSpawned) continue;

        // 거리가 멀면 풀로 반환
        float DistanceSq = FVector::DistSquared(PlayerLoc, Enemy->GetActorLocation());        
        if (DistanceSq > FMath::Square(DespawnDistance))
        {            
            PoolManager->ReleaseEnemy(Enemy);
        }
    }
}
