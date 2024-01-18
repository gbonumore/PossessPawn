// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainCharacter.h"
#include "GameFramework/PlayerController.h"
#include "PossessPawn/PossessPawnCharacter.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class POSSESSPAWN_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMainPlayerController();

	UPROPERTY(VisibleAnywhere)
	AMainCharacter* CurrentCharacter;

	UPROPERTY(EditAnywhere, Blueprintable, Category = Input)
	UInputMappingContext* CurrentMappingContext;
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
};
