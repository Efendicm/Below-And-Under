// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUp_Items.generated.h"

UCLASS()
class GAMEJAM_API APickUp_Items : public AActor
{
	GENERATED_BODY()
	
public:
	//Create a SceneComponent in Blueprint
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		USceneComponent* SceneComponent;
	//Create a static mesh component in blueprint
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* ItemMesh;
	//Shows the sphere in blueprint and being able to call it
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class USphereComponent* SphereCollider;
	//Create the rotation Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class URotatingMovementComponent* RotatingMovement;
	//Create the sound for the object
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Assests")
		class USoundBase* OverlapSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemType")
		bool IsWood = false;



	// Sets default values for this actor's properties
	APickUp_Items();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//Called when overlap begins with this actor
	UFUNCTION()
		void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
