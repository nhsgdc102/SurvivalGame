// Copyright 2020 Northview High School Game Development Club


#include "Zombie.h"

AZombie::AZombie()
{
	/*Write code here!*/
    
    scoreAddition = 5;
	//Set default values of health and scoreAddition

	
}

void AZombie::dieCharacter()
{
	/*Write code here*/
	/*Uncomment the code below and then modify it as instructed*/
	USurvivalGameInstance* gameInstance = Cast<USurvivalGameInstance>(UGameplayStatics::GetGameInstance(this));
	//Then use gameInstance to call addToScore(/*Insert scoreAddition here*/)
		//To call functions from a pointer, use the arrow ->
    gameInstance->addToScore(scoreAddition);


	//Also set bDead equal to true
    bDead = true;
	GetCharacterMovement()->StopMovementImmediately(); //stops zombie from walking any longer
    SetLifeSpan(10.f);
	//Use SetLifeSpan(float timeTillDeath) to set a timer for the zombie's death. Example-> SetLifeSpan(10.f);
}

