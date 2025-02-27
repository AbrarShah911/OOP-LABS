#include <iostream>
#include <string>
using namespace std;

class car{
	private:
		mutable string engine = "HoNdA";
		mutable string horsepower = "I still don't understand why we need horses in a car??";
		mutable float seating_capacity = 3.2;
		mutable float number_of_speakers = 10.3; // Some famouse speakers include Julius Cesar, neil degrasse tyson and Winston Churchill.

	public:
		void changeAttributes() const {
			this->engine = "2.6-liter, twin-turbocharged RB26DETT I6 engine";
			this->horsepower = "Why would I need horses? To feed them or smth??";
			this->seating_capacity = 4.5;
			this->number_of_speakers = -10.4;
		}

		void displayCarOrSmth(){
			cout << this->engine << endl;
			cout << this->horsepower << endl;
			cout << this->seating_capacity << endl;
			cout << this->number_of_speakers << endl;
		}

};

int main(){

		car nissanGTR;
		nissanGTR.displayCarOrSmth();
		cout << " " << endl;
		nissanGTR.changeAttributes();
		nissanGTR.displayCarOrSmth();
	return 0;
}