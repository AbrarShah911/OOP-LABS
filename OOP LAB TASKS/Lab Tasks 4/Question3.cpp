#include <iostream>
#include <string>
using namespace std;

class Invoice {
private:
	string partNumber;
	string partDescription;
	int quantity;
	double pricePerItem;

public:
	Invoice(string partNum, string partDesc, int qty, double price) {
		partNumber = partNum;
		partDescription = partDesc;
		quantity = (qty > 0) ? qty : 0;
		pricePerItem = (price > 0) ? price : 0.0;
	}


	double getInvoiceAmount() {
		return quantity * pricePerItem;
	}

	void displayInvoice(){
		cout << "Part Number: " << partNumber << "\n" << "Part Description: " << partDescription << "\n" << "Quantity: " << quantity << "\n" << "Price per Item: " << pricePerItem << "\n" << "Total Invoice Amount: " << getInvoiceAmount() << std::endl;
	}
};

int main() {
	Invoice invoice("1234", "Hammer", 5, 10.99);
	invoice.displayInvoice();

	return 0;
}
