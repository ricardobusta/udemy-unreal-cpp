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

void AMovingPlatform::MovePlatform(const float DeltaTime)
{
	auto Position = GetActorLocation() + MoveVelocity * DeltaTime;

	if (const auto CurrentDistance = FVector::Dist(Position, StartingLocation); CurrentDistance > MoveDistance)
	{
		Position = StartingLocation + MoveVelocity.GetSafeNormal() * MoveDistance;
		StartingLocation = Position;
		MoveVelocity = -MoveVelocity;

		const auto String = GetName();
		UE_LOG(LogTemp, Display, TEXT("Flip %s"), *String);
	}
	
	SetActorLocation(Position);
}

// Called every frame
void AMovingPlatform::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
}

