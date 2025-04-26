// Fill out your copyright notice in the Description page of Project Settings.


#include "C_BaseAI.h"

// Sets default values
AC_BaseAI::AC_BaseAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

}

// Called when the game starts or when spawned
void AC_BaseAI::BeginPlay()
{
	Super::BeginPlay();

    if (PatrolSplineActor)
    {
        PatrolSpline = PatrolSplineActor->FindComponentByClass<USplineComponent>();

        if (!PatrolSpline)
        {
            UE_LOG(LogTemp, Warning, TEXT("PatrolSpline non trovata nell'attore assegnato!"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("PatrolSplineActor non è stato assegnato!"));
    }

}

// Called every frame
void AC_BaseAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AC_BaseAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

