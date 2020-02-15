// Copyright 2020 Northview High School Game Development Club

#pragma once

#include "CoreMinimal.h"
#include "BasicCharacter.h"
//Imports game instance class for adding to player score
#include "SurvivalGameInstance.h"
//Imports gameplay statics class for getting game instance
#include "Kismet/GameplayStatics.h"

#include "Zombie.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVALGAME_API AZombie : public ABasicCharacter
{
	GENERATED_BODY()

public:
	//Constructor -- sets default values
	AZombie();

private:
	// Called when health dips to 0
	virtual void dieCharacter() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		//The amount added to the player's score when the zombie dies
		int32 scoreAddition;
	
};
