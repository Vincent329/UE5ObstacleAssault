// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatformNew.h"

// Sets default values
AMovingPlatformNew::AMovingPlatformNew()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	SetRootComponent(SceneRoot);

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform Static Mesh"));
	PlatformMesh->SetupAttachment(RootComponent);

	EndPositionPoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("End Point"));
	EndPositionPoint->SetupAttachment(RootComponent);
	EndPositionPoint->bHiddenInGame = true;
}

// Called when the game starts or when spawned
void AMovingPlatformNew::BeginPlay()
{
	Super::BeginPlay();
	StartPosition = GetActorLocation();
	EndPosition = EndPositionPoint->GetComponentLocation();

	f_Magnitude = FVector::Dist(StartPosition, EndPosition);
	v_Velocity = (EndPosition - StartPosition).GetSafeNormal();

	FString MyString = "MyString Value";
	FString DynamicValue = GetName();

	if (b_StartAtEnd == true)
	{
		float t = 0.95f;
		FVector EndPoint = StartPosition + (EndPosition - StartPosition) * t;
		SetActorLocation(EndPoint);
	}
}

void AMovingPlatformNew::MovePlatform(float DeltaTime)
{
	FVector CurrentPosition = GetActorLocation();
	CurrentPosition = CurrentPosition + (v_Velocity * f_Speed * DeltaTime);
	SetActorLocation(CurrentPosition);
	
	float f_distance = FVector::Dist(StartPosition, CurrentPosition);
	FString Name = GetName();
	if (f_distance > f_Magnitude)
	{
		float f_Overshoot = f_distance - f_Magnitude;
		
		UE_LOG(LogTemp, Display, TEXT("Name of Object: %s, Overshoot: %f"), *Name, f_Overshoot);
		FVector MoveDirection = v_Velocity.GetSafeNormal();
		StartPosition = StartPosition + MoveDirection * f_distance;
		SetActorLocation(StartPosition);
		v_Velocity = -v_Velocity;
	}
}

void AMovingPlatformNew::RotatePlatform(float DeltaTime)
{
	FRotator rotationAxis = FRotator::ZeroRotator;
}

// Called every frame
void AMovingPlatformNew::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
}

