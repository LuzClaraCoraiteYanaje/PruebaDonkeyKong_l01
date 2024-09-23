// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroElectrica.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Muro.h"

AMuroElectrica::AMuroElectrica()
{
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	MeshMuro = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshMuro->SetStaticMesh(MeshAsset.Object);
	MeshMuro->SetRelativeScale3D(FVector(3.0f, 0.5f, 2.0f));
	RootComponent = MeshMuro;
}

void AMuroElectrica::BeginPlay()
{
	Super::BeginPlay();
}

void AMuroElectrica::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
