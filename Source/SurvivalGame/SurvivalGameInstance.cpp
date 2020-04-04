// Copyright 2020 Northview High School Game Development Club


#include "SurvivalGameInstance.h"

USurvivalGameInstance::USurvivalGameInstance()
{
	/*Write code here*/
    score = 0;
	//Set score to a default of 0
}

void USurvivalGameInstance::addToScore(int32 addition)
{
	/*Write code here*/

	//Set score equal to score + addition
    score = score + addition;
	/*Write Code here*/
	/*Uncomment the code below and insert the necessary variable name*/
    if (scoreDelegate.IsBound()) {
        scoreDelegate.Broadcast(score);
    } //Updates the score displayed in the UI
}

int32 USurvivalGameInstance::getScore() const
{
	/*Write code here*/
	//Delete the code below and return the score instead
    return score;
}
