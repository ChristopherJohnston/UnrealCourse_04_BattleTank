// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"

// ENUM for aiming state
UENUM()
enum class EFiringState : uint8 { Reloading, Aiming, Locked };

// Forward Declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

// Holds barrel's properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category="Firing")
	void Fire();

	UFUNCTION(BlueprintCallable, Category="Setup")
	void Initialise(UTankBarrel* BarrelReference, UTankTurret* TurretReference);

protected:
	UPROPERTY(BlueprintReadOnly, Category="State")
	EFiringState FiringState = EFiringState::Reloading;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	virtual void BeginPlay() override;

	FVector AimDirection;
	
	UPROPERTY(EditDefaultsOnly, Category="Firing")
	bool FiringEnabled = true;

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
	bool IsBarrelMoving();

	// Sets default values for this pawn's properties
	UPROPERTY(EditDefaultsOnly, Category="Firing")
	float LaunchSpeed = 4000.0;

	float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;

	// Use TSubclassOf<> to limit what can be selected in editor. See: https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/TSubclassOf/
	UPROPERTY(EditDefaultsOnly, Category="Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;
};
