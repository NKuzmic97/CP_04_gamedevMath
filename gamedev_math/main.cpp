#include <iostream>

class Vector {
public:
	float x, y;
	//Vector3D float x,y,z;
};

class Point {
public:
	Point AddVector(Vector v) const;
	float x, y;
};

Point Point::AddVector(Vector v) const {
	return { x + v.x, y + v.y };
}


int main() {
	Point p = { 2,4 };
	Vector v = { -5,3 };
	Point newP = p.AddVector(v);
	std::cout << "New position: " << "x: " << newP.x << " , y: " << newP.y << std::endl;
	std::cin.get();
}