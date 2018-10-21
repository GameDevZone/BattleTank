// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "CrossHair")
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly, Category = "CrossHair")
	float CrossHairYLocation = 0.3333f;
	
	UPROPERTY(EditDefaultsOnly, Category = "CrossHair")
	float LineTraceRange = 1000000;
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// Get Player Controller Controlled Tank
	ATank * GetControlledTank() const;	

	// start the tank move the barrel so that a shot would it 
	// where the cross hair intersects the world
	void AimTowardsCrossHair();

private:
	// Return an Out Parameter, true if hit landscape
	bool GetSighRayHitLocation(FVector& HitLocation) const;

	// Return an look direction, 
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector& HitLocation, FVector LookDirection) const;
};
