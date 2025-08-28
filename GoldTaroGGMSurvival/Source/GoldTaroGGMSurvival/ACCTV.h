// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IExecuterable.h"
#include "GameFramework/Actor.h"
#include "ACCTV.generated.h"

UCLASS()
class GOLDTAROGGMSURVIVAL_API AACCTV : public APawn, public IIExecuterable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AACCTV();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EnforceFunc_Implementation(AActor* Owner);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
