#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	string name;
	int id;
	bool hasPaid;
	string stop;

public:
	Student(string n = "", int i = 0, bool paid = false, string s = "") : name(n), id(i), hasPaid(paid), stop(s) {}

	void registerStudent(string n, int i, string s) {
		name = n;
		id = i;
		stop = s;
		hasPaid = false;
	}

	void payFees() {
		hasPaid = true;
	}

	bool isActive() const {
		return hasPaid;
	}

	string getStop() const {
		return stop;
	}
};

class BusRoute {
private:
	string routeName;
	string stops[5]; // Fixed-size array for stops

public:
	BusRoute(string name = "", string s1 = "", string s2 = "", string s3 = "", string s4 = "", string s5 = "") {
		routeName = name;
		stops[0] = s1;
		stops[1] = s2;
		stops[2] = s3;
		stops[3] = s4;
		stops[4] = s5;
	}

	void displayStops() const {
		cout << "Stops for " << routeName << ":\n";
		for (int i = 0; i < 5; i++) {
			cout << "- " << stops[i] << endl;
		}
	}
};

class TransportationSystem {
private:
	Student students[100];
	int studentCount;
	BusRoute routes[2];

public:
	TransportationSystem() : studentCount(0), routes{BusRoute("Route A", "Stop 1", "Stop 2", "Stop 3", "Stop 4", "Stop 5"), 
		BusRoute("Route B", "Stop A", "Stop B", "Stop C", "Stop D", "Stop E")} {}

	void registerStudent(string name, int id, string stop) {
		if (studentCount < 100) {
			students[studentCount].registerStudent(name, id, stop);
			studentCount++;
		} else {
			cout << "Registration full!" << endl;
		}
	}

	void payFees(int id) {
		for (int i = 0; i < studentCount; i++) {
			if (students[i].isActive()) {
				cout << "Student " << id << " has already paid." << endl;
				return;
			}
		}
		cout << "Fees paid for student " << id << endl;
	}

	void showRoutes() const {
		for (int i = 0; i < 2; i++) {
			routes[i].displayStops();
		}
	}
};

int main() {
	TransportationSystem system;
	system.registerStudent("Ali", 1, "Stop 2");
	system.registerStudent("Ahmed", 2, "Stop A");
	system.payFees(1);
	system.showRoutes();
	return 0;
}
