// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"




void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* AIControlledTank = GetAIControlledTank();
	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Can not find AI possesed Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI possesed Tank: %s"), *AIControlledTank->GetName());
	}
}

ATank * ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
