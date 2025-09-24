// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FN_IHoldingInteractivable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UFN_IHoldingInteractivable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GOLDTAROGGMSURVIVAL_API IFN_IHoldingInteractivable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, Blueprintable,BlueprintCallable)
	ABSItemObjBase* UseItemObj(class AFN_PlayerArm* UsingArm, AActor* Caller);
	UFUNCTION(BlueprintNativeEvent, Blueprintable,BlueprintCallable)
	ABSItemObjBase* ALTUseItemObj(AFN_PlayerArm* UsingArm, AActor* Caller);
	UFUNCTION(BlueprintNativeEvent, Blueprintable,BlueprintCallable)
	ABSItemObjBase* ReleaseItemObj(AFN_PlayerArm* UsingArm, AActor* Caller);
	UFUNCTION(BlueprintNativeEvent, Blueprintable,BlueprintCallable)
	ABSItemObjBase* ReloadItemObj(AFN_PlayerArm* UsingArm, AActor* Caller);
	UFUNCTION(BlueprintNativeEvent, Blueprintable,BlueprintCallable)
	ABSItemObjBase* RealUseItemObj(AFN_PlayerArm* UsingArm, AActor* Caller);
	UFUNCTION(BlueprintNativeEvent, Blueprintable,BlueprintCallable)
	ABSItemObjBase* RealAltUseItemObj(AFN_PlayerArm* UsingArm, AActor* Caller);
	UFUNCTION(BlueprintNativeEvent, Blueprintable,BlueprintCallable)
	ABSItemObjBase* RealReloadItemObj(AFN_PlayerArm* UsingArm, AActor* Caller);
};
