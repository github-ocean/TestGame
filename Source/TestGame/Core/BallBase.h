// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

	int CurrentSelectedBallIndex;

	TArray<FVector> SloatLocation;
	TArray<class ABall*> BallSloat;

	bool SelectionStage[3] {false, false, false};
	int SelectedBalls[3];


//FUNCTIONS

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnAnyBallSelected(ABall* BallRef);

	void OnFirstSelection();
	void OnSecondSelection();
	void OnThirdSelection();

	bool IsSameType(int PreviousSelection);
	bool IsInRange(int PreviousSelection);
	
	void DestroySelectedBalls();
	void FillTheGap();
	void ClearVariables();
};
