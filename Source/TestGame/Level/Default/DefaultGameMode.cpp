// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultGameMode.h"
#include "DefaultPlayer.h"
#include "DefaultPlayerController.h"

ADefaultGameMode::ADefaultGameMode()
{
	DefaultPawnClass = ADefaultPlayer::StaticClass();
	PlayerControllerClass = ADefaultPlayerController::StaticClass();
}
