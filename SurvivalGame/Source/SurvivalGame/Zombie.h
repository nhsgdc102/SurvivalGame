// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCharacter.h"
#include "Zombie.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVALGAME_API AZombie : public ABasicCharacter
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	float attackPlayer(float maxDamage, float minDamage);
	
};
