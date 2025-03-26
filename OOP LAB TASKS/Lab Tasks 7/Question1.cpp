#include <iostream>
#include <string>
#include <numeric>
using namespace std;

class Fraction{
protected:
	int denominator;
	int numerator;

	void reduce() {
	    int g = gcd(numerator, denominator);
	    numerator /= g;
	    denominator /= g;
	    
	    if (denominator < 0) {
	        numerator = -numerator;
	        denominator = -denominator;
	    }
    }

public:

    Fraction(int num = 1, int denom = 1) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        reduce();
    }

    friend Fraction operator+(const Fraction& f1, const Fraction& f2);
    friend Fraction operator-(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);	
    friend Fraction operator/(const Fraction& f1, const Fraction& f2);	
 	friend bool operator==(const Fraction& f1, const Fraction& f2);
    friend bool operator!=(const Fraction& f1, const Fraction& f2);
    friend bool operator<(const Fraction& f1, const Fraction& f2);
    friend bool operator>(const Fraction& f1, const Fraction& f2);
    friend bool operator<=(const Fraction& f1, const Fraction& f2);
    friend bool operator>=(const Fraction& f1, const Fraction& f2);
    friend ostream& operator<<(ostream& os, const Fraction& f);
    friend istream& operator>>(istream& is, Fraction& f);


    void print() const {
        cout << numerator << "/" << denominator << endl;
    }
};

Fraction operator+(const Fraction& f1, const Fraction& f2) {
    int num = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    int denom = f1.denominator * f2.denominator;
    return Fraction(num, denom);
}

Fraction operator-(const Fraction& f1, const Fraction& f2) {
    int num = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    int denom = f1.denominator * f2.denominator;
    return Fraction(num, denom);
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
    int num = f1.numerator * f2.numerator;
    int denom = f1.denominator * f2.denominator;
    return Fraction(num, denom);
}

Fraction operator/(const Fraction& f1, const Fraction& f2) {
    if (f2.numerator == 0) {
        throw std::invalid_argument("Cannot divide by zero.");
    }
    int num = f1.numerator * f2.denominator;
    int denom = f1.denominator * f2.numerator;
    return Fraction(num, denom);
}

bool operator==(const Fraction& f1, const Fraction& f2) {
    return (f1.numerator == f2.numerator) && (f1.denominator == f2.denominator);
}

bool operator!=(const Fraction& f1, const Fraction& f2) {
    return !(f1 == f2);
}

bool operator<(const Fraction& f1, const Fraction& f2) {
    return (f1.numerator * f2.denominator < f2.numerator * f1.denominator);
}

bool operator>(const Fraction& f1, const Fraction& f2) {
    return (f1.numerator * f2.denominator > f2.numerator * f1.denominator);
}

bool operator<=(const Fraction& f1, const Fraction& f2) {
    return (f1 < f2) || (f1 == f2);
}

bool operator>=(const Fraction& f1, const Fraction& f2) {
    return (f1 > f2) || (f1 == f2);
}

ostream& operator<<(ostream& os, const Fraction& f) {
    os << f.numerator << "/" << f.denominator;
    return os;
}

istream& operator>>(istream& is, Fraction& f) {
    char slash; // To read the '/' character
    is >> f.numerator >> slash >> f.denominator;

    if (f.denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }

    f.reduce();
    return is;
}


int main(){

	Fraction f1;
	Fraction f2;
    
    cout << "Enter first fraction (format: a/b): ";
    cin >> f1;

    cout << "Enter second fraction (format: a/b): ";
    cin >> f2;

    cout << "You entered:\n";
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

	cout << "f1 + f2 = " << (f1 + f2) << endl;
	cout << "f1 - f2 = " << (f1 - f2) << endl;
	cout << "f1 * f2 = " << (f1 * f2) << endl;
	cout << "f1 / f2 = " << (f1 / f2) << endl;

	cout << boolalpha;
	cout << "f1 == f2: " << (f1 == f2) << endl;
	cout << "f1 != f2: " << (f1 != f2) << endl;
	cout << "f1 < f2: " << (f1 < f2) << endl;
	cout << "f1 > f2: " << (f1 > f2) << endl;
	cout << "f1 <= f2: " << (f1 <= f2) << endl;
	cout << "f1 >= f2: " << (f1 >= f2) << endl;


	return 0;
}