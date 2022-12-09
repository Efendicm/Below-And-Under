// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "items/Item.h"
#include "WoodItem.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_API UWoodItem : public UItem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
		float HealthToHeal;

public:
	UFUNCTION()
	 void Interact(class AMainCharacter* Character);
};
