#include <iostream>
using namespace std;

// Write a program that can resize a single dimension int array if the elements exceed the total size.
//Consider an int array of size 5 (uninitialized), you start adding items to the array and if the quantity of
//the elements exceeds double the array size. Once finished resizing the array again to the max quantity of
//the elements present in the array.

void resizeArray(int* &arr, int &size, int newSize);

int main() {
	int size = 5;
	int count = 0;
	int* arr = new int[size];

	int num;
	while (true) {
	 	cin >> num;
	 	if (num == -1) break;
	    
	 	if (count >= size) {
	    	resizeArray(arr, size, size * 2);
		}
	    
		arr[count++] = num;
	}

	if (count < size) {
		resizeArray(arr, size, count); // Resize to exact count
	}

	cout << "Final array contents: ";
	for (int i = 0; i < count; ++i) {
		cout << arr[i] << " ";
	}
	cout << "\n";

	delete[] arr;
	return 0;
}

void resizeArray(int*& arr, int& size, int newSize){

	int* newArr = new int[newSize];

	for(int i = 0; i < size; i++){
		newArr[i] = arr[i];
	}

	delete[] arr;
	arr = newArr;
	size = newSize;

}