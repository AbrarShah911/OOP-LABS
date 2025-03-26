#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigInteger {
private:
	vector<int> digits;
	bool isNegative;

public:
	BigInteger() : isNegative(false) {}
	BigInteger(const string &number);

	BigInteger operator+(const BigInteger &other) const;
	BigInteger operator-(const BigInteger &other) const;
	BigInteger operator*(const BigInteger &other) const;

	bool operator==(const BigInteger &other) const;
	bool operator!=(const BigInteger &other) const;
	bool operator<(const BigInteger &other) const;
	bool operator>(const BigInteger &other) const;

	friend ostream &operator<<(ostream &os, const BigInteger &num);
	friend istream &operator>>(istream &is, BigInteger &num);
};

BigInteger::BigInteger(const std::string &number) {
	isNegative = (number[0] == '-');
	for (int i = number.length() - 1; i >= (isNegative ? 1 : 0); i--) {
		digits.push_back(number[i] - '0');
	}
}

BigInteger BigInteger::operator+(const BigInteger &other) const {
	BigInteger result;
	int carry = 0, sum;
	size_t maxSize = std::max(digits.size(), other.digits.size());
	for (size_t i = 0; i < maxSize || carry; i++) {
		sum = carry;
		if (i < digits.size()) sum += digits[i];
		if (i < other.digits.size()) sum += other.digits[i];
		result.digits.push_back(sum % 10);
		carry = sum / 10;
	}
	return result;
}

ostream &operator<<(ostream &os, const BigInteger &num) {
	if (num.isNegative) os << "-";
	for (auto it = num.digits.rbegin(); it != num.digits.rend(); ++it) {
		os << *it;
	}
	return os;
}

istream &operator>>(istream &is, BigInteger &num) {
	string input;
	is >> input;
	num = BigInteger(input);
	return is;
}

int main() {
	BigInteger num1, num2;
	cout << "Enter two large numbers: ";
	cin >> num1 >> num2;

	BigInteger sum = num1 + num2;
	cout << "Sum: " << sum << endl;

	return 0;
}
