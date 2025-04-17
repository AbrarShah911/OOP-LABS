#include <iostream>
#include <string>
using namespace std;

class Wallet {
private:
	double balance;
	double dailyDepositTotal;
	double dailyWithdrawTotal;
	const double MAX_DAILY_DEPOSIT = 10000.0;
	const double MAX_DAILY_WITHDRAW = 5000.0;

public:
	Wallet() : balance(0.0), dailyDepositTotal(0.0), dailyWithdrawTotal(0.0) {}

	bool deposit(double amount) {
		if (amount <= 0) {
			cout << "Deposit amount must be positive.\n";
			return false;
		}
		if (dailyDepositTotal + amount > MAX_DAILY_DEPOSIT) {
			cout << "Deposit exceeds daily limit.\n";
			return false;
		}
		balance += amount;
		dailyDepositTotal += amount;
		cout << "Deposited: $" << amount << " | New Balance: $" << balance << "\n";
		return true;
	}

	bool withdraw(double amount) {
		if (amount <= 0) {
			cout << "Withdraw amount must be positive.\n";
			return false;
		}
		if (amount > balance) {
			cout << "Insufficient funds.\n";
			return false;
		}
		if (dailyWithdrawTotal + amount > MAX_DAILY_WITHDRAW) {
			cout << "Withdrawal exceeds daily limit.\n";
			return false;
		}
		balance -= amount;
		dailyWithdrawTotal += amount;
		cout << "Withdrew: $" << amount << " | New Balance: $" << balance << "\n";
		return true;
	}

	double getBalance() const {
		return balance;
	}

	void resetDailyLimits() {
		dailyDepositTotal = 0.0;
		dailyWithdrawTotal = 0.0;
	}
};

class User {
private:
	string userID;
	string name;
	Wallet wallet;

public:
	User(string id, string username) : userID(id), name(username) {}

	bool deposit(double amount) {
		cout << "[" << name << "] ";
		return wallet.deposit(amount);
	}

	bool withdraw(double amount) {
		cout << "[" << name << "] ";
		return wallet.withdraw(amount);
	}

	void checkBalance() const {
		cout << "[" << name << "] Current Balance: $" << wallet.getBalance() << "\n";
	}

	void resetDailyLimits() {
		wallet.resetDailyLimits();
	}
};
 

int main() {

	User user1("U001", "Alice");
	User user2("U002", "Bob");

	user1.deposit(3000);
	user1.withdraw(1000);
	user1.checkBalance();

	cout << "-------------------\n";

	user2.deposit(8000);
	user2.deposit(3000); // should fail
	user2.checkBalance();

	cout << "-------------------\n";

	user1.withdraw(5000);
	user1.checkBalance();

	cout << "-------------------\n";

	user1.resetDailyLimits();
	user1.deposit(6000);

	return 0;
}
