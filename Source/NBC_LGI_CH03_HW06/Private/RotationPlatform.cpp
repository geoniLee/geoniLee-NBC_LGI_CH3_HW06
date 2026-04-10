// Fill out your copyright notice in the Description page of Project Settings.


#include "RotationPlatform.h"

// Sets default values
ARotationPlatform::ARotationPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/ModularOldTown/Meshes/Decoration_Parts/SM_LionHeadStatue.SM_LionHeadStatue"));
	if (MeshAsset.Succeeded()) {
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	// 중앙을 기준으로 돌아가도록 pivot 수정
	StaticMeshComp->SetRelativeLocation(FVector(15, 0, -20));
	RotationSpeed = 30;
}

void ARotationPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (IsRandomLocate) {
		StartLocation = GetActorLocation();
		GetWorld()->GetTimerManager().SetTimer(
			TimerHandle,
			this,
			&ARotationPlatform::MoveRandomLocation,
			3,
			true
		);
	}
}

// Called every frame
void ARotationPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(RotationSpeed, 0, 0) * DeltaTime);
}

void ARotationPlatform::MoveRandomLocation()
{
	float RandomVectorX = FMath::RandRange(-300, 300);
	SetActorLocation(StartLocation + FVector(RandomVectorX, 0, 0));
}
