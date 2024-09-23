// Fill out your copyright notice in the Description page of Project Settings.


#include "plataforma.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
Aplataforma::Aplataforma()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube_Chamfer.1M_Cube_Chamfer'"));

	MeshPlataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshPlataforma->SetStaticMesh(MeshAsset.Object);
	RootComponent = MeshPlataforma;


	 // valores para el movimiento
	Speed = 100.0f;
	bMovingRight = true;

	MovementDirection = FVector(0.0f, 1.0f, 0.0f);

	MovementType = 0;
}

// Called when the game starts or when spawned
void Aplataforma::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	EndLocation = StartLocation + MovementDirection * 1000.0f;
	
}

// Called every frame
void Aplataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (MovementType > 0)  // Move only if MovementType is not zero
	{
		MovePlatform(DeltaTime);
	}
}

void Aplataforma::MovePlatform(float DeltaTime)
{
	/*FVector CurrentLocation = GetActorLocation();
	FVector Direction = (bMovingRight ? EndLocation : StartLocation) - CurrentLocation;
	Direction.Normalize();
	CurrentLocation += Direction * Speed * DeltaTime;
	SetActorLocation(CurrentLocation);

	if (FVector::Dist(CurrentLocation, bMovingRight ? EndLocation : StartLocation) < 10.0f)
	{
		bMovingRight = !bMovingRight;
	}*/


	if (MovementType == 1)  // Horizontal movement
	{
		FVector CurrentLocation = GetActorLocation();
		FVector Direction = (bMovingRight ? EndLocation : StartLocation) - CurrentLocation;
		Direction.Normalize();
		CurrentLocation += Direction * Speed * DeltaTime;
		SetActorLocation(CurrentLocation);

		if (FVector::Dist(CurrentLocation, bMovingRight ? EndLocation : StartLocation) < 10.0f)
		{
			bMovingRight = !bMovingRight;
		}
	}
	else if (MovementType == 2)  // Up and down movement (for platform 6)
	{
		FVector CurrentLocation = GetActorLocation();
		if (bMovingRight)
		{
			CurrentLocation.Z += Speed * DeltaTime;
			if (CurrentLocation.Z > EndLocation.Z)
			{
				bMovingRight = !bMovingRight;
			}
		}
		else
		{
			CurrentLocation.Z -= Speed * DeltaTime;
			if (CurrentLocation.Z < StartLocation.Z)
			{
				bMovingRight = !bMovingRight;
			}
		}
		SetActorLocation(CurrentLocation);
	}
}

void Aplataforma::SetMovementDirection(FVector NewDirection)
{
	MovementDirection = NewDirection;
	EndLocation = StartLocation + MovementDirection * 2000.0f;
}

void Aplataforma::SetMovementType(int32 NewMovementType)
{
	MovementType = NewMovementType;
}

