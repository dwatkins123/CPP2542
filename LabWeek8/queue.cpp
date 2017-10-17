#include <iostream>
#include "queue.h"

using namespace std;

void MyQueue::enqueue(int n)
{
	AddToBeginning(n);
}

int MyQueue::dequeue()
{
	return RemoveFromEnd();
}
