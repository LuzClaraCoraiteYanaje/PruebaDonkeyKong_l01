// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroLadrlillo.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Muro.h"



AMuroLadrlillo::AMuroLadrlillo()
{
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));

	MeshMuro = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshMuro->SetStaticMesh(MeshAsset.Object);
	MeshMuro->SetRelativeScale3D(FVector(4.0f, 0.5f, 3.0f));
	RootComponent = MeshMuro;
}

void AMuroLadrlillo::BeginPlay()
{
	Super::BeginPlay();
}

void AMuroLadrlillo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
