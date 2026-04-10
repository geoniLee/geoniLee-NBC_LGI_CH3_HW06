// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingObtacle.generated.h"

UCLASS()
class NBC_LGI_CH03_HW06_API AMovingObtacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingObtacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Obtacle")
	float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Obtacle")
	float MaxRange;
	
	int32 Direction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Obtacle")
	FVector StartPosition;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
