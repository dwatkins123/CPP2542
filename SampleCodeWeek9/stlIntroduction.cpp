#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>

using namespace std;

template <class T>
T max(T i, T j)
{
	if (i > j) {
		return i;
	}
	else {
		return j;
	}
}

int main()
{
	/*
	int x = 5, y = 10;
	int nMax = max(x, y);
	cout << "Max is " << nMax << "\n";

	double j = 5.2, k = 5.3;
	double m = max(j, k);
	cout << "Max is " << m << "\n";
	*/

	stack<int> s;
	s.push(5);
	s.push(15);
	s.push(25);
	s.push(35);
	s.push(45);

	cout << "Size is " << s.size() << "\n";

	cout << s.top() << "\n";
	cout << s.top() << "\n";
	cout << s.top() << "\n";
	cout << s.top() << "\n";

	s.pop();
	s.pop();

	cout << s.top() << "\n";

	cout << s.empty() << "\n";
	cout << "Size is " << s.size() << "\n";

	// Queue
	// push, pop, empty, size, front, back
	cout << "Starting of Queue\n";

	queue<int> q;
	cout << "Queue is " << q.empty() << "\n";
	q.push(5);
	q.push(15);
	q.push(25);
	q.push(35);
	q.push(45);

	cout << "Queue is " << q.empty() << "\n";
	cout << "Size is " << q.size() << "\n";
	cout << "Queue -- front " << q.front() << "\n";
	cout << "Queue -- back " << q.back() << "\n";
	q.pop();
	q.pop();
	cout << "Size is " << q.size() << "\n";
	cout << "Queue -- front " << q.front() << "\n";
	cout << "Queue -- back " << q.back() << "\n";

	vector<int> v;
	v.push_back(5);
	v.push_back(15);
	v.push_back(25);
	v.push_back(35);
	v.push_back(45);

	cout << "Size of vector is " << v.size() << "\n";
	v.pop_back();
	v.pop_back();
	cout << "Size of vector is " << v.size() << "\n";
	cout << "Capacity is " << v.capacity() << "\n";

	vector<int>::iterator i;

	for (i = v.begin(); i != v.end(); ++i) {
		cout << "element " << *i << "\n";
	}


	list<int> l;

	system("pause");
	return 0;
}
