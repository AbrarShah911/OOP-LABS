#include <iostream>
#include <string>
using namespace std;

struct employee{

	string employee_name;
	int employee_id;
	int employee_salary;
};

struct orginisation{

	string orginisation_name;
	int orginisation_number;
	employee orginisation_employee;
};

int main(){

	orginisation org;

	org.orginisation_name = "University";
	org.orginisation_number = 0213;
	org.orginisation_employee.employee_name = "Prof. Mcdonald";
	org.orginisation_employee.employee_id = 420;
	org.orginisation_employee.employee_salary = 30000;

	cout << "Orginisation: " << org.orginisation_name << endl;
	cout << "Orginisation Number: " << org.orginisation_number << endl;
	cout << "Employee Name: " << org.orginisation_employee.employee_name << endl;
	cout << "Employee ID: " << org.orginisation_employee.employee_id << endl;
	cout << "Employee Salary: " << org.orginisation_employee.employee_salary << endl;

	return 0;
}
