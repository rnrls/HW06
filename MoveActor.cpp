

#include "MoveActor.h"


AMoveActor::AMoveActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(SceneRoot);


	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Chair.SM_Chair"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
} 


void AMoveActor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}


void AMoveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = StartLocation;

	float RunningTime = GetGameTimeSinceCreation();
	NewLocation.Z += FMath::Sin(RunningTime * Speed) * Amplitude;

	SetActorLocation(NewLocation);
}

