// Fill out your copyright notice in the Description page of Project Settings.

#include "Ball.h"
#include "BallBase.h"
#include "Engine/World.h"

// Sets default values
ABallBase::ABallBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	
}

// Called when the game starts or when spawned
void ABallBase::BeginPlay()
{
	Super::BeginPlay();
	
// Initialize Sloat Location Array.
	float InitialLocationX = -60.f;
	float InitialLocationZ = -60.f;
	for (int i = 0; i <= 41; i++)
	{
		FVector InitialLocation = FVector(InitialLocationX, 0, InitialLocationZ);
		SloatLocation.Add(InitialLocation);
		if (InitialLocationX == 40.f)
		{
			InitialLocationX = -60.f;
			InitialLocationZ += 20.f;
		}
		else
		{
			InitialLocationX += 20;
		}
	}

// Spawning Actors.
	for (int i = 0; i <= 41; i++)
	{
		ABall* BallRef = GetWorld()->SpawnActor<ABall>(SloatLocation[i], FRotator(0.f, 0.f, 0.f));
		BallRef->BallBaseRef = this;
		BallSloat.Add(BallRef);
	}	
}

// Called every frame
void ABallBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Run when player select any ball.
void ABallBase::OnAnyBallSelected(ABall* BallRef)
{
	CurrentSelectedBallIndex = BallSloat.Find(BallRef);
	if (!SelectionStage[0])
	{
		OnFirstSelection();
	}
	else
	{
		if (!SelectionStage[1])
			OnSecondSelection();
		else
			OnThirdSelection();
	}		
}

// Selection Checkes.

// First Selection.
void ABallBase::OnFirstSelection()
{
	BallSloat[CurrentSelectedBallIndex]->ChangeMaterialLight(true);
	SelectionStage[0] = true;
	SelectedBalls[0] = CurrentSelectedBallIndex;
}

// Second Selection.
void ABallBase::OnSecondSelection()
{
	BallSloat[CurrentSelectedBallIndex]->ChangeMaterialLight(true);
	if (IsSameType(0) && IsInRange(0))
	{
		SelectionStage[1] = true;
		SelectedBalls[1] = CurrentSelectedBallIndex;
	}
	else
	{
		BallSloat[SelectedBalls[0]]->ChangeMaterialLight(false);
		SelectedBalls[0] = CurrentSelectedBallIndex;
	}
}

// Third Selection.
void ABallBase::OnThirdSelection()
{
	BallSloat[CurrentSelectedBallIndex]->ChangeMaterialLight(true);
	if (IsSameType(1) && IsInRange(1))
	{
		SelectionStage[2] = true;
		SelectedBalls[2] = CurrentSelectedBallIndex;
		DestroySelectedBalls();
		FillTheGap();
		ClearVariables();
	}
	else
	{
		BallSloat[SelectedBalls[0]]->ChangeMaterialLight(false);
		BallSloat[SelectedBalls[1]]->ChangeMaterialLight(false);
		SelectionStage[1] = false;
		SelectedBalls[0] = CurrentSelectedBallIndex;
		SelectedBalls[1] = 0;
	}
}

// Checking if object is same type.
bool ABallBase::IsSameType(int PreviousSelection)
{
	return BallSloat[CurrentSelectedBallIndex]->BallType == BallSloat[SelectedBalls[PreviousSelection]]->BallType;
}

// Checking if new selection is in range of old selection.
bool ABallBase::IsInRange(int PreviousSelection)
{
	int PreviousIndex = SelectedBalls[PreviousSelection];


	bool SameLinePrevious = CurrentSelectedBallIndex == PreviousIndex - 1;
	bool SameLineNext = CurrentSelectedBallIndex == PreviousIndex + 1;

	int UpLineIndex = PreviousIndex - 6;
	bool UpLine = CurrentSelectedBallIndex == UpLineIndex;
	bool UpLinePrevious = CurrentSelectedBallIndex == UpLineIndex - 1;
	bool UpLineNext = CurrentSelectedBallIndex == UpLineIndex + 1;

	int DownLineIndex = PreviousIndex + 6;
	bool DownLine = CurrentSelectedBallIndex == DownLineIndex;
	bool DownLinePrevious = CurrentSelectedBallIndex == DownLineIndex - 1;
	bool DownLineNext = CurrentSelectedBallIndex == DownLineIndex + 1;

	int PreviousRange = SelectedBalls[PreviousSelection] - 6, NextRange = SelectedBalls[PreviousSelection] + 6;
	if (
		  SameLinePrevious || SameLineNext
		 || UpLine || UpLinePrevious || UpLineNext
		|| DownLine || DownLinePrevious || DownLineNext
		)
		return true;
	else
		return false;
}

// when user select all correct objects, it will destroy all selected objects.
void ABallBase::DestroySelectedBalls()
{

	for (int i=0; i < 3; i++)
	{
		GetWorld()->DestroyActor(BallSloat[SelectedBalls[i]]);
		BallSloat[SelectedBalls[i]] = NULL;
	}
}

// Spawning a new object on empty gaps.
void ABallBase::FillTheGap()
{
	for (int i = 0; i < 3; i++)
	{
		int LastEmptyPositionInColumn = SelectedBalls[i];

		for (int LoopVarJ = SelectedBalls[i]; LoopVarJ < 42;)
		{
			if (BallSloat[LoopVarJ] != NULL)
			{	
				BallSloat.Swap(LastEmptyPositionInColumn, LoopVarJ);
				BallSloat[LastEmptyPositionInColumn]->SetActorLocation(SloatLocation[LastEmptyPositionInColumn]);
				LastEmptyPositionInColumn += 6;
				BallSloat[LoopVarJ] = NULL;
			}
			LoopVarJ += 6;
		}

		for (int LoopVarK = LastEmptyPositionInColumn; LoopVarK < 42;)
		{
			ABall* BallRef = GetWorld()->SpawnActor<ABall>(SloatLocation[LoopVarK], FRotator(0.f, 0.f, 0.f));
			BallRef->BallBaseRef = this;
			BallSloat[LoopVarK] = BallRef;
			LoopVarK += 6;
		}
	}
}

// Clear Varialbes.
void ABallBase::ClearVariables()
{
	for (int i = 0; i < 3; i++)
	{
		SelectionStage[i] = false;
		SelectedBalls[i] = 0;
	}
}
