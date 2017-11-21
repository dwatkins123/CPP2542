#include <iostream>
using namespace std;

class A {

public:
	static int age;

	A() {

	}

	~A() {

	}

	void Print() {
		cout << age << endl;
	}
};


A a, *b;

/* Can not execute outside of main
b = new A();
a.Print();
*/

int main()
{
	char *s = "ABCDEF";
	string s2 = "ABCDEF";

	cout << "s: " << s + 2 << endl;
	cout << "a: " << s << endl;

	// A.age = 5;

	b = new A();
	a.Print();

	system("pause");
	return 0;
}
