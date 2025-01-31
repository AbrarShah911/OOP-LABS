#include <iostream>
#include <cstdlib>


void* incArray(void* arr, int size);


int main(int argc, char* argv[]){

	int size = argc -1;
	int* newArr = new int[size];

	for(int i = 0; i<size;i++){
		newArr[i] = std::atoi(argv[i+1]);
	}

	void* modifiedArr = incArray(static_cast<int*>(newArr), size);

	int* result = static_cast<int*>(modifiedArr);

	for(int i = 0; i<size;i++){
		std::cout<<result[i]<<std::endl;
	}

		delete[] newArr;

	return 0;
}


void* incArray(void* arr, int size){
	int* intArr = static_cast<int*>(arr);
	for(int i = 0; i<size;i++){
		intArr[i] = intArr[i] + 5;
	}
	return intArr;
}