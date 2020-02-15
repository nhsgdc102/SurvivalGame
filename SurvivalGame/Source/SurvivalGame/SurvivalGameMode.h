// Copyright 2020 Northview High School Game Development Club

#pragma once

#include "CoreMinimal.h"
#include "SurvivalGameGameModeBase.h"
//Imports timer manager for setting timers to spawn zombies
#include "TimerManager.h"
//Imports Zombie class
#include "Zombie.h"
//Imports World class for spawning actors
#include "Engine/World.h"

#include "SurvivalGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVALGAME_API ASurvivalGameMode : public ASurvivalGameGameModeBase
{
	GENERATED_BODY()

public:
	//Constructor
	ASurvivalGameMode();

protected:
	void BeginPlay();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bShouldSpawnZombies;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float timeBetweenSpawns;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomLocation")
		//Most back location at which zombie can spawn
		float minimumXLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomLocation")
		//Most front location at which zombie can spawn
		float maximumXLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomLocation")
		//Most left location at which zombie can spawn
		float minimumYLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomLocation")
		//Most right location at which zombie can spawn
		float maximumYLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomLocation")
		//Height at which zombies are spawned
		float ZLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		//Used to set blueprint zombie class for spawning
		TSubclassOf<AZombie> ZombieClass; //Don't set initial value for this

private:
	FTimerHandle spawnTimerHandle;

public:
	void startSpawnTimer();

	UFUNCTION()
		void spawnZombie();

private:
	FVector getRandomLocation() const;
};
