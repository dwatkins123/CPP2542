#ifndef LIST_H
#define LIST_H

struct ListNode {
	int value;
	ListNode *next;
};

class MyLinkedList
{
private:
	ListNode *m_pHead;

protected:
	MyLinkedList();
	~MyLinkedList();

	void AddToBeginning(int nValue);
	int RemoveFromBeginning();
	int RemoveFromEnd();
};

const int EMPTY_LIST = -99999;
#endif
