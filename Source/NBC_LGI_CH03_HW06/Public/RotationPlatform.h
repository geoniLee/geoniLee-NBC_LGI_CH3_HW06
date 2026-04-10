// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "RotationPlatform.generated.h"

UCLASS()
class NBC_LGI_CH03_HW06_API ARotationPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotationPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;
	FTimerHandle TimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Obtacle")
	float RotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Obtacle")
	bool IsRandomLocate;

	FVector StartLocation;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void MoveRandomLocation();
};
