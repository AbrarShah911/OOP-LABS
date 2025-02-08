#include <iostream>
#include <string>
using namespace std;

/*

Create a class called Employee that includes three pieces of information as instance
variables—a first name (type
String), a last name (type String) and a monthly salary (double).
 If the monthly salary is not positive, set it to 0.0.
Write a test application named EmployeeTest that demonstrates class Employee’s
 capabilities. Create two
Employee objects and display each object’s yearly salary.
 Then give each Employee a 10% raise and display each
Employee’s yearly salary again.

*/

class Employee{
	string firstName;
	string lastName;
	double salary;

	public:
		Employee(string firstName, string lastName, double salary){
			this->firstName = firstName;
			this->lastName = lastName;
			if(salary < 0){
				this->salary = 0;
			}else{
				this->salary = salary;
			}
		}

		void brokeness(){
			cout << this->firstName << " " << this->lastName << "'s salary is: " << this->salary << endl;
			cout << "After a 10 percent raise this employee's salary will come to: " << this->salary * 1.1 << endl;
		}
};

int main(int argc, char* argv[]){

	Employee brokeDude1("Mark", "Gladio", 400);

	brokeDude1.brokeness();

	return 0;
}