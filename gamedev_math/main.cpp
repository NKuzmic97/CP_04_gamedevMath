#include <iostream>

class Point;

class Vector {
public:
	float Length() const;
	float LengthSq() const;

	Vector operator*(float s) const;
	Vector operator/(float s) const;

	Vector Normalized() const;

	float x, y;
	//Vector3D float x,y,z;
};

class Point {
public:
	Point AddVector(Vector v) const;
	float x, y;
};

float Vector::Length() const {
	return sqrt(x * x + y * y);
}

float Vector::LengthSq() const {
	return (x * x + y * y);
}

Vector Vector::operator*(float s) const {
	return { x*s,y*s };
}

Vector Vector::operator/(float s) const {
	return { x / s,y / s };
}

Vector Vector::Normalized() const {
	return (*this) / Length();
}


Point Point::AddVector(Vector v) const {
	return { x + v.x, y + v.y };
}

Vector operator-(Point a,Point b) {
	return { a.x - b.x,a.y - b.y };
}

int main() {
	Point i{ 3,4 };
	Point p{ 1,2 };

	Vector pi = i - p;
	Vector normalized = pi.Normalized();

	std::cout << "Pac-man's view vector: (" << normalized.x << ", " << normalized.y << ") " << std::endl;

	std::cout << "Pac-man's view vector length: " << normalized.Length() << std::endl;
	
	std::cin.get();
}