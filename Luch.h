#pragma once
#ifndef Ray_h
#define Ray_h
#include "Vector.h"

class Ray {
public:
	VC origin;
	VC direction;

	Ray(VC ori, VC dir) : origin(ori), direction(dir) {}

	VC get_point(double t) const {
		return origin + direction * t;
	}
	VC reflect_by(const VC& normal) const {
		return direction - normal * normal.dot(direction) * 2;
	}
};
#endif
