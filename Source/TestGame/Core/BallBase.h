// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Ball.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "BallBase.generated.h"

UCLASS()
class TESTGAME_API ABallBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

//VARIABLES

	TArray<class ABall*> Sloats;

//FUNCTIONS

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnAnyBallSelected(ABall* BallRef);

};
