// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

UCLASS()
class TESTGAME_API ABall : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
//VARIABLES

	int BallType = 0;

	class UStaticMeshComponent* BallMesh;

	class ABallBase* BallBaseRef;

	class UMaterialInstanceDynamic* DynamicMaterial;

	class URotatingMovementComponent* RotationComponent;

//FUNCTIONS

	// Sets default values for this actor's properties
	ABall();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnSelected(AActor* Target, FKey ButtonPressed);

	void CreateDynamicMaterial();
	void ChangeMaterialLight(bool LightValue);
};
