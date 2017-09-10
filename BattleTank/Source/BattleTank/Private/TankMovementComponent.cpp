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

	//UE_LOG(LogTemp, Warning, TEXT("Turning: %f"), Throw);

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	// No need to call Super --- Replacing the functionality
	FString TankName = GetOwner()->GetName();
	FString MoveVelocitySring = MoveVelocity.ToString();

	UE_LOG(LogTemp, Warning, TEXT("%s vectoring to: %s"), *TankName, *MoveVelocitySring);
}
