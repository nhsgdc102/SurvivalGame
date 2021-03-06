// Copyright 2020 Northview High School Game Development Club


#include "Weapon.h"

FName AWeapon::meshName(TEXT("WeaponMesh"));

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setting up weaponMesh
	weaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(AWeapon::meshName);
	RootComponent = weaponMesh;
	//Other details
	weaponMesh->Mobility = EComponentMobility::Movable; //Mesh will have to be able to move, so lighting should be generated dynamically (regenerates every time bullet moves)
	weaponMesh->SetGenerateOverlapEvents(false); //weapon mesh should not overlap anything
	weaponMesh->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No; //No need for stepping on the weapon mesh
	weaponMesh->SetCollisionProfileName("NoCollision"); //Weapon mesh should not collide with anything
	weaponMesh->SetCastShadow(true); //Weapon should have a shadow

	/*Write code here*/
    ammo = 5;

	//Set initial value of ammo
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/*Write Code Here Eric!
Update the method signature below based on what you wrote in Weapon.h
The method signatures will need to match so that the compiler can match the function declaration with the definition.
*/

// Returns true if spawn is successful, false if it was not
bool AWeapon::FireBullet()
{
	if (ammo > 0) //Will only proceed if ammo is greater than 0
	{
		/*Write Code Here Eric!
		Declare a structure of type FActorSpawnParameters. Initialize it using the default constructor.
		**https://docs.unrealengine.com/en-US/API/Runtime/Engine/Engine/FActorSpawnParameters/index.html
		Set the value of Owner inside the spawn parameters structure to the AActor* parameter you passed in.
		Also set the value of SpawnCollisionHandlingOverride to ESpawnActorCollisionHandlingMethod::AlwaysSpawn
		**You can access public variables inside the structure by using the "." operator.
		**ESpawnActorCollisionHandlingMethod is an enum documented here: https://docs.unrealengine.com/en-US/API/Runtime/Engine/Engine/ESpawnActorCollisionHandlingMeth-/index.html
		**An enum is a type of variable that can hold a set number of values. AlwaysSpawn is in this case one of the values of ESpawnActorCollisionHandlingMethod
		*/


		FTransform spawnTransform = weaponMesh->GetSocketTransform(TEXT("BulletSpawnSocket")); //spawnTransform contains the location, rotation, and scale with which the bullet should spawn

		/*Write Code Here Eric!
		Rewrite the SpawnActor call below to pass in the spawn parameters variable you created as an actual parameter
		Use this overloaded SpawnActor method: T* SpawnActor (UClass* Class, FTransform const& Transform, const FActorSpawnParameters& SpawnParameters)
		**T* means that this is a templated method. That means that you can pass in a type using < >. In this case the type of the return object is T*, meaning that it will be a pointer of the type you pass in.
		**BulletClass is the variable to use for UClass* Class. I'll explain why we use it later if you ask in person
		**For the FTransform const& Transform use spawnTransform
		*/
		ABullet* bullet = GetWorld()->SpawnActor<ABullet>(BulletClass, spawnTransform.GetLocation(), FRotator(spawnTransform.GetRotation()));
		if (IsValid(bullet)) //Proceeds if spawn is successful
		{
			/*Write code here*/
            ammo = ammo - 1;


			//Decrement ammo or Set it equal to ammo - 1
			return true;
		}
	}
	return false;
}
