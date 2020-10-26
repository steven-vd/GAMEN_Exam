// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveBlackboard.h"

// Sets default values
AInteractiveBlackboard::AInteractiveBlackboard() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	this->vectorSolver = VectorSolver();
}

// Called when the game starts or when spawned
void AInteractiveBlackboard::BeginPlay() {
	Super::BeginPlay();
	vecAxTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("VecAxInput"))));
	vecAyTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("VecAyInput"))));
	vecBxTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("VecBxInput"))));
	vecByTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("VecByInput"))));
}

// Called every frame
void AInteractiveBlackboard::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

void AInteractiveBlackboard::EnterDigit(int digit) {
	this->vectorSolver.EnterDigit(digit);
	vecAxTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf"), vectorSolver.vecA.x)));
	vecAyTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf"), vectorSolver.vecA.y)));
	vecBxTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf"), vectorSolver.vecB.x)));
	vecByTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf"), vectorSolver.vecB.y)));
}

void AInteractiveBlackboard::ClearVector() {
	
}

void AInteractiveBlackboard::SetSelected(Selectable selected) {
	this->vectorSolver.Selected = selected;
}

