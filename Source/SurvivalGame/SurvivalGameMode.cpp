// Copyright 2020 Northview High School Game Development Club


#include "SurvivalGameMode.h"

ASurvivalGameMode::ASurvivalGameMode()
{
	/*Write code here*/
    bShouldSpawnZombies = true;
    timeBetweenSpawns = 3.f;
    minimumXLocation = 0.0;
	//Set default values of all variables (bShouldSpawnZombies, timeBetweenSpawns, minimumXLocation, etc.)
}

void ASurvivalGameMode::BeginPlay()
{
	/*Write code here*/
    if (bShouldSpawnZombies == true) {
        startSpawnTimer();
    }
	//Make a conditional so that if bShouldSpawnZombies is true, startSpawnTimer() will be called
}

void ASurvivalGameMode::startSpawnTimer()
{
	GetWorldTimerManager().SetTimer(spawnTimerHandle, this, &ASurvivalGameMode::spawnZombie, 1.f, false, timeBetweenSpawns);
}

void ASurvivalGameMode::spawnZombie()
{
	/*Write code here*/
    GetWorld()->SpawnActor<AZombie>(ZombieClass, getRandomLocation(), FRotator(0.f));
}

FVector ASurvivalGameMode::getRandomLocation() const
{
	FVector randLocation;
	/*Write code here*/
	/*Uncomment code below and insert the necessary variables*/
	float XLocation = FMath::RandRange(-1930.2652f, 1829.73474f);
	float YLocation = FMath::RandRange(-1892.6547f, 1917.34521f);
	randLocation = FVector(XLocation, YLocation, ZLocation);

	return randLocation;
}
