// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FN_IHoldingInteractivable.h"
#include "GameFramework/Actor.h"
#include "FN_PlayerArm.generated.h"

class AFN_PlayerCharacter;
class ABSItemObjBase;

UCLASS()
class GOLDTAROGGMSURVIVAL_API AFN_PlayerArm : public AActor,public IFN_IHoldingInteractivable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFN_PlayerArm();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void SetHandPosTarget(FTransform BodyPos,FTransform TArgetPos);
	void ApplyHandPosTarget();
	void SetUpBodyJoint(UPrimitiveComponent* BodyCompo);
	void SetUpBodyJoint(UPrimitiveComponent* BodyCompo,FName BOneName);


	void SetHoldingItem(class ABSItemObjBase* ItemB);

	UFUNCTION(BlueprintCallable)
	void SetReverseArmComponent(class AFN_PlayerArm* ArmB)
	{
		ReverseArmComponent = ArmB;
	}
	
	protected:
	
	
	
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
	void NoItemUseArm(AActor* Caller);

	UFUNCTION(BlueprintCallable)
	void GrabArm(AActor* Caller);
public:
	UFUNCTION(BlueprintCallable)
	FHitResult GetHitResult();
	virtual ABSItemObjBase* UseItemObj_Implementation(AFN_PlayerArm* arm,AActor* Caller) override;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ABSItemObjBase* HoldingItem;
UFUNCTION(BLueprintCallable)
	void DropItem();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsRight = true;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="ArmPhysics")
	class UStaticMeshComponent* ArmTarget;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="__Hand")
	USceneComponent* InteractivePivot;
	// UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="__Hand")
	// TObjectPtr<USpringArmComponent> SprArmCompo;
	 UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="__Hand")
	 TObjectPtr<class UPhysicsHandleComponent> PhysArmCompo;
protected:
	// UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Item")
	// TObjectPtr<class UPhysicsConstraintComponent> BodyJoint;
	//
	// UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Item")
	// TObjectPtr<class UStaticMeshComponent> HandPoint;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Item")
	TObjectPtr<class USceneComponent> TestCompo;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Item")
	float GrabDistance = 1.8f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	 TEnumAsByte<ECollisionChannel> TraceChannel = ECC_Visibility;
	

	// class ABSItemObjBase* HoldingItem;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Item")
	class AActor* OwningPawn;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Item")
	AFN_PlayerCharacter* OwningChar;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Item")
	AFN_PlayerArm* ReverseArmComponent;
	
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Item")
	FTransform TargetPos;
};
