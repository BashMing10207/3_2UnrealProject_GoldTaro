// Fill out your copyright notice in the Description page of Project Settings.


#include "FN_ElectronicActor.h"

#include "FN_Electronic_Slot.h"
#include "FN_PlayerRoomSubSystem.h"

// Sets default values
AFN_ElectronicActor::AFN_ElectronicActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFN_ElectronicActor::PostInitializeComponents()
{
	

	
	Super::PostInitializeComponents();

}


// Called when the game starts or when spawned
void AFN_ElectronicActor::BeginPlay()
{
	Super::BeginPlay();
	UFN_PlayerRoomSubSystem* playerRoom = GetWorld()->GetSubsystem<UFN_PlayerRoomSubSystem>();
	if (playerRoom)
	{
		OwnerElectricSlot4 = playerRoom->ElectricSlot;
		if (OwnerElectricSlot4 != nullptr)
			OwnerElectricSlot4->AddElEvent(this);
	}
}

// Called every frame
void AFN_ElectronicActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFN_ElectronicActor::TurnOffEl_Implementation()
{
	IFN_IElectronicInteractive::TurnOffEl_Implementation();
}


