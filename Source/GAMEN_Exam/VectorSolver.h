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

		bool BasisOrthogonal(Vector* vec1, Vector* vec2);
		bool BasisNormal(Vector* vec1, Vector* vec2);
		bool BasisOrthogonal(Vector* vec1, Vector* vec2, Vector* vec3);
		bool BasisNormal(Vector* vec1, Vector* vec2, Vector* vec3);

	};
