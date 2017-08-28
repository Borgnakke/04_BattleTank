// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (auto ControlledTank = GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("Controller at %s"), *ControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Controller not found"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

//------------------------------------------------------------------------------------------//

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{	
	if (!GetControlledTank()) { return;	}

	FVector HitLocation; // out parameter
	if (GetSightRayHitLocation(HitLocation)) // will ray-trace
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());

		// linetrace throught the crosshair
		// if hit something
			//TODO tell the control tank to aim at this point
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// find the crosshair position
	int32 ViewportSizeX, ViewportSizeY; // size of the currentviewport
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation(ViewportSizeX*CossHairXLocation, ViewportSizeY*CossHairYLocation);

	// "de-project" the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString());
	}
	
	// line trace along that Look Direction and see what we hit (up to maximum range)
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraHitLocation; // not used ---- but the function need it
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraHitLocation, LookDirection))
		{ return true; }

	return false;
}