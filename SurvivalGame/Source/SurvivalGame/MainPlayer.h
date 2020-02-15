// Copyright 2020 Northview High School Game Development Club

#pragma once

#include "CoreMinimal.h"
#include "BasicCharacter.h"
#include "Components/InputComponent.h" //For binding inputs
#include "Engine/World.h" //For get world delta seconds
//Imports Weapon class
#include "Weapon.h"
//Imports ChildActorComponent
#include "Components/ChildActorComponent.h"

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

	//Fires off weapon
	void FireWeapon();

//Declaring Components
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		//Used to fire bullets
		UChildActorComponent* weaponComp; //Comp stands for component
	static FName weaponName;
	
private:
	// Called when health dips to 0
	virtual void dieCharacter() override;

private:
	//Controls speed of turning -- can adjust using scale in Input Settings
	float defaultTurnRate;
	//Controls speed of movement
	float defaultSpeed;
};
