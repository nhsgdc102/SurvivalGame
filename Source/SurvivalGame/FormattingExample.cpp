// Copyright 2020 Northview High School Game Development Club


#include "FormattingExample.h"
/**
* Put all necessary include statements below. Only include a file if you wish to access something within that class.
*/
#include "GameFramework/PlayerController.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
AFormattingExample::AFormattingExample()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/**
	* Create the default subobjects for each component and set additional default values for them if you wish.
	*/
	primitive = CreateDefaultSubobject<UPrimitiveComponent>(TEXT("Primitive"));
	/**
	* Make one of the components (usually of type UPrimitiveComponent) the root of the actor
	*/
	RootComponent = primitive;

	/**
	* Set the default values of all variables (excluding components because that is already done above)
	*/
	ActorController = nullptr; //This variable is intended to be set using SetActorController
}

// Called when the game starts or when spawned
void AFormattingExample::BeginPlay()
{
	Super::BeginPlay();
	
	//Just an example for how to call a delegate
	SomethingHappened_Delegate.Broadcast();
}

// Called when the game ends or the object is destroyed
void AFormattingExample::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	//Another delegate example
	AnotherThingHappened_Delegate.Broadcast(ActorController, this, primitive);
}

// Called every frame
void AFormattingExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Changes the ActorController pointer to point to whatever is passed in
void AFormattingExample::SetActorController(AController* Controller)
{
	ActorController = Controller;
}


