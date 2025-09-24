// Fill out your copyright notice in the Description page of Project Settings.


#include "FN_PlayerRoomSubSystem.h"

// void UFN_PlayerRoomSubSystem::AddStopEvent(void* method)
// {
// 	OnTurnOff.AddDynamic(method);
// }
void UFN_PlayerRoomSubSystem::AddElEvent(TScriptInterface<IFN_IElectronicInteractive> interface1)
{
	ElectricArray.Add(interface1);
}

void UFN_PlayerRoomSubSystem::DoTurnOff()
{
	for (int i = 0; i < ElectricArray.Num(); i++)
	{
		ElectricArray[i].GetInterface()->Execute_TurnOffEl(ElectricArray[i].GetObject());
	}
}

void UFN_PlayerRoomSubSystem::DOTurnOn()
{
	for (int i = 0; i < ElectricArray.Num(); i++)
	{
		ElectricArray[i].GetInterface()->Execute_TurnOnEL(ElectricArray[i].GetObject());
	}
}
