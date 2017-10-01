// Filename: hashTable.cpp
//
// Author: Dan Watkins (dwatkins@wwzard.com)
//
// Date: 09/30/2017
//
// Description: Implement a hash table using separate chaining
//
#include <iostream>
#include <cstdlib>

using namespace std;

// define nullptr for older versions of cplusplus
#ifndef nullptr
#define nullptr 0
#endif

struct ListNode {
	int value;
	ListNode *next;
};

const int HASH_TABLE_SIZE = 10;  // Array size for hash table

// Function prototypes
//
ListNode *createNode();
int getLocation(ListNode *pListNode);
int getHashKey(int nValue);
void insertNode(ListNode *pListNode[], ListNode *pLN, int nPosition);
void deleteNode(ListNode *pListNode[], int nDeleteVal);
void printHashTable(ListNode *pListNode[]);
bool searchNode(ListNode *pListNode[], int nFindVal);
void destroyHashTable(ListNode *pListNode[]);

int main()
{
	char ch = 'q';
	ListNode *pListNode[HASH_TABLE_SIZE];

	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		pListNode[i] = nullptr;
	}

	do {
		cout << "What would you like to do? \n";
		cout << "a - add list node ...\n";
		cout << "d - delete list node ...\n";
		cout << "s - search for value ...\n";
		cout << "x - destroy hash table ...\n";
		cout << "p - print hash table...\n";
		cout << "q - quit program...\n";

		cin >> ch;

		ListNode *np;
		int nPosition;
		int nValue;
		bool bExists;

		switch (ch) {
			case 'a':
				cout << "Adding list node ...\n";

				np = createNode();
				nPosition = getLocation(np);
				insertNode(pListNode, np, nPosition);
				break;

			case 'd':
				cout << "Deleting list node ...\n";
				cout << "Enter a value for the list node to delete. \n";
				cin >> nValue;
				deleteNode(pListNode, nValue);
				printHashTable(pListNode);
				break;

			case 's':
				cout << "Search for value ...\n";
				cout << "Enter a value for the list node to search. \n";
				cin >> nValue;
				bExists = searchNode(pListNode, nValue);

				bExists ? cout << "found\n" : cout << "not found\n";
				break;

			case 'x':
				cout << "Destroying hash table ...\n";
				destroyHashTable(pListNode);
				break;

			case 'p':
				cout << "Printing hash table...\n";
				printHashTable(pListNode);
				break;

			case 'q':
				cout << "Quitting\n";
				destroyHashTable(pListNode);
				break;

			default:
				cout << "Invalid action, please try again...\n";
				break;
		}
	} while (ch != 'q');

	return 0;
}

ListNode *createNode()
{
	ListNode *pListNode = new ListNode;

	pListNode->value = 0;
	pListNode->next = nullptr;

	return pListNode;
}

int getLocation(ListNode *pListNode)
{
	int val = rand();
	pListNode->value = val;

	return getHashKey(val);
}

int getHashKey(int nValue)
{
	return (nValue % HASH_TABLE_SIZE);
}

void insertNode(ListNode *pListNode[], ListNode *pLN, int nPosition)
{
	if (pListNode[nPosition] == nullptr) {
		pListNode[nPosition] = pLN;
	}
	else {
		ListNode *nodePtr = pListNode[nPosition];
		ListNode *prevPtr = nullptr;

		while (nodePtr != nullptr && nodePtr->value < pLN->value) {
			prevPtr = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (prevPtr == nullptr) { //creating head
			pListNode[nPosition] = pLN;
			pLN->next = nodePtr;
		}
		else {
			prevPtr->next = pLN;
			pLN->next = nodePtr;
		}
	}
}

void printHashTable(ListNode *pListNode[])
{
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		cout << "Index: " << i << "\n";

		if (pListNode[i] != nullptr) {
			ListNode *pMyListNode = pListNode[i];

			while (pMyListNode != nullptr) {
				cout << pMyListNode->value << "\n";
				pMyListNode = pMyListNode->next;
			}

			cout << "\n";
		}
		else {
			cout << "Hash table is empty\n\n";
		}
	}
}

void destroyHashTable(ListNode *pListNode[])
{
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		if (pListNode[i] != nullptr) {
			ListNode *pThisListNode = pListNode[i];

			while (pThisListNode != nullptr) {
				ListNode *pNextPtr = pThisListNode->next;
				delete pThisListNode;
				pThisListNode = pNextPtr;
			}

			pListNode[i] = nullptr;
		}
	}
}

bool searchNode(ListNode *pListNode[], int nFindVal)
{
	int nHashKey = getHashKey(nFindVal);

	ListNode *pThisListNode = pListNode[nHashKey];

	while (pThisListNode != nullptr) {
		if (pThisListNode->value == nFindVal) {
			return true;
		}

		if (pThisListNode->value > nFindVal) {
			return false;
		}

		pThisListNode = pThisListNode->next;
	}

	return false;
}

void deleteNode(ListNode *pListNode[], int nDeleteVal)
{

	int nHashKey = getHashKey(nDeleteVal);

	ListNode *pThisListNode = pListNode[nHashKey];
	ListNode *pPrevNode = nullptr;

	bool bFoundNode = false;

	while (pThisListNode != nullptr) {
		if (pThisListNode->value == nDeleteVal) {
			cout << "Found value, deleting...\n";

			if (pPrevNode == nullptr) { // At head
				if (pThisListNode->next) {  // Set head to next
					pListNode[nHashKey] = pThisListNode->next;
				}
				else { // Only one in list
					pListNode[nHashKey] = nullptr;
				}
			}
			else {
				pPrevNode->next = pThisListNode->next;
			}

			delete pThisListNode;
			bFoundNode = true;

			break;
		}

		if (pThisListNode->value > nDeleteVal) {
			// not found, break
			break;
		}

		pPrevNode = pThisListNode;
		pThisListNode = pThisListNode->next;
	}

	if (!bFoundNode) {
		cout << "Value not found\n";
	}
}
