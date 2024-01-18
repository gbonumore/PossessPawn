// Copyright Epic Games, Inc. All Rights Reserved.

#include "PossessPawnGameMode.h"
#include "PossessPawnCharacter.h"
#include "UObject/ConstructorHelpers.h"

APossessPawnGameMode::APossessPawnGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
