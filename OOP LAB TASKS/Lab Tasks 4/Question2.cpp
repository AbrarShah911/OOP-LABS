#include <iostream>
using namespace std;

class Account {
private:
    double balance;

public:
    Account(double initialBalance) {
        if (initialBalance >= 0)
            balance = initialBalance;
        else {
            balance = 0;
            cout << "Initial balance was invalid." << endl;
        }
    }

    // Credit function to add amount to balance
    void credit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Invalid amount." << std::endl;
        }
    }


    void debit(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            cout << "Debit amount exceeded." << endl;
        }
    }


    double getBalance() {
        return balance;
    }
};

int main() {
    Account myAccount(100000.0);

    myAccount.credit(30.0);
    cout << "After credit: " << myAccount.getBalance() << endl;

    myAccount.debit(10.0);
    cout << "After debit: " << myAccount.getBalance() << endl;

    myAccount.debit(150000000.0); 

    return 0;
}