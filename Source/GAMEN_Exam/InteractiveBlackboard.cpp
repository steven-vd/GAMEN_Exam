// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveBlackboard.h"

// Sets default values
AInteractiveBlackboard::AInteractiveBlackboard() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	triangleSolver = TriangleSolver();
}

// Called when the game starts or when spawned
void AInteractiveBlackboard::BeginPlay() {
	Super::BeginPlay();

}

// Called every frame
void AInteractiveBlackboard::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

void AInteractiveBlackboard::EnterDigit(int digit) {
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::FromInt(digit));
}

