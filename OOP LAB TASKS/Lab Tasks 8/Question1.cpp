#include <iostream>
#include <vector>
using namespace std;

class Account {
protected:
	string accountNumber;
	double balance;
	string accountHolderName;

public:
	Account(string accNum, double bal, string holderName)
		: accountNumber(accNum), balance(bal), accountHolderName(holderName) {}

	virtual void deposit(double amount) {
		balance += amount;
		cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
	}

	virtual bool withdraw(double amount) {
		if (amount > balance) {
			cout << "Insufficient funds!" << endl;
			return false;
		}
		balance -= amount;
		cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
		return true;
	}

	virtual void calculateInterest() = 0;

	virtual void printStatement() {
		cout << "Account Holder: " << accountHolderName << "\nAccount Number: " << accountNumber << "\nBalance: " << balance << endl;
	}

	string getAccountInfo() {
		return "Account: " + accountNumber + " | Holder: " + accountHolderName + " | Balance: " + to_string(balance);
	}

	virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
	double interestRate;
	double minimumBalance;

public:
	SavingsAccount(string accNum, double bal, string holderName, double rate, double minBal)
		: Account(accNum, bal, holderName), interestRate(rate), minimumBalance(minBal) {}

	void calculateInterest() override {
		if (balance >= minimumBalance) {
			double interest = balance * (interestRate / 100);
			balance += interest;
			cout << "Interest Added: " << interest << " | New Balance: " << balance << endl;
		}
	}

	bool withdraw(double amount) override {
		if (balance - amount < minimumBalance) {
			cout << "Withdrawal denied! Maintaining minimum balance required." << endl;
			return false;
		}
		return Account::withdraw(amount);
	}
};

class CheckingAccount : public Account {
public:
	CheckingAccount(string accNum, double bal, string holderName)
		: Account(accNum, bal, holderName) {}

	void calculateInterest() override {
		cout << "Checking accounts do not earn interest." << endl;
	}
};

class FixedDepositAccount : public Account {
private:
	double fixedInterestRate;
	string maturityDate;

public:
	FixedDepositAccount(string accNum, double bal, string holderName, double rate, string maturity)
		: Account(accNum, bal, holderName), fixedInterestRate(rate), maturityDate(maturity) {}

	void calculateInterest() override {
		double interest = balance * (fixedInterestRate / 100);
		cout << "Fixed Deposit Interest: " << interest << " (Paid at maturity: " << maturityDate << ")" << endl;
	}

	bool withdraw(double amount) override {
		cout << "Withdrawals not allowed before maturity date: " << maturityDate << endl;
		return false;
	}
};

int main() {
	SavingsAccount sa("CHACHEE420", 5000, "Ustaad Shapatar", 3.5, 1000);
	CheckingAccount ca("HAHA123LOL", 2000, "Kamil Polish Wala");
	FixedDepositAccount fda("FDAGOTME007", 10000, "Saleem...Just Saleem", 5.0, "2026-12-31");

	sa.deposit(1000);
	sa.withdraw(4500);
	sa.calculateInterest();
	sa.printStatement();

	ca.deposit(500);
	ca.withdraw(700);
	ca.calculateInterest();
	ca.printStatement();

	fda.calculateInterest();
	fda.withdraw(1000);
	fda.printStatement();

	return 0;
}