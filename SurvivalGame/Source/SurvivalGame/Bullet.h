// Copyright 2020 Northview High School Game Development Club

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//Imports class for capsule collision -- https://docs.unrealengine.com/en-US/API/Runtime/Engine/Components/UCapsuleComponent/index.html
#include "Components/CapsuleComponent.h"
//Imports class for static mesh -- https://docs.unrealengine.com/en-US/Engine/Content/Types/StaticMeshes/index.html
#include "Components/StaticMeshComponent.h" 
//Imports class for projectile movement component -- https://docs.unrealengine.com/en-US/API/Runtime/Engine/GameFramework/UProjectileMovementComponent/index.html
#include "GameFramework/ProjectileMovementComponent.h"
/*Write Code Here Eric!
Write an include statement for the MainPlayer.h file.
**This will let you call the OnHitSuccess method from the bullet class
*/

//Imports class for zombie so that bullet can inflict damage
#include "Zombie.h"

#include "Bullet.generated.h"

UCLASS()
class SURVIVALGAME_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

//Declaring components
/*Components are objects that you can add on to your main object.
They have some code already that can help your object achieve certain tasks.
For example, the projectile movement component will be able to move the bullet 
as if it is a projectile (it accounts for gravity, collision, etc.).
Research each component by clicking the links above to see what they do.
*/
public: //Always declare components as public so that you can access them from blueprints
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true")) //Typical macro to use for components
		//Serves as the hitbox for the bullet
		UCapsuleComponent* hitbox;
	static FName hitboxName; //This contains the name that will be displayed for the component in blueprints
	/*Side note -- this variable is declared static because its value should be the same for every object of the Bullet class*/

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* bulletMesh;
	static FName meshName;

	/*Write Code Here!*/
	//Declare everything needed for the projectile movement component below

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
        UProjectileMovementComponent* projComp;
    static FName projCompName;

	/*Use the examples above to declare a pointer for the projectile movement component.
	Here are some tips:
	->Pointers are declared like regular variables, but after the class name put an asterisk
	->The class you will need to use is UProjectileMovementComponent
	->Copy over the UPROPERTY(...) macro from above
	->Name the pointer and name variable whatever you want, but make sure it is convenient to use
	->Remember to create the name variable and declare it static too!
	*/

public:
	UFUNCTION()
		// Called when hitbox hits something
		void OnHitboxHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
		/*Info:
		->HitComponent means the component that was hit, which in this case will always be hitbox
		->OtherActor means the actor that hitbox hit. We need to see if this is the zombie or not and then apply damage
		->OtherComp means the component of the actor that the hitbox hit. This will come in use later
		->NormalImpulse is not needed
		->Hit is not needed
		*/

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		//The amount of damage the bullet can inflict on zombies
		float damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		//The distance the bullet can travel before it disappears
		float range;


};
