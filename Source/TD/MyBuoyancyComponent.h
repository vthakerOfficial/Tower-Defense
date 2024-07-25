// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BuoyancyComponent.h"
#include "MyBuoyancyComponent.generated.h"

/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class TD_API UMyBuoyancyComponent : public UBuoyancyComponent
{
	GENERATED_BODY()
	
	virtual void ApplyForces(float DeltaTime, FVector LinearVelocity, float ForwardSpeed, float ForwardSpeedKmh, UPrimitiveComponent* PrimitiveComponent) override;

};
