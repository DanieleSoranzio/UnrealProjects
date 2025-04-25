// Copyright Epic Games, Inc. All Rights Reserved.

#include "GP3SoranzioDanieleSTGameMode.h"
#include "GP3SoranzioDanieleSTCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGP3SoranzioDanieleSTGameMode::AGP3SoranzioDanieleSTGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
