// Fill out your copyright notice in the Description page of Project Settings.


#include "FN_EnemyMoveNode.h"

// Sets default values
AFN_EnemyMoveNode::AFN_EnemyMoveNode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFN_EnemyMoveNode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFN_EnemyMoveNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

 }
// #if WITH_EDITOR
//
// #include "DrawDebugHelpers.h"
//
// // void AFN_EnemyMoveNode::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
// // {
// // 	Super::PostEditChangeProperty(PropertyChangedEvent);
// //
// // 	// for (int i = 0; i < NextNodes.Num(); i++)
// // 	// {
// // 	// 	if (!NextNodes.IsValidIndex(i))
// // 	// 	break;
// // 	// 	if (NextNodes[i] == nullptr)
// // 	// 		break;
// // 	// 	
// // 	// 	DrawDebugDirectionalArrow(
// // 	// 	   GetWorld(),
// // 	// 	   GetActorLocation(),
// // 	// 	   NextNodes[i]->GetActorLocation(),
// // 	// 	   FVector::Distance(GetActorLocation(),NextNodes[i]->GetActorLocation()),    // 화살표 길이
// // 	// 	   FColor::Green,
// // 	// 	   true, -1.f, 0, 5.0f
// // 	//    );
// // 	// }
// // 	
// // }
//
//
// void AFN_EnemyMoveNode::OnConstruction(const FTransform& Transform)
// {
// 	
// 	for (int i = 0; i < NextNodes.Num(); i++)
// 	{
// 		if (!NextNodes.IsValidIndex(i))
// 			break;
// 		if (NextNodes[i] == nullptr)
// 			break;
// 		
// 		DrawDebugDirectionalArrow(
// 		   GetWorld(),
// 		   GetActorLocation(),
// 		   NextNodes[i]->GetActorLocation(),
// 		   FVector::Distance(GetActorLocation(),NextNodes[i]->GetActorLocation()),    // 화살표 길이
// 		   FColor::Green,
// 		   true, 0.1f, 0, 5.0f
// 	   );
// 	}
// }
// #endif
//
