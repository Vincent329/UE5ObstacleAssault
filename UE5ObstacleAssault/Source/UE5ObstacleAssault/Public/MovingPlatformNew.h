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

	UPROPERTY(EditAnywhere, meta = (Tooltip = "how fast this will go")) // hi
	float f_Speed = 10.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void MovePlatform(float DeltaTime);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(VisibleAnywhere)
	FVector StartPosition;

	UPROPERTY(VisibleAnywhere)
	FVector EndPosition;

	UPROPERTY(VisibleAnywhere)
	FVector v_Velocity;

	UPROPERTY(VisibleAnywhere)
	float f_Magnitude;
	 
};
