// Copyright Epic Games, Inc. All Rights Reserved.

#include "PruebaDonkeyKong_l01GameMode.h"
#include "PruebaDonkeyKong_l01Character.h"
#include "UObject/ConstructorHelpers.h"
#include "plataforma.h"
#include "EnemigoCubo.h"
#include "MuroElectrica.h"
#include "MuroLadrlillo.h"

APruebaDonkeyKong_l01GameMode::APruebaDonkeyKong_l01GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void APruebaDonkeyKong_l01GameMode::BeginPlay()
{
    GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, TEXT("Actor Spawning"));

    // Definiciones iniciales
    FVector posicionInicial = FVector(1180.0, -419.9, 760.0);
    FRotator rotacionInicial = FRotator(0.0f, 0.0f, 5.0f);
    FTransform SpawnLocationCP;

    float incrementoAltoEntrePisos = 450.0f;
    float incrementoInicioPiso = 100.0f;
    float anchoComponentePlataforma = -500.0f;
    float mitadPlataforma = (anchoComponentePlataforma * 5.0f) / 2.0f;
   // float incrementoAltoComponentePlataforma = -105.0f;

    for (int npp = 0; npp < 7; npp++) {

       /* if (npp == 0 && npp == 1)
        {
            rotacionInicial.Roll = rotacionInicial.Roll * -1;
            incrementoInicioPiso = incrementoInicioPiso * -1;
            incrementoAltoComponentePlataforma = incrementoAltoComponentePlataforma * -1;
            SpawnLocationCP.SetRotation(FQuat(rotacionInicial));

            for (int ncp = 0; ncp < 5; ncp++) {
                SpawnLocationCP.SetLocation(FVector(posicionInicial.X, posicionInicial.Y + anchoComponentePlataforma * ncp, posicionInicial.Z));
                Aplataforma* plataforma = GetWorld()->SpawnActor<Aplataforma>(Aplataforma::StaticClass(), SpawnLocationCP);
                if (ncp < 4) {
                    posicionInicial.Z = posicionInicial.Z + incrementoAltoComponentePlataforma;
                }
            }

            posicionInicial.Z = posicionInicial.Z + incrementoAltoEntrePisos;
            posicionInicial.Y = posicionInicial.Y + incrementoInicioPiso;
        }*/
        // Cambiar la posición y rotación inicial para las plataformas 7 y superiores
        if (npp >= 2) {
            posicionInicial = FVector(1180.0, 300.0, 1330.0 + incrementoAltoEntrePisos * (npp - 2)); // Incrementa la altura para cada plataforma 3, 4, 5
            rotacionInicial = FRotator(0.0f, 0.0f, 0.0f);

            if (npp % 2 == 0) {
                posicionInicial.Y -= 600.0f; // Mover a la derecha
            }
            else {
                posicionInicial.Y += 600.0f; // Mover a la izquierda
            }

        }

        rotacionInicial.Roll *= -1;
        incrementoInicioPiso *= -1;

        SpawnLocationCP.SetRotation(FQuat(rotacionInicial));
        SpawnLocationCP.SetLocation(posicionInicial);

        // Crear la plataforma
        Aplataforma* plataforma = GetWorld()->SpawnActor<Aplataforma>(Aplataforma::StaticClass(), SpawnLocationCP);

        if (plataforma) {
            /*FVector escalaPlataforma;
            if (npp == 0 && npp == 1) {*/
                // Configurar la escala de la plataforma
                 FVector escalaPlataforma = FVector(2.5f, 12.0f, 0.5f);
           // }
            // Ajustar el tamaño de la plataforma 7
            if (npp >= 2) {
                escalaPlataforma = FVector(3.0f, 10.0f, 0.5f);
            }
            plataforma->SetActorScale3D(escalaPlataforma);


            //if (npp == 6)
            //{
            //    plataforma->SetMovementDirection(FVector(0.0f, 0.0f, -1.0f));  // Movimiento vertical
            //    plataforma->SetMovementType(2);  // Movimiento vertical (plataforma 6)
            //}
            //else 
            if (npp >= 2)
            {
                if (npp % 2 == 0)
                {
                    plataforma->SetMovementDirection(FVector(0.0f, 1.0f, 0.0f));  // Mover a la derecha (pares)
                }
                else
                {
                    plataforma->SetMovementDirection(FVector(0.0f, -1.0f, 0.0f));  // Mover a la izquierda (impares)
                }
                plataforma->SetMovementType(1);  // Movimiento horizontal
            }
            else
            {
                plataforma->SetMovementType(0);  // Plataforma estacionaria
            }


            ComponentePlataformaMap.Add(npp, plataforma);
        }

        // Ajuste de posición para la siguiente plataforma
        if (npp >= 2) {
            posicionInicial.Z += incrementoAltoEntrePisos;
        }
        else {
            posicionInicial.Z += incrementoAltoEntrePisos;
            posicionInicial.Y += incrementoInicioPiso + mitadPlataforma;
        }
    }
    SpawnCubosEnemigos();
    SpawClasesHijas();
}

void APruebaDonkeyKong_l01GameMode::Tick(float DeltaTime)
{
    for (auto& Elem : ComponentePlataformaMap)
    {
        if (Elem.Value)
        {
            Elem.Value->MovePlatform(DeltaTime);
        }
    }
}

void APruebaDonkeyKong_l01GameMode::SpawnCubosEnemigos()
{

    FVector BaseLocation = FVector(1180.0f, 300.0f, 1360.0f);
    float OffsetZ = 450.0f;

    for (int32 i = 0; i < 5; ++i)
    {
        FTransform SpawnLocation;
        FVector NewLocation = BaseLocation;
        NewLocation.Z += i * OffsetZ; // Incrementa la posición Z en 350 unidades por cada cubo
        SpawnLocation.SetLocation(NewLocation);
        SpawnLocation.SetRotation(FQuat(FRotator(0.0f, 0.0f, 0.0f)));
        CubosEnemigos.Add(GetWorld()->SpawnActor<AEnemigoCubo>(AEnemigoCubo::StaticClass(), SpawnLocation));
    }
}

void APruebaDonkeyKong_l01GameMode::SpawClasesHijas()
{
    UWorld* World = GetWorld();
    if (World)
    {

         FVector  PosicionMuro1 = FVector(1180.0f, -300.0f, 800.0f);
         FVector  PosicionMuro2 = FVector(1180.0f, -1769.9, 1410.0f);


        // Spawnear ClaseHija1 en PosicionHija1
        FActorSpawnParameters SpawnParams;
        AMuroElectrica* Hija1 = World->SpawnActor<AMuroElectrica>(AMuroElectrica::StaticClass(), PosicionMuro1, FRotator::ZeroRotator, SpawnParams);

        // Spawnear ClaseHija2 en PosicionHija2
        AMuroLadrlillo* Hija2 = World->SpawnActor<AMuroLadrlillo>(AMuroLadrlillo::StaticClass(), PosicionMuro2, FRotator::ZeroRotator, SpawnParams);
    }

}
