// Fill out your copyright notice in the Description page of Project Settings.


#include "RPlatformSpawner.h"

// Sets default values
ARPlatformSpawner::ARPlatformSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnCount = 10;
}

void ARPlatformSpawner::SpawnMyActor()
{
	if (!GetWorld() || !ActorClass) return;

	// 스폰할 Location
	float RandomOffsetX = FMath::RandRange(-300, 300);
	float RandomOffsetY = FMath::RandRange(-300, 300);
	float RandomOffsetZ = FMath::RandRange(-100, 300);
	FVector RandomOffset = FVector(RandomOffsetX, RandomOffsetY, RandomOffsetZ);
	FVector SpawnLocation = GetActorLocation() + SpawnOffset + RandomOffset;

	// 스폰할 Rotation
	float RandomVectorX = FMath::RandRange(-180, 180);
	float RandomVectorY = FMath::RandRange(-180, 180);
	float RandomVectorZ = FMath::RandRange(-180, 180);
	FRotator SpawnRotation = FRotator(RandomVectorX, RandomVectorY, RandomVectorZ);

	// 스폰할 Scale
	FVector SpawnScale = FVector(3);

	// 스폰할 Transform
	FTransform SpawnTransform(SpawnRotation, SpawnLocation, SpawnScale);

	FActorSpawnParameters SpawnParams;
	// 스폰된 액터의 소유자를 지정
	SpawnParams.Owner = this;
	// 스폰 위치에 충돌이 있으면 조절하고 스폰
	SpawnParams.SpawnCollisionHandlingOverride = 
		ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	AActor* NewActor = GetWorld()->SpawnActor<AActor>(
		ActorClass,
		SpawnTransform,
		SpawnParams
	);

	SpawnCount--;
	if (SpawnCount <= 0) {
		// 반복 생성 종료
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	}
}

// Called when the game starts or when spawned
void ARPlatformSpawner::BeginPlay()
{
	Super::BeginPlay();

	// 1초마다 반복 생성
	GetWorld()->GetTimerManager().SetTimer(
		TimerHandle,
		this,
		&ARPlatformSpawner::SpawnMyActor,
		1,
		true
	);
}

// Called every frame
void ARPlatformSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

