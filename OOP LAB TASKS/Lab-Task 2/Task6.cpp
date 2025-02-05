#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Question did not specify what do exactly do when structures are made.

struct subject
{
	string subjectName;
};

struct student
{
	int id;
	vector<subject> student_subject;
};

int main(){

	student myStudent;

	myStudent.id = 345345;
	myStudent.student_subject.push_back({"Mathematics"});


	cout << myStudent.id << endl;
	cout << myStudent.student_subject[0].subjectName << endl;

	return 0;
}