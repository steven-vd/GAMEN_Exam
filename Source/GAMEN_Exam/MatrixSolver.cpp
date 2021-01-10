#include "MatrixSolver.h"

#include "assert.h"

MatrixSolver::MatrixSolver() {
	MatA = Matrix3(Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 1));
	MatB = Matrix3(Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 1));
	MatC = Matrix2(Vector(1, 0, 0), Vector(0, 1, 0));
	MatD = Matrix2(Vector(1, 0, 0), Vector(0, 1, 0));
}

MatrixSolver::~MatrixSolver() {
}

void MatrixSolver::EnterDigit(int digit) {
	switch (this->Selected) {
	case Selectable::MatA11:
		MatA.vecA.x *= 10;
		MatA.vecA.x += digit;
		break;
	case Selectable::MatA21:
		MatA.vecA.y *= 10;
		MatA.vecA.y += digit;
		break;
	case Selectable::MatA31:
		MatA.vecA.z *= 10;
		MatA.vecA.z = digit;
		break;
	case Selectable::MatA12:
		MatA.vecB.x *= 10;
		MatA.vecB.x += digit;
		break;
	case Selectable::MatA22:
		MatA.vecB.y *= 10;
		MatA.vecB.y += digit;
		break;
	case Selectable::MatA32:
		MatA.vecB.z *= 10;
		MatA.vecB.z += digit;
		break;
	case Selectable::MatA13:
		MatA.vecC.x *= 10;
		MatA.vecC.x += digit;
		break;
	case Selectable::MatA23:
		MatA.vecC.y *= 10;
		MatA.vecC.y += digit;
		break;
	case Selectable::MatA33:
		MatA.vecC.z *= 10;
		MatA.vecC.z += digit;
		break;

	case Selectable::MatB11:
		MatB.vecA.x *= 10;
		MatB.vecA.x += digit;
		break;
	case Selectable::MatB21:
		MatB.vecA.y *= 10;
		MatB.vecA.y += digit;
		break;
	case Selectable::MatB31:
		MatB.vecA.z *= 10;
		MatB.vecA.z = digit;
		break;
	case Selectable::MatB12:
		MatB.vecB.x *= 10;
		MatB.vecB.x += digit;
		break;
	case Selectable::MatB22:
		MatB.vecB.y *= 10;
		MatB.vecB.y += digit;
		break;
	case Selectable::MatB32:
		MatB.vecB.z *= 10;
		MatB.vecB.z += digit;
		break;
	case Selectable::MatB13:
		MatB.vecC.x *= 10;
		MatB.vecC.x += digit;
		break;
	case Selectable::MatB23:
		MatB.vecC.y *= 10;
		MatB.vecC.y += digit;
		break;
	case Selectable::MatB33:
		MatB.vecC.z *= 10;
		MatB.vecC.z += digit;
		break;

	case Selectable::MatC11:
		MatC.vecA.x *= 10;
		MatC.vecA.x += digit;
		break;
	case Selectable::MatC21:
		MatC.vecA.y *= 10;
		MatC.vecA.y += digit;
		break;
	case Selectable::MatC12:
		MatC.vecB.x *= 10;
		MatC.vecB.x += digit;
		break;
	case Selectable::MatC22:
		MatC.vecB.y *= 10;
		MatC.vecB.y += digit;
		break;

	case Selectable::MatD11:
		MatD.vecA.x *= 10;
		MatD.vecA.x += digit;
		break;
	case Selectable::MatD21:
		MatD.vecA.y *= 10;
		MatD.vecA.y += digit;
		break;
	case Selectable::MatD12:
		MatD.vecB.x *= 10;
		MatD.vecB.x += digit;
		break;
	case Selectable::MatD22:
		MatD.vecB.y *= 10;
		MatD.vecB.y += digit;
		break;

	case Selectable::None:
	default:
		break;
	}
}

