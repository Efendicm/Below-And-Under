// Fill out your copyright notice in the Description page of Project Settings.


#include "items/FoodItem.h"
#include "MainCharacter.h"

void UFoodItem::Use(class AMainCharacter* Character)
{
	if (Character)
	{
		Character->Health += HealthToHeal;
	}
}
