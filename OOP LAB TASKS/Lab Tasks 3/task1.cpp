#include <iostream>
#include <string>
using namespace std;

/*
Create a class User with two public fields: int Age and string Name. In the Main method, create an object of class
User and set Name to &quot;Teo&quot; and Age to 24. Then, output to the screen: &quot;My name is {Name} and I&#39;m {Age} years
old.&quot; using object fields for Name and Age.
*/

class person_whos_name_is_gonna_be_Teo{

	public:
		int age;
		string name;

		void getNameAndAge(){
			cout << "My name is " << this->name << " and my age is " << this->age << endl;
		}
};


int main(int argc, char* argv[]){

	person_whos_name_is_gonna_be_Teo weirdo1;

	weirdo1.age = 24;
	weirdo1.name = "Teo";
	weirdo1.getNameAndAge();

	return 0;
}