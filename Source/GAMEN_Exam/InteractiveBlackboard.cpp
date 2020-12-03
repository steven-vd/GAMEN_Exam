#include "InteractiveBlackboard.h"
#include "DrawDebugHelpers.h"
// Sets default values
AInteractiveBlackboard::AInteractiveBlackboard() {
	PrimaryActorTick.bCanEverTick = true;
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

	magBTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("VecBMagnitude"))));
	normBxTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("NormBx"))));
	normByTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("NormBy"))));

	determinantTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("Determinant"))));
}

void AInteractiveBlackboard::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	const float vectorWidth = 50.f;
	//Get longest and shortest vector
	Vector longest, shortest;
	double vecAMag = vectorSolver.vecA.GetMagnitude();
	double vecBMag = vectorSolver.vecB.GetMagnitude();
	if (vecAMag > vecBMag) {
		//vecA is longest
		longest = vectorSolver.vecA;
		shortest = vectorSolver.vecB;
	} else {
		//vecB is longest or they are equal
		longest = vectorSolver.vecB;
		shortest = vectorSolver.vecA;
	}

	double lenRatio = shortest.GetMagnitude() / longest.GetMagnitude();
	longest = longest.GetNormalized();
	shortest = shortest.GetNormalized();

	//Vector looks
	float const thickness = 5;
	float const arrowSize = 250;

	//draw longest vector
	FVector start = this->GetActorTransform().GetLocation();
	FVector end = FVector(start.X, start.Y + longest.x * vectorsMaxLength, start.Z + longest.y * vectorsMaxLength);
	DrawDebugDirectionalArrow(GetWorld(), start, end, arrowSize, FColor::White, false, -1.f, 10, thickness);
	//draw shortest vector
	start = this->GetActorTransform().GetLocation();
	end = FVector(start.X, start.Y + shortest.x * vectorsMaxLength * lenRatio, start.Z + shortest.y * vectorsMaxLength * lenRatio);
	DrawDebugDirectionalArrow(GetWorld(), start, end, arrowSize, FColor::White, false, -1.f, 10, thickness);
}

void AInteractiveBlackboard::UpdateUI() {
	vecAxTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf cm"), vectorSolver.vecA.x)));
	vecAyTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf cm"), vectorSolver.vecA.y)));
	vecBxTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf cm"), vectorSolver.vecB.x)));
	vecByTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf cm"), vectorSolver.vecB.y)));

	magATRC->SetText(FText::FromString(FString::Printf(TEXT("%lf cm"), vectorSolver.vecA.GetMagnitude())));
	normAxTRC->SetText(FText::FromString(FString::Printf(TEXT("x: %lf"), vectorSolver.vecA.GetNormalized().x)));
	normAyTRC->SetText(FText::FromString(FString::Printf(TEXT("y: %lf cm"), vectorSolver.vecA.GetNormalized().y)));

	magBTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf cm"), vectorSolver.vecB.GetMagnitude())));
	normBxTRC->SetText(FText::FromString(FString::Printf(TEXT("x: %lf cm"), vectorSolver.vecB.GetNormalized().x)));
	normByTRC->SetText(FText::FromString(FString::Printf(TEXT("y: %lf cm"), vectorSolver.vecB.GetNormalized().y)));

	determinantTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf"), vectorSolver.vecA.GetDeterminent(&vectorSolver.vecB))));
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

void AInteractiveBlackboard::InvertVector() {
	vectorSolver.InvertVector();
	this->UpdateUI();
}

void AInteractiveBlackboard::ClearVector() {
	vectorSolver.ClearVector();
	this->UpdateUI();
}

void AInteractiveBlackboard::SetSelected(Selectable selected) {
	this->vectorSolver.Selected = selected;
}

