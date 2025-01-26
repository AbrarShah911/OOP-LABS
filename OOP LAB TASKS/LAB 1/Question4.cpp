#include <iostream>
#include <iomanip>

int main() {
	double kg, pounds;

	std::cout << "Enter the weight in kilograms: ";
	std::cin >> kg;

	pounds = kg * 2.2;

	std::cout << std::fixed << std::setprecision(2);

	std::cout << "Weight in kilograms: " << kg << " kg" << std::endl;
	std::cout << "Equivalent weight in pounds: " << pounds << " lbs" << std::endl;

	return 0;
}
