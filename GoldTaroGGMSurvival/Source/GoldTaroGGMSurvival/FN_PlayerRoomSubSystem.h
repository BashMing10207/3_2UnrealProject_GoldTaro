// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FN_IElectronicInteractive.h"
#include "Subsystems/WorldSubsystem.h"
#include "FN_PlayerRoomSubSystem.generated.h"

class AFN_Electronic_Slot;
/**
 * 
 */
UCLASS(BlueprintTYpe)

class GOLDTAROGGMSURVIVAL_API UFN_PlayerRoomSubSystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	
	TObjectPtr<AFN_Electronic_Slot> ElectricSlot;
public:
	
	void InitElectronic(AFN_Electronic_Slot* el)
	{
		ElectricSlot = el;
	}

	UFUNCTION(BlueprintCallable,Blueprintable)
	AFN_Electronic_Slot* GetElectronicSlot()
	{
		if (ElectricSlot)
		return ElectricSlot;

#if UE_EDITOR

		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "ElectricSlot_and_your_mom_are_Null");
#endif 
		
		return nullptr;
	};
	

	
	
};
