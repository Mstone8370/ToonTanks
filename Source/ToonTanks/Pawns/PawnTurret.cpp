// Fill out your copyright notice in the Description page of Project Settings.

#include "PawnTurret.h"
#include "PawnTank.h"

#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
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
	
	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
	
	DrawDebugCircle(
		GetWorld(),
		GetActorLocation(),
		FireRange,
		64,
		FColor::Orange,
		true,
		-1.f,
		0,
		5.f,
		FVector(0.f, 1.f, 0.f),
		FVector(1.f, 0.f, 0.f),
		false
	);
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PlayerPawn || ReturnDistanceToPlayer() == -1.f || ReturnDistanceToPlayer() >= FireRange)
	{
		return;
	}

	RotateTurretFunction(PlayerPawn->GetActorLocation());
}

void APawnTurret::CheckFireCondition()
{
	if (!PlayerPawn)
	{
		return;
	}

	float DistanceToPlayer = ReturnDistanceToPlayer();
	if (DistanceToPlayer >= 0 && DistanceToPlayer <= FireRange)
	{
		Fire();
	}

}

float APawnTurret::ReturnDistanceToPlayer()
{
	if (!PlayerPawn)
	{
		return -1.f;
	}

	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}

void APawnTurret::HandleDestruction()
{
	Super::HandleDestruction();
}
