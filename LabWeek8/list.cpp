#include <iostream>
#include "list.h"

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

void MyLinkedList::AddToBeginning(int nValue)
{
	ListNode *pNewNode = new ListNode;

	pNewNode->value = nValue;
	pNewNode->next = nullptr;

	if (m_pHead == nullptr) {  // List is empty
		m_pHead = pNewNode;
	}
	else {
		ListNode *pNodePtr = m_pHead;
		m_pHead = pNewNode;
		pNewNode->next = pNodePtr;
	}
}

int MyLinkedList::RemoveFromBeginning()
{
	if (m_pHead == nullptr) {  // List is empty
		return EMPTY_LIST;
	}

	int nReturnValue = m_pHead->value;

	if (m_pHead->next != nullptr) {
		delete m_pHead;
		m_pHead = nullptr;
	}
	else {
		ListNode *newHeadNode = m_pHead->next;
		delete m_pHead;
		m_pHead = newHeadNode;
	}

	return nReturnValue;
}

int MyLinkedList::RemoveFromEnd()
{
	if (m_pHead == nullptr) { // List is empty, nothing to delete
		return EMPTY_LIST;
	}

	ListNode *pNodePtr = m_pHead;
	ListNode *pPrevPtr = nullptr;

	if (m_pHead->next == nullptr) {
		int nReturnValue = m_pHead->value;
		delete m_pHead;
		m_pHead = nullptr;
		return nReturnValue;
	}

	while (pNodePtr != nullptr) {
		pPrevPtr = pNodePtr;
		pNodePtr = pNodePtr->next;
	}

	int nReturnValue = pPrevPtr->value;
	
	delete pNodePtr;

	return nReturnValue;
}
