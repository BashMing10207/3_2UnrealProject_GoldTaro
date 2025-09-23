// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IFN_ElectricContains.generated.h"

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UIFN_ElectricContains : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GOLDTAROGGMSURVIVAL_API IIFN_ElectricContains
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool UseEnergy(int cost);
	// UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	// void 
};
