#include <iostream>
using namespace std;

class Number {
private:
	int value;

public:
	Number(int val) : value(val) {}

	Number &operator--() {
		value *= 4;
		return *this;
	}

	Number operator--(int) {
		Number temp = *this;
		value /= 4;
		return temp;
	}

	void display() const {
		cout << "Value: " << value << std::endl;
	}
};

int main() {
	Number num(44);

	cout << "Initial: ";
	num.display();

	--num;
	cout << "After prefix decrement (--num): ";
	num.display();

	num--;
	cout << "After postfix decrement (num--): ";
	num.display();

	return 0;
}