void MatrixSolver::Clear() {
	switch (this->Selected) {
	case Selectable::MatA11:
		MatA.vecA.x = 0;
		break;
	case Selectable::MatA21:
		MatA.vecA.y = 0;
		break;
	case Selectable::MatA31:
		MatA.vecA.z = 0;
		break;
	case Selectable::MatA12:
		MatA.vecB.x = 0;
		break;
	case Selectable::MatA22:
		MatA.vecB.y = 0;
		break;
	case Selectable::MatA32:
		MatA.vecB.z = 0;
		break;
	case Selectable::MatA13:
		MatA.vecC.x = 0;
		break;
	case Selectable::MatA23:
		MatA.vecC.y = 0;
		break;
	case Selectable::MatA33:
		MatA.vecC.z = 0;
		break;

	case Selectable::MatB11:
		MatB.vecA.x = 0;
		break;
	case Selectable::MatB21:
		MatB.vecA.y = 0;
		break;
	case Selectable::MatB31:
		MatB.vecA.z = 0;
		break;
	case Selectable::MatB12:
		MatB.vecB.x = 0;
		break;
	case Selectable::MatB22:
		MatB.vecB.y = 0;
		break;
	case Selectable::MatB32:
		MatB.vecB.z = 0;
		break;
	case Selectable::MatB13:
		MatB.vecC.x = 0;
		break;
	case Selectable::MatB23:
		MatB.vecC.y = 0;
		break;
	case Selectable::MatB33:
		MatB.vecC.z = 0;
		break;

	case Selectable::MatC11:
		MatC.vecA.x = 0;
		break;
	case Selectable::MatC21:
		MatC.vecA.y = 0;
		break;
	case Selectable::MatC12:
		MatC.vecB.x = 0;
		break;
	case Selectable::MatC22:
		MatC.vecB.y = 0;
		break;

	case Selectable::MatD11:
		MatD.vecA.x = 0;
		break;
	case Selectable::MatD21:
		MatD.vecA.y = 0;
		break;
	case Selectable::MatD12:
		MatD.vecB.x = 0;
		break;
	case Selectable::MatD22:
		MatD.vecB.y = 0;
		break;

	case Selectable::None:
	default:
		break;
	}
}

void MatrixSolver::Invert() {
	switch (this->Selected) {
	case Selectable::MatA11:
		MatA.vecA.x *= -1;
		break;
	case Selectable::MatA21:
		MatA.vecA.y *= -1;
		break;
	case Selectable::MatA31:
		MatA.vecA.z *= -1;
		break;
	case Selectable::MatA12:
		MatA.vecB.x *= -1;
		break;
	case Selectable::MatA22:
		MatA.vecB.y *= -1;
		break;
	case Selectable::MatA32:
		MatA.vecB.z *= -1;
		break;
	case Selectable::MatA13:
		MatA.vecC.x *= -1;
		break;
	case Selectable::MatA23:
		MatA.vecC.y *= -1;
		break;
	case Selectable::MatA33:
		MatA.vecC.z *= -1;
		break;

	case Selectable::MatB11:
		MatB.vecA.x *= -1;
		break;
	case Selectable::MatB21:
		MatB.vecA.y *= -1;
		break;
	case Selectable::MatB31:
		MatB.vecA.z *= -1;
		break;
	case Selectable::MatB12:
		MatB.vecB.x *= -1;
		break;
	case Selectable::MatB22:
		MatB.vecB.y *= -1;
		break;
	case Selectable::MatB32:
		MatB.vecB.z *= -1;
		break;
	case Selectable::MatB13:
		MatB.vecC.x *= -1;
		break;
	case Selectable::MatB23:
		MatB.vecC.y *= -1;
		break;
	case Selectable::MatB33:
		MatB.vecC.z *= -1;
		break;

	case Selectable::MatC11:
		MatC.vecA.x *= -1;
		break;
	case Selectable::MatC21:
		MatC.vecA.y *= -1;
		break;
	case Selectable::MatC12:
		MatC.vecB.x *= -1;
		break;
	case Selectable::MatC22:
		MatC.vecB.y *= -1;
		break;

	case Selectable::MatD11:
		MatD.vecA.x *= -1;
		break;
	case Selectable::MatD21:
		MatD.vecA.y *= -1;
		break;
	case Selectable::MatD12:
		MatD.vecB.x *= -1;
		break;
	case Selectable::MatD22:
		MatD.vecB.y *= -1;
		break;

	case Selectable::None:
	default:
		break;
	}

}

