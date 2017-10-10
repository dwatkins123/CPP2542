#ifndef LINKEDLISTADT_H
#define LINKEDLISTADT_H

struct ListNode {
	int value;
	ListNode *next;
};

class MyLinkedList
{
	private:
		ListNode *m_pHead;

	public:
		MyLinkedList();
		~MyLinkedList();

		void insertNode(int nValue);
		void deleteNode(int nValue);
		void printMyList();
		bool searchNode(int nValue);
		bool isEmpty();
};

#endif
