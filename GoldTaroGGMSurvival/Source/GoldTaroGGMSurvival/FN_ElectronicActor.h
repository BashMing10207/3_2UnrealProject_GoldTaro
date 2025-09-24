// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FN_IElectronicInteractive.h"
#include "GameFramework/Actor.h"
#include "FN_ElectronicActor.generated.h"

UCLASS()
class GOLDTAROGGMSURVIVAL_API AFN_ElectronicActor : public AActor,public IFN_IElectronicInteractive
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFN_ElectronicActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void TurnOffEl_Implementation() override;;
};
