// Fill out your copyright notice in the Description page of Project Settings.


#include "FN_PlayerArm.h"
#include "BSItemObjBase.h"
#include "FN_PlayerCharacter.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"


AFN_PlayerArm::AFN_PlayerArm()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TestCompo = CreateDefaultSubobject<USceneComponent>("TestCompo");
	RootComponent = TestCompo;
	// HandPoint = CreateDefaultSubobject<UStaticMeshComponent>("HandPoint");
	// BodyJoint = CreateDefaultSubobject<UPhysicsConstraintComponent>("BodyJoint");
	// //RootComponent = BodyJoint;
	// BodyJoint->SetupAttachment(TestCompo);
	// HandPoint->SetupAttachment(BodyJoint);

	// SprArmCompo = CreateDefaultSubobject<USpringArmComponent>("springArmCompo");
	//
	ArmTarget = CreateDefaultSubobject<UStaticMeshComponent>("ArmTarget");
	ArmTarget->SetupAttachment(TestCompo);
	// ArmTarget->SetupAttachment(SprArmCompo);
	
	PhysArmCompo = CreateDefaultSubobject<UPhysicsHandleComponent>("PhysArmCompo");
}	

// Called when the game starts or when spawned
void AFN_PlayerArm::BeginPlay()
{
	Super::BeginPlay();
	PhysArmCompo->GrabComponent(ArmTarget,NAME_None,ArmTarget->GetComponentLocation(),true);


	//BodyJoint->UpdateConstraintFrames();	
}

// Called every frame
void AFN_PlayerArm::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// TestCompo->SetWorldTransform
	// SetActorTransform(OwningPawn->GetActorTransform());
	// BodyJoint->SetRelativeLocation(FVector(0, 0, 0));
	//TestCompo->SetWorldTransform(OwningPawn->GetActorTransform());
	ApplyHandPosTarget();
	// GEngine->AddOnScreenDebugMessage(-1,0.5f,FColor::Red,
	// 	(FString::Printf(TEXT("%f,%f,%f"),BodyJoint->GetComponentLocation().X,BodyJoint->GetComponentLocation().Y,BodyJoint->GetComponentLocation().Z)));
	// ApplyHandPosTarget() 마지막에
	//BodyJoint->UpdateConstraintFrames();

}

void AFN_PlayerArm::SetHandPosTarget_Implementation(FTransform BodyPos,FTransform TArgetPos)
{
	PhysArmCompo->SetTargetLocationAndRotation(TargetPos.GetLocation(),TArgetPos.GetRotation().Rotator());
	//TArgetPos.SetScale3D(FVector(1.0f,1.0f,1.0f));
	// TargetPos= BodyJoint->GetComponentTransform().Inverse() * TArgetPos;
	// TargetPos.SetLocation(BodyJoint->GetComponentTransform().InverseTransformPosition(TargetPos.GetLocation())*-1);
}
void AFN_PlayerArm::ApplyHandPosTarget()
{
	// BodyJoint->SetLinearPositionTarget(TargetPos.GetLocation());
	// BodyJoint->SetAngularOrientationTarget(TargetPos.GetRotation().Rotator());
	// BodyJoint->UpdateConstraintFrames();

}
void AFN_PlayerArm::SetUpBodyJoint(UPrimitiveComponent* BodyCompo)
{
		// PhysArmCompo->GrabComponent(ArmTarget,NAME_None,ArmTarget->GetComponentLocation(),true);
		//
	
	// BodyJoint->SetConstrainedComponents(BodyCompo,NAME_None,HandPoint,
	// NAME_None);
	// Frame1: HandPoint 기준(로컬)
	// A) 컴포넌트 연결
	// BodyJoint->SetConstrainedComponents(
	// 	HandPoint, NAME_None,
	// 	BodyCompo,  NAME_None
	// );
	//
	// // B) Frame1: HandPoint 로컬 기준 (Identity)
	// BodyJoint->SetConstraintReferenceFrame(
	// 	EConstraintFrame::Frame1,
	// 	FTransform::Identity
	// );
	//
	// // C) Frame2: BodyCompo 기준, HandPoint 기준으로 상대 위치 계산
	// //    → 같은 기준점에서 목표를 해석하게 만듭니다.
	// FTransform HandWorld  = HandPoint->GetComponentTransform();
	// FTransform BodyWorld  = BodyCompo->GetComponentTransform();
	// FTransform Frame2     = BodyWorld.GetRelativeTransform(HandWorld);
	//
	// BodyJoint->SetConstraintReferenceFrame(
	// 	EConstraintFrame::Frame2,
	// 	Frame2
	// );
	//BodyJoint->UpdateConstraintFrames();

	OwningPawn = (BodyCompo->GetOwner());
	OwningChar = Cast<AFN_PlayerCharacter>(OwningPawn);
}
void AFN_PlayerArm::SetUpBodyJoint(UPrimitiveComponent* BodyCompo,FName BOneName)
{
	//BodyJoint->SetConstrainedComponents(HandPoint,NAME_None,BodyCompo,
	//BOneName);
}

void AFN_PlayerArm::SetHoldingItem(ABSItemObjBase* ItemB)
{
	HoldingItem = ItemB;
}

