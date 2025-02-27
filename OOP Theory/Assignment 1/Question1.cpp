#include <iostream>
#include <string>
using namespace std;

// Forward Declaration
class Mentor;
class Skill;

//Student class

class Student{
	private:
		int studentID;
		string name;
		int age;
		Mentor* mentorAssigned;
		string sportsInterests[5];

	public:
		Student(int id, string Name, int Age)
			: studentID(id), name(Name), age(Age),mentorAssigned(nullptr){}

	void registerForMentorship(Mentor* m);
	void viewMentorDetails();
	void updateSportsInterest(int index, string sport);

	void display() {
		cout << "Student ID: " << studentID << "\nName: " << name << "\nAge: " << age << endl;
		cout << "Sports Interests: ";
		for (const auto& sport : sportsInterests) {
			if (!sport.empty()) {
				cout << sport << " ";
			}
		}
		cout << endl;
	}

	int getID() { return studentID; }
	string getName() { return name; }
};

// Mentor class

class Mentor{
	private:
		int mentorID;
		string name;
		string sportsExpertise[3];
		int maxLearners;
		Student* assignedLearners[10];
		int currentLearners;

	public:
		Mentor(int id, string Name, string expertise[], int maxL) 
			: mentorID(id), name(Name), maxLearners(maxL), currentLearners(0) {
		for (int i = 0; i < 3; i++) {
			sportsExpertise[i] = expertise[i];
		}

		for (int i = 0; i < 10; i++) {
			assignedLearners[i] = nullptr;
		}
	}

	bool assignLearner(Student* s){
		bool flag = false;
		for (int i = 0; i < 10; i++) {
			if(assignedLearners[i] == nullptr){
				assignedLearners[i] = s;
				flag = true;
			}else{
				continue;
			}
		}
		if (flag){
			return true;
		}else{
			cout<< "Max learners reached!!" << endl;
			return false;
		}
	}

	void removeLearner(Student* s){
		for (int i = 0; i < currentLearners; i++) {
			if (assignedLearners[i] == s) {
				for (int j = i; j < currentLearners - 1; j++) {
					assignedLearners[j] = assignedLearners[j + 1];
				}
				assignedLearners[currentLearners - 1] = nullptr;
				currentLearners--;
				cout << "Student removed from mentorship." << endl;
				return;
			}
		}
		cout << "Student not found in mentor's list." << endl;
	}

	void viewLearners(){
		cout << "Mentor: " << name << " (ID: " << mentorID << ") has " << currentLearners << " learners.\n";
		for (int i = 0; i < currentLearners; i++) {
			cout << " - " << assignedLearners[i]->getName() << " (ID: " << assignedLearners[i]->getID() << ")\n";
		}
	}

	void provideGuidance() {
		cout << "Mentor " << name << " is providing guidance to learners." << endl;
	}

	void display() {
		cout << "Mentor ID: " << mentorID << "\nName: " << name << "\nSports Expertise: ";
		for(const auto& sport: sportsExpertise){
			if(!sport.empty()){
				cout << sport << " " << endl;
			}
		}
		cout << "\nMax Learners: " << maxLearners << "\nCurrent Learners: " << currentLearners << endl;
	}

	string getName(){return name;}
};

// student Methods

void Student::registerForMentorship(Mentor* m){
	
	if(mentorAssigned == nullptr){
		this->mentorAssigned = m;
	}else{
		cout<<"Mentor already assigned!"<<endl;
		}
}

void Student::viewMentorDetails(){
	if(mentorAssigned != nullptr){
		mentorAssigned->display();
	}else{
		cout<<"Mentor not assigned!"<<endl;
	}
}

void Student::updateSportsInterest(int index, string sport){
	if (index >= 0 && index < 5) {
		sportsInterests[index] = sport;
		cout << "Sports interest updated." << endl;
	} else {
		cout << "Invalid index." << endl;
	}
}

// Sport class

class Sport{
	private:
		int sportID;
		string name;
		string description;
		Skill* requiredSkills[10];

	public:
		Sport(int id, string Name, string des):sportID(id), name(Name), description(des){
			for(int i = 0; i<10;i++){
				requiredSkills[i] = nullptr;
			}
		}

		void addSkill(Skill* s);
		void removeSkill(Skill* s);
};

// Skill Class

class Skill{
	private:
		int skillID;
		string skillName;
		string description;

	public:
		Skill(int id, string sn, string des): skillID(id), skillName(sn), description(des){}

		void showDetails(){
			cout<< this->skillID << " " << this->skillName << " " << this->description << endl; 
		}

		void updateSkillDescription(string newDescription){
			this->description = newDescription;
			cout << "New skill description is: " << newDescription << endl;
		}
};

// Sport methods
void Sport::addSkill(Skill* s) {
	for (int i = 0; i < 10; i++) {
		if (requiredSkills[i] == nullptr) {
			requiredSkills[i] = s;
			cout << "Skill added!" << endl;
			return;
		}
	}
	cout << "Skills full!" << endl;
}

void Sport::removeSkill(Skill* s){
	for (int i = 0; i < 10; i++) {
		if (requiredSkills[i] == s) {
			requiredSkills[i] = nullptr;
			cout << "Skill removed!" << endl;
			return;
		}
	}
	cout << "Skill not found!" << endl;
}


int main(){
	
	string mentorExpertise[] = {"Football", "Basketball", "Tennis"};
	Mentor m1(101, "Coach Smith", mentorExpertise, 3);

	Student s1(1, "John Doe", 20);
	Student s2(2, "Alice Brown", 22);

	s1.registerForMentorship(&m1);
	s2.registerForMentorship(&m1);

	m1.viewLearners();

	s1.viewMentorDetails();
	s2.viewMentorDetails();

	s1.updateSportsInterest(0, "Cricket");
	s1.display();

	m1.provideGuidance();
	m1.removeLearner(&s1);
	m1.viewLearners();

	Skill skill1(1, "Dribbling", "Control the ball efficiently");
	Skill skill2(2, "Passing", "Accurate passing techniques");

	Sport football(101, "Football", "Team sport involving a ball");
	football.addSkill(&skill1);
	football.addSkill(&skill2);

	football.removeSkill(&skill1);
	
	
	return 0;
}