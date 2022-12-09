// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp.h"

APickUp::APickUp()
{
	PickUpMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickUpMesh");

	ItemID = FName("Please Enter ID");
}