// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Muro.h"
#include "MuroLadrlillo.generated.h"

/**
 * 
 */
UCLASS()
class PRUEBADONKEYKONG_L01_API AMuroLadrlillo : public AMuro
{
	GENERATED_BODY()
public:
	AMuroLadrlillo();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
