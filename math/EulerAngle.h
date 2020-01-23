#pragma once
#include "vector.h"
#include  <cmath>

class EulerAngle {
public:
	EulerAngle():p(0),y(0),r(0) {}
	EulerAngle(float p_,float y_,float r_):p(p_),y(y_),r(r_){}

	Vector ToVector() const {
		Vector result;
		result.x = cos(y) * cos(p);
		result.y = sin(p);
		result.z = sin(y) * cos(p);

		return result;
	}
	void Normalize() {
		if (p > 89) p = 89.0f;
		if (p < -89) p = -89.0f;

		while (y < -180) y += 360;
		while (y > 180) y -= 360;

	}
public:
	float p, y, r;
};