// Filename: Arrays.cpp
//
// Author: Dan Watkins (dwatkins@wwzard.com)
//
// Date: 08/24/2017
//
// Description: Perform operations on arrays and pointers
//

#include <iostream>
#include <cstdlib>

using namespace std;

// function prototypes

int *createArray(int nArraySize);
void copyArray(const int srcArray[], int *pDestArray, int nSize);
void printArray(const int *pArray, int nSize);
void freeMemory(int *pArray);

// Function name: main()
// 
// Parameters: none
//
// Return values - int - 0 for success
// 
// Description: Declares static array and calls the
//              array functions
//
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	const int ARRAY_SIZE = 10;

	int *pNewArray = createArray(ARRAY_SIZE);
	copyArray(array, pNewArray, ARRAY_SIZE);
	printArray(pNewArray, ARRAY_SIZE);
	freeMemory(pNewArray);
	return 0;
}

// Function name: createArray()
// 
// Parameters: int nArraySize, the size of the array to create
//
// Return values - int * - pointer to new integer array 
// 
// Description: Creates an integer array of the specified size
//
int *createArray(int nArraySize) 
{
	int *pNewArray = new int[nArraySize];
	return pNewArray;
}

// Function name: copyArray()
// 
// Parameters: const int srcArray - the source array to copy
//             int *pDestArray - pointer to the destination array
//             int nSize - the size of the array to copy
//
// Return values - none (void)
// 
// Description: Copy an array to another.  The destination array
//              must have been allocated to the correct size.
//
void copyArray(const int srcArray[], int *pDestArray, int nSize)
{
	for (int i = 0; i < nSize; i++) {
		pDestArray[i] = srcArray[i];
	}
}

// Function name: printArray()
// 
// Parameters: const int *pArray - ponter to the array to print
//             int nSize - the size of the array to print
//
// Return values - none (void)
// 
// Description: Print the contents of an integer array
//
void printArray(const int *pArray, int nSize)
{
	bool bFirstOne = true;

	for (int i = 0; i < nSize; i++) {
		if (bFirstOne) {
			bFirstOne = false;
		}
		else {
			cout << " ";
		}

		cout << *(pArray + i);
	}

	cout << "\n";
}

// Function name: freeMemory()
// 
// Parameters: int *pArray - ponter to the array to free
//
// Return values - none (void)
// 
// Description: Free the memory allocated to the passed array
//
void freeMemory(int *pArray)
{
	delete [] pArray;
}
