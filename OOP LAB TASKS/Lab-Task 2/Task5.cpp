#include <iostream>
#include <string>
#include <algorithm>  
using namespace std;

struct struct_that_must_montain_an_id_and_a_name_and_I_was_out_of_names{
	int id;
	string name;
};

bool compareByID(const struct_that_must_montain_an_id_and_a_name_and_I_was_out_of_names &struct1, const struct_that_must_montain_an_id_and_a_name_and_I_was_out_of_names &struct2) {
	return struct1.id < struct2.id;
}

bool compareByName(const struct_that_must_montain_an_id_and_a_name_and_I_was_out_of_names &struct1, const struct_that_must_montain_an_id_and_a_name_and_I_was_out_of_names &struct2) {
	return struct1.name < struct2.name;
}


int main(){

	int count;

	cout << "Please enter the number of structs you want to create" << endl;
	cin >> count;
	struct_that_must_montain_an_id_and_a_name_and_I_was_out_of_names *structArr = new struct_that_must_montain_an_id_and_a_name_and_I_was_out_of_names[count];

	for(int i = 0; i < count; ++i){
		cout << "Please enter an id" << endl;
		cin >> structArr[i].id;
		cout << "Please enter a name" << endl;
		cin.ignore();
		getline(cin, structArr[i].name);
	}


	sort(structArr, structArr + count, compareByID);

	cout << "\nSorted by ID:\n";
	for (int i = 0; i < count; ++i) {
		cout << "ID: " << structArr[i].id << ", Name: " << structArr[i].name << endl;
	}

	sort(structArr, structArr + count, compareByName);

	cout << "\nSorted by Name:\n";
	for (int i = 0; i < count; ++i) {
		cout << "ID: " << structArr[i].id << ", Name: " << structArr[i].name << endl;
	}


	delete[] structArr;

	return 0;
}