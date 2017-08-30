// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Elevate(float DegreesPerSecond, FRotator DeltaRotator);
	
private:
	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxDegreesPerSecond = 20.0f;
	
	UPROPERTY(EditAnywhere, Category = "Setup")
	float MinElevation = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxElevation = 45.0f;

};
