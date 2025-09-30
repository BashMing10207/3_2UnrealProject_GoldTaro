// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FN_EnemyMoveNode.generated.h"

UCLASS()
class GOLDTAROGGMSURVIVAL_API AFN_EnemyMoveNode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFN_EnemyMoveNode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// //virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	// virtual void OnConstruction(const FTransform& Transform) override;

public:
	UPROPERTY(EditAnywhere,BLueprintReadWrite)
	TArray<AFN_EnemyMoveNode*> NextNodes;
};
