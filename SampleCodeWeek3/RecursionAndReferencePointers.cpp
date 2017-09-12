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

int main()
{
	int i = 5;
	showLoop(i);

	cout << "using recursion: " << endl;
	showRecursion(i);

	// system("pause");  Windows only
	return 0;
}

