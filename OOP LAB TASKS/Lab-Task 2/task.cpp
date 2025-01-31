#include <iostream>

int main(int argc, char* argv[]){

	int sum = 0;
	int *arr = new int[argc-1];

	for(int i = 0; i<argc-1;i++){
		*(arr+i) = std::atoi(argv[i+1]);
	}

	for(int i = 0; i<argc-1;i++){
		sum += arr[i];
	}

	std::cout<<sum<<std::endl;

	delete[] arr;

	return 0;
} 