#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/StreamableManager.h"
#include "ProjectHD/SubtitleTypes.h"
#include "IntroCutsceneManager.generated.h"

class ULevelSequence;
class ULevelSequencePlayer;
class ACinematicPod;
class UNiagaraSystem;
class USoundBase;

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
	class ULevelSequence* IntroSequence;

	UPROPERTY()
	class ULevelSequencePlayer* SequencePlayer;

	// 시네마틱 포드 설정
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cutscene")
	TSubclassOf<ACinematicPod> CinematicPodClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cutscene")
	FVector PodSpawnLocation = FVector(0.0f, 0.0f, 50000.0f);

	// 포드 스폰 딜레이
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cutscene")
	float PodSpawnDelay = 3.0f;

	// ===== 비동기 프리로드 에셋 (TSoftPtr - 레벨 로드 시 자동 로드 안 됨) =====

	// 프리로드할 액터 클래스들 (적, 무기, 포드 등)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AsyncPreload")
	TArray<TSoftClassPtr<AActor>> PreloadActorClasses;

	// 프리로드할 나이아가라 시스템들
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AsyncPreload")
	TArray<TSoftObjectPtr<UNiagaraSystem>> PreloadNiagaraSystems;

	// 프리로드할 사운드들
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AsyncPreload")
	TArray<TSoftObjectPtr<USoundBase>> PreloadSounds;

	// 프리로드할 기타 에셋들 (스켈레탈 메시, 머티리얼 등)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AsyncPreload")
	TArray<TSoftObjectPtr<UObject>> PreloadMiscAssets;

	// ===== 워밍업 스폰 (프리로드 완료 후 실제 스폰) =====

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Warmup")
	TArray<TSubclassOf<AActor>> WarmupActorClasses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Warmup")
	TArray<UNiagaraSystem*> WarmupNiagaraSystems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Warmup")
	TArray<USoundBase*> WarmupSounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Warmup")
	FVector WarmupSpawnLocation = FVector(0.0f, 0.0f, -5000.0f);

	// 워밍업 완료 후 추가 대기 시간 (오디오 디코딩 등)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Warmup")
	float WarmupExtraDelay = 15.0f;

	// ===== 로딩 화면 =====

	// 로드할 서브레벨 이름
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loading")
	FName SublevelToLoad;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loading")
	TSubclassOf<UUserWidget> LoadingWidgetClass;

	UPROPERTY()
	UUserWidget* LoadingWidget;

	// 비동기 로드 핸들
	TSharedPtr<FStreamableHandle> PreloadHandle;

	// 프리로드 완료 여부
	bool bPreloadComplete = false;

	// 컷씬 사운드
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	class USoundBase* IntroCutsceneSound;

	// 자막 키
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	FName IntroCutsceneSubtitleKey;

	// 컷씬 종료 후 재생할 BGM
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundBase* PostCutsceneBGM;

	// BGM 페이드인 시간
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	float BGMFadeInDuration = 5.0f;

public:
	// 자막 델리게이트
	UPROPERTY(BlueprintAssignable, Category = "Sound")
	FOnSoundPlayedSignature OnSoundPlayed;

protected:
	// 비동기 프리로드 시작
	void StartAsyncPreload();

	// 프리로드 완료 콜백
	void OnPreloadComplete();

	// 서브레벨 로드 완료 콜백
	UFUNCTION()
	void OnSublevelLoaded();

	// 시퀀서 끝났을 때
	UFUNCTION()
	void OnSequenceFinished();

	// 시네마틱 포드 스폰
	void SpawnCinematicPod();

	// 워밍업 액터 스폰 (프리로드 완료 후)
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
