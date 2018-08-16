// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel; // Forward Declaration
class UTankTurret;
class AProjectile;
class UTankMovementComponent;
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category="Firing")
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly, Category="Setup")
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	ATank();

	UPROPERTY(EditDefaultsOnly, Category="Firing")
	bool FiringEnabled = true;

	// Sets default values for this pawn's properties
	UPROPERTY(EditDefaultsOnly, Category="Firing")
	float LaunchSpeed = 4000.0;

	// Use TSubclassOf<> to limit what can be selected in editor. See: https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/TSubclassOf/
	UPROPERTY(EditDefaultsOnly, Category="Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;

	// TODO: Remove
	UTankBarrel* Barrel = nullptr;
};
