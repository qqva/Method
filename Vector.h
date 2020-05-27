#pragma once
#ifndef Vect_h
#define Vect_h
#include <cmath>
using namespace std;

class VC {
public:

	double X;
	double Y;
	double Z;
	double dot(const VC& vec) const {
		return X * vec.X + Y * vec.Y + Z * vec.Z;
	}
	double norm() const {
		return sqrt(dot(*this));
	}
	double norm2() const {
		return dot(*this);
	}
////////////////////////////////////////////////////////////////
	VC(double x, double y, double z) : X(x), Y(y), Z(z) {}

	VC operator +(const VC& vec) const {
		return VC(X + vec.X, Y + vec.Y, Z + vec.Z);
	}

	VC operator -(const VC& vec) const {
		return VC(X - vec.X, Y - vec.Y, Z - vec.Z);
	}

	VC operator *(double scalar) const {
		return VC(scalar * X, scalar * Y, scalar * Z);
	}

/////////////////////////////////////////////////////////
	VC directProduct(const VC& vec) const {
		return VC(vec.X * X, vec.Y * Y, vec.Z * Z);
	}

	VC crossProduct(const VC& vec) const {
		return VC(vec.Y * Z - vec.Z * Y, vec.Z * X - vec.X * Z, vec.X * Y - vec.Y * X);
	}

	VC normalize() {
		return (*this) * (1 / norm());
	}
/////////////////////////////////////////////////////////////////
};
#endif
