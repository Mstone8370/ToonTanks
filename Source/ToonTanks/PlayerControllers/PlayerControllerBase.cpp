// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"

void APlayerControllerBase::SetPlayerEnabledState(bool SetPlayerEnabled)
{
	APawn* PlayerPawn = GetPawn();
	if (PlayerPawn)
	{
		if (SetPlayerEnabled)
		{
			PlayerPawn->EnableInput(this);
		}
		else
		{
			PlayerPawn->DisableInput(this);
		}
	}

	bShowMouseCursor = SetPlayerEnabled;
}