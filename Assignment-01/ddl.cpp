// Filename: ddl.cpp
//
// Author: Dan Watkins (dwatkins@wwzard.com)
//
// Date: 08/31/2017
//
// Description: Implement a double linked list with various operations
//
#include <iostream>

using namespace std;

// define nullptr for older versions of C++
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

	int val, elementKey;
	bool bKeyFound = false;

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
			case 'i':
				// i - insert at beginning of list
				// make new node new head, next is former head
				// (if there was one)
				//
				cout << "inserting at beginning of list\n";
				cout << "enter an integer ";
				cin >> val;

				newNode = new ListNode;
				newNode->value = val;
				newNode->next = nullptr;
				newNode->previous = nullptr;

				// if empty list, new node becomes both head and tail
				if (head == nullptr) {
					head = newNode;
					tail = newNode;
				}
				else {
					nodePtr = head;
					head = newNode;
					head->next = nodePtr;
					nodePtr->previous = head;
				}

				break;
			
			case 'd':
				// d - delete from beginning of list
				//
				cout << "deleting item from beginning of list\n";

				if (head == nullptr) {
					cout << "Empty list, nothing to delete\n";
				}
				else if (head->next == nullptr) {
					// delete, but list is empty
					delete head;
					head = nullptr;
					tail = nullptr;
				}
				else {
					nodePtr = head->next;
					delete head;
					head = nodePtr;
					nodePtr->previous = nullptr;
				}

				break;

			case 'a':
				// a - insert last - add element to end of list
				// make node new tail, previous is old tail, if
				// there was one
				//
				cout << "adding to end of list\n";
				cout << "enter an integer ";
				cin >> val;

				newNode = new ListNode;
				newNode->value = val;
				newNode->next = nullptr;
				newNode->previous = nullptr;

				// if empty list, new node becomes both head and tail
				if (head == nullptr) {
					head = newNode;
					tail = newNode;
				}
				else {
					nodePtr = tail;
					tail = newNode;
					tail->previous = nodePtr;
					nodePtr->next = tail;
				}

				break;

			case 'D':
				// D - delete from end of list
				//
				cout << "deleting item from end of list\n";

				if (tail == nullptr) {
					cout << "Empty list, nothing to delete\n";
				}
				else if (tail->previous == nullptr) {
					// delete, but list is empty
					delete tail;
					head = nullptr;
					tail = nullptr;
				}
				else {
					nodePtr = tail->previous;
					delete tail;
					tail = nodePtr;
					nodePtr->next = nullptr;
				}

				break;

			case 'I':
				// I - insert after an element by value
				//
				cout << "inserting at after an element\n";
				cout << "enter an integer to insert: ";
				cin >> val;
				cout << "\nEnter the value to insert after: ";
				cin >> elementKey;

				// Walk thru list searching for key to insert after
				nodePtr = head;

				bKeyFound = false;

				while (nodePtr != nullptr) {
					if (nodePtr->value == elementKey) {
						bKeyFound = true;

						newNode = new ListNode;
						newNode->value = val;
						newNode->next = nullptr;
						newNode->previous = nullptr;

						nextPtr = nodePtr->next;

						if (nextPtr) {
							newNode->next = nextPtr;
						}
						else {
							// new node is new tail
							tail = newNode;
						}

						nodePtr->next = newNode;
						nextPtr->previous = newNode;
						newNode->previous = nodePtr;
						break; // out of while loop
					}

					nodePtr = nodePtr->next;
				}

				if (!bKeyFound) {
					cout << "Key not found, no insert\n";
				}

				break;

			case 'r':
				// r - delete using key ("remove")
				//
				cout << "deleting (\"removing\") an element by key\n";
				cout << "Please enter the key of the element to remove\n";
				cin >> val;

				// Walk thru list searching for key to insert after
				nodePtr = head;

				bKeyFound = false;

				while (nodePtr != nullptr) {
					if (nodePtr->value == val) {
						bKeyFound = true;
						prevPtr = nodePtr->previous;
						nextPtr = nodePtr->next;

						if (prevPtr == nullptr && nextPtr == nullptr) { // deleting last element in list
							head = nullptr;
							tail = nullptr;
						}
						else if (prevPtr == nullptr) { // Element was head
							head = nextPtr;
							nextPtr->previous = nullptr;
						}
						else if (nextPtr == nullptr) { // Element was tail
							tail = prevPtr;
							prevPtr->next = nullptr;
						}
						else {
							nextPtr->previous = prevPtr;
							prevPtr->next = nextPtr;
						}

						break; // out of while loop
					}

					nodePtr = nodePtr->next;
				}

				if (!bKeyFound) {
					cout << "Key not found, no insert\n";
				}

				break;

			case 'p':
				// p - display forward
				// walk the list from head forward
				//
				if (head == nullptr) {
					cout << "No items in list\n";
				}
				else {
					nodePtr = head;

					while (nodePtr) {
						cout << "elem: " << nodePtr->value << "\n";
						nodePtr = nodePtr->next;
					}
				}

				break;

			case 'P':
				// P - display backward
				// walk the list from tail backward
				//
				if (tail == nullptr) {
					cout << "No items in list\n";
				}
				else {
					nodePtr = tail;

					while (nodePtr) {
						cout << "elem: " << nodePtr->value << "\n";
						nodePtr = nodePtr->previous;
					}
				}

				break;

			case 'q':
				cout << "quitting\n";

				// free memory allocated
				//
				nodePtr = head;

				while (nodePtr != nullptr) {
					prevPtr = nodePtr->next;
					delete nodePtr;
					nodePtr = prevPtr;
				}

				head = nullptr;
				break;

				default:
					// Unrecognized action entered
					cout << "Try again\n";
					break;
			}
	} while (ch != 'q');

	return 0;
}
