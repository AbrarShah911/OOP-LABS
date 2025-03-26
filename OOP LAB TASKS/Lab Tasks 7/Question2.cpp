#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Polynomial; // FORWARD DECLARATION TO USE FRIEND CLASS!


class PolynomialUtils { // FRIEND CLASS WITH TWO STATIC FUNCTIONS TO USE LATER ON
public:
	static int evaluate(const Polynomial &p, int x);
	static Polynomial derivative(const Polynomial &p);
};

class Polynomial {
private:
	vector<int> coefficients;

public:
	friend class PolynomialUtils;

	Polynomial() {}

	Polynomial(const vector<int>& coeffs) : coefficients(coeffs) {}

	// Addition operator
	Polynomial operator+(const Polynomial& other) const {
		size_t maxSize = max(coefficients.size(), other.coefficients.size());
		vector<int> result(maxSize, 0);
		
		for (size_t i = 0; i < coefficients.size(); ++i)
			result[i] += coefficients[i];
		
		for (size_t i = 0; i < other.coefficients.size(); ++i)
			result[i] += other.coefficients[i];
		
		return Polynomial(result);
	}

	// Subtraction operator
	Polynomial operator-(const Polynomial& other) const {
		size_t maxSize = max(coefficients.size(), other.coefficients.size());
		vector<int> result(maxSize, 0);
		
		for (size_t i = 0; i < coefficients.size(); ++i)
			result[i] += coefficients[i];
		
		for (size_t i = 0; i < other.coefficients.size(); ++i)
			result[i] -= other.coefficients[i];
		
		return Polynomial(result);
	}

	// Multiplication operator
	Polynomial operator*(const Polynomial& other) const {
		vector<int> result(coefficients.size() + other.coefficients.size() - 1, 0);
		
		for (size_t i = 0; i < coefficients.size(); ++i) {
			for (size_t j = 0; j < other.coefficients.size(); ++j) {
				result[i + j] += coefficients[i] * other.coefficients[j];
			}
		}
		return Polynomial(result);
	}

	friend ostream& operator<<(ostream& os, const Polynomial& p) {
		bool first = true;
		for (int i = p.coefficients.size() - 1; i >= 0; --i) {
			if (p.coefficients[i] != 0) {
				if (!first) os << " ";
				if (p.coefficients[i] > 0 && !first) os << "+ ";
				if (p.coefficients[i] < 0) os << "- ";
				os << abs(p.coefficients[i]);
				if (i > 0) os << "x^" << i;
				first = false;
			}
		}
		if (first) os << "0"; 
		return os;
	}
};

int PolynomialUtils::evaluate(const Polynomial &p, int x) {
	int result = 0;
	for (size_t i = 0; i < p.coefficients.size(); ++i) {
		result += p.coefficients[i] * pow(x, i);
	}
	return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial &p) {
	if (p.coefficients.size() <= 1) return Polynomial({0});
	
	vector<int> deriv(p.coefficients.size() - 1);
	for (size_t i = 1; i < p.coefficients.size(); ++i) {
		deriv[i - 1] = p.coefficients[i] * i;
	}
	return Polynomial(deriv);
}

int main() {
	Polynomial p1({3, 0, 5});  // 3 + 0x + 5x^2
	Polynomial p2({1, 2, 4});  // 1 + 2x + 4x^2

	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;

	cout << "p1 + p2: " << (p1 + p2) << endl;
	cout << "p1 - p2: " << (p1 - p2) << endl;
	cout << "p1 * p2: " << (p1 * p2) << endl;

	cout << "p1 evaluated at x=2: " << PolynomialUtils::evaluate(p1, 2) << endl;
	cout << "Derivative of p1: " << PolynomialUtils::derivative(p1) << endl;
	
	return 0;
}