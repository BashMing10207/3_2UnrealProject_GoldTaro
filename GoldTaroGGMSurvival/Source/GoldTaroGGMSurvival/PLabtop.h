// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FN_IElectronicInteractive.h"
#include "IFNInteractivable.h"
#include "GameFramework/Pawn.h"
#include "PLabtop.generated.h"


UCLASS(BlueprintType, Blueprintable)
class GOLDTAROGGMSURVIVAL_API APLabtop : public APawn, public IIFNInteractivable, public IFN_IElectronicInteractive
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APLabtop();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void TurnOff() override;
};
