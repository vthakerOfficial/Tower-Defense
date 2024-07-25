// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBuoyancyComponent.h"

void UMyBuoyancyComponent::ApplyForces(float DeltaTime, FVector LinearVelocity, float ForwardSpeed, float ForwardSpeedKmh, UPrimitiveComponent* PrimitiveComponent)
{
	if (IsUsingAsyncPath())
	{
		return;
	}
	
	const int32 NumPontoonsInWater = UpdatePontoons(DeltaTime, ForwardSpeed, ForwardSpeedKmh, SimulatingComponent);
	bIsInWaterBody = NumPontoonsInWater > 0;

	if (SimulatingComponent->IsSimulatingPhysics())
	{
		const ECollisionEnabled::Type Collision = SimulatingComponent->GetCollisionEnabled();
		if (Collision == ECollisionEnabled::QueryAndPhysics || Collision == ECollisionEnabled::PhysicsOnly)
		{
			//ApplyBuoyancy(SimulatingComponent);

			FVector TotalForce = FVector::ZeroVector;
			FVector TotalTorque = FVector::ZeroVector;

			TotalForce += ComputeWaterForce(DeltaTime, LinearVelocity);

			if (BuoyancyData.bApplyDragForcesInWater)
			{
				TotalForce += ComputeLinearDragForce(LinearVelocity);
				TotalTorque += ComputeAngularDragTorque(SimulatingComponent->GetPhysicsAngularVelocityInDegrees());
			}

			SimulatingComponent->AddForce(TotalForce, NAME_None, /*bAccelChange=*/true);
			SimulatingComponent->AddTorqueInDegrees(TotalTorque, NAME_None, /*bAccelChange=*/true);
		}
	}
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("Helloooo")));
}
