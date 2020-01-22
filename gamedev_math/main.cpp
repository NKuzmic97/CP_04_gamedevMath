#include <iostream>

class Vector {
public:
	float Length() const;
	float LengthSqr() const;
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

float Vector::LengthSqr() const {
	return (x * x + y * y);
}

Point Point::AddVector(Vector v) const {
	return { x + v.x, y + v.y };
}

Vector operator-(Point a,Point b) {
	return { a.x - b.x,a.y - b.y };
}

int main() {
	Point p{ 0,-1 };
	Point i{ 1,1 };
	Point c{ 2,-1 };

	Vector ip{ p - i };
	Vector cp{ p - c };

	float lenSqrCP = cp.LengthSqr();
	float lenSqrIP = ip.LengthSqr();

	std::cout << "Length squared of CP: " << lenSqrCP << std::endl;
	std::cout << "Length squared of IP: " << lenSqrIP << std::endl;

	std::cout << "Closer is " << ((lenSqrCP < lenSqrIP) ? "Clyde.":"Inky.") << std::endl;
	
	std::cin.get();
}