#include <iostream>
using namespace std;

// This function returns an array of N even numbers
int* getEvenNumbers(int N) {
	// Declaration of a static local integer array
	int *evenNumberArray = new int[100];
	int i, even = 2;

	for (i = 0; i<N; i++) {
		evenNumberArray[i] = even;
		even += 2;
	}
	// Returning base address of evenNumberArray array
	return evenNumberArray;
}

int main() {
	int *array, counter;
	array = getEvenNumbers(10);
	cout << "Even Numbers\n";
	for (counter = 0; counter<10; counter++) {
		cout << *(array + counter) << " ";
	}

	return 0;
}