// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIController_Boat.generated.h"

/**
 * 
 */
UCLASS()
class TD_API AAIController_Boat : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void Tick(float DeltaTime) override;

//public:
//	UFUNCTION(BlueprintImplementableEvent)
//	void onReachedTargetLocation();






private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = true) )
	bool bShouldMove = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = true))
	FVector targetLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = true))
	float targetAcceptanceRadius = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = true))
	float rotationInterpSpeed = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = true))
	float movementInterpSpeed = .05f;

};
