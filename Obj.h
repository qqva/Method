#pragma once
#ifndef Objects_h
#define Objects_h
#include "Color.h"
#include "Vector.h"
#include "Luch.h"
#include <cmath>
#include <vector>
#include <iostream>
#include "float.h"

class Sphere{	
public:
	VC Center;
	double Radius;
	Color_cvet color;
	const double SELF_AVOID_T = 1e-2;
	Sphere(VC center, double radius, Color_cvet color) : Center(center), Radius(radius),color(color){}

	VC get_center() const {
		return Center;
	}

	VC get_normal(const VC& p) const {
		return ((p - Center) * (-1 / Radius)).normalize();
	}

//////////////////////////////////////////////////////////////////////////////////


	bool intersect(const Ray& ray, double& t) const {
		VC v = ray.origin - Center;

		const double b = 2 * v.dot(ray.direction);
		const double c = v.dot(v) - Radius * Radius;
		double delta = b * b - 4 * c;

		if (delta < 0) {
			t = FLT_MAX;// no intersection, at 'infinity'
			return false;
		}

		const double t1 = (-b - sqrt(delta)) / 2;
		const double t2 = (-b + sqrt(delta)) / 2;

		if (t2 < SELF_AVOID_T) {
			t = FLT_MAX;
			return false;
		}

		t = (t1 >= SELF_AVOID_T) ? t1 : t2;

		return true;
	}
};
#endif
