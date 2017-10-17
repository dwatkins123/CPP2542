#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

class MyQueue : MyLinkedList
{
public:
	void enqueue(int nValue);
	int dequeue();
};

#endif