void MatrixSolver::DotRight() {
	switch (this->Selected) {
	case Selectable::MatA11:
		MatA.vecA.x *= 10;
		break;
	case Selectable::MatA21:
		MatA.vecA.y *= 10;
		break;
	case Selectable::MatA31:
		MatA.vecA.z *= 10;
		break;
	case Selectable::MatA12:
		MatA.vecB.x *= 10;
		break;
	case Selectable::MatA22:
		MatA.vecB.y *= 10;
		break;
	case Selectable::MatA32:
		MatA.vecB.z *= 10;
		break;
	case Selectable::MatA13:
		MatA.vecC.x *= 10;
		break;
	case Selectable::MatA23:
		MatA.vecC.y *= 10;
		break;
	case Selectable::MatA33:
		MatA.vecC.z *= 10;
		break;

	case Selectable::MatB11:
		MatB.vecA.x *= 10;
		break;
	case Selectable::MatB21:
		MatB.vecA.y *= 10;
		break;
	case Selectable::MatB31:
		MatB.vecA.z *= 10;
		break;
	case Selectable::MatB12:
		MatB.vecB.x *= 10;
		break;
	case Selectable::MatB22:
		MatB.vecB.y *= 10;
		break;
	case Selectable::MatB32:
		MatB.vecB.z *= 10;
		break;
	case Selectable::MatB13:
		MatB.vecC.x *= 10;
		break;
	case Selectable::MatB23:
		MatB.vecC.y *= 10;
		break;
	case Selectable::MatB33:
		MatB.vecC.z *= 10;
		break;

	case Selectable::MatC11:
		MatC.vecA.x *= 10;
		break;
	case Selectable::MatC21:
		MatC.vecA.y *= 10;
		break;
	case Selectable::MatC12:
		MatC.vecB.x *= 10;
		break;
	case Selectable::MatC22:
		MatC.vecB.y *= 10;
		break;

	case Selectable::MatD11:
		MatD.vecA.x *= 10;
		break;
	case Selectable::MatD21:
		MatD.vecA.y *= 10;
		break;
	case Selectable::MatD12:
		MatD.vecB.x *= 10;
		break;
	case Selectable::MatD22:
		MatD.vecB.y *= 10;
		break;

	case Selectable::None:
	default:
		break;
	}
}

void MatrixSolver::DotLeft() {
	switch (this->Selected) {
	case Selectable::MatA11:
		MatA.vecA.x /= 10;
		break;
	case Selectable::MatA21:
		MatA.vecA.y /= 10;
		break;
	case Selectable::MatA31:
		MatA.vecA.z /= 10;
		break;
	case Selectable::MatA12:
		MatA.vecB.x /= 10;
		break;
	case Selectable::MatA22:
		MatA.vecB.y /= 10;
		break;
	case Selectable::MatA32:
		MatA.vecB.z /= 10;
		break;
	case Selectable::MatA13:
		MatA.vecC.x /= 10;
		break;
	case Selectable::MatA23:
		MatA.vecC.y /= 10;
		break;
	case Selectable::MatA33:
		MatA.vecC.z /= 10;
		break;

	case Selectable::MatB11:
		MatB.vecA.x /= 10;
		break;
	case Selectable::MatB21:
		MatB.vecA.y /= 10;
		break;
	case Selectable::MatB31:
		MatB.vecA.z /= 10;
		break;
	case Selectable::MatB12:
		MatB.vecB.x /= 10;
		break;
	case Selectable::MatB22:
		MatB.vecB.y /= 10;
		break;
	case Selectable::MatB32:
		MatB.vecB.z /= 10;
		break;
	case Selectable::MatB13:
		MatB.vecC.x /= 10;
		break;
	case Selectable::MatB23:
		MatB.vecC.y /= 10;
		break;
	case Selectable::MatB33:
		MatB.vecC.z /= 10;
		break;

	case Selectable::MatC11:
		MatC.vecA.x /= 10;
		break;
	case Selectable::MatC21:
		MatC.vecA.y /= 10;
		break;
	case Selectable::MatC12:
		MatC.vecB.x /= 10;
		break;
	case Selectable::MatC22:
		MatC.vecB.y /= 10;
		break;

	case Selectable::MatD11:
		MatD.vecA.x /= 10;
		break;
	case Selectable::MatD21:
		MatD.vecA.y /= 10;
		break;
	case Selectable::MatD12:
		MatD.vecB.x /= 10;
		break;
	case Selectable::MatD22:
		MatD.vecB.y /= 10;
		break;

	case Selectable::None:
	default:
		break;
	}
}

