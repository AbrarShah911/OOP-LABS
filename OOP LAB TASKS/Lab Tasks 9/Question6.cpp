#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
	string model;
	float price;

public:
	Car(string m) : model(m), price(0.0) {}

	string getModel() const {
		return model;
	}

	float getPrice() const {
		return price;
	}

	virtual void setPrice(float p) = 0;
};

class Color : public Car {
private:
	string color;

public:
	Color(string m, string c) : Car(m), color(c) {}

	void setPrice(float p) override {
		price = p; 
	}

	void display() const {
		cout << "Model: " << model << ", Color: " << color << ", Price: " << price << endl;
	}
};

class Company : public Car {
private:
	string companyName;

public:
	Company(string m, string c) : Car(m), companyName(c) {}

	void setPrice(float p) override {
		price = p; 
	}

	void display() const {
		cout << "Model: " << model << ", Company: " << companyName << ", Price: " << price << endl;
	}
};

int main() {
	Color myColorCar("Gaari", "Laal");
	myColorCar.setPrice(20000);
	myColorCar.display();

	Company myCompanyCar("SUI", "RONALDO");
	myCompanyCar.setPrice(30000);
	myCompanyCar.display();

	return 0;
}
