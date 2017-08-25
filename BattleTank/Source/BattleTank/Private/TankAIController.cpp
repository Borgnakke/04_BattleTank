// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (auto ControlledTank = GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("AI at %s"), *ControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AI not found"));
	}
}


//------------------------------------------------------------------------------------------//

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

