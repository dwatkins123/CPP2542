#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int intArr[] = { 1, 3, 5, 7, 9, 11, 13, 19, 15, 17 };
	vector<int> v1(intArr, intArr + 12);
	vector<int>::const_iterator i1;

	i1 = v1.cbegin();

	while (i1 != v1.cend()) {
		cout << *i1 << " ";
		i1++;
	}

	cout << endl;

	v1[10] = -1;
	v1[11] = -1;

	i1 = v1.cbegin();
	
	while (i1 != v1.cend()) {
		cout << *i1 << " ";
		i1++;
	}

	cout << endl;

	/* Illegal - beyond scope 
	v1[12] = -1;
	*/

	v1.push_back(-1);
	cout << "size of v1 : " << v1.size() << endl;

	vector<int> v2(v1.begin(), v1.end());
	i1 = v2.begin();

	while (i1 != v2.cend()) {
		cout << *i1 << " ";
		i1++;
	}

	cout << endl;

	i1 = v2.cbegin();

	while (i1 != v2.cend()) {
		cout << *i1 << " ";
		i1++;
	}

	cout << endl;


	vector<int> v3(v1.cbegin() + 4, v1.cend());

	i1 = v3.cbegin();

	while (i1 != v3.cend()) {
		cout << *i1 << " ";
		i1++;
	}

	cout << endl;

	system("pause");
	return 0;
}
