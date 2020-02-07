// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCharacter.h"
#include "Components/InputComponent.h" //For binding inputs
#include "Engine/World.h" //For get world delta seconds

#include "MainPlayer.generated.h"

/**
 * 
 */
UCLASS()
class SURVIVALGAME_API AMainPlayer : public ABasicCharacter
{
	GENERATED_BODY()
	
public:
	// Constructor -- Sets default values for this character's properties
	AMainPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Functions binded to inputs
	//Controls yaw of camera
	void LookYaw(float yaw);
	//Controls pitch of camera
	void LookPitch(float pitch);

	//Moves character to right
	void MoveRight(float input);
	//Moves character forward
	void MoveForward(float input);

private:
	//Controls speed of turning -- can adjust using scale in Input Settings
	float defaultTurnRate;
	//Controls speed of movement
	float defaultSpeed;
};