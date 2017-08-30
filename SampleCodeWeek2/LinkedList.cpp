#include <iostream>

using namespace std;

// define nullptr for older versions of cplusplus
#ifndef nullptr
#define nullptr 0
#endif

int main()
{
	struct ListNode {
		int value;
		ListNode *next;
	};

	ListNode *head = nullptr;
	ListNode *nodePtr = nullptr;
	ListNode *newNode = nullptr;
	ListNode *prevPtr = nullptr;

	char ch = 'q';

	do {
		cout << "a - add\n";
		cout << "i - insert\n";
		cout << "d - delete\n";
		cout << "p - print\n";
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
