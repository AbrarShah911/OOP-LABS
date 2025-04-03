#include <iostream>
#include <unordered_map>
using namespace std;

class Currency {
protected:
	double amount;
	string currencyCode;
	string currencySymbol;
	double exchangeRate;

public:
	Currency(double amt, string code, string symbol, double rate)
		: amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

	virtual double convertToBase() = 0;
	virtual double convertTo(Currency &targetCurrency) {
		double baseAmount = convertToBase();
		return baseAmount / targetCurrency.exchangeRate;
	}

	virtual void displayCurrency() = 0;

	virtual ~Currency() {}
};

class Dollar : public Currency {
public:
	Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

	double convertToBase() override {
		return amount * exchangeRate; // USD is the base currency
	}

	void displayCurrency() override {
		cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
	}
};

class Euro : public Currency {
public:
	Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {} // 1 EUR = 1.1 USD

	double convertToBase() override {
		return amount * exchangeRate;
	}

	void displayCurrency() override {
		cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
	}
};

class Rupee : public Currency {
public:
	Rupee(double amt) : Currency(amt, "PKR", "Rs", 0.0036) {} // 1 PKR = 0.0036 USD haha lol, we're so done for bro, its like not even a joke

	double convertToBase() override {
		return amount * exchangeRate;
	}

	void displayCurrency() override {
		cout << "Amount: " << currencySymbol << amount << " (" << currencyCode << ")" << endl;
	}
};

int main() {
	Dollar usd(100);
	Euro eur(50);
	Rupee inr(5000);

	usd.displayCurrency();
	eur.displayCurrency();
	inr.displayCurrency();

	cout << "Converted: " << usd.convertTo(eur) << " EUR" << endl;
	cout << "Converted: " << eur.convertTo(usd) << " USD" << endl;
	cout << "Converted: " << inr.convertTo(usd) << " USD" << endl;

	return 0;
}
