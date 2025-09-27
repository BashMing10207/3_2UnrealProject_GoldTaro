// Fill out your copyright notice in the Description page of Project Settings.


#include "FN_Electronic_Slot.h"

#include "FN_IElectronicInteractive.h"
#include "FN_PlayerRoomSubSystem.h"

// Sets default values
AFN_Electronic_Slot::AFN_Electronic_Slot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFN_Electronic_Slot::BeginPlay()
{
	Super::BeginPlay();
	// if (GetWorld() == nullptr)
	// {
	// 	if (IsValid(GetWorld()->GetSubsystem<UFN_PlayerRoomSubSystem>()))
	// 		GetWorld()->GetSubsystem<UFN_PlayerRoomSubSystem>()->InitElectronic(this);
	// }
}

void AFN_Electronic_Slot::PostInitializeComponents()
{
	if (GetWorld() != nullptr)
	{
		if (IsValid(GetWorld()->GetSubsystem<UFN_PlayerRoomSubSystem>()))
		GetWorld()->GetSubsystem<UFN_PlayerRoomSubSystem>()->InitElectronic(this);
	}
		
	Super::PostInitializeComponents();
}

// Called every frame
void AFN_Electronic_Slot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFN_Electronic_Slot::AddElEvent(TScriptInterface<IFN_IElectronicInteractive> interface1)
{
	ElectricArray.Add(interface1);
}

void AFN_Electronic_Slot::UseEnergy_Implementation(int cost,bool& bisTurnOn)
{
	CurrentEnergy += cost;

	if (CurrentEnergy <= 0)
		DoTurnOff();
	bisTurnOn = CurrentEnergy <= 0;
	CheckEnergy();
}

void AFN_Electronic_Slot::SetEnergy_Implementation(int newEnergy, int& remainingEnergy)
{
	remainingEnergy = CurrentEnergy;
	CurrentEnergy = newEnergy;

	if (CurrentEnergy > 0)
	DoTurnOff();
	else
		DoTurnOff();
	CheckEnergy();
}

void AFN_Electronic_Slot::GetEnergy_Implementation(int& remainingEnergy)
{
	remainingEnergy = CurrentEnergy;

}

void AFN_Electronic_Slot::CheckEnergy_Implementation()
{
	
}

void AFN_Electronic_Slot::AddUseage(int amount)
{
	Useage += amount;
}

void AFN_Electronic_Slot::DoTurnOff()
{
	for (int i = 0; i < ElectricArray.Num(); i++)
	{
		ElectricArray[i].GetInterface()->Execute_TurnOffEl(ElectricArray[i].GetObject());
	}
}

void AFN_Electronic_Slot::DOTurnOn()
{
	for (int i = 0; i < ElectricArray.Num(); i++)
	{
		ElectricArray[i].GetInterface()->Execute_TurnOnEL(ElectricArray[i].GetObject());
	}
}
