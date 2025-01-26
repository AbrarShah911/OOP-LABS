#include <iostream>
#include <iomanip>

int main() {

	int customerID;
	std::string customerName;
	int unitsConsumed;
	double chargePerUnit, amountCharged, surcharge = 0, netAmount;


	std::cout << "Enter Customer ID: ";
	std::cin >> customerID;
	std::cin.ignore(); 
	std::cout << "Enter Customer Name: ";
	std::getline(std::cin, customerName);
	std::cout << "Enter Units Consumed: ";
	std::cin >> unitsConsumed;


	if (unitsConsumed <= 199) {
		chargePerUnit = 16.20;
	} else if (unitsConsumed >= 200 && unitsConsumed < 300) {
		chargePerUnit = 20.10;
	} else if (unitsConsumed >= 300 && unitsConsumed < 500) {
		chargePerUnit = 27.10;
	} else {
		chargePerUnit = 35.90;
	}

	amountCharged = unitsConsumed * chargePerUnit;

	if (amountCharged > 18000) {
		surcharge = amountCharged * 0.15;
	}

	netAmount = amountCharged + surcharge;

	std::cout << std::fixed << std::setprecision(2);
	std::cout << "\nCustomer ID : " << customerID << std::endl;
	std::cout << "Customer Name : " << customerName << std::endl;
	std::cout << "Units Consumed : " << unitsConsumed << std::endl;
	std::cout << "Amount Charged Rs. " << chargePerUnit << " per unit : " << amountCharged << std::endl;
	std::cout << "Surcharge Amount : " << surcharge << std::endl;
	std::cout << "Net Amount Paid by the Customer : " << netAmount << std::endl;

	return 0;
}