Matrix3 Matrix3::Add(Matrix3 other) {
	return Matrix3(
		Vector(vecA.x + other.vecA.x, vecA.y + other.vecA.y, vecA.z + other.vecA.z),
		Vector(vecB.x + other.vecB.x, vecB.y + other.vecB.y, vecB.z + other.vecB.z),
		Vector(vecC.x + other.vecC.x, vecC.y + other.vecC.y, vecC.z + other.vecC.z)
	);
}

Matrix3 Matrix3::Sub(Matrix3 other) {
	return Matrix3(
		Vector(vecA.x - other.vecA.x, vecA.y - other.vecA.y, vecA.z - other.vecA.z),
		Vector(vecB.x - other.vecB.x, vecB.y - other.vecB.y, vecB.z - other.vecB.z),
		Vector(vecC.x - other.vecC.x, vecC.y - other.vecC.y, vecC.z - other.vecC.z)
	);
}

Matrix3 Matrix3::Mul(Matrix3 other) {
	return Matrix3(
		Vector(
			vecA.x * other.vecA.x + vecA.y * other.vecB.x + vecA.z * other.vecC.x,
			vecA.x * other.vecA.y + vecA.y * other.vecB.y + vecA.z * other.vecC.y,
			vecA.x * other.vecA.z + vecA.y * other.vecB.z + vecA.z * other.vecC.z
		),
		Vector(
			vecB.x * other.vecA.x + vecB.y * other.vecB.x + vecB.z * other.vecC.x,
			vecB.x * other.vecA.y + vecB.y * other.vecB.y + vecB.z * other.vecC.y,
			vecB.x * other.vecA.z + vecB.y * other.vecB.z + vecB.z * other.vecC.z
		),
		Vector(
			vecC.x * other.vecA.x + vecC.y * other.vecB.x + vecC.z * other.vecC.x,
			vecC.x * other.vecA.y + vecC.y * other.vecB.y + vecC.z * other.vecC.y,
			vecC.x * other.vecA.z + vecC.y * other.vecB.z + vecC.z * other.vecC.z
		)
	);
}

double Matrix3::ComputeDeterminant() {
	return vecA.GetDeterminent(&vecB, &vecC);
}


Matrix2 Matrix2::Add(Matrix2 other) {
	return Matrix2(
		Vector(vecA.x + other.vecA.x, vecA.y + other.vecA.y, 0),
		Vector(vecB.x + other.vecB.x, vecB.y + other.vecB.y, 0)
	);
}

Matrix2 Matrix2::Sub(Matrix2 other) {
	return Matrix2(
		Vector(vecA.x - other.vecA.x, vecA.y - other.vecA.y, 0),
		Vector(vecB.x - other.vecB.x, vecB.y - other.vecB.y, 0)
	);
}

Matrix2 Matrix2::Mul(Matrix2 other) {
	return Matrix2(
		Vector(
			vecA.x * other.vecA.x + vecA.y * other.vecB.x,
			vecA.x * other.vecA.y + vecA.y * other.vecB.y,
			0
		),
		Vector(
			vecB.x * other.vecA.x + vecB.y * other.vecB.x,
			vecB.x * other.vecA.y + vecB.y * other.vecB.y,
			0
		)
	);
}

double Matrix2::ComputeDeterminant() {
	return vecA.GetDeterminent2D(&vecB);
}

Matrix3::Matrix3() {
	assert(false);
}

Matrix3::Matrix3(Vector vecA, Vector vecB, Vector vecC) {
	this->vecA = vecA;
	this->vecB = vecB;
	this->vecC = vecC;
}

Matrix2::Matrix2() {
	assert(false);
}

Matrix2::Matrix2(Vector vecA, Vector vecB) {
	this->vecA = vecA;
	this->vecB = vecB;
}
