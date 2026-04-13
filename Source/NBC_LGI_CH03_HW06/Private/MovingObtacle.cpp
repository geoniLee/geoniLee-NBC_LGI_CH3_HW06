// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingObtacle.h"

// Sets default values
AMovingObtacle::AMovingObtacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// SceneRoot 생성
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	// StaticMesh 생성
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	// StaticMesh Asset 지정
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/ModularOldTown/Meshes/CliffsRocks/SM_Rock_03.SM_Rock_03"));
	if (MeshAsset.Succeeded()) {
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	// 초기 설정(크기, 위치, 범위, 스피드)
	SetActorScale3D(FVector(4));
	StartPosition = FVector(1000, 2000, 0);
	MaxRange = 500;
	MoveSpeed = 100;
	Direction = -1;
}

// Called when the game starts or when spawned
void AMovingObtacle::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(StartPosition);
}

// Called every frame
void AMovingObtacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorWorldOffset(FVector(0, MoveSpeed * Direction, 0) * DeltaTime);
	double CurrentY = GetActorLocation().Y;

	// 범위 제한에 걸리면 방향 전환
	if (Direction == -1 && CurrentY < (StartPosition.Y - MaxRange)) Direction = 1;
	else if (Direction == 1 && CurrentY > (StartPosition.Y + MaxRange)) Direction = -1;
}