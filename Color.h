#pragma once
#ifndef Color_h
#define Color_h

class Color_cvet {

public:
	int r, g, b;
	Color_cvet(int red, int green, int blue) : r(red), g(green), b(blue) {}

	Color_cvet scale_by(double scalar)const {
		return (scalar > 0) ? Color_trunc(scalar * r, scalar * g, scalar * b) : Color_cvet(0, 0, 0);
	}
	Color_cvet scale_by2(double scalar)const {
		if (scalar < 0)
			return  Color_cvet(0, 0, 0);
		scalar *= scalar;
		return Color_trunc(scalar * r, scalar * g, scalar * b);
	}
	Color_cvet mix_with(const Color_cvet& rhs) const {
		return Color_cvet(r * rhs.r, g * rhs.g, b * rhs.b);
	}
	Color_cvet operator *(double scalar)const {
		return Color_cvet(scalar * r, scalar * g, scalar * b);
	}
	Color_cvet operator +(const Color_cvet& rhs) const {
		return Color_trunc(r + rhs.r, g + rhs.g, b + rhs.b);
	}
	
	
	
	///////////////////////////////////////////////////
	static int trunc(int val) {
		return (val > 255) ? 255 : val;
	}
	static Color_cvet Color_trunc(int red, int green, int blue) {
		return Color_cvet(trunc(red), trunc(green), trunc(blue));
	}
};

#endif
