// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveActor.generated.h"

UCLASS()
class SPARTAPROJECT_API AMoveActor : public AActor
{
	GENERATED_BODY()
	
public:	

	AMoveActor();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveActor|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveActor|Components")
	
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MoveActor|Properties")
	
	FVector StartLocation;

	float Amplitude = 50.f;
	float Speed = 1.f;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
