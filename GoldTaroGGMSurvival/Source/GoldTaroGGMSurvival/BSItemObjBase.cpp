// Fill out your copyright notice in the Description page of Project Settings.


#include "BSItemObjBase.h"
#include "AdvencedInteractableObjCompo.h"

// Sets default values
ABSItemObjBase::ABSItemObjBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InteractableObjCompo = CreateDefaultSubobject<UAdvencedInteractableObjCompo>("InteractableObjCompo");

	
}
ASkeltalMeshItemObjBase::ASkeltalMeshItemObjBase()
{
	MeshCompo = CreateDefaultSubobject<USkeletalMeshComponent>("MeshCompo");

	RootComponent = MeshCompo;
}

AStaticMeshItemObjBase::AStaticMeshItemObjBase()
{
	MeshCompo = CreateDefaultSubobject<UStaticMeshComponent>("MeshCompo");
	RootComponent = MeshCompo;	
}

// Called when the game starts or when spawned
void ABSItemObjBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABSItemObjBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// ABSItemObjBase* ABSItemObjBase::ItemHolderInteractive(ABSItemHolder* Holder,bool HoldOn)
// {
// 	if (HoldOn)
// 	{
// 		ItemHolder = Holder;
// 		BeAttach(true);
// 	}
// 	else
// 	{
// 		ItemHolder = nullptr;
// 		BeAttach(false);
// 	}
//
// 	return this;
// 	
// }

void ABSItemObjBase::Interact_Implementation(AFN_PlayerArm* arm,AActor* caller,ABSItemObjBase* &target)
{
	if (arm == nullptr ||HoldingArm != nullptr || !bCanHold)
	{
		target = nullptr;
		return;
	}
	
	// if (ItemHolder != nullptr)
	// {
	// 	ItemHolder->DropItem();
	// 	ItemHolder->HoldItem(nullptr);
	// }
	
	HoldingArm = arm;
	BeAttach(true);
	

	
	target = this;
}

ABSItemObjBase* ABSItemObjBase::UseItemObj_Implementation(AFN_PlayerArm* UsingArm, AActor* Caller)
{
	// for (auto i : Cast<ABS_BaseChar>(Caller)->GetSkeletalMeshComponent())
	// {
	// 	i->GetAnimInstance()->Montage_Play(UseItemAnim);
	// 	i->GetAnimInstance()->Montage_JumpToSection(
	// 	UsingArm->bIsRight ? FName(TEXT("Default")):FName(TEXT("Mirror")),UseItemAnim);
	// }

	// Cast<ABS_BaseChar>(Caller)->GetSkeletalMeshComponent()->GetAnimInstance()->Montage_JumpToSection()
	
	return this;
}

ABSItemObjBase* ABSItemObjBase::ALTUseItemObj_Implementation(AFN_PlayerArm* UsingArm, AActor* Caller)
{
	
	// // Cast<ABS_BaseChar>(Caller)->GetSkeletalMeshComponent()->GetAnimInstance()->PlaySlotAnimationAsDynamicMontage(AltUseItemAnim,
	// // UsingArm->bIsRight ? FName(TEXT("Default")):FName(TEXT("Mirror")),0.1f,0.1f,1,1);
	// Cast<ABS_BaseChar>(Caller)->GetSkeletalMeshComponent()->GetAnimInstance()->Montage_Play(AltUseItemAnim);
	// Cast<ABS_BaseChar>(Caller)->GetSkeletalMeshComponent()->GetAnimInstance()->Montage_JumpToSection(
	// 	UsingArm->bIsRight ? FName(TEXT("Default")):FName(TEXT("Mirror")),AltUseItemAnim);

	// for (auto i : Cast<ABS_BaseChar>(Caller)->GetSkeletalMeshComponent())
	// {
	// 	i->GetAnimInstance()->Montage_Play(AltUseItemAnim);
	// 	i->GetAnimInstance()->Montage_JumpToSection(
	// 	UsingArm->bIsRight ? FName(TEXT("Default")):FName(TEXT("Mirror")),AltUseItemAnim);
	// }
	return this;
}

ABSItemObjBase* ABSItemObjBase::ReleaseItemObj_Implementation(AFN_PlayerArm* UsingArm, AActor* Caller)
{
	// // Cast<ABS_BaseChar>(Caller)->GetSkeletalMeshComponent()->GetAnimInstance()->PlaySlotAnimationAsDynamicMontage(ReleaseItemAnim,
	// //UsingArm->bIsRight ? FName(TEXT("Default")):FName(TEXT("Mirror")),0.1f,0.1f,1,1);
	// Cast<ABS_BaseChar>(Caller)->GetSkeletalMeshComponent()->GetAnimInstance()->Montage_Play(ReleaseItemAnim);
	// // (ReleaseItemAnim,
	// // FName(TEXT("Default")),0.1f,0.1f,1,1);
	// Cast<ABS_BaseChar>(Caller)->GetSkeletalMeshComponent()->GetAnimInstance()->Montage_JumpToSection(
	// 		UsingArm->bIsRight ? FName(TEXT("Default")):FName(TEXT("Mirror")),ReleaseItemAnim);

	// for (auto i : Cast<ABS_BaseChar>(Caller)->GetSkeletalMeshComponent())
	// {
	// 	i->GetAnimInstance()->Montage_Play(ReleaseItemAnim);
	// 	i->GetAnimInstance()->Montage_JumpToSection(
	// 	UsingArm->bIsRight ? FName(TEXT("Default")):FName(TEXT("Mirror")),ReleaseItemAnim);
	// }
	BeAttach(false);
	
	return this;
}

// ABSItemObjBase* ABSItemObjBase::RealUseItemObj_Implementation(AFN_PlayerArm* UsingArm, AActor* Caller)
// {
// 	
// 	return this;
// }
//
// ABSItemObjBase* ABSItemObjBase::RealAltUseItemObj_Implementation(AFN_PlayerArm* UsingArm, AActor* Caller)
// {
// 	
// 	return this;
// }

void ABSItemObjBase::BeAttach(bool isAttach)
{
	if (isAttach)
	{
		MeshCompo->SetSimulatePhysics(false);
		MeshCompo->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		
	}
	else
	{
		DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		MeshCompo->SetSimulatePhysics(true);
		MeshCompo->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		SetOwner(nullptr);
		HoldingArm = nullptr;
	}
}



