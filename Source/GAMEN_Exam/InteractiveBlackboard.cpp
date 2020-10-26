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

	magATRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("VecAMagnitude"))));
	normAxTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("NormAx"))));
	normAyTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("NormAy"))));
}

void AInteractiveBlackboard::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

void AInteractiveBlackboard::UpdateUI() {
	vecAxTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf"), vectorSolver.vecA.x)));
	vecAyTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf"), vectorSolver.vecA.y)));
	vecBxTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf"), vectorSolver.vecB.x)));
	vecByTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf"), vectorSolver.vecB.y)));

	magATRC->SetText(FText::FromString(FString::Printf(TEXT("%lf"), vectorSolver.vecA.GetMagnitude())));
}

void AInteractiveBlackboard::EnterDigit(int digit) {
	this->vectorSolver.EnterDigit(digit);
	this->UpdateUI();
}

void AInteractiveBlackboard::DotLeftVector() {
	vectorSolver.DotLeft();
	this->UpdateUI();
}

void AInteractiveBlackboard::DotRightVector() {
	vectorSolver.DotRight();
	this->UpdateUI();
}

void AInteractiveBlackboard::ClearVector() {
	vectorSolver.ClearVector();
	this->UpdateUI();
}

void AInteractiveBlackboard::SetSelected(Selectable selected) {
	this->vectorSolver.Selected = selected;
}

