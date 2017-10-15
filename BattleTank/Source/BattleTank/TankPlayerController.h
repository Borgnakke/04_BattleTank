// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // must be the last include

/**
 * 
 */


UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	class ATank* GetControlledTank() const;

private:

	/**
	Start the tank moving the barrel so that the shot would hit where the crosshair
	intersect the world
	*/
	void AimTowardsCrosshair();

	/**Return an out parameter, true if hit landscape */
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	// Crosshair location
	UPROPERTY(EditDefaultsOnly)
	float CossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CossHairYLocation = 0.33333f;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0f;
};
