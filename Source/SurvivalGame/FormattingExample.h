// Copyright 2020 Northview High School Game Development Club

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FormattingExample.generated.h"

/** 
 * The space below is for forward declarations (same as incomplete declarations).
 * Make a forward declaration to a class whenever you need to use it to declare
 * a pointer in the header file. Alternatively, you could include the header file
 * for that class in the include section above, but that causes coupling and increases
 * compile time. Though forward declaring is good enough for declaring pointers in the header file,
 * if you need to make further use of that class in the source file (.cpp), you must make an include
 * statement within the source file (.cpp). As opposed to including something in the header file,
 * including a class's header file via a source file does not cause coupling.
 * See the following link for a deeper understanding:
 *	http://umich.edu/~eecs381/handouts/IncompleteDeclarations.pdf 
 */
class AController;
class UPrimitiveComponent;

/** 
 * Below is the section for declaring multicast delegates. The purpose of multicast delegates is as follows:
 *	You can bind a function to a multicast delegate in C++ or in Blueprints.
 *	Then, when you call that delegate, the delegate will in turn call each function binded to it.
 *	Therefore, simply by calling one delegate, you can indirectly call numerous functions.
 *	Of all the types of delegates, multicast delegates are especially useful because they allow
 *	binding in Blueprints, which is often an important tool.
 * To see how to declare multicast delegates, see:
 *	https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Delegates/Multicast/index.html 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSomethingHappened);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAnotherThingHappened, AController*, Controller, AActor*, Self, UPrimitiveComponent*, Component);
/** Technically, the lines above only create the signatures for delegates. As shown in the class body below, you must declare the actual multicast delegates separately. */

UCLASS()
class SURVIVALGAME_API AFormattingExample : public AActor
{
	GENERATED_BODY()

/** 
 * The space below is just for declaring the constructor
 * Declaring a constructor has bit of weird syntax as opposed to a traditional function:
 *	1. It must be declared public. This is why the constructor below has the public: statment before it.
 *	2. Its name must be identical to that of the class its in. Or else it will not compile.
 *	3. It should have no return type. Constructors cannot return anything anyway.
 *	4. In UE4, constructors cannot have parameters. Always keep the paranthesis empty.
 * For a deeper understanding of what constructors are used for in UE4, 
 * see the "Constructor Format" section in:
 * https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Reference/Classes/index.html
 */
public:	
	// Sets default values for this actor's properties
	AFormattingExample();

/** The protected section below is usually for overriding functions */
protected:
	/** Use the area below to override functions from the parent class (AActor)*/
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called when the game ends or the object is destroyed
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

/**
* The space below is for declaring all functions you wish to be public. 
* This includes functions you wish to access from blueprints
*/
public:	
	/** 
	* As shown below, override the Tick function in the public section.
	* If it is not public, it cannot be called every frame.
	*/
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/**
	* To declare functions you need to access from Blueprints,
	* put a UFUNCTION() macro above its declaration. This willallow the
	* UE4 reflection system to recognize the function and give it special
	* properties within Blueprints. If you just need to call it in Blueprints,
	* simply type BluerprintCallable within the macro.
	* See the following for a deeper understandng:
	* https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Reference/Functions/index.html
	*/
	UFUNCTION(BlueprintCallable)
		// Changes the ActorController pointer to point to whatever is passed in
		void SetActorController(AController* Controller);
	/** As shown above, alway write the purpose of the function above its declaration */

/**
* Declare all private functions below. Usually these are helper functions that you use within other functions
*/
private:
	


/**
* Declare all components below. You may want to make them protected instead;
*/
private:
	UPROPERTY(Category = "FormattingExample", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UPrimitiveComponent* primitive;

/**
* Declare all delegates below. They should be public so that they can be accessed from other classes.
*/
public:
	FSomethingHappened SomethingHappened_Delegate;
	FAnotherThingHappened AnotherThingHappened_Delegate;

/**
* Declare all public, protected, and private variables below
*/
public:

protected:

private:
	AController* ActorController;


};
