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
    GetWorldTimerManager().SetTimer(MaintainTimer, this, &AEnemySpawnManager::MaintainMissionZones, 10.0f, true);
}

void AEnemySpawnManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AEnemySpawnManager::MaintainMissionZones()
{
    for (ASpawnZone* Zone : MissionZones)
    {
        if (Zone)
        {
            Zone->MaintainEnemyCount(PoolManager);
        }
    }
}

void AEnemySpawnManager::SpawnPatrolSquad()
{
    if (!PoolManager || PatrolEnemyTypes.Num() == 0) return;

    FVector PlayerLoc = GetPlayerLocation();
    
    // 플레이어 주변 랜덤 위치
    FVector RandomDirection = FVector(FMath::RandRange(-1.f, 1.f), FMath::RandRange(-1.f, 1.f), 0).GetSafeNormal();
    FVector SpawnCenter = PlayerLoc + RandomDirection * PatrolSpawnDistance;

    // 정찰대 스폰
    for (int32 i = 0; i < PatrolSquadSize; ++i)
    {
        TSubclassOf<AEnemyBase> RandomClass = PatrolEnemyTypes[FMath::RandRange(0, PatrolEnemyTypes.Num() - 1)];
        
        FVector Offset = FVector(FMath::RandRange(-200.f, 200.f), FMath::RandRange(-200.f, 200.f), 0);
        FVector SpawnLoc = SpawnCenter + Offset;
        FRotator SpawnRot = FRotator(0, FMath::RandRange(0.f, 360.f), 0);

        PoolManager->AcquireEnemy(RandomClass, SpawnLoc, SpawnRot);
    }

    UE_LOG(LogTemp, Warning, TEXT("정찰대 스폰: %s"), *SpawnCenter.ToString());
}

FVector AEnemySpawnManager::GetPlayerLocation() const
{
    ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    return Player ? Player->GetActorLocation() : FVector::ZeroVector;
}