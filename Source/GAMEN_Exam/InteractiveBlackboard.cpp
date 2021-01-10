#include "InteractiveBlackboard.h"
#include "DrawDebugHelpers.h"
#include "VectorSolver.h"

#include "assert.h"

// Sets default values
AInteractiveBlackboard::AInteractiveBlackboard() {
	PrimaryActorTick.bCanEverTick = true;
	this->vectorSolver = VectorSolver();
}

// Called when the game starts or when spawned
void AInteractiveBlackboard::BeginPlay() {
	Super::BeginPlay();

	/* --- Vector Stuff --- */
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

	/* --- Matrix Stuff --- */
	matA11TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatA11Input"))));
	matA12TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatA12Input"))));
	matA13TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatA13Input"))));
	matA21TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatA21Input"))));
	matA22TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatA22Input"))));
	matA23TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatA23Input"))));
	matA31TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatA31Input"))));
	matA32TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatA32Input"))));
	matA33TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatA33Input"))));

	matB11TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatB11Input"))));
	matB12TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatB12Input"))));
	matB13TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatB13Input"))));
	matB21TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatB21Input"))));
	matB22TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatB22Input"))));
	matB23TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatB23Input"))));
	matB31TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatB31Input"))));
	matB32TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatB32Input"))));
	matB33TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatB33Input"))));

	matABR11TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatABR11Input"))));
	matABR12TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatABR12Input"))));
	matABR13TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatABR13Input"))));
	matABR21TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatABR21Input"))));
	matABR22TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatABR22Input"))));
	matABR23TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatABR23Input"))));
	matABR31TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatABR31Input"))));
	matABR32TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatABR32Input"))));
	matABR33TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatABR33Input"))));

	matC11TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatC11Input"))));
	matC12TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatC12Input"))));
	matC21TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatC21Input"))));
	matC22TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatC22Input"))));

	matD11TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatD11Input"))));
	matD12TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatD12Input"))));
	matD21TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatD21Input"))));
	matD22TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatD22Input"))));

	matCDR11TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatCDR11Input"))));
	matCDR12TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatCDR12Input"))));
	matCDR21TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatCDR21Input"))));
	matCDR22TRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatCDR22Input"))));

	detMatA = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("DetMatA"))));
	detMatB = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("DetMatB"))));
	detMatC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("DetMatC"))));
	detMatD = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("DetMatD"))));

	matABOperandTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatABOperation"))));
	matCDOperandTRC = ((UTextRenderComponent*)(GetDefaultSubobjectByName(TEXT("MatCDOperation"))));

}

