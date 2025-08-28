// Fill out your copyright notice in the Description page of Project Settings.


#include "ACCTV.h"

// Sets default values
AACCTV::AACCTV()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AACCTV::BeginPlay()
{
	Super::BeginPlay();
	
}

void AACCTV::EnforceFunc_Implementation(AActor* OwnerActor)
{
	//IIExecuterable::EnforceFunc_Implementation(Owner);
}

// Called every frame
void AACCTV::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

