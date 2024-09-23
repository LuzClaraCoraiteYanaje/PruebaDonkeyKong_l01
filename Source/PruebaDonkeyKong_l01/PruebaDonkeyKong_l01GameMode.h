// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PruebaDonkeyKong_l01GameMode.generated.h"

class Aplataforma;
class AEnemigoCubo;
class AMuroELectrica;
class AMuroLadrlillo;

UCLASS(minimalapi)
class APruebaDonkeyKong_l01GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APruebaDonkeyKong_l01GameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:

	TMap<int32,Aplataforma*> ComponentePlataformaMap;

	//AEnemigoCubo* Cubo;
	TArray<AActor*> CubosEnemigos;
	void SpawnCubosEnemigos();
	void SpawClasesHijas();
};



