// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "plataforma.generated.h"

UCLASS()
class PRUEBADONKEYKONG_L01_API Aplataforma : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aplataforma();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	 class UStaticMeshComponent* MeshPlataforma;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void MovePlatform(float DeltaTime);
	void SetMovementDirection(FVector NewDirection);
	void SetMovementType(int32 NewMovementType);

private:
	FVector StartLocation;
	FVector EndLocation;
	FVector MovementDirection;
	float Speed;
	bool bMovingRight;

	int32 MovementType;

};
