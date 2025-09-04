// Fill out your copyright notice in the Description page of Project Settings.


#include "PLabtop.h"

// Sets default values
APLabtop::APLabtop()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APLabtop::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APLabtop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APLabtop::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

