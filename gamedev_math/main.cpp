#include <iostream>

class Point;

class Vector {
public:
	float Length() const;
	float LengthSq() const;

	Vector operator*(float s) const;
	Vector operator/(float s) const;
	Vector operator-(const Vector& v) const;
	Vector operator+(const Vector& v) const;


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

Vector Vector::operator-(const Vector& v) const {
	return { x - v.x,y - v.y };
}

Vector Vector::operator+(const Vector& v) const {
	return { x + v.x,y + v.y };
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

float DotProduct(const Vector& a,const Vector& b) {
	return a.x * b.x + a.y * b.y;
}

int main() {
	Vector r{4,0};
	Vector d{ 0,-5 };

	Vector v = r + d;

	std::cout << "Pac-man's new velocity: (" << v.x << " ," << v.y << ")" << std::endl;
	
	std::cin.get();
}