// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IFN_ElectricContains.h"
#include "GameFramework/Actor.h"
#include "FN_Electronic_Slot.generated.h"

UCLASS(BlueprintType,Blueprintable)
class GOLDTAROGGMSURVIVAL_API AFN_Electronic_Slot : public AActor,public IIFN_ElectricContains
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFN_Electronic_Slot();

	
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int CurrentEnergy;
UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int Useage=0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int Difficulty=0;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	TArray<TScriptInterface<IFN_IElectronicInteractive>> ElectricArray;

	
	
public:
	UFUNCTION(BlueprintCallable)
	void AddElEvent(TScriptInterface<IFN_IElectronicInteractive> iterface1);
	// void AddStopEvent(void* method);

	virtual void UseEnergy_Implementation(int cost, bool& bisTurnOn) override;
	virtual void SetEnergy_Implementation(int newEnergy,int& remainingEnergy) override;
	virtual void GetEnergy_Implementation(int& remainingEnergy) override;

	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void CheckEnergy();

	UFUNCTION(BlueprintCallable)
	void AddUseage(int amount);
	
	UFUNCTION(BlueprintCallable)
	void DoTurnOff();
	UFUNCTION(BlueprintCallable)
	void DOTurnOn();
};


