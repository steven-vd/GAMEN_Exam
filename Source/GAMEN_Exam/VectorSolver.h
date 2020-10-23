// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


	struct Vector {
	public:
		double x, y;
	public:
		Vector();
		Vector(double x, double y);

		double GetMagnitude();
		Vector GetNormalized();
		double GetDeterminent(Vector* other);
		Vector GetScaled(double scalar);
	};


	UENUM(BlueprintType)
		enum Selectable {
		None UMETA(DisplayName = "None"),
		VecAx UMETA(DisplayName = "VecAx"),
		VecAy UMETA(DisplayName = "VecAy"),
		VecBx UMETA(DisplayName = "VecBx"),
		VecBy UMETA(DisplayName = "VecBy")
	};

	class GAMEN_EXAM_API VectorSolver {
	public:
		int Selected;
		Vector vecA, vecB;

	public:
		VectorSolver();
		~VectorSolver();

		void EnterDigit(int digit);

	};
