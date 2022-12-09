// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayController.h"
#include "Interactable.h"
#include "GameplayGameMode.h"
#include "MainCharacter.h"
#include "CraftSystem.h"

void AGameplayController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Use", IE_Pressed, this, &AGameplayController::Interact);
}

void AGameplayController::Interact()
{
	if (CurrentInteractable)
	{
		CurrentInteractable->Interact(this);
	}

}

void AGameplayController::AddItemToInventoryByID(FName ID)
{
	
	AGameplayGameMode* GameMode = Cast<AGameplayGameMode>(GetWorld()->GetAuthGameMode());

	UDataTable* ItemTable = GameMode->GetItemDB();

	FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "");

	if (ItemToAdd)
	{
		Inventory.Add(*ItemToAdd);
	}

}

void  AGameplayController::CraftItem(FInventoryItem ItemA, FInventoryItem ItemB, AGameplayController* Controller)
{
	//Check for crafting comb
	for (auto Craft : ItemB.CraftCombinations)
	{

		if (Craft.ComponentID == ItemA.ItemID)
		{

			if (Craft.bDestroyItemA)
			{
				Inventory.RemoveSingle(ItemA);
			}

			if (Craft.bDestroyItemB)
			{
				Inventory.RemoveSingle(ItemB);
			}
			AddItemToInventoryByID(Craft.ProductID);
			ReloadInventory();
		}

	}

}

