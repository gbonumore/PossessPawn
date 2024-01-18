// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MainPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Character/MainCharacter.h"

AMainPlayerController::AMainPlayerController()
{
}

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();
	CurrentCharacter = Cast<AMainCharacter>(GetPawn());
	if (CurrentCharacter)
	{
		Possess(CurrentCharacter);
		SetupInputComponent();
	}


}

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (!InputComponent || !CurrentCharacter) return;
	if (const APlayerController* PlayerController = Cast<APlayerController>(CurrentCharacter->GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(CurrentMappingContext, 0);
		}
	}
}
