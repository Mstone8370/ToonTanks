// Fill out your copyright notice in the Description page of Project Settings.

#include "PawnTurret.h"

#include "TimerManager.h"

APawnTurret::APawnTurret()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void APawnTurret::CheckFireCondition()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire Condition Checked"));
}