void AInteractiveBlackboard::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	const float vectorWidth = 50.f;
	//Get longest, middle and shortest vector
	Vector longest, middle, shortest;
	double vecAMag = vectorSolver.vecA.GetMagnitude();
	double vecBMag = vectorSolver.vecB.GetMagnitude();
	double vecCMag = vectorSolver.vecC.GetMagnitude();
	if (vecAMag > vecBMag && vecAMag > vecCMag) {
		//vecA is longest
		longest = vectorSolver.vecA;
		if (vecBMag > vecCMag) {
			middle = vectorSolver.vecB;
			shortest = vectorSolver.vecC;
		}
		else {
			middle = vectorSolver.vecC;
			shortest = vectorSolver.vecB;
		}
	}
	else if (vecBMag >= vecAMag && vecBMag > vecCMag) {
		//vecB is longest or they are equal
		longest = vectorSolver.vecB;
		if (vecAMag > vecCMag) {
			middle = vectorSolver.vecA;
			shortest = vectorSolver.vecC;
		}
		else {
			middle = vectorSolver.vecC;
			shortest = vectorSolver.vecA;
		}
	}
	else {
		//vecC is longest or they are equal
		longest = vectorSolver.vecC;
		if (vecAMag > vecBMag) {
			middle = vectorSolver.vecA;
			shortest = vectorSolver.vecB;
		}
		else {
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
	/* --- Vector --- */
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

	UE_LOG(LogTemp, Warning, TEXT("NIGGER"));

	if (vectorSolver.BasisOrthoNormal(&vectorSolver.vecA, &vectorSolver.vecB, &vectorSolver.vecC)) {
		//3D Orthonormal
		xyzBasisTRC->SetText(FText::FromString(TEXT("Orthonormal Basis")));
	}
	else if (vectorSolver.BasisOrthogonal(&vectorSolver.vecA, &vectorSolver.vecB, &vectorSolver.vecC)) {
		//3D Orthogonal
		xyzBasisTRC->SetText(FText::FromString(TEXT("Orthogonal Basis")));
	}
	else if (vectorSolver.Basis(&vectorSolver.vecA, &vectorSolver.vecB, &vectorSolver.vecC)) {
		xyzBasisTRC->SetText(FText::FromString(TEXT("Random Basis")));
	}
	else {
		xyzBasisTRC->SetText(FText::FromString(TEXT("Not a Basis")));
	}

	if (vectorSolver.BasisOrthoNormal(&vectorSolver.vecA, &vectorSolver.vecB)) {
		//3D Orthonormal
		xyBasisTRC->SetText(FText::FromString(TEXT("Orthonormal Basis")));
	}
	else if (vectorSolver.BasisOrthogonal(&vectorSolver.vecA, &vectorSolver.vecB)) {
		//3D Orthogonal
		xyBasisTRC->SetText(FText::FromString(TEXT("Orthogonal Basis")));
	}
	else if (vectorSolver.Basis(&vectorSolver.vecA, &vectorSolver.vecB)) {
		xyBasisTRC->SetText(FText::FromString(TEXT("Random Basis")));
	}
	else {
		xyBasisTRC->SetText(FText::FromString(TEXT("Not a Basis")));
	}

	/* --- Matrixi --- */
	matA11TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatA.vecA.x)));
	matA12TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatA.vecB.x)));
	matA13TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatA.vecC.x)));
	matA21TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatA.vecA.y)));
	matA22TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatA.vecB.y)));
	matA23TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatA.vecC.y)));
	matA31TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatA.vecA.z)));
	matA32TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatA.vecB.z)));
	matA33TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatA.vecC.z)));

	matB11TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatB.vecA.x)));
	matB12TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatB.vecB.x)));
	matB13TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatB.vecC.x)));
	matB21TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatB.vecA.y)));
	matB22TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatB.vecB.y)));
	matB23TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatB.vecC.y)));
	matB31TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatB.vecA.z)));
	matB32TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatB.vecB.z)));
	matB33TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatB.vecC.z)));


	matC11TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatC.vecA.x)));
	matC12TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatC.vecB.x)));
	matC21TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatC.vecA.y)));
	matC22TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatC.vecB.y)));

	matD11TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatD.vecA.x)));
	matD12TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatD.vecB.x)));
	matD21TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatD.vecA.y)));
	matD22TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatD.vecB.y)));

	detMatA->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatA.ComputeDeterminant())));
	detMatB->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatB.ComputeDeterminant())));
	detMatC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatC.ComputeDeterminant())));
	detMatD->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matrixSolver.MatD.ComputeDeterminant())));

	Matrix3 matABR;
	switch (matABOperand) {
	case PLUS:
		matABR = matrixSolver.MatA.Add(matrixSolver.MatB);
		matABOperandTRC->SetText(TEXT("+"));
		break;
	case MINUS:
		matABR = matrixSolver.MatA.Sub(matrixSolver.MatB);
		matABOperandTRC->SetText(TEXT("-"));
		break;
	case MULTIPLY:
		matABR = matrixSolver.MatA.Mul(matrixSolver.MatB);
		matABOperandTRC->SetText(TEXT("*"));
		break;
	}
	matABR11TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matABR.vecA.x)));
	matABR12TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matABR.vecB.x)));
	matABR13TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matABR.vecC.x)));
	matABR21TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matABR.vecA.y)));
	matABR22TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matABR.vecB.y)));
	matABR23TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matABR.vecC.y)));
	matABR31TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matABR.vecA.z)));
	matABR32TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matABR.vecB.z)));
	matABR33TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matABR.vecC.z)));

	Matrix2 matCDR;
	switch (matCDOperand) {
	case PLUS:
		matCDR = matrixSolver.MatC.Add(matrixSolver.MatD);
		matCDOperandTRC->SetText(TEXT("+"));
		break;
	case MINUS:
		matCDR = matrixSolver.MatC.Sub(matrixSolver.MatD);
		matCDOperandTRC->SetText(TEXT("-"));
		break;
	case MULTIPLY:
		matCDR = matrixSolver.MatC.Mul(matrixSolver.MatD);
		matCDOperandTRC->SetText(TEXT("*"));
		break;
	}
	matCDR11TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matCDR.vecA.x)));
	matCDR12TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matCDR.vecB.x)));
	matCDR21TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matCDR.vecA.y)));
	matCDR22TRC->SetText(FText::FromString(FString::Printf(TEXT("%.1lf"), matCDR.vecB.y)));

}

void AInteractiveBlackboard::EnterDigit(int digit) {
	this->vectorSolver.EnterDigit(digit);
	this->matrixSolver.EnterDigit(digit);
	this->UpdateUI();
}

void AInteractiveBlackboard::DotLeftVector() {
	vectorSolver.DotLeft();
	matrixSolver.DotLeft();
	this->UpdateUI();
}

void AInteractiveBlackboard::DotRightVector() {
	vectorSolver.DotRight();
	matrixSolver.DotRight();
	this->UpdateUI();
}

void AInteractiveBlackboard::InvertVector() {
	vectorSolver.InvertVector();
	matrixSolver.Invert();
	this->UpdateUI();
}

void AInteractiveBlackboard::ClearVector() {
	vectorSolver.ClearVector();
	matrixSolver.Clear();
	this->UpdateUI();
}

void AInteractiveBlackboard::SetSelected(Selectable selected) {
	this->vectorSolver.Selected = selected;
	this->matrixSolver.Selected = selected;
}

void AInteractiveBlackboard::ToggleABOperand() {
	switch (matABOperand) {
	case PLUS:
		matABOperand = Operand::MINUS;
		break;
	case MINUS:
		matABOperand = Operand::MULTIPLY;
		break;
	case MULTIPLY:
		matABOperand = Operand::PLUS;
		break;
	}
	this->UpdateUI();
}

void AInteractiveBlackboard::ToggleCDOperand() {
	switch (matCDOperand) {
	case PLUS:
		matCDOperand = Operand::MINUS;
		break;
	case MINUS:
		matCDOperand = Operand::MULTIPLY;
		break;
	case MULTIPLY:
		matCDOperand = Operand::PLUS;
		break;
	}
	this->UpdateUI();
}
