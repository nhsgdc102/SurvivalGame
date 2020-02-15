// Copyright 2020 Northview High School Game Development Club


#include "MainPlayer.h"

FName AMainPlayer::weaponName("Weapon");

// Sets default values
AMainPlayer::AMainPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setting up weapon component
	weaponComp = CreateDefaultSubobject<UChildActorComponent>(AMainPlayer::weaponName);
	weaponComp->SetChildActorClass(AWeapon::StaticClass());

	defaultTurnRate = 10.f;
	defaultSpeed = 10.f;
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

	/*Write Code Here!*/

	//Bind FireWeapon() to "Shoot" using the example above, but use BindAction instead of BindAxis
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

void AMainPlayer::FireWeapon()
{
	AWeapon* weapon = Cast<AWeapon>(weaponComp->GetChildActor());
	if (IsValid(weapon))
	{
		/*Write Code Here*/

		//Use the weapon object to call FireBullet()
		//To call a function using a pointer, use the arrow ->
	}
}

//Overrides dieCharacter() in BasicCharacter
void AMainPlayer::dieCharacter()
{
	//Finish function later
	//Will need to end the game and do a variety of things

}