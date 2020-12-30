// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OnClicked.AddUniqueDynamic(this, &ABall::OnSelected);
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//Setup ball mesh and material.
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
	int RandomIntForMaterial = FMath::RandRange(1, 4);
	ConstructorHelpers::FObjectFinder<UMaterial> BallMeshMaterialRedLocation(TEXT("/Game/Materials/BallRed.BallRed"));
	ConstructorHelpers::FObjectFinder<UMaterial> BallMeshMaterialGreenLocation(TEXT("/Game/Materials/BallGreen.BallGreen"));
	ConstructorHelpers::FObjectFinder<UMaterial> BallMeshMaterialBlueLocation(TEXT("/Game/Materials/BallBlue.BallBlue"));
	ConstructorHelpers::FObjectFinder<UMaterial> BallMeshMaterialYellowLocation(TEXT("/Game/Materials/BallYellow.BallYellow"));
	switch (RandomIntForMaterial)
	{
	case 1:
		// Red Material, Type 1.
		if (BallMeshMaterialRedLocation.Succeeded())
		{
			BallMesh->SetMaterial(0, BallMeshMaterialRedLocation.Object);
			BallType = 1;
		}
		break;
	case 2:
		// Green Material, Type 2.

		if (BallMeshMaterialGreenLocation.Succeeded())
		{
			BallMesh->SetMaterial(0, BallMeshMaterialGreenLocation.Object);
			BallType = 2;
		}
		break;
	case 3:
		// Blue Material, Type 3.

		if (BallMeshMaterialBlueLocation.Succeeded())
		{
			BallMesh->SetMaterial(0, BallMeshMaterialBlueLocation.Object);
			BallType = 3;
		}
		break;
	case 4:
		// Yellow Material, Type 4.

		if (BallMeshMaterialYellowLocation.Succeeded())
		{
			BallMesh->SetMaterial(0, BallMeshMaterialYellowLocation.Object);
			BallType = 4;
		}
		break;
	default:
		break;
	}

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
	ABall* BallRef = this;
	BallBaseRef->OnAnyBallSelected(BallRef);
}