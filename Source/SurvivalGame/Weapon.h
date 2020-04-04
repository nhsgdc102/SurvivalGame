// Copyright 2020 Northview High School Game Development Club

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//Imports class for static mesh -- https://docs.unrealengine.com/en-US/Engine/Content/Types/StaticMeshes/index.html
#include "Components/StaticMeshComponent.h" 
//Imports Bullet class
#include "Bullet.h"
//Imports World class so that weapon can spawn bullet
#include "Engine/World.h"

#include "Weapon.generated.h"

UCLASS()
class SURVIVALGAME_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

//Declaring components
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* weaponMesh;
	static FName meshName;

//Firing bullet
public:
	/*Write Code Here Eric!
	Rewrite the method signature below to accept a pointer to an object of type AActor.
	**Hint--Add a formal parameter. Make sure to name it "owner" for convenience.
	http://www.infobrother.com/Tutorial/C++/C++_Pointer_Object
	*/

	//Spawns a bullet--returns true or false indicating if spawn was successful
	bool FireBullet();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 ammo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<ABullet> BulletClass;

};
