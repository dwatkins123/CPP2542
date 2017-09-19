#include <iostream>
using namespace std; // define nullptr for older versions of cplusplus
#ifndef nullptr define nullptr 0 endif
int main() {
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
		cout << "e - add to the end...\n";
		cout << "i - insert in the middle...\n";
		cout << "b - add to the beginning...\n";
		cout << "d - find & delete...\n";
		cout << "h - delete head...\n";
		cout << "t - delete tail ...\n";
		cout << "p - print...\n";
		cout << "s - search...\n";
		cout << "f - empty...\n";
		cout << "q - quit\n";
		cin >> ch;
		switch (ch) {
		case 'e':
			cout << "adding to the end...\n";
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
			cout << "inserting in the middle...\n";
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
				while (nodePtr->next != nullptr && 
nodePtr->value < val) {
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
		case 'b':
			cout << "adding to the beginning...\n";
			cout << "enter a value to be added to the 
beginning ";
			cin >> val;
			newNode = new ListNode;
			newNode->value = val;
			newNode->next = nullptr;
			if (head == nullptr) {
				head = newNode;
			}
			else {
				newNode->next = head;
				head = newNode;
			}
			break;
		case 'd':
			cout << "find and delete...\n";
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
				while (nodePtr != nullptr && 
nodePtr->value != val) {
					prevPtr = nodePtr;
					nodePtr = nodePtr->next;
				}
				if (nodePtr->value == val) {
					if (nodePtr->next) {
						prevPtr->next = 
nodePtr->next;
					}
					else {
						prevPtr->next = nullptr;
					}
					delete nodePtr;
				}
			}
			break;
		case 'h':
			cout << "h -- delete head ... \n";
			if (head == nullptr) {
				cout << "list is empty\n";
			}
			else {
				nodePtr = head->next;
				delete head;
				head = nodePtr;
			}
			break;
		case 't':
			cout << "t -- delete tail ...\n";
			if (head == nullptr) {
				cout << "nothing to delete\n";
			}
			else {
				nodePtr = head;
				while (nodePtr->next != nullptr) {
					prevPtr = nodePtr;
					nodePtr = nodePtr->next;
				}
				prevPtr->next = nullptr;
				delete nodePtr;
				nodePtr = nullptr;
			}
			break;
		case 'p':
			cout << "printing ...\n";
			nodePtr = head;
			while (nodePtr) {
				cout << "elem: " << nodePtr->value << 
"\n";
				nodePtr = nodePtr->next;
			}
			break;
		case 's':
			cout << "enter a value to be searched \n";
			cin >> val;
			nodePtr = head;
			while (nodePtr != nullptr) {
				if (val == nodePtr->value) {
					cout << "found it" << endl;
					system("pause");
					break;
				}
				nodePtr = nodePtr->next;
			}
			break;
		case 'f':
			if (head == nullptr) {
				cout << "list is empty\n";
			}
			else {
				cout << "list is not empty\n";
			}
			break;
		case 'q':
			cout << "quitting\n";
			nodePtr = head;
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
	system("pause");
	return 0;
}
