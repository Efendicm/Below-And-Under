// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS()
class GAMEJAM_API AInteractable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractable();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Interacts with the Item
	UFUNCTION(BlueprintImplementableEvent)
		void Interact(APlayerController* Controller);
		
	UPROPERTY(EditDefaultsOnly)
	FString Name;

	UPROPERTY(EditDefaultsOnly)
	FString Action;


	UFUNCTION(BlueprintCallable, Category = "PickUp")
		FString GetUseText() const { return FString::Printf(TEXT("%s : Press E to %s"), *Name, *Action); }



};
