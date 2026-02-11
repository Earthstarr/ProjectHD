#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "HDGameInstance.generated.h"

// 전방 선언
enum class EStratagemType : uint8;

// 미션 결과 데이터
USTRUCT(BlueprintType)
struct FMissionResult
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Result")
	float MissionTime = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Result")
	int32 EnemiesKilled = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Result")
	int32 PlayerDeaths = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Result")
	int32 FinalScore = 0;

	// 스트라타젬 종류별 사용 횟수
	UPROPERTY(BlueprintReadWrite, Category = "Result")
	int32 Bomb500kgUsed = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Result")
	int32 SupplyUsed = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Result")
	int32 EagleClusterUsed = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Result")
	int32 OrbitalLaserUsed = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Result")
	int32 SentryUsed = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Result")
	int32 RearmUsed = 0;

	// 총 스트라타젬 사용 횟수
	int32 GetTotalStratagemsUsed() const
	{
		return Bomb500kgUsed + SupplyUsed + EagleClusterUsed + OrbitalLaserUsed + SentryUsed + RearmUsed;
	}
};

UCLASS()
class PROJECTHD_API UHDGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UHDGameInstance();

	// ===== BGM 시스템 =====

	UFUNCTION(BlueprintCallable, Category = "Audio")
	void PlayBGM(USoundBase* Music, float FadeInDuration = 1.0f);

	UFUNCTION(BlueprintCallable, Category = "Audio")
	void StopBGM(float FadeOutDuration = 1.0f);

	UFUNCTION(BlueprintCallable, Category = "Audio")
	void SetBGMVolume(float Volume);

	UFUNCTION(BlueprintPure, Category = "Audio")
	USoundBase* GetCurrentBGM() const { return CurrentBGMSound; }

	UFUNCTION(BlueprintPure, Category = "Audio")
	bool IsBGMPlaying() const;

	// ===== 스폰 시스템 =====

	UPROPERTY(BlueprintReadWrite, Category = "Spawn")
	bool bShouldSpawnWithPod = false;

	UPROPERTY(BlueprintReadWrite, Category = "Spawn")
	FVector PodSpawnLocation = FVector::ZeroVector;

	// ===== 미션 결과 시스템 =====

	// 미션 맵 이름 (이 맵에서만 타이머 작동)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Mission")
	FName MissionLevelName = TEXT("Map_Main2");

	UPROPERTY(BlueprintReadOnly, Category = "Mission")
	FMissionResult MissionResult;

	// 미션 타이머 실행 중 여부
	UPROPERTY(BlueprintReadOnly, Category = "Mission")
	bool bMissionTimerRunning = false;

	// ===== 점수 설정 (블루프린트에서 수정 가능) =====

	// 플레이어 사망 페널티
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Mission|Score")
	int32 DeathPenalty = 100;

	// 시간 보너스 기준 시간 (초)
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Mission|Score")
	float TimeBonusBaseSeconds = 900.0f;

	// 시간 보너스 배율
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Mission|Score")
	float TimeBonusMultiplier = 3.0f;

	// 무사망 보너스
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Mission|Score")
	int32 NoDealthBonus = 1000;

	// 미션 결과 리셋 (새 미션 시작 시 호출)
	UFUNCTION(BlueprintCallable, Category = "Mission")
	void ResetMissionResult();

	// 미션 타이머 시작
	UFUNCTION(BlueprintCallable, Category = "Mission", meta = (WorldContext = "WorldContextObject"))
	void StartMissionTimer(UObject* WorldContextObject);

	// 미션 타이머 정지 및 시간 기록
	UFUNCTION(BlueprintCallable, Category = "Mission", meta = (WorldContext = "WorldContextObject"))
	void StopMissionTimer(UObject* WorldContextObject);

	// 적 처치 기록
	UFUNCTION(BlueprintCallable, Category = "Mission")
	void AddEnemyKill(int32 ScoreValue = 10);

	// 플레이어 사망 기록
	UFUNCTION(BlueprintCallable, Category = "Mission")
	void AddPlayerDeath();

	// 스트라타젬 사용 기록
	UFUNCTION(BlueprintCallable, Category = "Mission")
	void AddStratagemUsed(EStratagemType Type);

	// 최종 점수 계산
	UFUNCTION(BlueprintCallable, Category = "Mission")
	void CalculateFinalScore();

	// 미션 결과 가져오기
	UFUNCTION(BlueprintPure, Category = "Mission")
	FMissionResult GetMissionResult() const { return MissionResult; }

	// 점수 기반 등급 가져오기 (SS, S, A, B, C, D, F)
	UFUNCTION(BlueprintPure, Category = "Mission")
	FString GetMissionGrade() const;

	// 등급별 색상
	UFUNCTION(BlueprintPure, Category = "Mission")
	FLinearColor GetMissionGradeColor() const;

	// 미션 시간 포맷팅 (MM:SS)
	UFUNCTION(BlueprintPure, Category = "Mission")
	FString GetFormattedMissionTime() const;

protected:
	UPROPERTY()
	class UAudioComponent* BGMComponent;

	UPROPERTY()
	USoundBase* CurrentBGMSound;

	UPROPERTY(EditDefaultsOnly, Category = "Audio")
	float DefaultBGMVolume = 0.5f;

	// 미션 시작 시간 (초)
	float MissionStartTime = 0.0f;
};
