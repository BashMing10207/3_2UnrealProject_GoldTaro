// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FN_IElectronicInteractive.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UFN_IElectronicInteractive : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GOLDTAROGGMSURVIVAL_API IFN_IElectronicInteractive
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void TurnOnInteractive();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void StopElectrinicInteractive();
};
