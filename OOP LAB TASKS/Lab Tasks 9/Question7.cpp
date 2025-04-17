#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
	string name;
	float salary;

public:
	virtual void getData() {
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter salary: ";
		cin >> salary;
	}

	virtual void displayData() {
		cout << "Name: " << name << ", Salary: " << salary << endl;
	}

	virtual void bonus() = 0; // Pure virtual function
	virtual ~Person() {}
};

class Admin : virtual public Person {
public:
	void getData() override {
		cout << "Please Enter Admin Info: \n";
		Person::getData();
	}

	void displayData() override {
		cout << "Displaying Admin Info:\n";
		Person::displayData();
	}

	void bonus() override {
		cout << "Admin Bonus: " << (salary * 0.10f) << endl;
	}
};

class Account : virtual public Person {
public:
	void getData() override {
		cout << "Please Enter Account Info:\n";
		Person::getData();
	}

	void displayData() override {
		cout << "Displaying Account Info:\n";
		Person::displayData();
	}

	void bonus() override {
		cout << "Account Bonus: " << (salary * 0.08f) << endl;
	}
};

class Master : public Admin, public Account {
public:
	void getData() override {
		cout << "Please Enter Master Info:\n";
		Person::getData();
	}

	void displayData() override {
		cout << "Displaying Master Info:\n";
		Person::displayData();
	}

	void bonus() override {
		cout << "Master Bonus: " << (salary * 0.15f) << endl;
	}
};

int main() {
	Person* ptr;

	cout << "\n--- Admin Employee ---\n";
	Admin a;
	ptr = &a;
	ptr->getData();
	ptr->displayData();
	ptr->bonus();

	cout << "\n--- Account Employee ---\n";
	Account acc;
	ptr = &acc;
	ptr->getData();
	ptr->displayData();
	ptr->bonus();

	cout << "\n--- Master Employee ---\n";
	Master m;
	ptr = &m;
	ptr->getData();
	ptr->displayData();
	ptr->bonus();

	return 0;
}
