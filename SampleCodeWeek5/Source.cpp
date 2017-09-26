#include <iostream>

using namespace std;

struct ListNode {
	int value;
	ListNode *next;
};

// Function prototypes
//
ListNode *CreateNode();
int GetLocation(ListNode *pListNode);
void InsertNode(ListNode *pListNode[], ListNode *pLN, int nPostion);
void Print(ListNode *pListNode[], int nArraySize);

int main()
{
	char ch = 'q';
	ListNode *pListNode[10];

	for (int i = 0; i < 10; i++) {
		pListNode[i] = nullptr;
	}

	do {
		cout << "What would you like to do? \n";
		cout << "a - add...\n";
		cout << "d - destroy...\n";
		cout << "p - print...\n";
		cout << "q - quit...\n";

		cin >> ch;

		ListNode *np;
		int nPosition;

		switch (ch) {
			case 'a':
				cout << "Adding...\n";

				np = CreateNode();
				nPosition = GetLocation(np);
				InsertNode(pListNode, np, nPosition);

				break;

			case 'd':
				cout << "Destroying...\n";
				Delete(pListNode, 10);
				break;

			case 'p':
				cout << "Printing...\n";
				Print(pListNode, 10);
				break;

			case 'q':
				cout << "Quitting\n";
				Delete(pListNode, 10);
				break;

			default:
				cout << "Try again\n";
				break;
		}
	} while (ch != 'q');

	return 0;
}

ListNode *CreateNode()
{
	ListNode *pListNode = new ListNode;

	pListNode->value = 0;
	pListNode->next = nullptr;

	return pListNode;
}

int GetLocation(ListNode *pListNode)
{
	int val = rand();
	pListNode->value = val;

	return val % 10;
}

void InsertNode(ListNode *pListNode[], ListNode *pLN, int nPosition)
{
	if (pListNode[nPosition] == nullptr) {
		pListNode[nPosition] = pLN;
	}
	else {
		ListNode *nodePtr = pListNode[nPosition];
		ListNode *prevPtr = nullptr;

		while (nodePtr->next != nullptr && nodePtr->value < pLN->value) {
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

void Print(ListNode *pListNode[], int nArraySize)
{
	for (int i = 0; i < nArraySize; i++) {
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
			cout << "List is empty\n\n";
		}
	}
}

void Destroy(ListNode *pListNode[], int nArraySize)
{
	for (int i = 0; i < nArraySize; i++) {
		if (pListNode[i] != nullptr) {
			ListNode *pThisListNode = pListNode[i];

			while (pThisListNode != nullptr) {
				ListNode *pNextPtr = pThisListNode->next;
				delete pThisListNode;
				pThisListNode = pNextPtr;
			}
		}
	}
}
