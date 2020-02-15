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

// Returns true if spawn is successful, false if it was not
bool AWeapon::FireBullet()
{
	if (ammo > 0) //Will only proceed if ammo is greater than 0
	{
		FTransform spawnTransform = weaponMesh->GetSocketTransform(TEXT("BulletSpawnSocket")); //spawnTransform contains the location, rotation, and scale with which the bullet should spawn
		ABullet* bullet = GetWorld()->SpawnActor<ABullet>(BulletClass, spawnTransform.GetLocation(), FRotator(spawnTransform.GetRotation()));
		if (IsValid(bullet)) //Proceeds if spawn is successful
		{
			/*Write code here*/


			//Decrement ammo or Set it equal to ammo - 1
			return true;
		}
	}
	return false;
}
