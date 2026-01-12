#include "HDSupplyPod.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "Character/Player/FPSCharacter.h"
#include "Kismet/GameplayStatics.h"

AHDSupplyPod::AHDSupplyPod()
{
	PrimaryActorTick.bCanEverTick = true;
	
	// 본체 (Root)
	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	RootComponent = BodyMesh;
	
	// 기둥 (BodyMesh에 부착)
	PillarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PillarMesh"));
	PillarMesh->SetupAttachment(BodyMesh);

	// 왼쪽 상자 (PillarMesh에 부착)
	LeftSupplyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftSupplyMesh"));
	LeftSupplyMesh->SetupAttachment(PillarMesh);

	// 오른쪽 상자 (PillarMesh에 부착)
	RightSupplyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightSupplyMesh"));
	RightSupplyMesh->SetupAttachment(PillarMesh);

	// 감지 범위
	InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSphere"));
	InteractionSphere->SetupAttachment(BodyMesh);
	InteractionSphere->SetSphereRadius(1400.f); // 감지 범위
    
	// 물리 설정 (낙하를 위해)
	BodyMesh->SetSimulatePhysics(true);
	BodyMesh->SetNotifyRigidBodyCollision(true);
		
	// 위젯 설정
	InteractionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InteractionWidget"));
	InteractionWidget->SetupAttachment(PillarMesh);
	InteractionWidget->SetRelativeLocation(FVector(0, 0, 200.f)); // 머리 위 위치
	InteractionWidget->SetWidgetSpace(EWidgetSpace::Screen);
}

void AHDSupplyPod::BeginPlay()
{
	Super::BeginPlay();
	
	// 시작할 때는 위젯 숨기기
	InteractionWidget->SetVisibility(false);

	// 오버랩 이벤트 바인딩
	InteractionSphere->OnComponentBeginOverlap.AddDynamic(this, &AHDSupplyPod::HandleSphereBeginOverlap);
	InteractionSphere->OnComponentEndOverlap.AddDynamic(this, &AHDSupplyPod::HandleSphereEndOverlap);
}

void AHDSupplyPod::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bIsDeployed && BodyMesh && BodyMesh->IsSimulatingPhysics())
	{
		BodyMesh->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
		
		FVector Start = GetActorLocation() + (FVector::UpVector * 100.f);
		FVector Velocity = BodyMesh->GetPhysicsLinearVelocity();
		float TraceLength = (Velocity.Size() * DeltaTime) + 100.f;
		FVector End = Start + (FVector::UpVector * -TraceLength);

		FHitResult GroundHit;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);

		// 라인 트레이스는 NoCollision 상태여도 Visibility 채널로 바닥을 감지합니다.
		if (GetWorld()->LineTraceSingleByChannel(GroundHit, Start, End, ECC_Visibility, Params))
		{
			// 박히는 시점에 물리 끄고 고체 상태로 변경
			BodyMesh->SetSimulatePhysics(false);
            
			// 땅 위에 BlockAll
			BodyMesh->SetCollisionProfileName(TEXT("BlockAll"));
			PillarMesh->SetCollisionProfileName(TEXT("BlockAll"));
			LeftSupplyMesh->SetCollisionProfileName(TEXT("BlockAll"));
			RightSupplyMesh->SetCollisionProfileName(TEXT("BlockAll"));
            
			// 정확한 위치 고정
			SetActorLocation(GroundHit.ImpactPoint + FVector(0.f, 0.f, -90.f));

			bIsDeployed = true;
			StartDeploySequence(); // 블루프린트 애니메이션 호출
			
			if (DeploySound) 
			{
				UGameplayStatics::PlaySoundAtLocation(this, DeploySound, GetActorLocation());
			}	

			if (ImpactSound) 
			{
				UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation());
			}			
		}
	}
}

// --- 오버랩 처리 루틴 ---

void AHDSupplyPod::HandleSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 충돌한 대상이 플레이어 캐릭터인지 확인
	if (Cast<AFPSCharacter>(OtherActor))
	{
		OnOverlapBegin();
	}
}

void AHDSupplyPod::HandleSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Cast<AFPSCharacter>(OtherActor))
	{
		OnOverlapEnd();
	}
}

// --- 인터페이스 함수들 ---

void AHDSupplyPod::OnOverlapBegin()
{	
	if (RemainingSupplies > 0)
	{
		InteractionWidget->SetVisibility(true);
	}	
}

void AHDSupplyPod::OnOverlapEnd()
{
	InteractionWidget->SetVisibility(false);
}

