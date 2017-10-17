#ifndef STACK_H
#define STACK_H

#include "list.h"

class MyStack : MyLinkedList
{
public:
	void push(int nValue);
	int pop();
};

#endif
