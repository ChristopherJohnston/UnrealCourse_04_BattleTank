// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/World.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	// How close can the AI tank get to the player tank
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float AcceptanceRadius = 1000;

private:
	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnTankDeath();
};
