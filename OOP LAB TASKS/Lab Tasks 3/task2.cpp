#include <iostream>
using namespace std;

/*
Create a class called Date that includes three pieces of information as
 instance variables—a month (typeint), a day
(typeint) and a year (typeint).
 Provide a method displayDate that displays the month, day and year separated by
forward slashes(/).
 Write a test application named DateTest that demonstrates classDate’s capabilities.

*/

class Date{

	int month;
	int day;
	int year;

	public:

		Date(int month, int day, int year){
			this->month = month;
			this->day = day;
			this->year = year;
		}

		void displayDate(){
			cout << "The date that you have set is: " << this->day << " / " << this->month << " / " << this->year << endl;
		}

};

int main(int argc, char* argv[]){

	Date today(stoi(argv[1]),stoi(argv[2]),stoi(argv[3]));

	today.displayDate();

}