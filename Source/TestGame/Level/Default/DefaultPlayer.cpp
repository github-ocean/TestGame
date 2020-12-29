// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultPlayer.h"
#include "Camera/CameraComponent.h"

// Sets default values
ADefaultPlayer::ADefaultPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void ADefaultPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADefaultPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADefaultPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);



}

