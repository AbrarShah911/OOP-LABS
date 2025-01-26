#include <iostream>

int main(int argc, char* args[]){

	int sum = 0;

	for(int i = 1; i<argc;i++){
		sum += std::stoi(args[i]);
	}

	std::cout<<"SUM: " << sum << " ." << std::endl;

	return 0;
}