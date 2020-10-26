// Fill out your copyright notice in the Description page of Project Settings.


#include "VectorSolver.h"
#include <math.h>
#include <assert.h>

VectorSolver::VectorSolver() {
	this->Selected = Selectable::None;
	vecA = Vector(0, 0);
	vecB = Vector(0, 0);
}

VectorSolver::~VectorSolver() {
}

void VectorSolver::EnterDigit(int digit) {
	switch (this->Selected) {
	case Selectable::VecAx:
		vecA.x *= 10;
		vecA.x += digit;
		break;
	case Selectable::VecAy:
		vecA.y *= 10;
		vecA.y += digit;
		break;
	case Selectable::VecBx:
		vecB.x *= 10;
		vecB.x += digit;
		break;
	case Selectable::VecBy:
		vecB.y *= 10;
		vecB.y += digit;
		break;
	case Selectable::None:
	default:
		break;
	}
}

void VectorSolver::ClearVector() {
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
