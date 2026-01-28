#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "EggActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEggDestroyed, AEggActor*, DestroyedEgg);

UCLASS()
class PROJECTHD_API AEggActor : public AEnemyBase
{
	GENERATED_BODY()
    
public:
	AEggActor();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Egg")
	UStaticMeshComponent* EggMesh;

	UPROPERTY(BlueprintAssignable, Category = "Egg")
	FOnEggDestroyed OnEggDestroyed;

	UPROPERTY(EditAnywhere, Category = "Egg")
	UParticleSystem* DestroyEffect;

	UPROPERTY(EditAnywhere, Category = "Egg")
	USoundBase* DestroySound;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator, AActor* DamageCauser) override;

protected:
	virtual void BeginPlay() override;
    
private:
	void DestroyEgg();
};