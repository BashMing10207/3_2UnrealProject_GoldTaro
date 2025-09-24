#pragma once

#include "CoreMinimal.h"
#include "FN_IHoldingInteractivable.h"

#include "GameFramework/Actor.h"
#include "IFNInteractivable.h"
#include "BSItemObjBase.generated.h"

class UPhysicsConstraintComponent;

UCLASS()
class GOLDTAROGGMSURVIVAL_API ABSItemObjBase : public AActor, public IIFNInteractivable, public IFN_IHoldingInteractivable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABSItemObjBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	ABSItemObjBase* ItemHolderInteractive(class ABSItemHolder* Holder,bool HoldOn);
	
public:
UMeshComponent* GetMeshComponent()
{
	return MeshCompo;
}
protected:	
	virtual void Interact_Implementation(AFN_PlayerArm* arm,AActor* caller,ABSItemObjBase* &target) override;

	
	virtual ABSItemObjBase* UseItemObj_Implementation(AFN_PlayerArm* UsingArm, AActor* Caller) override;

	virtual ABSItemObjBase* ALTUseItemObj_Implementation(AFN_PlayerArm* UsingArm, AActor* Caller) override;

	virtual ABSItemObjBase* ReleaseItemObj_Implementation(AFN_PlayerArm* UsingArm, AActor* Caller) override;
	
	//virtual ABSItemObjBase* GetItemObj_Implementation() override;;
	
	virtual void BeAttach(bool isAttach);
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UMeshComponent> MeshCompo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UAdvencedInteractableObjCompo> InteractableObjCompo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class AFN_PlayerArm> HoldingArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UAnimMontage> UseItemAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UAnimMontage> AltUseItemAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UAnimMontage> ReleaseItemAnim;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanHold = true;
};



UCLASS(Blueprintable)
class GOLDTAROGGMSURVIVAL_API ASkeltalMeshItemObjBase : public ABSItemObjBase
{
	GENERATED_BODY()

	public: ASkeltalMeshItemObjBase();
};

UCLASS(Blueprintable)
class GOLDTAROGGMSURVIVAL_API AStaticMeshItemObjBase : public ABSItemObjBase
{
	GENERATED_BODY()

public: AStaticMeshItemObjBase();
};