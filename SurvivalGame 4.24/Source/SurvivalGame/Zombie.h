// Copyright 2020 Northview High School Game Development Club

#pragma once

#include "CoreMinimal.h"
#include "BasicCharacter.h"
//Imports game instance class for adding to player score
#include "SurvivalGameInstance.h"
//Imports gameplay statics class for getting game instance
#include "Kismet/GameplayStatics.h"
//Imports character movement class for stopping movement
#include "GameFramework/CharacterMovementComponent.h"

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

/*Write Code Here*/
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float attackPower;

//Create a public float variable named attackPower. This is how much damage the zombie does every time it strike the main player. Give it UPROPERTY(EditAnywhere, BlueprintReadWrite)
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        bool bDead;

/*Write Code Here*/


//Create a public boolean variable named bDead. Give it UPROPERTY(EditAnywhere, BlueprintReadWrite) so that it can be accessed from the Zombie_BP blueprint.
//This variable will be used to determine if the hitboxes should be active
};
