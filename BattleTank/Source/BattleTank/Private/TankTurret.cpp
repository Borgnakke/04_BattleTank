// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"



void UTankTurret::RotateTurret(float RelativeSpeed)
{
	// converter a direção em uma rotação
	// aplicar a rotação no socket do barrel ----> pitch
	// rotacionar a torre ----> Yaw

	auto ClampRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);

	float RotationChange = ClampRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float NewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0.0f, NewRotation, 0.0f));
}
