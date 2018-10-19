// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();

	if (ControlledTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *GetControlledTank()->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));

	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Aim Towards CrossHair
	AimTowardsCrossHair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank())
		return;

	FVector HitLocation;	// OUT Parameter

	if (GetSighRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());

			// tell controlled tank to aim at this point
	}
	
}
// get world location if line trace through cross hair, true if it hits the landscape 
bool ATankPlayerController::GetSighRayHitLocation(FVector& HitLocation) const
{
	// Find cross hair position
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	UE_LOG(LogTemp, Warning, TEXT("ViewPortSizeX: %d"), ViewPortSizeX);
	UE_LOG(LogTemp, Warning, TEXT("ViewPortSizeY: %d"), ViewPortSizeY);
	
	FVector2D ScreenLocation = FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);

	// De-project the screen position to world position
	// line trace along the look direction, and see what we hit
	return true;
}

