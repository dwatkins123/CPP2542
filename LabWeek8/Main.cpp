#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

// define nullptr for older versions of cplusplus
#ifndef nullptr
#define nullptr 0
#endif

int main()
{
	MyStack *pStack = new MyStack;

	pStack->push(4);
	pStack->push(6);

	cout << pStack->pop() << "\n";

	MyQueue *pQueue = new MyQueue;

	pQueue->enqueue(4);
	pQueue->enqueue(6);

	cout << pQueue->dequeue() << "\n";

	delete pStack;
	delete pQueue;

	system("pause");
}
