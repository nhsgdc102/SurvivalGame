// Copyright 2020 Northview High School Game Development Club


#include "SurvivalGameMode.h"

ASurvivalGameMode::ASurvivalGameMode()
{
	/*Write code here*/


	//Set default values of all variables (bShouldSpawnZombies, timeBetweenSpawns, minimumXLocation, etc.)
}

void ASurvivalGameMode::BeginPlay()
{
	/*Write code here*/

	//Make a conditional so that if bShouldSpawnZombies is true, startSpawnTimer() will be called
}

void ASurvivalGameMode::startSpawnTimer()
{
	GetWorldTimerManager().SetTimer(spawnTimerHandle, this, &ASurvivalGameMode::spawnZombie, 1.f, false, timeBetweenSpawns);
}

void ASurvivalGameMode::spawnZombie()
{
	/*Write code here*/

	//Use GetWorld()->SpawnActor<AZombie>(ZombieClass, /*Insert call to GetRandomLocation() here*/, FRotator(0.f));
}

FVector ASurvivalGameMode::getRandomLocation() const
{
	FVector randLocation;
	/*Write code here*/
	/*Uncomment code below and insert the necessary variables*/
	//float XLocation = FMath::RandRange(/*Insert minimum*/, /*Insert maximum*/);
	//float YLocation = FMath::RandRange(/*Insert minimum*/, /*Insert maximum*/);
	//randLocation = FVector(XLocation, YLocation, ZLocation);

	return randLocation;
}