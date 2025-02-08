#include <iostream>
using namespace std;

	class Glass {
	public:
	int LiquidLevel;

	Glass() { // Constructor
		LiquidLevel = 200;
	}

	void Refill() {
		LiquidLevel = 200;
		cout << "The glass has been refilled to 200 ml." << endl;
	}

	void Drink(int milliliters) {
		LiquidLevel -= milliliters;

		if (LiquidLevel < 100) {
			Refill();
		}
	}

};

	int main() {
	Glass myGlass; 

	while (true) {
		cout << "Current liquid level: " << myGlass.LiquidLevel << " ml." << endl;
		cout << "Enter the amount of liquid you drank (in ml), or type 'exit' to quit: ";

		string input;
		getline(cin, input);

		if (input == "exit") {
			break;
		}

		try{
			int drinkAmount = stoi(input);
			myGlass.Drink(drinkAmount);
		}
		catch (const invalid_argument&) { // catches any invalid argument if a wring amount to srink water is input.
			cout << "Invalid input. Please enter a valid number or 'exit' to quit." << endl;
		}
	}

	return 0;
	}
