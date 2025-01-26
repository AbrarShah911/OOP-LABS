#include <iostream>
#include <iomanip>
#include <string>

int main() {
	std::string movieName;
	double adultPrice, childPrice, donationPercent;
	int adultTicketsSold, childTicketsSold;

	std::cout << "Enter the movie name: ";
	getline(std::cin, movieName);

	std::cout << "Enter the adult ticket price: $";
	std::cin >> adultPrice;

	std::cout << "Enter the child ticket price: $";
	std::cin >> childPrice;

	std::cout << "Enter the number of adult tickets sold: ";
	std::cin >> adultTicketsSold;

	std::cout << "Enter the number of child tickets sold: ";
	std::cin >> childTicketsSold;

	std::cout << "Enter the percentage of gross amount to be donated: ";
	std::cin >> donationPercent;

	// Calculations
	double grossAmount = (adultPrice * adultTicketsSold) + (childPrice * childTicketsSold);
	double donationAmount = grossAmount * (donationPercent / 100);
	double netSale = grossAmount - donationAmount;

	std::cout << "\n";
	std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< std::endl;
	std::cout << std::left << std::setw(40) << "Movie Name:" << std::setw(30) << movieName << std::endl;
	std::cout << std::left << std::setw(40) << "Number of Tickets Sold:" << std::right << std::setw(10) << adultTicketsSold + childTicketsSold << std::endl;
	std::cout << std::left << std::setw(40) << "Gross Amount:" << std::right << std::setw(10) << "$" << std::fixed << std::setprecision(2) << grossAmount << std::endl;
	std::cout << std::left << std::setw(40) << "Percentage of Gross Amount Donated:" << std::right << std::setw(10) << std::fixed << std::setprecision(2) << donationPercent << "%" << std::endl;
	std::cout << std::left << std::setw(40) << "Amount Donated:" << std::right << std::setw(10) << "$" << std::fixed << std::setprecision(2) << donationAmount << std::endl;
	std::cout << std::left << std::setw(40) << "Net Sale:" << std::right << std::setw(10) << "$" << std::fixed << std::setprecision(2) << netSale << std::endl;
	std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< std::endl;

    return 0;
}
