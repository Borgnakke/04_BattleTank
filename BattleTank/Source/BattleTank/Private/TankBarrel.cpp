// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"




void UTankBarrel::Elevate(float DegreesPerSecond, FRotator DeltaRotator)
{
	// converter a dire��o em uma rota��o
	// aplicar a rota��o no socket do barrel ----> pitch
	// rotacionar a torre ----> Yaw

	UE_LOG(LogTemp, Warning, TEXT("Barrel Speed: %f"), DegreesPerSecond);
}