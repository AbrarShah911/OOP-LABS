#include <iostream>
#include <vector>
using namespace std;

class Person {
protected:
	string name, id, address, phoneNumber, email;

public:
	Person(string n, string i, string addr, string phone, string mail)
		: name(n), id(i), address(addr), phoneNumber(phone), email(mail) {}

	virtual void displayInfo() {
		cout << "Name: " << name << "\nID: " << id << "\nAddress: " << address
			 << "\nPhone: " << phoneNumber << "\nEmail: " << email << endl;
	}

	void updateInfo(string addr, string phone, string mail) {
		address = addr;
		phoneNumber = phone;
		email = mail;
	}

	virtual ~Person() {}
};

class Student : public Person {
private:
	vector<string> coursesEnrolled;
	double GPA;
	int enrollmentYear;

public:
	Student(string n, string i, string addr, string phone, string mail, double gpa, int year)
		: Person(n, i, addr, phone, mail), GPA(gpa), enrollmentYear(year) {}

	void enrollCourse(string course) {
		coursesEnrolled.push_back(course);
	}

	void displayInfo() override {
		Person::displayInfo();
		cout << "Enrollment Year: " << enrollmentYear << "\nGPA: " << GPA << "\nCourses: ";
		for (string course : coursesEnrolled) cout << course << ", ";
		cout << endl;
	}

	string getName(){
		return this->name;
	}
};

class Professor : public Person {
private:
	string department;
	vector<string> coursesTaught;
	double salary;

public:
	Professor(string n, string i, string addr, string phone, string mail, string dept, double sal)
		: Person(n, i, addr, phone, mail), department(dept), salary(sal) {}

	void addCourse(string course) {
		coursesTaught.push_back(course);
	}

	void displayInfo() override {
		Person::displayInfo();
		cout << "Department: " << department << "\nSalary: " << salary << "\nCourses: ";
		for (string course : coursesTaught) cout << course << ", ";
		cout << endl;
	}
};

class Staff : public Person {
private:
	string department, position;
	double salary;

public:
	Staff(string n, string i, string addr, string phone, string mail, string dept, string pos, double sal)
		: Person(n, i, addr, phone, mail), department(dept), position(pos), salary(sal) {}

	void displayInfo() override {
		Person::displayInfo();
		cout << "Department: " << department << "\nPosition: " << position << "\nSalary: " << salary << endl;
	}
};

class Course {
private:
	string courseId, courseName, instructor, schedule;
	int credits;
	vector<Student *> enrolledStudents; // vecotr of student tupe pointers

public:
	Course(string id, string name, int cred, string instr, string sched)
		: courseId(id), courseName(name), credits(cred), instructor(instr), schedule(sched) {}

	void registerStudent(Student *s) {
		enrolledStudents.push_back(s);
		s->enrollCourse(courseName);
	}

	void displayCourseInfo() {
		cout << "Course ID: " << courseId << "\nCourse Name: " << courseName << "\nCredits: " << credits
			 << "\nInstructor: " << instructor << "\nSchedule: " << schedule << "\nEnrolled Students: ";
		for (Student *s : enrolledStudents) cout << s->getName() << ", ";
		cout << endl;
	}
};

int main() {
	Student s1("Yeves Saint Laurent", "CS150", "1544 New England", "7348957987", "Yeves_Laurent@hotmail.com", 3.8, 2022);
	Professor p1("Midas", "MOO101", "2 BC (Before Trojan War)", "900090000", "midas@emailsDidntExistAtThatTime.com", "Art of Turning Everything into Gold", 0);
	Staff st1("King Arthur", "ST201", "Litterally England....all of it", "754850983", "Auther@allMail.com", "Admin", "Manager", 60000);

	Course c1("SOD101", "Science Of Dedunction", 3, "Dr. Sherlock Holms", "MWF 10-11 AM");
	c1.registerStudent(&s1);

	s1.displayInfo();
	cout << " " << endl;
	p1.displayInfo();
	cout << " " << endl;
	st1.displayInfo();
	cout << " " << endl;
	c1.displayCourseInfo();

	return 0;
}
