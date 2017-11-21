#include <iostream>
using namespace std;

class A {
public:
	int x;

	A() {
		x = 0;
	}
};

class B : public A {
public:
	B() {
		x = 1;
	}
};

class C : private B {
public:
	C() {
		x = 2;
	}
};

int main1()
{
	C c1;
	cout << c1.x << endl;

	system("pause");
	return 0;
}
