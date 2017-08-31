// Filename: DoubleLinkedList.cpp
//
// Author: Dan Watkins (dwatkins@wwzard.com)
//
// Date: 08/31/2017
//
// Description: Implement a double linked list with various operations
//
#include <iostream>

using namespace std;

// define nullptr for older versions of cplusplus
#ifndef nullptr
#define nullptr 0
#endif

int main()
{
	// The list node structure.  With both next and previous pointers,
	// it becomes a "doubly" linked list.
	//
	struct ListNode {
		int value;
		ListNode *next;
		ListNode *previous;
	};

	// Various pointers to ListNode needed
	//
	ListNode *head = nullptr;
	ListNode *tail = nullptr;
	ListNode *nodePtr = nullptr;
	ListNode *newNode = nullptr;
	ListNode *prevPtr = nullptr;
	ListNode *nextPtr = nullptr;

	// Action character
	char ch = 'q';

	// Loop through until they quit
	//
	do {
		cout << "i - insertion - add to beginning of list\n";
		cout << "d - deletion - delete element at beginning of list\n";
		cout << "a - insert last - add element to end of list\n";
		cout << "D - delete last - delete element at end of list\n";
		cout << "I - insert after - add an element after an item of the list\n";
		cout << "r - delete - delete an element from the list using the key\n";
		cout << "p - display forward - display the complete list in a forward manner\n";
		cout << "P - display forward - display the complete list in a backward manner\n";
		cout << "q - quit\n";

		cin >> ch;

		switch (ch) {
		case 'a':
			cout << "adding\n";
			cout << "enter an integer ";
			int val;
			cin >> val;

			newNode = new ListNode;
			newNode->value = val;
			newNode->next = nullptr;

			if (head == nullptr) {
				head = newNode;
			}
			else {
				nodePtr = head;
				while (nodePtr->next != nullptr) {
					cout << "hello" << endl;
					nodePtr = nodePtr->next;
				}
				nodePtr->next = newNode;
			}

			cout << "head elem: " << head->value << "\n";
			break;

		case 'i':
			cout << "inserting\n";
			cout << "enter an integer ";
			cin >> val;

			newNode = new ListNode;
			newNode->value = val;
			newNode->next = nullptr;

			if (head == nullptr) {
				head = newNode;
			}
			else {
				nodePtr = head;
				while (nodePtr->next != nullptr && nodePtr->value < val) {
					prevPtr = nodePtr;
					nodePtr = nodePtr->next;
				}
				if (prevPtr == nullptr) {
					head = newNode;
					newNode->next = nodePtr;
				}
				else if (nodePtr->value > val) {
					prevPtr->next = newNode;
					newNode->next = nodePtr;
				}
				else {
					nodePtr->next = newNode;
				}
			}

			cout << "head elem: " << head->value << "\n";
			break;

		case 'd':
			cout << "deleting\n";
			cout << "enter a value to be deleted ";
			cin >> val;

			if (head == nullptr) {
				return 0;
			}

			if (head->value == val) {
				nodePtr = head->next;
				delete head;
				head = nodePtr;
			}
			else {
				nodePtr = head;
				while (nodePtr != nullptr && nodePtr->value != val) {
					prevPtr = nodePtr;
					nodePtr = nodePtr->next;
				}

				if (nodePtr->value == val) {
					if (nodePtr->next) {
						prevPtr->next = nodePtr->next;
					}
					else {
						prevPtr->next = nullptr;
					}

					delete nodePtr;
				}
			}

			break;

		case 'p':
			cout << "printing ...\n";

			nodePtr = head;

			while (nodePtr) {
				cout << "elem: " << nodePtr->value << "\n";
				nodePtr = nodePtr->next;
			}

			break;

		case 'q':
			cout << "quitting\n";

			while (nodePtr != nullptr) {
				prevPtr = nodePtr->next;
				delete nodePtr;
				nodePtr = prevPtr;
			}

			head = nullptr;
			break;


		default:
			cout << "Try again\n";
			break;
		}
	} while (ch != 'q');

	// system("pause"); - Windows only extension
	return 0;
}

