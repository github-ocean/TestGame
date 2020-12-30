// Fill out your copyright notice in the Description page of Project Settings.

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
	
	float InitialLocationX = -60.f;
	float InitialLocationZ = -60.f;

	for (int i = 0; i <= 41; i++)
	{
		FVector InitialLocation = FVector(InitialLocationX, 0, InitialLocationZ);
		
		FActorSpawnParameters SpawnParm;
		ABall* BallRef = GetWorld()->SpawnActor<ABall>(InitialLocation, FRotator(0.f, 0.f, 0.f));

		Sloats.Add(BallRef);
		
		//GetWorld()->SpawnActor(ABall::StaticClass(), InitialLocation, SpawnParm);
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

	for (int i = 0; i <= 41; i++)
	{
		FVector ActorLocation = Sloats[i]->GetActorLocation();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Location: X=%f Y=%f Z=%f"),ActorLocation.X, ActorLocation.Y, ActorLocation.Z));
	}
}

// Called every frame
void ABallBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



