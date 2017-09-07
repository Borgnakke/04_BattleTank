// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initiaze(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveFoward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }

	//float AdjustedThrow = FMath::Clamp<float>(Throw, -1.0f, 1.0f);

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }

	//float AdjustedThrow = FMath::Clamp<float>(Throw, -1.0f, 1.0f);

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}
