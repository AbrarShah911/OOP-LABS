#include <iostream>
using namespace std;

class Shape {
private:
	double area;

public:
	Shape(double a) : area(a) {}

	Shape operator+(const Shape &other) const {
		return Shape(this->area + other.area);
	}

	void display() const {
		cout << "Area: " << area << endl;
	}
};

int main() {
	Shape shape1(25.5), shape2(30.7);

	cout << "Shape 1: ";
	shape1.display();
	cout << "Shape 2: ";
	shape2.display();

	Shape totalArea = shape1 + shape2;
	cout << "Total Area: ";
	totalArea.display();

	return 0;
}