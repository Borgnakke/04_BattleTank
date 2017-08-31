// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"
#include "Components/SceneComponent.h"




void UTankBarrel::Elevate(float RelativeSpeed)
{
	// converter a direção em uma rotação
	// aplicar a rotação no socket do barrel ----> pitch
	// rotacionar a torre ----> Yaw

	auto ClampRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);

	float ElevationChange = ClampRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	
	SetRelativeRotation(FRotator(FMath::Clamp<float>(RawNewElevation, 0.0f, 45.0f), 0.0f, 0.0f));
}