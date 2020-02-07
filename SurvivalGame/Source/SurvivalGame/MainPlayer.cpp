// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayer.h"

// Sets default values
AMainPlayer::AMainPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	defaultTurnRate = 10.f;
	defaultSpeed = 10.f;

	/*Write Code Here!*/
	//Set initial values


}

// Called when the game starts or when spawned
void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Yaw", this, &AMainPlayer::LookYaw);
	PlayerInputComponent->BindAxis("Pitch", this, &AMainPlayer::LookPitch);

	/*Write Code Here!*/

	//Setup inputs for the movement following the example above
	//Bind MoveForward and MoveRight to axis inputs "Forward" and "Right", respectively
}

void AMainPlayer::LookYaw(float yaw)
{	
	AddControllerYawInput(yaw*defaultTurnRate*GetWorld()->GetDeltaSeconds());
}

void AMainPlayer::LookPitch(float pitch)
{
	AddControllerYawInput(pitch*defaultTurnRate*GetWorld()->GetDeltaSeconds());
}

void AMainPlayer::MoveForward(float input)
{
	/*Write Code Here!*/

	//Use AddMovementInput(GetActorForwardVector(), /*Insert expression here*/)
	//For the expression follow the examples above in LookYaw and LookPitch
}

void AMainPlayer::MoveRight(float input)
{
	/*Write Code Here!*/

	//Use AddMovementInput(GetActorRightVector(), /*Insert expression here*/)
	//For the expression follow the examples above in LookYaw and LookPitch
}