ABSItemObjBase* AFN_PlayerArm::UseItemObj_Implementation(AFN_PlayerArm* arm, AActor* Caller)
{
	// if (HoldingItem == nullptr)
	{
		if (HoldingItem != nullptr)
		{
			IFN_IHoldingInteractivable::Execute_UseItemObj(HoldingItem,this,OwningPawn);
		}
		else
		{
			NoItemUseArm(Caller);
		}
	}
		
	
	
	return nullptr;
}


void AFN_PlayerArm::GrabArm(AActor* Caller)
{

	//GEngine->AddOnScreenDebugMessage(-1,0.9f,FColor::Red,"Hit.GetActor()->GetName()");

	ABSItemObjBase* TempItemPtr = HoldingItem;
	// if (!!HoldingItem)
	// {
	// 	IIBSHoldingInteractiveable::Execute_ReleaseItemObj(HoldingItem,this,OwningPawn);
	// 	HoldingItem = nullptr;
	// }
		
	FVector Start = GetActorTransform().GetLocation();
	FVector End = GetActorTransform().GetLocation() + GetActorForwardVector()*GrabDistance;

	if (!!InteractivePivot)
	{
		Start = InteractivePivot->GetComponentLocation();
		End = InteractivePivot->GetComponentLocation() + InteractivePivot->GetForwardVector()*GrabDistance;
	
	}
	
	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);           // 자기 자신 무시
	Params.AddIgnoredActor(OwningPawn);
	
	if (!!ReverseArmComponent)
		Params.AddIgnoredActor(ReverseArmComponent);
	Params.bTraceComplex = true;            // 정밀 충돌 검사
	Params.bReturnPhysicalMaterial = false;

	bool bHit = GetWorld()->LineTraceSingleByChannel(
		Hit,
		Start,
		End,
		ECC_Visibility,     // 사용할 채널
		Params
	);

	if (bHit)
	{
		if (!!Hit.GetActor())
		{
			IIFNInteractivable* TargetItem = Cast<IIFNInteractivable>(Hit.GetActor());
			if (TargetItem != nullptr)
			{
				
				
				GEngine->AddOnScreenDebugMessage(-1,0.9f,FColor::Red,Hit.GetActor()->GetName());
				TargetItem->Execute_Interact(Hit.GetActor(),this,OwningPawn,HoldingItem);
				
				
				if (!!HoldingItem)
				{
					HoldingItem->AttachToComponent(ArmTarget,FAttachmentTransformRules::SnapToTargetNotIncludingScale
						);//,bIsRight ? FName(TEXT("RightHand")):FName(TEXT("LeftHand"))
					if (HoldingItem->GetMeshComponent()->DoesSocketExist("Pivot"))
					{
						FTransform PivotTransform =HoldingItem->GetMeshComponent()->GetSocketTransform("Pivot");
	 					FTransform Delta = ArmTarget->GetComponentTransform().GetRelativeTransform(PivotTransform);
						// HoldingItem->SetActorRelativeTransform(PivotTransform * ScaleTrm);
						
						HoldingItem->GetMeshComponent()->SetRelativeLocation(-Delta.GetLocation());
						HoldingItem->GetMeshComponent()->SetRelativeRotation(Delta.GetRotation().Inverse());
					}
					else
					{
						
					}
				}
				else
				{
					
				}
			}
		}

	}
}

FHitResult AFN_PlayerArm::GetHitResult()
{
	FVector Start = GetActorTransform().GetLocation();
	FVector End = GetActorTransform().GetLocation() + GetActorForwardVector()*GrabDistance;

	if (!!InteractivePivot)
	{
		Start = InteractivePivot->GetComponentLocation();
		End = InteractivePivot->GetComponentLocation() + InteractivePivot->GetForwardVector()*GrabDistance;
	
	}
	
	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);           // 자기 자신 무시
	Params.AddIgnoredActor(OwningPawn);
	
	if (!!ReverseArmComponent)
		Params.AddIgnoredActor(ReverseArmComponent);
	Params.bTraceComplex = true;            // 정밀 충돌 검사
	Params.bReturnPhysicalMaterial = false;

	bool bHit = GetWorld()->LineTraceSingleByChannel(
		Hit,
		Start,
		End,
		ECC_Visibility,     // 사용할 채널
		Params
	);
	return Hit;
}

void AFN_PlayerArm::DropItem()
{
	if (HoldingItem != nullptr)
	{
		IFN_IHoldingInteractivable::Execute_ReleaseItemObj(HoldingItem,this,OwningPawn);
		HoldingItem = nullptr;
	}
}
//
// class AFN_PlayerArm* AFN_PlayerArm::UseArm_Implementation(AActor* Caller)
// {
// 	// if (HoldingItem == nullptr)
// 	{
// 		if (HoldingItem != nullptr)
// 		{
// 			IFN_IHoldingInteractivable::Execute_UseItemObj(HoldingItem,this,OwningPawn);
// 		}
// 		else
// 		{
// 			NoItemUseArm(Caller);
// 		}
// 	}
// 		
// 	
// 	
// 	return this;
// }
