// Fill out your copyright notice in the Description page of Project Settings.


#include "FN_InteractiveableObject.h"

// Sets default values
AFN_InteractiveableObject::AFN_InteractiveableObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFN_InteractiveableObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFN_InteractiveableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFN_InteractiveableObject::Interact_Implementation(AFN_PlayerCharacter* player)
{
	IIFNInteractivable::Interact_Implementation(player);
}

