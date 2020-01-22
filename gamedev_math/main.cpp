#include <iostream>

class Point;

class Vector {
public:
	float Length() const;
	float LengthSq() const;

	Vector operator*(float s) const;
	Vector operator/(float s) const;
	

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


Point Point::AddVector(Vector v) const {
	return { x + v.x, y + v.y };
}

Vector operator-(Point a,Point b) {
	return { a.x - b.x,a.y - b.y };
}

int main() {
	Vector v{ 3,4 };
	std::cout << "Pac-man initial speed: " << v.Length() << std::endl;
	Vector vDouble = v * 2;
	std::cout << "Pac-man double speed: " << vDouble.Length() << std::endl;
	Vector vHalf = v / 2;
	std::cout << "Pac-man half speed: " << vHalf.Length() << std::endl;
	std::cin.get();
}