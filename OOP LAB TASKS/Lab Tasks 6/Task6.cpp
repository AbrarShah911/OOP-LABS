#include <iostream>
#include <string>
using namespace std;

// Base class: Student
class Student {
protected:
    string name;
    int rollNumber;

public:
    Student(string n, int roll) : name(n), rollNumber(roll) {}

    void displayStudentDetails() const {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
    }
};

class Marks : public Student {
protected:
    int numCourses;
    int* marks;

public:
    Marks(string n, int roll, int num) : Student(n, roll), numCourses(num) {
        marks = new int[numCourses]; 
    }

    void inputMarks() {
        cout << "Enter marks for " << numCourses << " courses: " << endl;
        for (int i = 0; i < numCourses; i++) {
            cout << "Course " << (i + 1) << ": ";
            cin >> marks[i];
        }
    }

    void displayMarks() const {
        cout << "Marks obtained in courses:" << endl;
        for (int i = 0; i < numCourses; i++) {
            cout << "Course " << (i + 1) << ": " << marks[i] << endl;
        }
    }

    int getTotalMarks() const {
        int total = 0;
        for (int i = 0; i < numCourses; i++) {
            total += marks[i];
        }
        return total;
    }

    int getNumCourses() const {
        return numCourses;
    }

    ~Marks() {
        delete[] marks; 
    }
};

class Result : public Marks {
public:
    Result(string n, int roll, int num) : Marks(n, roll, num) {}

    void displayResult() {
        int totalMarks = getTotalMarks();
        float averageMarks = (float)totalMarks / getNumCourses();

        displayStudentDetails();
        displayMarks();
        cout << "Total Marks: " << totalMarks << endl;
        cout << "Average Marks: " << averageMarks << endl;
    }
};

// Main function
int main() {
    string studentName;
    int rollNumber, numCourses;

    cout << "Enter Student Name: ";
    getline(cin, studentName);
    cout << "Enter Roll Number: ";
    cin >> rollNumber;
    cout << "Enter Number of Courses: ";
    cin >> numCourses;

    Result studentResult(studentName, rollNumber, numCourses);

    studentResult.inputMarks();
    cout << "\n--- Student Report ---\n";
    studentResult.displayResult();

    return 0;
}
