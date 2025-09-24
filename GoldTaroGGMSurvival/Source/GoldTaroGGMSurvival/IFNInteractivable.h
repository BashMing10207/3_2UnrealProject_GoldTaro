#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "IFNInteractivable.generated.h"
class ABSItemObjBase;
// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UIFNInteractivable : public UInterface
{
	GENERATED_BODY()
};

class GOLDTAROGGMSURVIVAL_API IIFNInteractivable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Interact(AFN_PlayerArm* playerArm, AActor* caller, ABSItemObjBase*& target);
};
