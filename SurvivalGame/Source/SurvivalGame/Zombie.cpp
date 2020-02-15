// Copyright 2020 Northview High School Game Development Club


#include "Zombie.h"

AZombie::AZombie()
{
	/*Write code here!*/


	//Set default values of health and scoreAddition

	
}

void AZombie::dieCharacter()
{
	/*Write code here*/
	/*Uncomment the code below and then modify it as instructed*/
	//USurvivalGameInstance* gameInstance = Cast</*Insert name of game instance class*/>(UGameplayStatics::GetGameInstance(this));
	//Then use gameInstance to call addToScore(/*Insert scoreAddition here*/)
		//To call functions from a pointer, use the arrow -> 

	this->Destroy();
}