// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FN_IElectronicInteractive.h"
#include "Subsystems/WorldSubsystem.h"
#include "FN_PlayerRoomSubSystem.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(Fbaeshdelegate);
UCLASS()

class GOLDTAROGGMSURVIVAL_API UFN_PlayerRoomSubSystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	Fbaeshdelegate OnTurnOff;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	TArray<TScriptInterface<IFN_IElectronicInteractive>> ElectricArray;

	
public:
	UFUNCTION(BlueprintCallable)
	void AddElEvent(TScriptInterface<IFN_IElectronicInteractive> iterface1);
	// void AddStopEvent(void* method);

	UFUNCTION(BlueprintCallable)
	void DoTurnOff();
	UFUNCTION(BlueprintCallable)
	void DOTurnOn();
	
};
