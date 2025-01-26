#include <iostream>
#include <cstdlib>

int main(int argc, char* args[]){

	float* newArr = new float[argc];

	for(int i = 1; i<argc;i++){
		newArr[i-1] = std::stof(args[i]);
	}

	for(int i = 0; i<argc-2;i++){
		 for(int j = 0; j<argc-i-2;j++){
		 	if (newArr[j] > newArr[j+1]){
		 		float temp = newArr[j+1];
		 		newArr[j+1] = newArr[j];
		 		newArr[j] = temp;
		 	}
		 }
	}

	std::cout<<"Second Highest Number is: " << newArr[argc-3] << "." << std::endl;

	delete[] newArr;

	return 0;
}