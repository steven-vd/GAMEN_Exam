// Fill out your copyright notice in the Description page of Project Settings.


#include "VectorSolver.h"
#include <math.h>
#include <assert.h>

VectorSolver::VectorSolver() {
	vecA = Vector(0, 0);
	vecB = Vector(0, 0);
}

VectorSolver::~VectorSolver() {
}

void VectorSolver::EnterDigit(int digit) {
	//DEBUG
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::FromInt(digit));

	this->Selected = Selectable::None;
}

Vector::Vector() {
	assert(false);
}

Vector::Vector(double x, double y) {
	this->x = x;
	this->y = y;
}

double Vector::GetMagnitude() {
	return sqrt(x * x + y * y);
}

Vector Vector::GetNormalized() {
	return GetScaled(1.0 / GetMagnitude());
}

double Vector::GetDeterminent(Vector* other) {
	return x * other->y - y * other->x;
}

Vector Vector::GetScaled(double scalar) {
	return Vector(x * scalar, y * scalar);
}