void AHDSupplyPod::Interact(AFPSCharacter* Interactor)
{
	if (!Interactor) return;
	if (RemainingSupplies <= 0) return;
	
	// 모든 무기 탄창 보급
	TArray<FWeaponInstance>& Inventory = Interactor->GetWeaponInventory();
	int32 CurrentIdx = Interactor->CurrentWeaponIndex;
	
	// 보급이 필요한지 체크하는 변수들
	bool bNeedsMag = false;
	bool bNeedsGrenades = (Interactor->CurrentGrenadeCount < Interactor->MaxGrenadeCount);
	bool bNeedsStims = (Interactor->CurrentStimCount < Interactor->MaxStimCount);

	// 모든 무기를 돌며 하나라도 탄창이 부족한지 확인
	for (int32 i = 0; i < Inventory.Num(); ++i)
	{
		if (Inventory[i].WeaponData)
		{
			// 현재 장착 중인 무기라면 캐릭터의 변수를 체크, 아니면 인벤토리 체크
			int32 TargetMagCount = (i == CurrentIdx) ? Interactor->CurrentMagCount : Inventory[i].CurrentMagCount;

			if (TargetMagCount < Inventory[i].WeaponData->MaxMag)
			{
				bNeedsMag = true;
				break;
			}
		}
	}

	// 모든 항목이 꽉 차있다면 return
	if (!bNeedsMag && !bNeedsGrenades && !bNeedsStims) return;	
		
	for (int32 i = 0; i < Inventory.Num(); ++i)
	{
		FWeaponInstance& Weapon = Inventory[i];
		if (Weapon.WeaponData)
		{
			int32 SupplyAmount = Weapon.WeaponData->AmmoSuppliedPerBox;
			Weapon.CurrentMagCount = FMath::Min(Weapon.CurrentMagCount + SupplyAmount, Weapon.WeaponData->MaxMag);

			// 만약 이 무기가 현재 들고 있는 무기라면 캐릭터 변수도 업데이트
			if (i == CurrentIdx)
			{
				Interactor->CurrentMagCount = Weapon.CurrentMagCount;
			}
		}
	}

	// 수류탄 및 주사기 보급
	Interactor->CurrentGrenadeCount = FMath::Min(Interactor->CurrentGrenadeCount + 3, Interactor->MaxGrenadeCount);
	Interactor->CurrentStimCount = FMath::Min(Interactor->CurrentStimCount + 2, Interactor->MaxStimCount);
	
	// 획득 사운드
	if (SupplyPickupSound)
	{		
		UGameplayStatics::PlaySoundAtLocation(this, SupplyPickupSound, GetActorLocation());
	}
	
	TArray<UStaticMeshComponent*> AvailableSupplies;
	if (LeftSupplyMesh && LeftSupplyMesh->IsVisible()) AvailableSupplies.Add(LeftSupplyMesh);
	if (RightSupplyMesh && RightSupplyMesh->IsVisible()) AvailableSupplies.Add(RightSupplyMesh);

	if (AvailableSupplies.Num() > 0)
	{
		UStaticMeshComponent* ClosestMesh = nullptr;
		float ClosestDistance = MAX_FLT;
		FVector PlayerLoc = Interactor->GetActorLocation();

		// 플레이어에게 가장 가까운 메쉬 찾기
		for (UStaticMeshComponent* Mesh : AvailableSupplies)
		{
			float Dist = FVector::DistSquared(Mesh->GetComponentLocation(), PlayerLoc);
			if (Dist < ClosestDistance)
			{
				ClosestDistance = Dist;
				ClosestMesh = Mesh;
			}
		}

		// 가장 가까운 메쉬 숨기기
		if (ClosestMesh)
		{
			ClosestMesh->SetVisibility(false);
		}
	}

	RemainingSupplies--;

	// 모든 보급품 소진 시 위젯 숨기기
	if (RemainingSupplies <= 0) 
	{
		InteractionWidget->SetVisibility(false);
		EndDeploySequence();
		
		if (UnDeploySound)
		{		
			UGameplayStatics::PlaySoundAtLocation(this, UnDeploySound, GetActorLocation());
		}
	}

	// UI 갱신 델리게이트 호출
	if (Inventory.IsValidIndex(CurrentIdx))
	{
		Interactor->OnAmmoChanged.Broadcast(
			Interactor->CurrentAmmo, 
			Interactor->CurrentMagCount,
			Inventory[CurrentIdx].WeaponData->MaxMag
		);
	}

	// 수류탄 및 주사기 UI 갱신
	Interactor->OnGrenadeChanged.Broadcast(Interactor->CurrentGrenadeCount, Interactor->MaxGrenadeCount);
	Interactor->OnStimChanged.Broadcast(Interactor->CurrentStimCount, Interactor->MaxStimCount);	
}