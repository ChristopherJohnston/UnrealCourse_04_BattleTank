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

	UPROPERTY(BlueprintReadOnly, Category = Input)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	bool FiringEnabled = true;

	// Sets default values for this pawn's properties
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000.0;

	// Use TSubclassOf<> to limit what can be selected in editor. See: https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/TSubclassOf/
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;	

	float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;
};
