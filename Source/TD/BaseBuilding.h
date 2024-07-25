	// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include <Perception/AISenseConfig_Sight.h>
#include "Perception/AIPerceptionComponent.h"

#include "BaseBuilding.generated.h"

UCLASS()
class TD_API ABaseBuilding : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseBuilding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void onActorDetected(AActor* detectedActor, FAIStimulus stimulus);
	void onActorForgotten(AActor* forgottenActor);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



private:
	class UAIPerceptionComponent* perception;

	UPROPERTY(EditAnywhere)
	TArray<AActor*> targetPawns;
};
