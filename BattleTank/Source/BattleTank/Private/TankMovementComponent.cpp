// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTracktoSet, UTankTrack* RightTracktoSet)
{
	if (!LeftTracktoSet || !RightTracktoSet) { return; }
	LeftTrack = LeftTracktoSet;
	RightTrack = RightTracktoSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), Throw);

	LeftTrack->SetThrottle(Throw);

	RightTrack->SetThrottle(Throw);
}
