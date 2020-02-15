// Copyright 2020 Northview High School Game Development Club


#include "Bullet.h"

FName ABullet::hitboxName(TEXT("Hitbox")); //Sets the name inside hitboxName
/*Side note -- this line has to be outside of any of the methods because hitboxName is static*/
FName ABullet::meshName(TEXT("BulletMesh"));

/*Write Code Here!*/


/*Set the value of the name inside the projectile movement's name variable you declared using the examples above*/

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setting up hitbox
	hitbox = CreateDefaultSubobject<UCapsuleComponent>(ABullet::hitboxName); //Constructs the object that hitbox will refer to--this unique instantiation is necessary when objects need to serve as components
	RootComponent = hitbox; //Since the projectile movement component moves the root of the object, it is better to set hitbox as the root to make sure it is moved
	//Other details
	hitbox->Mobility = EComponentMobility::Movable;
	hitbox->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;
	hitbox->SetCollisionProfileName("Bullet"); //This will enable the hitbox to collide with the zombies
	hitbox->OnComponentHit.AddDynamic(this, &ABullet::OnHitboxHit);

	//Setting up bulletMesh
	bulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(ABullet::meshName);
	bulletMesh->SetupAttachment(RootComponent); //makes sure mesh will move along with the root
	//Other details
	bulletMesh->Mobility = EComponentMobility::Movable; //Mesh will have to be able to move, so lighting should be generated dynamically (regenerates every time bullet moves)
	bulletMesh->SetGenerateOverlapEvents(false); //Bullet mesh should not overlap anything
	bulletMesh->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No; //No need for stepping on the bullet mesh
	bulletMesh->SetCollisionProfileName("NoCollision"); //Bullet mesh should not collide with anything
	bulletMesh->SetCastShadow(false); //No need for bullet to have shadow

	/*Write Code Here!*/
	//Setting up projectile movement component -> write your code below
	
	
	/*Use the examples above to set up the projectile movement component.*/
	//->Make sure to use the function CreateDefaultSubobject</*Insert class name here*/>(ABullet::/*Insert name variable here*/)
	//->No need to set up attachments to root or anything else 

	/*Write code here*/


	//Set the initial values of damage and range. Make sure both are positive
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	/*Write code here*/


	//Copy this code and insert in the right names: SetLifeSpan(range / (/*Insert name of projectile movement component*/->InitialSpeed);
	//This code calculaes and sets the total amount of time the bullet should exist for after spawning
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called when hitbox hits something
void ABullet::OnHitboxHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	AZombie* zombie = Cast<AZombie>(OtherActor); //Cast will return the Zombie object if OtherActor is of the Zombie class, or it will return NULL
	if (IsValid(zombie)) //Will only proceed to the code below if zombie is not NULL and OtherActor is of the Zombie class
	{
		zombie->applyDamage(damage);
	}
}