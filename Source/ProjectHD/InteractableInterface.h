// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractableInterface.generated.h"

class AFPSCharacter;

UINTERFACE(MinimalAPI)
class UInteractableInterface : public UInterface
{
	GENERATED_BODY()
};

class PROJECTHD_API IInteractableInterface
{
	GENERATED_BODY()
	
public:
	// 상호작용 시 실행될 함수
	virtual void Interact(AFPSCharacter* Interactor) = 0;
	
	// 위젯을 띄우기 위한 함수
	virtual void OnOverlapBegin() = 0;
	virtual void OnOverlapEnd() = 0;
};
