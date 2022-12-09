// Fill out your copyright notice in the Description page of Project Settings.


#include "items/PickUp_Items.h"
#include "Components/SphereComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "MainCharacter.h"
#include "items/InventoryComponent.h"
#include "items/WoodItem.h"
#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>


// Sets default values
APickUp_Items::APickUp_Items()
{
	//Create The Component in Bluerints For the coin
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;
	//Create a Collision for the coin to collide with the player
	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SphereCollider->SetupAttachment(SceneComponent);
	SphereCollider->SetCollisionProfileName(TEXT("OverlapPawn"));
	//Create the base mesh of the coin to give it the assets 
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	ItemMesh->SetupAttachment(SphereCollider);
	ItemMesh->SetCollisionProfileName(TEXT("OverlapPawn"));
	//Lets the coin roate to give it motion
	RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));
	RotatingMovement->RotationRate = FRotator(0, 180, 0);


}

// Called when the game starts or when spawned
void APickUp_Items::BeginPlay()
{
	Super::BeginPlay();
	//Overlap called when the game starts to scan for it
	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &APickUp_Items::OnSphereOverlap);

}

void APickUp_Items::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Call to the runcharacter to detect if they overlap to add and destroy the Item
	AMainCharacter* MainCharacter = Cast<AMainCharacter>(OtherActor);

	if (MainCharacter)
	{
		if (OverlapSound)
		{
			//Calling the sound for the Item to give a sound at the location of overlap
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), OverlapSound, GetActorLocation());
		}
		UWoodItem* WoodPick = Cast<UWoodItem>(OtherActor);
		if (IsWood)
		{
			WoodPick->Interact(MainCharacter);
		}
		//Destroys the Item
		Destroy();
	}
}

