// Fill out your copyright notice in the Description page of Project Settings.


#include "VectorSolver.h"

VectorSolver::VectorSolver() {
}

VectorSolver::~VectorSolver() {
}

void VectorSolver::EnterDigit(int digit) {
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::FromInt(digit));
}
