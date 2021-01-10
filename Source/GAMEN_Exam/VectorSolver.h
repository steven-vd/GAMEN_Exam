// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


struct Vector {
public:
	double x, y, z;
public:
	Vector();
	Vector(double x, double y, double z);

	double GetMagnitude();
	Vector GetNormalized();
	double GetDeterminent2D(Vector* other);
	double GetDeterminent(Vector* other1, Vector* other2);
	Vector GetScaled(double scalar);
	double GetDotProduct2D(Vector* other);
	double GetDotProduct(Vector* other);
};


UENUM(BlueprintType)
enum Selectable {
	None UMETA(DisplayName = "None"),
	VecAx UMETA(DisplayName = "VecAx"),
	VecAy UMETA(DisplayName = "VecAy"),
	VecAz UMETA(DisplayName = "VecAz"),
	VecBx UMETA(DisplayName = "VecBx"),
	VecBy UMETA(DisplayName = "VecBy"),
	VecBz UMETA(DisplayName = "VecBz"),
	VecCx UMETA(DisplayName = "VecCx"),
	VecCy UMETA(DisplayName = "VecCy"),
	VecCz UMETA(DisplayName = "VecCz"),

	MatA11 UMETA(DisplayName = "MatA11"),
	MatA12 UMETA(DisplayName = "MatA12"),
	MatA13 UMETA(DisplayName = "MatA13"),
	MatA21 UMETA(DisplayName = "MatA21"),
	MatA22 UMETA(DisplayName = "MatA22"),
	MatA23 UMETA(DisplayName = "MatA23"),
	MatA31 UMETA(DisplayName = "MatA31"),
	MatA32 UMETA(DisplayName = "MatA32"),
	MatA33 UMETA(DisplayName = "MatA33"),
	MatB11 UMETA(DisplayName = "MatB11"),
	MatB12 UMETA(DisplayName = "MatB12"),
	MatB13 UMETA(DisplayName = "MatB13"),
	MatB21 UMETA(DisplayName = "MatB21"),
	MatB22 UMETA(DisplayName = "MatB22"),
	MatB23 UMETA(DisplayName = "MatB23"),
	MatB31 UMETA(DisplayName = "MatB31"),
	MatB32 UMETA(DisplayName = "MatB32"),
	MatB33 UMETA(DisplayName = "MatB33"),
	MatC11 UMETA(DisplayName = "MatC11"),
	MatC12 UMETA(DisplayName = "MatC12"),
	MatC21 UMETA(DisplayName = "MatC21"),
	MatC22 UMETA(DisplayName = "MatC22"),
	MatD11 UMETA(DisplayName = "MatD11"),
	MatD12 UMETA(DisplayName = "MatD12"),
	MatD21 UMETA(DisplayName = "MatD21"),
	MatD22 UMETA(DisplayName = "MatD22"),
};

UENUM(BlueprintType)
enum BasisType {
	BasisNone UMETA(DisplayName = "BasisNone"),
	Orthogonal UMETA(DisplayName = "Orthogonal"),
	Orthonormal UMETA(DisplayName = "Orthonormal"),
};

class GAMEN_EXAM_API VectorSolver {
public:
	int Selected;
	Vector vecA, vecB, vecC;

public:
	VectorSolver();
	~VectorSolver();

	void EnterDigit(int digit);
	void DotLeft();
	void DotRight();
	void InvertVector();
	void ClearVector();

	bool Basis(Vector* vec1, Vector* vec2);
	bool BasisOrthogonal(Vector* vec1, Vector* vec2);
	bool BasisOrthoNormal(Vector* vec1, Vector* vec2);
	bool Basis(Vector* vec1, Vector* vec2, Vector* vec3);
	bool BasisOrthogonal(Vector* vec1, Vector* vec2, Vector* vec3);
	bool BasisOrthoNormal(Vector* vec1, Vector* vec2, Vector* vec3);

};
