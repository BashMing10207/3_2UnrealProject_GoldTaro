// Fill out your copyright notice in the Description page of Project Settings.


#include "FN_PlayerCharacter.h"

#include "IFNInteractivable.h"
#include "Camera/CameraComponent.h"

AFN_PlayerCharacter::AFN_PlayerCharacter()
{
	
}

void AFN_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFN_PlayerCharacter::Jump);
	PlayerInputComponent->BindAxis("MoveForward", this, &AFN_PlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFN_PlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MouseX", this, &AFN_PlayerCharacter::RotateX);
	PlayerInputComponent->BindAxis("MouseY", this, &AFN_PlayerCharacter::RotateY);
	PlayerInputComponent->BindAxis("Crouch", this, &AFN_PlayerCharacter::DoCrouch);
	PlayerInputComponent->BindAction("Interactive", IE_Pressed, this, &AFN_PlayerCharacter::Interact);
	PlayerInputComponent->BindAction("Click", IE_Pressed, this, &AFN_PlayerCharacter::Click);
	PlayerInputComponent->BindAction("AltClick", IE_Pressed, this, &AFN_PlayerCharacter::ALTClick);
}

void AFN_PlayerCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}
void AFN_PlayerCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void AFN_PlayerCharacter::RotateX(float Value)
{
	AddControllerYawInput(Value);
}

void AFN_PlayerCharacter::RotateY(float Value)
{
	AddControllerPitchInput(-Value);
}

void AFN_PlayerCharacter::DoJump()
{
	Jump();
}

void AFN_PlayerCharacter::DoCrouch(float Value)
{
	if (Value > 0.2f)
		Crouch();
	else
	{
		UnCrouch();
	}
}

void AFN_PlayerCharacter::Interact()
{
	FCollisionQueryParams Params(SCENE_QUERY_STAT(LineTrace), /*bTraceComplex=*/false);
	Params.AddIgnoredActor(this);
	FHitResult OutHit;

	
	if (CameraComp != nullptr)
	{
		const bool bHit =GetWorld() ->LineTraceSingleByChannel(
		OutHit,
		CameraComp->GetComponentLocation(), CameraComp->GetComponentLocation() + CameraComp->GetForwardVector()*InteractiveRange,
		ECC_Visibility,       // 흔히 Visibility 사용
		Params
	);
		// if (bHit)
		// {
		// 	if (OutHit.GetActor())
		// 	{
		// 		IIFNInteractivable* target = Cast<IIFNInteractivable>(OutHit.GetActor());
		// 		if (target)
		// 		{
		// 			IIFNInteractivable::Execute_Interact(OutHit.GetActor(),nullptr,this);
		// 		}
		// 	}
		// }
	}
	
}

void AFN_PlayerCharacter::Click()
{
	
}

void AFN_PlayerCharacter::ALTClick()
{
	
}


