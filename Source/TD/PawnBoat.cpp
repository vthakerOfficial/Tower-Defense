// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBoat.h"

// Sets default values
APawnBoat::APawnBoat()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APawnBoat::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APawnBoat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawnBoat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//void APawnBoat::SetActorRotation(const FRotator& NewRotation)
//{
//	FRotator newNewRotation = NewRotation;
//	newNewRotation.Yaw -= 90;
//	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("Yaw has been modified!")));
//	Super::SetActorRotation(NewRotation);
//}



