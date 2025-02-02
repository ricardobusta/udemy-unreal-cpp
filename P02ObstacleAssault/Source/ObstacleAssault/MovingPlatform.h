// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector MoveVelocity = FVector(0, 0, 0);
	UPROPERTY(EditAnywhere, Category="Moving Platform")
	float MoveDistance = 100;
	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FRotator RotateVelocity = FRotator();

private:
	FVector StartingLocation;

public:
	AMovingPlatform();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
};
