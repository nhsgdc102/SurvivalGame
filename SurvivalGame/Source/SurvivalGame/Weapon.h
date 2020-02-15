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
	//Spawns a bullet--returns true or false indicating if spawn was successful
	bool FireBullet();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 ammo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<ABullet> BulletClass;

};
