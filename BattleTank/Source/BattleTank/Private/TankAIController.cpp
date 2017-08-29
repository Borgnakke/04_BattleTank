// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (auto ControlledTank = GetAIControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("AI at %s"), *ControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AI not found"));
	}

	if (auto EnemyTank = GetPlayerTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank at %s"), *EnemyTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player Tank not found not found"));
	}
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (auto PlayerTank = GetPlayerTank())
	{
		// TODO ---> Move towards the player
		
		// Aim towards the player
		GetAIControlledTank()->AimAt(PlayerTank->GetActorLocation());
	}
}

//------------------------------------------------------------------------------------------//

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	APawn* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	return Cast<ATank>(PlayerTank);
}