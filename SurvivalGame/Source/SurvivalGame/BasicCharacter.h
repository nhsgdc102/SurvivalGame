// Copyright 2020 Northview High School Game Development Club

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BasicCharacter.generated.h"

UCLASS()
class SURVIVALGAME_API ABasicCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Constructor -- Sets default values for this character's properties
	ABasicCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//For decreasing the character's health
	void applyDamage(float damage);

	//For increasing the character's health
	void restoreHealth(float gain);

	//For making the character die
	virtual void dieCharacter(); /*Honestly couldn't think of a professional name*/

public:
	/*Write Code Here!*/
	//Declare health variable here (float type)



};
