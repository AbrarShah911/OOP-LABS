#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
	string color;
	double positionX, positionY;
	double borderThickness;

public:
	Shape(double x, double y, string col, double border = 1.0)
		: positionX(x), positionY(y), color(col), borderThickness(border) {}

	//THE FOLLOWING ARE PURE VIRTUAL FUNCTIONS. EVERY DERIVED CLASS MUST HAVE THE IMPLEMENTATIONS OF THESE FUNCTIONS IN THEM.
	virtual void draw() = 0;
	virtual double calculateArea() = 0;
	virtual double calculatePerimeter() = 0;

	virtual ~Shape() {}
};

class Circle : public Shape {
private:
	double radius;

public:
	Circle(double x, double y, double r, string col)
		: Shape(x, y, col), radius(r) {}

	void draw() override {
		cout << "Drawing Circle at (" << positionX << ", " << positionY << ") with radius " << radius << " and color " << color << endl;
	}

	double calculateArea() override {
		return M_PI * radius * radius;
	}

	double calculatePerimeter() override {
		return 2 * M_PI * radius;
	}
};

class Rectangle : public Shape {
private:
	double width, height;

public:
	Rectangle(double x, double y, double w, double h, string col)
		: Shape(x, y, col), width(w), height(h) {}

	void draw() override {
		cout << "Drawing Rectangle at (" << positionX << ", " << positionY << ") with width " << width << " and height " << height << " and color " << color << endl;
	}

	double calculateArea() override {
		return width * height;
	}

	double calculatePerimeter() override {
		return 2 * (width + height);
	}
};

class Triangle : public Shape {
private:
	double sideA, sideB, sideC;

public:
	Triangle(double x, double y, double a, double b, double c, string col)
		: Shape(x, y, col), sideA(a), sideB(b), sideC(c) {}

	void draw() override {
		cout << "Drawing Triangle at (" << positionX << ", " << positionY << ") with sides " << sideA << ", " << sideB << ", " << sideC << " and color " << color << endl;
	}

	double calculateArea() override {
		double s = (sideA + sideB + sideC) / 2;
		return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
	}

	double calculatePerimeter() override {
		return sideA + sideB + sideC;
	}
};

int main() {
	Circle c(5, 5, 10, "Like What is color even Red.");
	Rectangle r(0, 0, 20, 15, "The weird blue that apple names their phone color");
	Triangle t(2, 2, 3, 4, 5, "Tarnished green");

	c.draw();
	cout << "Area: " << c.calculateArea() << " | Perimeter: " << c.calculatePerimeter() << endl;

	r.draw();
	cout << "Area: " << r.calculateArea() << " | Perimeter: " << r.calculatePerimeter() << endl;

	t.draw();
	cout << "Area: " << t.calculateArea() << " | Perimeter: " << t.calculatePerimeter() << endl;

	return 0;
}