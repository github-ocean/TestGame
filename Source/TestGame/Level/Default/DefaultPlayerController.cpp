// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultPlayerController.h"

ADefaultPlayerController::ADefaultPlayerController()
{
	bShowMouseCursor = true;
	UE_LOG(LogTemp, Warning, TEXT("PlayerController is working."));
}