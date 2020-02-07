// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
//World timer manager
#include "TimerManager.h"
#include "Zombie.h"
#include "Engine/World.h"

#include "SurvivalGameGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVALGAME_API ASurvivalGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	//Constructor
	ASurvivalGameGameModeBase();

protected:
	void BeginPlay();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bShouldSpawnZombies;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float timeBetweenSpawns;

private:
	FTimerHandle spawnTimerHandle;

public:
	void startSpawnTimer();

	UFUNCTION()
		void spawnZombie();

private:
	FVector getRandomLocation();
	
};
