#include <iostream>
#include "LinkedListADT.h"

using namespace std;

MyLinkedList::MyLinkedList()
{
	m_pHead = nullptr;
}

MyLinkedList::~MyLinkedList()
{
	ListNode *pListNode = m_pHead;
	ListNode *pNextPtr;

	while (pListNode != nullptr) {
		pNextPtr = pListNode->next;
		delete pListNode;
		pListNode = pNextPtr;
	}
}

void MyLinkedList::insertNode(int nValue)
{
	ListNode *pNewNode = new ListNode;

	pNewNode->value = nValue;
	pNewNode->next = nullptr;

	if (m_pHead == nullptr) {  // List is empty
		m_pHead = pNewNode;
	}
	else {
		ListNode *pNodePtr = m_pHead;
		ListNode *pPrevPtr = nullptr;
		
		while (pNodePtr->next != nullptr && pNodePtr->value < nValue) {
			pPrevPtr = pNodePtr;
			pNodePtr = pNodePtr->next;
		}

		if (pPrevPtr == nullptr) {
			m_pHead = pNewNode;
			pNewNode->next = pNodePtr;
		}
		else if (pNodePtr->value > nValue) {
			pPrevPtr->next = pNewNode;
			pNewNode->next = pNodePtr;
		}
		else {
			pNodePtr->next = pNewNode;
		}
	}
}

void MyLinkedList::deleteNode(int nValue)
{
	if (m_pHead == nullptr) { // List is empty, nothing to delete
		return;
	}
	
	ListNode *pNodePtr;
	ListNode *pPrevPtr = nullptr;

	if (m_pHead->value == nValue) {
		pNodePtr = m_pHead->next;
		delete m_pHead;
		m_pHead = pNodePtr;
	}
	else {
		pNodePtr = m_pHead;

		while (pNodePtr != nullptr && pNodePtr->value != nValue) {
			pPrevPtr = pNodePtr;
			pNodePtr = pNodePtr->next;
		}

		if (pNodePtr == nullptr) { // not found 
			return;
		}

		if (pNodePtr->value == nValue) {
			if (pNodePtr->next) {
				pPrevPtr->next = pNodePtr->next;
			}
			else {
				pPrevPtr->next = nullptr;
			}

			delete pNodePtr;
		}
	}
}

void MyLinkedList::printMyList()
{
	ListNode *pNodePtr = m_pHead;

	while (pNodePtr) {
		cout << "elem: " << pNodePtr->value << "\n";
		pNodePtr = pNodePtr->next;
	}
}

bool MyLinkedList::searchNode(int nValue)
{
	if (m_pHead == nullptr) { // List is empty, nothing to search
		return false;
	}

	ListNode *pNodePtr;
	ListNode *pPrevPtr;

	if (m_pHead->value == nValue) {
		return true;
	}
	else {
		pNodePtr = m_pHead;

		while (pNodePtr != nullptr && pNodePtr->value != nValue) {
			pPrevPtr = pNodePtr;
			pNodePtr = pNodePtr->next;
		}

		if (pNodePtr == nullptr) { // not found
			return false;
		}

		if (pNodePtr->value == nValue) {
			return true;
		}

		return false;
	}
}

bool MyLinkedList::isEmpty()
{
	return (m_pHead == nullptr);
}
