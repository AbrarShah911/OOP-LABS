#include <iostream>
#include <string>
using namespace std;

class BankAccount{
	protected:
		int balance;
		int AccNum;

	public:
		BankAccount(int bal, int AN): balance(bal), AccNum(AN){}

		int getBalance(){
			return balance;
		} 

		void setBalance(int num){
			balance = num;
		}

		int getAccNum(){
			return AccNum;
		}

		void withdraw(int num){
			balance = balance - num;
			cout << balance <<  endl;
		}

		void deposit(int num){
			balance = balance + num;
			cout << balance <<  endl;
		}

};

class SavingsAccount: virtual public BankAccount{
	private:
		int monthlyInterest;

	public:
		SavingsAccount(int bal, int AN, int MI): BankAccount(bal, AN), monthlyInterest(MI) {}

		void applyMI(){
			balance += balance * (monthlyInterest / 100.0);
		}
};

class CheckingAccount: virtual public BankAccount{
	private:
		int overdraft;

	public:
		CheckingAccount(int bal, int AN, int OD): BankAccount(bal, AN), overdraft(OD) {}

		void overdraftAmmount(int num){
			if(num > overdraft){
				cout << "Cannot take out this much money!" << endl;
			}else{
				balance -= num;
			}
		}
};

class BusinessAccount : virtual public BankAccount{
	private:
		int tax;

	public:
		BusinessAccount(int bal, int AN, int t): BankAccount(bal, AN), tax(t) {}

		void depositBizz(int num){
			balance += (num - tax);
		}
};


class Employee{
protected:
    string name;
    int ID;

public:
    Employee(string n, int id) : name(n), ID(id) {}

    void showInfo() {
        cout << "Employee Name: " << name << ", ID: " << ID << endl;
    }
};


class Customer {
private:
    string name;
    BankAccount* account;

public:
    Customer(string n, BankAccount* acc) : name(n), account(acc) {}

    void deposit(int amount) {
        account->deposit(amount);
    }

    void withdraw(int amount) {
        account->withdraw(amount);
    }
};


class Teller : public Employee {
public:
    Teller(string n, int id) : Employee(n, id) {}

    void deposit(BankAccount& acc, int amount) {
        acc.deposit(amount);
    }

    void withdraw(BankAccount& acc, int amount) {
        acc.withdraw(amount);
    }

    void freezeAccount() {
        cout << "Account has been frozen!" << endl;
    }
};


class Manager : public Employee, public BankAccount {
public:
    Manager(string n, int id, int bal, int AN) : Employee(n, id), BankAccount(bal,AN) {}

    void overrideLimit(int newBalance) {
        setBalance(newBalance);
        cout << "Balance overridden. New balance: " << newBalance << endl;
    }

    void adjustOverdraftLimit(CheckingAccount& acc, int newLimit) {
        acc = CheckingAccount(acc.getBalance(), acc.getAccNum(), newLimit);
        cout << "Overdraft limit adjusted to: " << newLimit << endl;
    }
};


int main(){ 

    SavingsAccount sa(1000, 12345, 5);
    CheckingAccount ca(500, 67890, 200);
    BusinessAccount ba(2000, 54321, 50);
    Customer cust("John", &sa);
    Teller teller("Alice", 1001);
    Manager manager("Bob", 2001, 1000, 12345);

    cout << "Initial Balances:\n";
    cout << "Savings: " << sa.getBalance() << "\n";
    cout << "Checking: " << ca.getBalance() << "\n";
    cout << "Business: " << ba.getBalance() << "\n\n";

    cout << "Applying Monthly Interest on Savings Account:\n";
    sa.applyMI();
    
    cout << "\nCustomer Deposits 200 into Savings Account:\n";
    cust.deposit(200);
    
    cout << "\nTeller Freezing an Account:\n";
    teller.freezeAccount();

    cout << "\nManager Overriding Business Account Balance to 5000:\n";
    manager.overrideLimit(ba, 5000);


	return 0;
}

