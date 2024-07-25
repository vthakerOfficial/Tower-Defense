// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseBuilding.h"




// Sets default values
ABaseBuilding::ABaseBuilding()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	perception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComp"));
	if (UAISenseConfig_Sight* sightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"))) {
		perception->ConfigureSense(*sightConfig);
		perception->SetDominantSense(*sightConfig->GetSenseImplementation());
		perception->OnTargetPerceptionUpdated.AddDynamic(this, &ABaseBuilding::onActorDetected);
		perception->OnTargetPerceptionForgotten.AddDynamic(this, &ABaseBuilding::onActorForgotten);
	}
}

// Called when the game starts or when spawned
void ABaseBuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseBuilding::onActorDetected(AActor* detectedActor, FAIStimulus stimulus)
{
	if (detectedActor->ActorHasTag("Enemy")) {
		targetPawns.Add(detectedActor);
	}
}

void ABaseBuilding::onActorForgotten(AActor* forgottenActor)
{
	if (forgottenActor->ActorHasTag("Enemy")) {
		targetPawns.RemoveSingle(forgottenActor);
	}
}

// Called every frame
void ABaseBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



}

// Called to bind functionality to input
void ABaseBuilding::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

