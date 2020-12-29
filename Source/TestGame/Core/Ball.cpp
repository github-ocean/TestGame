// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	BallMesh->SetupAttachment(GetRootComponent());

	ConstructorHelpers::FObjectFinder<UStaticMesh> BallMeshLocation(TEXT("/Game/BasicShapes/Sphere.Sphere"));
	if (BallMeshLocation.Succeeded())
	{
		BallMesh->SetStaticMesh(BallMeshLocation.Object);
		BallMesh->SetWorldScale3D(FVector(0.1f, 0.1f, 0.1f));
		BallMesh->SetGenerateOverlapEvents(true);
		BallMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		SetActorEnableCollision(true);
	}
	OnClicked.AddUniqueDynamic(this, &ABall::OnSelected);

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABall::OnSelected(AActor* Target, FKey ButtonPressed)
{
	UE_LOG(LogTemp, Warning, TEXT("Clicked."));
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, FString("Clicking."));
}