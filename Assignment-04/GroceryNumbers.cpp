// Filename: GroceryNumbers.cpp
//
// Author: Dan Watkins (dwatkins@wwzard.com)
//
// Date: 10/23/2017
//
// Description: Implement a grocery store number queue with STL
//

#include <iostream>
#include <queue>

using namespace std;

// define nullptr for older versions of C++
#ifndef nullptr
#define nullptr 0
#endif

int main()
{
	char ch = 'q';

	// Loop through until they quit
	//
	int nCounter = 0;
	queue<int> nMyQueue;
	bool bWasDeleted;

	do {
		cout << "a - add a number to the list\n";
		cout << "d - delete from the list\n";
		cout << "r - remove a specific number from the list\n";
		cout << "p - print list\n";
		cout << "q - quit\n";

		cin >> ch;
		queue<int> nNewQueue;
		int nFirstEntry, nNoToDelete;

		switch (ch) {
			case 'a':
				cout << "Adding... \n";
				nCounter++;
				nMyQueue.push(nCounter);
				break;

			case 'd':
				cout << "Deleting... \n";

				if (!(nMyQueue.empty())) {
					nMyQueue.pop();
				}
				break;

			case 'r':
				if (nMyQueue.empty()) {
					cout << "Queue is empty\n";
					break;
				}

				nFirstEntry = nMyQueue.front();

				cout << "Remove - enter a number between " << nFirstEntry << " and " << nCounter << " to delete\n";
				cin >> nNoToDelete;

				bWasDeleted = false;

				if (nNoToDelete < nFirstEntry || nNoToDelete > nCounter) {
					cout << "Invalid entry\n";
					break;
				}

				// Copy all numbers except the one to delete to new queue;
				while (!(nMyQueue.empty())) {
					if (nMyQueue.front() != nNoToDelete) {
						nNewQueue.push(nMyQueue.front());
					}
					else {
						bWasDeleted = true;
					}

					nMyQueue.pop();
				}

				// copy back to the original queue
				nMyQueue = nNewQueue;

				if (bWasDeleted) {
					cout << "Number was deleted\n";
				}
				else {
					cout << "Number was not found\n";
				}

				break;

			case 'p':
				nNewQueue = nMyQueue;
				while (!(nNewQueue.empty())) {
					cout << nNewQueue.front() << "\n";
					nNewQueue.pop();
				}

				cout << "\n";
				break;

			case 'q':
				break;

			default:
				// Unrecognized action entered
				cout << "Try again\n";
				break;
		}
	} while (ch != 'q');

	system("pause");
	return 0;
}
