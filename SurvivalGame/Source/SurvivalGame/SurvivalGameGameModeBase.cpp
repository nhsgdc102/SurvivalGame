// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "SurvivalGameGameModeBase.h"

ASurvivalGameGameModeBase::ASurvivalGameGameModeBase()
{
	/*Write code here*/
	//Set default values of bShouldSpawnZombies and timeBetweenSpawns

}

void ASurvivalGameGameModeBase::BeginPlay()
{
	/*Write code here*/

	//Make a conditional so that if bShouldSpawnZombies is true, startSpawnTimer() will be called
}

void ASurvivalGameGameModeBase::startSpawnTimer()
{
	GetWorldTimerManager().SetTimer(spawnTimerHandle, this, &ASurvivalGameGameModeBase::spawnZombie, 1.f, false, timeBetweenSpawns);
}

void ASurvivalGameGameModeBase::spawnZombie()
{
	/*Write code here*/

	//Use GetWorld()->SpawnActor<AZombie>(/*Insert call to get location here*/, FRotator(0.f));
}

FVector ASurvivalGameGameModeBase::getRandomLocation()
{
	/*Write code here*/
	//Ask Aneet for help

	return FVector(0.f);
}