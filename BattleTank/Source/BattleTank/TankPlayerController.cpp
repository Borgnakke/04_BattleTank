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


//------------------------------------------------------------------------------------------//

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}