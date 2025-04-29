#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Employee{
	int id;
	string name;
	string designation;
	int yearsOfService;
};


class Handler {
private:
	Employee emp;
	string fileName;

public:
	Handler(string fN, Employee empo) {
		this->fileName = fN;
		this->emp = empo;
	}

	void saveEmployee(const Employee& emp, const string& filename) {
		ofstream file(filename, ios::app); // using append to save multiple employees
		if (file.is_open()) {
			file << emp.id << endl;
			file << emp.name << endl;
			file << emp.designation << endl;
			file << emp.yearsOfService << endl;
			file.close();
		}
	}

	Employee loadEmployee(const string& filename) {
		Employee emp;
		ifstream file(filename);
		if (file.is_open()) {
			file >> emp.id;
			file.ignore();
			getline(file, emp.name);
			getline(file, emp.designation);
			file >> emp.yearsOfService;
			file.close();
		}
		return emp;
	}

void part1(const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "File could not be opened.\n";
		return;
	}

	Employee emp;
	bool found = false;

	while (file >> emp.id) {
		file.ignore();
		getline(file, emp.name);
		getline(file, emp.designation);
		file >> emp.yearsOfService;
		file.ignore();

		if (emp.yearsOfService >= 2 && emp.designation == "Manager") {
			found = true;
			break; 
		}
	}

	file.close();

	if (!found) {
		cout << "No manager found with 2 or more years of service!" << endl;
		return;
	}

	ofstream outFile(filename, ios::trunc);
	outFile << emp.id << endl;
	outFile << emp.name << endl;
	outFile << emp.designation << endl;
	outFile << emp.yearsOfService << endl;
	outFile.close();

	cout << "Qualified Manager: " << emp.name << " saved to file." << endl;
}

};


int main(){

	Employee e1 = {101, "kamil", "Manager", 3};
	Employee e2 = {102, "Bruh", "Clerk", 1};
	Employee e3 = {103, "frank", "Manager", 1};

	Handler handler("Data.txt", e1);
	handler.saveEmployee(e1, "Data.txt");
	handler.saveEmployee(e2, "Data.txt");
	handler.saveEmployee(e3, "Data.txt");

	handler.part1("Data.txt");

	return 0;
}