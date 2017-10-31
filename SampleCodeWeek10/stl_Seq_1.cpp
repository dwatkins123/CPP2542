#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	array<int, 10> nArray;
	cout << "size of array is : " << nArray.size() << "\n";
	cout << "maxsize of array is : " << nArray.max_size() << "\n";


	vector<int> nVector;
	cout << "size of vector is : " << nVector.size() << "\n";
	cout << "capacity of vector is : " << nVector.capacity() << "\n";
	cout << "maxsize of vector is : " << nVector.max_size() << "\n";

	vector<int> nVector2 = { 1, 3, 5, 7, 9 };
	cout << "size of vector2 is : " << nVector2.size() << "\n";
	cout << "capacity of vector2 is : " << nVector2.capacity() << "\n";
	cout << "maxsize of vector2 is : " << nVector2.max_size() << "\n";

	vector<int> nVector3 = { 1, 3, 5, 7, 9 };
	cout << "size of vector3 is : " << nVector3.size() << "\n";
	cout << "capacity of vector3 is : " << nVector3.capacity() << "\n";
	cout << "maxsize of vector3 is : " << nVector3.max_size() << "\n";

	cout << "printing array" << "\n";

	for (int i = 0; i < nArray.size(); i++) {
		nArray[i] = i;
	}

	for (int i = 0; i < nArray.size(); i++) {
		cout << nArray[i] << " ";
	}

	cout << "\n";

	cout << "Printing second array\n";

	// nArray.assign(0);

	for (int i = 0; i < nArray.size(); i++) {
		cout << nArray[i] << " ";
	}

	cout << "\n";

	cout << "at is: " << nArray.at(6) << "\n";

	array<int, nArray.size()>::iterator ai1;
	ai1 = nArray.begin();

	while (ai1 != nArray.end()) {
		cout << "e: " << *ai1++ << "\n";
	}

	array<int, nArray.size()>::const_iterator ai2;
	ai2 = nArray.cbegin();

	while (ai2 != nArray.cend()) {
		cout << "e: " << *ai2++ << "\n";
	}

	array<int, nArray.size()>::const_reverse_iterator ai3;
	ai3 = nArray.crend();

	while (ai3 != nArray.crend()) {
		cout << "e: " << *ai3++ << "\n";
	}

	cout << "printing vector" << "\n";

	for (int i = 0; i < nVector3.size(); i++) {
		nVector3[i] = i;
	}

	for (int i = 0; i < nVector3.size(); i++) {
		cout << nVector3[i] << " ";
	}

	cout << "\n";

	cout << "const iterator \n";

	for (int i = 0; i < nVector3.size(); i++)
	{
		nVector3.at(i) = i + 10;
	}

	for (int i = 0; i < nVector3.size(); i++) {
		cout << nVector3.at(i) << " ";
	}

	cout << "\n";

	vector<int>::const_iterator vi1;
	vi1 = nVector3.cbegin();

	while (vi1 != nVector3.cend()) {
		cout << "vci: " << *vi1++ << "\n";
	}

	cout << "\n";

	cout << "reverse iterator \n";
	vector<int>::const_reverse_iterator vi3;
	vi3 = nVector3.crbegin();

	while (vi3 != nVector3.crend()) {
		cout << "vci: " << *vi3++ << "\n";
	}

	cout << "\n";

	stack<int> s1;

	cout << "stack size: " << s1.size() << "\n";

	for (int i = 0; i < 10; i++) {
		s1.push(i);
		cout << "stack size: " << s1.size() << "\n";
	}

	cout << "top is: " << s1.top() << "\n";

	s1.pop();
	s1.pop();
	s1.pop();

	cout << "top is: " << s1.top() << "\n";
	cout << "stack size: " << s1.size() << "\n";

	for (int i = 0; i < 100; i++) {
		nVector.push_back(i);
		cout << "size of vector is : " << nVector.size() << "\n";
		cout << "capacity of vector is : " << nVector.capacity() << "\n";
		cout << "maxsize of vector is : " << nVector.max_size() << "\n";
	}

	queue<int> q;
	deque<int> dq;

	deque<int>::const_reverse_iterator dqi;

	system("pause");
	return 0;
}
