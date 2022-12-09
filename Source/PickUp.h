// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "PickUp.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_API APickUp : public AInteractable
{
	GENERATED_BODY()

public:

	APickUp();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "PickUp")
		void OnUsed();


protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* PickUpMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ItemID;
	
};
