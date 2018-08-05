// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel; // Forward Declaration
class UTankTurret;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	ATank();

	// Sets default values for this pawn's properties
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 4000.0;

	UFUNCTION(BlueprintCallable, Category=Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAimingComponent* TankAimingComponent = nullptr;

public:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;	
};
