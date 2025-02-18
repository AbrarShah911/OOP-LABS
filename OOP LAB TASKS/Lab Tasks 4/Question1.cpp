#include <iostream>
#include <cmath>
using namespace std;

class Circle {
private:
    double radius;

public:

	Circle(double r) : radius(r) {}

	double getArea() {
		return M_PI * radius * radius;
	}


	double getPerimeter() {
		return 2 * M_PI * radius;
	}
};

int main() {
    double r;
	cout << "Enter radius: ";
	cin >> r;
    
    Circle c(r);
    
	cout << "Area: " << c.getArea() << endl;
	cout << "Perimeter: " << c.getPerimeter() << endl;
    
    return 0;
}