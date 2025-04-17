#include <iostream>
#include <string>
using namespace std;

class Student {
public:
	virtual double getTuition(const string& status, int creditHours) = 0;
	virtual ~Student() {}
};

class GraduateStudent : public Student {
private:
	string researchTopic;

public:
	void setResearchTopic(const string& topic) {
		researchTopic = topic;
	}

	string getResearchTopic() const {
		return researchTopic;
	}

	double getTuition(const string& status, int creditHours) override {
		if (status == "undergraduate") {
			return 200.0 * creditHours;
		} else if (status == "graduate") {
			return 300.0 * creditHours;
		} else if (status == "doctoral") {
			return 400.0 * creditHours;
		} else {
			cout << "Invalid status entered.\n";
			return 0.0;
		}
	}
};

int main() {
	GraduateStudent grad;
	grad.setResearchTopic("Why do cows give milk");

	string status;
	int creditHours;

	cout << "Enter student status: ";
	cin >> status;
	cout << "Enter number of credit hours: ";
	cin >> creditHours;

	cout << "Research Topic: " << grad.getResearchTopic() << endl;
	cout << "Tuition Fee: Rs " << grad.getTuition(status, creditHours) << endl;

	return 0;
}
