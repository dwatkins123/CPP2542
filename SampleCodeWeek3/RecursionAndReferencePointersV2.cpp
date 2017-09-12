#include <iostream>
using namespace std;

void showLoop(int i)
{
	while (i > 0) {
		cout << "i is: " << i << endl;
		i--;
	}
}

void showRecursion(int i)
{
	if (i > 0) {
		cout << "i is: " << i << endl;
		i--;
		showRecursion(i);
		cout << "i is: " << i << endl;
	}
}

void func(int *&p, int v)
{
	cout << "func: ptr " << p << endl;
	p = &v;
	cout << "func: ptr " << p << endl;
}

int main()
{
	int i = 5, *ptr;
	int val = 10;

	ptr = &i;
	cout << "ptr: " << ptr << endl;
	func(ptr, val);
	cout << "ptr: " << ptr << endl;

	return 0;
}
