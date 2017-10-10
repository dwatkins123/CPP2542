#include <iostream>
#include "LinkedListADT.h"

using namespace std;

// define nullptr for older versions of cplusplus
#ifndef nullptr
#define nullptr 0
#endif

int main()
{
	char ch = 'q';

	MyLinkedList *pLinkedList = new MyLinkedList;
	int val;
	bool flag;

	do {
		cout << "i - insert\n";
		cout << "d - delete\n";
		cout << "p - print\n";
		cout << "s - search\n";
		cout << "f - is empty\n";
		cout << "q - quit\n";

		cin >> ch;

		switch (ch) {
			case 'i':
				cout << "enter a value to insert \n";
				cin >> val;

				pLinkedList->insertNode(val);
				break;

			case 'd':
				cout << "enter a value to delete \n";
				cin >> val;

				pLinkedList->deleteNode(val);
				break;

			case 'p':
				cout << "printing ...\n";

				pLinkedList->printMyList();
				break;

			case 's':
				cout << "enter a value to be searched \n";
				cin >> val;

				flag = pLinkedList->searchNode(val);

				flag ? cout << "node found\n" : cout << "node not found\n";
				break;

			case 'f':
				flag = pLinkedList->isEmpty();

				flag ? cout << "List is empty\n" : cout << "List is not empty\n";
				break;

			case 'q': cout << "quitting ... " << endl;
				break;

			default:
				cout << "Try again\n";
				break;
		}
	} while (ch != 'q');

	// system("pause"); - Windows only extension
	delete pLinkedList;
	return 0;
}
