// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartingLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto Position = GetActorLocation() + MoveVelocity * DeltaTime;

	auto CurrentDistance = FVector::Dist(Position, StartingLocation);

	if (CurrentDistance > MoveDistance)
	{
		Position = StartingLocation + MoveVelocity.GetSafeNormal() * MoveDistance;
		StartingLocation = Position;
		MoveVelocity = -MoveVelocity;
	}
	
	SetActorLocation(Position);
}

