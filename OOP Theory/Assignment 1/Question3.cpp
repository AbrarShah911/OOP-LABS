#include <iostream>
#include <string>
using namespace std;

struct Car
{
	string model;
	string EligibilityCriteria[3];
	float rentalPrice; // in dollars per day
};

class User{
	private:
		int age;
		int userId;
		string license;
		long int contactInformation;
	public:
		User(int Age = 0, int id = 0, string lice = " ", long int contactInfo = 0)
			:age(Age), userId(id), license(lice), contactInformation(contactInfo){}

		void registerUser(int Age, int id, string lice, long int contactInfo){
			age = Age;
			userId = id;
			license = lice;
			contactInformation = contactInfo;
		}

		void updateUser(int Age, int id, string lice, long int contactInfo){
			age = Age;
			userId = id;
			license = lice;
			contactInformation = contactInfo;
		}

		string getLicense(){
			return license;
		}
};

class System{
	
	private:
		Car *cars;

	public:
		System(){
			cars = new Car[5];
			cars[0].model = "Toyota";
			cars[0].rentalPrice = 150.76;
			cars[0].EligibilityCriteria[0] = "Learner";
			cars[0].EligibilityCriteria[1] = "Intermediate";
			cars[0].EligibilityCriteria[2] = "Full";

			cars[1].model = "McLaren P1";
			cars[1].rentalPrice = 1500.76;
			cars[1].EligibilityCriteria[0] = "LOL";
			cars[1].EligibilityCriteria[1] = "Intermediate";
			cars[1].EligibilityCriteria[2] = "Full";

			cars[2].model = "Space X rocket Ship";
			cars[2].rentalPrice = 15000.76;
			cars[2].EligibilityCriteria[0] = "LOL";
			cars[2].EligibilityCriteria[1] = "I'on think so!'";
			cars[2].EligibilityCriteria[2] = "Full";
		}

		void Rent(User *user){
			int choice;

			cout << "Please select a car to rent from (0, 1 or 2): " << endl;
			for(int i = 0; i < 3; i++){
				cout << cars[i].model << endl;
			}

			cin >> choice;

			if(user->getLicense() == cars[choice].EligibilityCriteria[0]
				|| user->getLicense() == cars[choice].EligibilityCriteria[1]
				|| user->getLicense() == cars[choice].EligibilityCriteria[2]){
				cout << "You can rent this car!" << endl;
			}else{
				cout << "You cannot rent this car!" << endl;
			}

		}

		~System(){
			delete[] cars;
		}

};

int main(){

	System rentalSystem;

	User user;
	user.registerUser(25, 101, "Learner", 1234567890); // Example user

	rentalSystem.Rent(&user);

	return 0;
}