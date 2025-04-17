#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Flight {
private:
	string flightNumber;
	string departure;
	string arrival;
	int capacity;
	int bookedSeats;

public:
	Flight(string flightNum, string dep, string arr, int cap)
		: flightNumber(flightNum), departure(dep), arrival(arr), capacity(cap), bookedSeats(0) {}

	bool bookSeat() {
		if (bookedSeats < capacity) {
			bookedSeats++;
			cout << "Seat booked" << flightNumber << "\n";
			return true;
		}
		cout << "Booking failed " << flightNumber << ".\n";
		return false;
	}

	bool cancelSeat() {
		if (bookedSeats > 0) {
			bookedSeats--;
			cout << "Seat canceled" << flightNumber << "\n";
			return true;
		}
		cout << "Cancelation failed" << flightNumber << "\n";
		return false;
	}

	bool upgradeSeat() {
		if (bookedSeats > 0) {
			cout << "Seat upgraded" << flightNumber << "\n";
			return true;
		}
		cout << "Upgrade failed " << flightNumber << "\n";
		return false;
	}

	int getCapacity() const {
		return capacity;
	}

	int getBookedSeats() const {
		return bookedSeats;
	}
};

class Passenger {
private:
	string name;
	string id;

public:
	Passenger(string passengerName, string passengerId)
		: name(passengerName), id(passengerId) {}

	void requestBooking(Flight& flight) {
		if (flight.bookSeat()) {
			cout << name << " has successfully booked a seat.\n";
		} else {
			cout << name << " failed to book a seat.\n";
		}
	}

	void requestCancel(Flight& flight) {
		if (flight.cancelSeat()) {
			cout << name << " has successfully canceled a seat.\n";
		} else {
			cout << name << " failed to cancel a seat.\n";
		}
	}

	void requestUpgrade(Flight& flight) {
		if (flight.upgradeSeat()) {
			cout << name << " has successfully upgraded a seat.\n";
		} else {
			cout << name << " failed to upgrade a seat.\n";
		}
	}
};

int main() {

	Flight flight1("A123", "Adis Ababa", "Antarctica", 10);
	Flight flight2("B456", "Chicago", "Florence", 5);

	Passenger passenger1("Tayyar", "P001");
	Passenger passenger2("Murghi", "P002");

	passenger1.requestBooking(flight1);
	passenger1.requestBooking(flight1);
	passenger1.requestBooking(flight1);
	passenger2.requestBooking(flight1);
	passenger2.requestCancel(flight1);
	passenger2.requestUpgrade(flight1);

	Passenger passenger3("Charlie", "P003");
	passenger3.requestBooking(flight2);

	return 0;
}
