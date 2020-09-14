// Copyright Epic Games, Inc. All Rights Reserved.

#include "Networking_ConceptsGameMode.h"
#include "Networking_ConceptsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANetworking_ConceptsGameMode::ANetworking_ConceptsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
