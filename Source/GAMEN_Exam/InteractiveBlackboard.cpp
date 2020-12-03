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
	vecAzTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("VecAzInput"))));
	vecBxTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("VecBxInput"))));
	vecByTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("VecByInput"))));
	vecBzTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("VecBzInput"))));
	vecCxTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("VecCxInput"))));
	vecCyTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("VecCyInput"))));
	vecCzTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("VecCzInput"))));

	magATRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("VecAMagnitude"))));
	normAxTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("NormAx"))));
	normAyTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("NormAy"))));
	normAzTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("NormAz"))));

	magBTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("VecBMagnitude"))));
	normBxTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("NormBx"))));
	normByTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("NormBy"))));
	normBzTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("NormBz"))));

	magCTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("VecCMagnitude"))));
	normCxTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("NormCx"))));
	normCyTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("NormCy"))));
	normCzTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("NormCz"))));

	determinantTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("Determinant"))));

	xyBasisTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("XyBasisLabel"))));
	xyzBasisTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("XyzBasisLabel"))));
}

void AInteractiveBlackboard::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	const float vectorWidth = 50.f;
	//Get longest and shortest vector
	Vector longest, middle, shortest;
	double vecAMag = vectorSolver.vecA.GetMagnitude();
	double vecBMag = vectorSolver.vecB.GetMagnitude();
	double vecCMag = vectorSolver.vecC.GetMagnitude();
	//TODO maybe let vec c factor in here. or not. whatever
	if (vecAMag > vecBMag && vecAMag > vecCMag) {
		//vecA is longest
		longest = vectorSolver.vecA;
		if (vecBMag > vecCMag) {
			middle = vectorSolver.vecB;
			shortest = vectorSolver.vecC;
		} else {
			middle = vectorSolver.vecC;
			shortest = vectorSolver.vecB;
		}
	} else if (vecBMag > vecAMag && vecBMag > vecCMag){
		//vecB is longest or they are equal
		longest = vectorSolver.vecB;
		if (vecAMag > vecCMag) {
			middle = vectorSolver.vecA;
			shortest = vectorSolver.vecC;
		} else {
			middle = vectorSolver.vecC;
			shortest = vectorSolver.vecA;
		}
	} else {
		//vecC is longest or they are equal
		longest = vectorSolver.vecC;
		if (vecAMag > vecBMag) {
			middle = vectorSolver.vecA;
			shortest = vectorSolver.vecB;
		} else {
			middle = vectorSolver.vecB;
			shortest = vectorSolver.vecA;
		}
	}

	double shortestLongestRatio = shortest.GetMagnitude() / longest.GetMagnitude();
	double middleLongestRatio = middle.GetMagnitude() / longest.GetMagnitude();
	longest = longest.GetNormalized();
	middle = middle.GetNormalized();
	shortest = shortest.GetNormalized();

	//Vector looks
	float const thickness = 5;
	float const arrowSize = 250;

	//draw longest vector
	FVector start = this->GetActorTransform().GetLocation();
	FVector end = FVector(start.X + longest.z * vectorsMaxLength, start.Y + longest.x * vectorsMaxLength, start.Z + longest.y * vectorsMaxLength);
	DrawDebugDirectionalArrow(GetWorld(), start, end, arrowSize, FColor::White, false, -1.f, 10, thickness);
	//draw middle vector
	start = this->GetActorTransform().GetLocation();
	end = FVector(start.X + middle.z * vectorsMaxLength * middleLongestRatio, start.Y + middle.x * vectorsMaxLength * middleLongestRatio, start.Z + middle.y * vectorsMaxLength * middleLongestRatio);
	DrawDebugDirectionalArrow(GetWorld(), start, end, arrowSize, FColor::White, false, -1.f, 10, thickness);
	//draw shortest vector
	start = this->GetActorTransform().GetLocation();
	end = FVector(start.X + shortest.z * vectorsMaxLength * shortestLongestRatio, start.Y + shortest.x * vectorsMaxLength * shortestLongestRatio, start.Z + shortest.y * vectorsMaxLength * shortestLongestRatio);
	DrawDebugDirectionalArrow(GetWorld(), start, end, arrowSize, FColor::White, false, -1.f, 10, thickness);
}

void AInteractiveBlackboard::UpdateUI() {
	vecAxTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf cm"), vectorSolver.vecA.x)));
	vecAyTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf cm"), vectorSolver.vecA.y)));
	vecAzTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf cm"), vectorSolver.vecA.z)));
	vecBxTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf cm"), vectorSolver.vecB.x)));
	vecByTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf cm"), vectorSolver.vecB.y)));
	vecBzTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf cm"), vectorSolver.vecB.z)));
	vecCxTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf cm"), vectorSolver.vecC.x)));
	vecCyTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf cm"), vectorSolver.vecC.y)));
	vecCzTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf cm"), vectorSolver.vecC.z)));

	magATRC->SetText(FText::FromString(FString::Printf(TEXT("%lf cm"), vectorSolver.vecA.GetMagnitude())));
	normAxTRC->SetText(FText::FromString(FString::Printf(TEXT("x: %lf"), vectorSolver.vecA.GetNormalized().x)));
	normAyTRC->SetText(FText::FromString(FString::Printf(TEXT("y: %lf cm"), vectorSolver.vecA.GetNormalized().y)));
	normAzTRC->SetText(FText::FromString(FString::Printf(TEXT("z: %lf cm"), vectorSolver.vecA.GetNormalized().z)));

	magBTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf cm"), vectorSolver.vecB.GetMagnitude())));
	normBxTRC->SetText(FText::FromString(FString::Printf(TEXT("x: %lf cm"), vectorSolver.vecB.GetNormalized().x)));
	normByTRC->SetText(FText::FromString(FString::Printf(TEXT("y: %lf cm"), vectorSolver.vecB.GetNormalized().y)));
	normBzTRC->SetText(FText::FromString(FString::Printf(TEXT("z: %lf cm"), vectorSolver.vecB.GetNormalized().z)));

	magCTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf cm"), vectorSolver.vecC.GetMagnitude())));
	normCxTRC->SetText(FText::FromString(FString::Printf(TEXT("x: %lf cm"), vectorSolver.vecC.GetNormalized().x)));
	normCyTRC->SetText(FText::FromString(FString::Printf(TEXT("y: %lf cm"), vectorSolver.vecC.GetNormalized().y)));
	normCzTRC->SetText(FText::FromString(FString::Printf(TEXT("z: %lf cm"), vectorSolver.vecC.GetNormalized().z)));

	double det = vectorSolver.vecA.GetDeterminent(&vectorSolver.vecB, &vectorSolver.vecC);
	determinantTRC->SetText(FText::FromString(FString::Printf(TEXT("%lf"), det)));

	//TODO show basis

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

