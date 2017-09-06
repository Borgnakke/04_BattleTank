// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initiaze(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveFoward(float Throw)
{
	float AdjustedThrow = FMath::Clamp<float>(Throw, -1.0f, 1.0f);

	LeftTrack->SetThrottle(AdjustedThrow);
	RightTrack->SetThrottle(AdjustedThrow);


	UE_LOG(LogTemp, Warning, TEXT("Intend move foward throw: %f"), Throw);
}
