#include <iostream>
#include "stack.h"

using namespace std;

void MyStack::push(int n)
{
	AddToBeginning(n);
}

int MyStack::pop()
{
	return RemoveFromBeginning();
}
