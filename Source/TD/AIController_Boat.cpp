// Fill out your copyright notice in the Description page of Project Settings.


#include "AIController_Boat.h"

void AAIController_Boat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (bShouldMove) {

		if (APawn* controlledPawn = GetPawn()) {
			FVector myLocation = controlledPawn->GetActorLocation();

			
			// rotation stuff
			FVector rotationToTargetAsVector = (targetLocation - myLocation).GetSafeNormal();
			FRotator desiredRotation = controlledPawn->GetActorRotation();
			//if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("%f"), controlledPawn->GetActorRotation().Yaw-rotationToTargetAsVector.Rotation().Yaw));
			desiredRotation.Yaw = rotationToTargetAsVector.Rotation().Yaw;
			//if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("")));
			
			// if within 30 degrees will just lock onto it
			bool bShouldLockRotation = FMath::Abs(
				FMath::FindDeltaAngleDegrees(desiredRotation.Yaw,
					controlledPawn->GetActorRotation().Yaw))
				<= 30.0f;
			
			FRotator newRotation;
			if (bShouldLockRotation) {
				newRotation = desiredRotation;
			}
			else {
				newRotation = FMath::RInterpTo(
					controlledPawn->GetActorRotation(),
					desiredRotation,
					DeltaTime,
					rotationInterpSpeed
				);
			}

			// moving stuff
			FVector newLocation = FMath::Lerp(
				myLocation,
				targetLocation,
				DeltaTime * movementInterpSpeed
				);

			// logic to lock into desired if we are close enough
			controlledPawn->SetActorLocationAndRotation(newLocation, newRotation);
		}
		


	}
}





