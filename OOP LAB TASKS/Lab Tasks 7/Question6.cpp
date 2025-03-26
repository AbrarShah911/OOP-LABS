#include <iostream>
using namespace std;

class Person {
protected:
	int employeeID;

public:
	void getData() {
		cout << "Enter Employee ID: ";
		cin >> employeeID;
	}
	
	void displayData() const {
		cout << "Employee ID: " << employeeID << endl;
	}
};

class Admin : public Person {
protected:
	string name;
	double monthlyIncome;

public:
	void getData() {
		Person::getData();
		cout << "Enter Name: ";
		cin >> name;
		cout << "Enter Monthly Income: ";
		cin >> monthlyIncome;
	}

	double bonus() const {
		return monthlyIncome * 0.05 * 12;
	}

	void displayData() const {
		Person::displayData();
		cout << "Name: " << name << endl;
		cout << "Monthly Income: " << monthlyIncome << endl;
		cout << "Annual Bonus: " << bonus() << endl;
	}
};

class Accounts : public Person {
protected:
	string name;
	double monthlyIncome;

public:
	void getData() {
		Person::getData();
		cout << "Enter Name: ";
		cin >> name;
		cout << "Enter Monthly Income: ";
		cin >> monthlyIncome;
	}

	double bonus() const {
		return monthlyIncome * 0.05 * 12;
	}

	void displayData() const {
		Person::displayData();
		cout << "Name: " << name << endl;
		cout << "Monthly Income: " << monthlyIncome << endl;
		cout << "Annual Bonus: " << bonus() << endl;
	}
};

int main() {
	Admin adminEmployee;
	Accounts accountsEmployee;

	cout << "Enter details for Admin Employee:\n";
	adminEmployee.getData();

	cout << "\nEnter details for Accounts Employee:\n";
	accountsEmployee.getData();

	cout << "\nEmployee Details:\n";
	adminEmployee.displayData();
	cout << endl;
	accountsEmployee.displayData();

	return 0;
}
