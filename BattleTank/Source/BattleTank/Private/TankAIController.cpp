// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* AIControlledTank = GetAIControlledTank();
	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Can not find AI possesed Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI possesed Tank: %s"), *AIControlledTank->GetName());
	}


	ATank* PlayerControlledTank = GetPlayerTank();
	if (!PlayerControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Can not find Player possesed Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI find Player Tank: %s"), *PlayerControlledTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		// TODO Move towards the player

		// Aim towards the player
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire when ready
	}
}

ATank * ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerTank == nullptr)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerTank);
}
