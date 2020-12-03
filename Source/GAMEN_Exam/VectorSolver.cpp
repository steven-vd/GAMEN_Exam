#include "VectorSolver.h"
#include <math.h>
#include <assert.h>

VectorSolver::VectorSolver() {
	this->Selected = Selectable::None;
	vecA = Vector(0, 0, 0);
	vecB = Vector(0, 0, 0);
	vecC = Vector(0, 0, 0);
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
	case Selectable::VecAz:
		vecA.z *= 10;
		vecA.z += digit;
		break;
	case Selectable::VecBx:
		vecB.x *= 10;
		vecB.x += digit;
		break;
	case Selectable::VecBy:
		vecB.y *= 10;
		vecB.y += digit;
		break;
	case Selectable::VecBz:
		vecB.z *= 10;
		vecB.z += digit;
		break;
	case Selectable::VecCx:
		vecC.x *= 10;
		vecC.x += digit;
		break;
	case Selectable::VecCy:
		vecC.y *= 10;
		vecC.y += digit;
		break;
	case Selectable::VecCz:
		vecC.z *= 10;
		vecC.z += digit;
		break;
	case Selectable::None:
	default:
		break;
	}
}

void VectorSolver::DotLeft() {
	switch (this->Selected) {
	case Selectable::VecAx:
		vecA.x /= 10;
		break;
	case Selectable::VecAy:
		vecA.y /= 10;
		break;
	case Selectable::VecAz:
		vecA.z /= 10;
		break;
	case Selectable::VecBx:
		vecB.x /= 10;
		break;
	case Selectable::VecBy:
		vecB.y /= 10;
		break;
	case Selectable::VecBz:
		vecB.z /= 10;
		break;
	case Selectable::VecCx:
		vecC.x /= 10;
		break;
	case Selectable::VecCy:
		vecC.y /= 10;
		break;
	case Selectable::VecCz:
		vecC.z /= 10;
		break;
	case Selectable::None:
	default:
		break;
	}
}

void VectorSolver::DotRight() {
	switch (this->Selected) {
	case Selectable::VecAx:
		vecA.x *= 10;
		break;
	case Selectable::VecAy:
		vecA.y *= 10;
		break;
	case Selectable::VecAz:
		vecA.z *= 10;
		break;
	case Selectable::VecBx:
		vecB.x *= 10;
		break;
	case Selectable::VecBy:
		vecB.y *= 10;
		break;
	case Selectable::VecBz:
		vecB.z *= 10;
		break;
	case Selectable::VecCx:
		vecC.x *= 10;
		break;
	case Selectable::VecCy:
		vecC.y *= 10;
		break;
	case Selectable::VecCz:
		vecC.z *= 10;
		break;
	case Selectable::None:
	default:
		break;
	}
}

void VectorSolver::InvertVector() {
	switch (this->Selected) {
	case Selectable::VecAx:
		vecA.x *= -1;
		break;
	case Selectable::VecAy:
		vecA.y *= -1;
		break;
	case Selectable::VecAz:
		vecA.z *= -1;
		break;
	case Selectable::VecBx:
		vecB.x *= -1;
		break;
	case Selectable::VecBy:
		vecB.y *= -1;
		break;
	case Selectable::VecBz:
		vecC.z *= -1;
		break;
	case Selectable::VecCx:
		vecC.x *= -1;
		break;
	case Selectable::VecCy:
		vecC.y *= -1;
		break;
	case Selectable::VecCz:
		vecB.z *= -1;
		break;
	case Selectable::None:
	default:
		break;
	}
}

void VectorSolver::ClearVector() {
	switch (this->Selected) {
	case Selectable::VecAx:
		vecA.x = 0;
		break;
	case Selectable::VecAy:
		vecA.y = 0;
		break;
	case Selectable::VecAz:
		vecA.z = 0;
		break;
	case Selectable::VecBx:
		vecB.x = 0;
		break;
	case Selectable::VecBy:
		vecB.y = 0;
		break;
	case Selectable::VecBz:
		vecB.z = 0;
		break;
	case Selectable::VecCx:
		vecC.x = 0;
		break;
	case Selectable::VecCy:
		vecC.y = 0;
		break;
	case Selectable::VecCz:
		vecC.z = 0;
		break;
	case Selectable::None:
	default:
		break;
	}
}

Vector::Vector() {
	assert(false);
}

Vector::Vector(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

double Vector::GetMagnitude() {
	return sqrt(x * x + y * y + z * z);
}

Vector Vector::GetNormalized() {
	return GetScaled(1.0 / GetMagnitude());
}

double Vector::GetDeterminent(Vector* other1, Vector* other2) {
	double det =
		x * (other1->y * other2->z - other2->y * other1->y) -
		other1->x * (y * other2->z - other2->y * z) +
		other2->x * (y * other1->z - other1->y * z);
	UE_LOG(LogTemp, Warning, TEXT("X: %ld, %ld, %ld"), x, y, z);
	UE_LOG(LogTemp, Warning, TEXT("Y: %ld, %ld, %ld"), other1->x, other1->y, other1->z);
	UE_LOG(LogTemp, Warning, TEXT("Z: %ld, %ld, %ld"), other2->x, other2->y, other2->z);
	UE_LOG(LogTemp, Warning, TEXT("Det: %ld"), det);
	return det;
}

double Vector::GetDeterminent2D(Vector* other) {
	return x * other->y - y * other->x;//2D
}

Vector Vector::GetScaled(double scalar) {
	return Vector(x * scalar, y * scalar, z * scalar);
}
