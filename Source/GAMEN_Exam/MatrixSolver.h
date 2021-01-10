#pragma once

#include "CoreMinimal.h"
#include "VectorSolver.h"

struct Matrix3 {
public:
	Vector vecA, vecB, vecC;
public:
	Matrix3();
	Matrix3(Vector vecA, Vector vecB, Vector vecC);
	Matrix3 Add(Matrix3 other);
	Matrix3 Sub(Matrix3 other);
	Matrix3 Mul(Matrix3 other);
	double ComputeDeterminant();
};

struct Matrix2 {
public:
	Vector vecA, vecB;
public:
	Matrix2();
	Matrix2(Vector vecA, Vector vecB);
	Matrix2 Add(Matrix2 other);
	Matrix2 Sub(Matrix2 other);
	Matrix2 Mul(Matrix2 other);
	double ComputeDeterminant();
};

class GAMEN_EXAM_API MatrixSolver {
public:
	Matrix3 MatA, MatB;
	Matrix2 MatC, MatD;
	Selectable Selected = Selectable::None;
public:
	MatrixSolver();
	~MatrixSolver();
	void EnterDigit(int digit);
	void Clear();
	void Invert();
	void DotRight();
	void DotLeft();
};
