// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatformNew.generated.h"

UCLASS()
class UE5OBSTACLEASSAULT_API AMovingPlatformNew : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatformNew();

	UPROPERTY(VisibleDefaultsOnly, Category = "Scene", meta =(DisplayName = "SceneRoot", ToolTip = "Scene Root"))
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh", meta =(DisplayName = "MeshComp", ToolTip = "The Mesh the Platform will Take"))
	UStaticMeshComponent* PlatformMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh", meta = (DisplayName = "End Position", ToolTip = "The Mesh representing the distance"))
	UStaticMeshComponent* EndPositionPoint;

	UPROPERTY(EditAnywhere, Category =  "Custom Parameter", meta = (DisplayName = "Speed Value", Tooltip = "how fast this will go")) // hi
	float f_Speed = 10.0f;

	UPROPERTY(EditAnywhere, Category =  "Custom Parameter", meta = (DisplayName = "Start At End", Tooltip = "Have the block start at the end position?")) // hi
	bool b_StartAtEnd;

	UPROPERTY(EditAnywhere, Category =  "Custom Parameter", meta = (DisplayName = "Rotational Speed Value", Tooltip = "how fast this will go")) // hi
	float f_RotationSpeed = 10.0f;

	UPROPERTY(EditAnywhere, Category =  "Custom Parameter", meta = (DisplayName = "Should Rotate", Tooltip = "Have the block start at the end position?")) // hi
	bool b_ShouldRotate;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(VisibleAnywhere)
	FVector StartPosition;

	UPROPERTY(VisibleAnywhere)
	FVector EndPosition;

	UPROPERTY(VisibleAnywhere, Category = "Movement Parameters")
	FVector v_Velocity;

	UPROPERTY(VisibleAnywhere)
	float f_Magnitude;

	UFUNCTION()
	void MovePlatform(float DeltaTime);

	UFUNCTION()
	void RotatePlatform(float DeltaTime);

};
