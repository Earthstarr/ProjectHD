#include "CinematicPod.h"
#include "Components/StaticMeshComponent.h"
#include "NiagaraComponent.h"

ACinematicPod::ACinematicPod()
{
	PrimaryActorTick.bCanEverTick = true;

	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	RootComponent = CubeMesh;

	// 기본 큐브 메시 설정
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeFinder(TEXT("/Engine/BasicShapes/Cube"));
	if (CubeFinder.Succeeded())
	{
		CubeMesh->SetStaticMesh(CubeFinder.Object);
		CubeMesh->SetWorldScale3D(FVector(0.5f));
	}

	// 거리 컬링 방지
	CubeMesh->bNeverDistanceCull = true;
	CubeMesh->SetBoundsScale(100.0f);

	// 나이아가라 궤적 컴포넌트
	TrailComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("TrailComponent"));
	TrailComponent->SetupAttachment(CubeMesh);
	TrailComponent->bAutoActivate = true;

	// 거리 컬링 방지
	TrailComponent->SetAllowScalability(false);
	TrailComponent->bNeverDistanceCull = true;
	TrailComponent->SetBoundsScale(100.0f);
}

void ACinematicPod::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("[CinematicPod] BeginPlay - Location: %s"), *GetActorLocation().ToString());
}

void ACinematicPod::Destroyed()
{
	Super::Destroyed();
	UE_LOG(LogTemp, Warning, TEXT("[CinematicPod] Destroyed - Location: %s"), *GetActorLocation().ToString());
}

void ACinematicPod::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 아래로 떨어지기
	FVector NewLocation = GetActorLocation();
	NewLocation.Z -= FallSpeed * DeltaTime;
	SetActorLocation(NewLocation);
}
