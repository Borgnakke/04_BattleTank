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
	
	class ATank* GetControlledTank() const;

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	
	/**
	Start the tank moving the barrel so that the shot would hit where the crosshair
	intersect the world
	*/
	void AimTowardsCrosshair();

	/**Return an out parameter, true if hit landscape */
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	// Crosshair location
	UPROPERTY(EditAnywhere)
	float CossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CossHairYLocation = 0.33333f;
};
