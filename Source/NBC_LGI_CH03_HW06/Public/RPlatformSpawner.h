// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "RPlatformSpawner.generated.h"

UCLASS()
class NBC_LGI_CH03_HW06_API ARPlatformSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARPlatformSpawner();

	UPROPERTY(EditAnywhere, Category = "SpawnActor")
	TSubclassOf<AActor> ActorClass;

	UPROPERTY(EditAnywhere, Category = "SpawnActor")
	FVector SpawnOffset;

	UFUNCTION(BlueprintCallable, Category = "SpawnActor")
	void SpawnMyActor();

	FTimerHandle TimerHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int SpawnCount;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
