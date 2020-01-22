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

Vector operator-(Point a,Point b) {
	return { a.x - b.x,a.y - b.y };
}

int main() {
	Point p{ 0,-1 };
	Point i{ 1,1 };

	Vector v{ p - i };

	std::cout << "Result: " << "< " << v.x << ", " << v.y << " >" << std::endl;
	std::cin.get();
}