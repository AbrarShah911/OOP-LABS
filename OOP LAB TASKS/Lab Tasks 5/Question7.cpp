#include <iostream>
using namespace std;

class Student{
	const int roll_no;
	public:
		Student(int num) : roll_no(num){}
		void displayrno(){
			cout<<roll_no<<endl;
		}
};

int main(){
	int val;
	cout<<"Enter a roll no: ";
	cin>>val;
	Student s(val);
	cout<<"Rollnum: ";
	s.displayrno();
	return 0;
}