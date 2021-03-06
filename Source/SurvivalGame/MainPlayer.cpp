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
    PlayerInputComponent->BindAxis("Forward", this, &AMainPlayer::MoveForward);
    PlayerInputComponent->BindAxis("Right", this, &AMainPlayer::MoveRight);
	//Setup inputs for the movement following the example above
	//Bind MoveForward and MoveRight to axis inputs "Forward" and "Right", respectively

	/*Write Code Here!*/
    PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &AMainPlayer::FireWeapon);
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
    AddMovementInput(GetActorForwardVector(), input*defaultSpeed*GetWorld()->GetDeltaSeconds());
	//Use AddMovementInput(GetActorForwardVector(), /*Insert expression here*/)
	//For the expression follow the examples above in LookYaw and LookPitch
}

void AMainPlayer::MoveRight(float input)
{
	/*Write Code Here!*/
    AddMovementInput(GetActorRightVector(), input*defaultSpeed*GetWorld()->GetDeltaSeconds());
	//Use AddMovementInput(GetActorRightVector(), /*Insert expression here*/)
	//For the expression follow the examples above in LookYaw and LookPitch
}

void AMainPlayer::FireWeapon()
{
	AWeapon* weapon = Cast<AWeapon>(weaponComp->GetChildActor());
	if (IsValid(weapon))
	{
		/*Write Code Here Eric!
		Change the FireBullet method call below to pass in a reference to the current object. 
		**Use the "this" reserved word to get the reference
		**This reference will be the actual parameter for the AActor* formal parameter you wrote in Weapon.h
		*/

		/*Write Code Here*/
        weapon->FireBullet();
		//Use the weapon object to call FireBullet()
		//To call a function using a pointer, use the arrow ->
	}
}

/*Write Code Here Eric!
Write an empty method definition for the OnHitSuccess method you created
**Basically copy over the method signature but include "AMainPlayer::" before the name. This lets the compiler know what class to look in to match the definition to the declaration.
**It will be empty for now, but later we will add additional code to make it functional. This will be the basic setup so that we can implement the Call of Duty hit marker mechanism.
*/


//Overrides dieCharacter() in BasicCharacter
void AMainPlayer::dieCharacter()
{
	//Finish function later
	//Will need to end the game and do a variety of things
    
}
