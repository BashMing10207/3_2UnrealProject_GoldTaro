// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FN_BaseCharacter.h"
#include "FN_PlayerCharacter.generated.h"

class UCameraComponent;
/**
 * 
 */
UCLASS()
class GOLDTAROGGMSURVIVAL_API AFN_PlayerCharacter : public AFN_BaseCharacter
{
	GENERATED_BODY()
	
public:

	AFN_PlayerCharacter();

	
	
protected:

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<UCameraComponent> CameraComp;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float InteractiveRange = 200.f;
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	void MoveForward(float Value);
	void MoveRight(float Value);
	void RotateX(float Value);
	void RotateY(float Value);
	void DoJump();

	void DoCrouch(float Value);

	void Interact();
	void Click();
	void ALTClick();
};
