#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectHD/SubtitleTypes.h"
#include "IntroCutsceneManager.generated.h"

class ULevelSequence;
class ULevelSequencePlayer;
class ACinematicPod;

UCLASS()
class PROJECTHD_API AIntroCutsceneManager : public AActor
{
	GENERATED_BODY()

public:
	AIntroCutsceneManager();

protected:
	virtual void BeginPlay() override;

	// 인트로 시퀀서
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cutscene")
	ULevelSequence* IntroSequence;

	UPROPERTY()
	ULevelSequencePlayer* SequencePlayer;

	// 시네마틱 포드 설정
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cutscene")
	TSubclassOf<ACinematicPod> CinematicPodClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cutscene")
	FVector PodSpawnLocation = FVector(0.0f, 0.0f, 50000.0f);

	// 포드 스폰 딜레이
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cutscene")
	float PodSpawnDelay = 3.0f;

	// 워밍업 에셋들 (블루프린트에서 설정)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Warmup")
	TArray<TSubclassOf<AActor>> WarmupActorClasses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Warmup")
	TArray<class UNiagaraSystem*> WarmupNiagaraSystems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Warmup")
	TArray<class USoundBase*> WarmupSounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Warmup")
	FVector WarmupSpawnLocation = FVector(0.0f, 0.0f, -5000.0f);

	// 컷씬 사운드
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	class USoundBase* IntroCutsceneSound;

	// 자막 키
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	FName IntroCutsceneSubtitleKey;

public:
	// 자막 델리게이트
	UPROPERTY(BlueprintAssignable, Category = "Sound")
	FOnSoundPlayedSignature OnSoundPlayed;

protected:
	// 시퀀서 끝났을 때
	UFUNCTION()
	void OnSequenceFinished();

	// 시네마틱 포드 스폰
	void SpawnCinematicPod();

	// 워밍업 액터 스폰
	void SpawnWarmupActors();

public:
	// 컷씬 완료 델리게이트
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnIntroCutsceneFinished);

	UPROPERTY(BlueprintAssignable, Category = "Cutscene")
	FOnIntroCutsceneFinished OnIntroCutsceneFinished;

	// 컷씬 시작
	UFUNCTION(BlueprintCallable, Category = "Cutscene")
	void StartCutscene();
};
