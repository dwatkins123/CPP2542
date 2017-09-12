#include <iostream>
using namespace std;

#ifndef nullptr
#define nullptr 0
#endif

struct TreeNode {
	int value;
	TreeNode *left;
	TreeNode *right;
};

TreeNode *root = nullptr;

void insertNode(int num);
void printNode();
void PreOrder(TreeNode *nodePtr);
void PostOrder(TreeNode *nodePtr);
void InOrder(TreeNode *nodePtr);

int main()
{
	char ch;
	int num;

	do {
		cout << " i-insert\n d-delete\n p-print\n q-quit ";
		cin >> ch;

		switch (ch) {
			case 'i':
				cout << "Please enter a value to be inserted: ";
				cin >> num;
				insertNode(num);
				break;

			case 'd':
			case 'p':
				printNode();
				break;

			case 'q':
				return 0;
				break;

			default:
				cout << "invalid entry " << endl;
				break;
		}

	} while (ch != 'q');

	return 0;
}

void insert(TreeNode *&nodePtr, TreeNode *newNode)
{
	if (nodePtr == nullptr) {
		nodePtr = newNode;
	}
	else if (newNode->value < nodePtr->value) {
		insert(nodePtr->left, newNode);
	}
	else if (newNode->value > nodePtr->value) {
		insert(nodePtr->right, newNode);
	}
}

void insertNode(int num)
{
	TreeNode *newNode;
	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = nullptr;
	newNode->right = nullptr;


	insert(root, newNode);
}

void printNode()
{
	int val;
	cout << "Please select traversing mechanism " << endl;
	cout << " 1-PreOrder\n 2-PostOrder\n 3-InOrder";
	cin >> val;

	switch (val) {
		case 1:
			PreOrder(root);
			break;
		case 2:
			PostOrder(root);
			break;
		case 3:
			InOrder(root);
			break;
		default:
			cout << "invalid option, I'm going back\n";
			break;
	}
}


void PreOrder(TreeNode *nodePtr) {
	if (nodePtr != nullptr) {
		cout << nodePtr->value << endl;
		PreOrder(nodePtr->left);
		PreOrder(nodePtr->right);
	}
}

void PostOrder(TreeNode *nodePtr) {
	if (nodePtr != nullptr) {
		PostOrder(nodePtr->left);
		PostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}

void InOrder(TreeNode *nodePtr) {
	if (nodePtr != nullptr) {
		InOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		InOrder(nodePtr->right);
	}
}

