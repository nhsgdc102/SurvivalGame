// Copyright 2020 Northview High School Game Development Club

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SurvivalGameInstance.generated.h"

/**
 * 
 */

 //To be binded to UI; used to update score
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FScoreSignature, int32, pScore); //p indicates that it is a parameter

UCLASS()
class SURVIVALGAME_API USurvivalGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	//Constructor--sets default values
	USurvivalGameInstance();

public:
	UPROPERTY(BlueprintAssignable, Category = "UpdateUI")
		FScoreSignature scoreDelegate;

private:
	/*Write code here*/


	//Declare a variable of type int32 (equivalent to int) to store the score

//Using score
public:
	//Called by Zombie actors when they die
	void addToScore(int32 addition);

	UFUNCTION(BlueprintPure)
		int32 getScore() const;
};
