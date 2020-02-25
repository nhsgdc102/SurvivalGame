// Copyright 2020 Northview High School Game Development Club


#include "BasicCharacter.h"

// Sets default values
ABasicCharacter::ABasicCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*Write Code Here!*/
	//Set initial value of health
	health = 100.f;

}

// Called when the game starts or when spawned
void ABasicCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasicCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasicCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABasicCharacter::applyDamage(float damage)
{
	/*Write Code Here!*/
	health = FMath::Clamp<float>(health - damage, 0.f, 100.f);
	//Subtract the amount specified in damage from health and clamp it between 0 and 100 using the function below
	// FMath::Clamp<float>(/*Insert expression here*/,0.f, 100.f)
	//Then set the result of the function above to health

	/*Write Code Here!*/
	//Uncomment the code below and then add what is needed
	//if(/*Insert name of health variable*/ <= 0)
	//	dieCharacter();
}

void ABasicCharacter::restoreHealth(float gain)
{
	/*Write Code Here!*/
	health = FMath::Clamp<float>(health + gain, 0.f, 100.f);
	//Add the amount specified in gain to health and clamp it between 0 and 100 using the function below
	// FMath::Clamp<float>(/*Insert expression here*/,0.f, 100.f)
	//Then set the result of the function above to health
}

void ABasicCharacter::dieCharacter()
{
	//This code is probably not sufficient for MainPlayer or Zombie objects so the function will need to be overrided
	this->Destroy();
}