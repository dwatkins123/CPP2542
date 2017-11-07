#include <iostream>
#include <set>
#include <array>
#include <string>
#include <iterator>
#include <unordered_set>

using namespace std;

void print(set<int> s) {
	set<int>::iterator it1 = s.cbegin();

	while (it1 != s.cend()) {
		cout << " " << *it1;
		it1++;
	}

	cout << endl;
}

template <class myT>

void print2(set<myT> s) {
	set<myT>::iterator it3 = s.cbegin();

	while (it3 != s.cend()) {
		cout << " " << *it3;
		it3++;
	}

	cout << endl;
}

void print(unordered_set<int> s) {
	unordered_set<int>::iterator it1 = s.cbegin();

	while (it1 != s.cend()) {
		cout << " " << *it1;
		it1++;
	}

	cout << endl;
}

void print(multiset<int> s) {
	auto it = s.cbegin();

	while (it != s.cend()) {
		cout << " " << *it;
		it++;
	}

	cout << "\n";
}

int main()
{
	set<int> s1;
	set<int> s2 = { 1, 2, 3, 4, 5 };
	set<int> s3{ 2, 4, 6, 8, 10 };
	set<int> s4(s3);

	set<int> s6 = { 1, 1, 2, 2, 3, 4, 5, 5, 100, 50 };

	set<int>::iterator it1;
	multiset<int> ms = { 1, 1, 2, 2, 3, 4, 5, 5, 100, 50 };

	it1 = s3.cbegin();

	while (it1 != s3.cend()) {
		cout << " " << *it1;
		it1++;
	}
	
	cout << "\n";

	print(s6);

	print2(s6);

	s6.insert(110);
	s6.insert(120);

	print(s6);

	set<int>::const_reverse_iterator it2;
	it2 = s3.crbegin();

	while (it2 != s3.crend()) {
		cout << " " << *it2;
		it2++;
	}

	cout << endl;
 
	if (s6.count(5)) {
		cout << "5 is a set member\n";
	}
	else {
		cout << "5 does not exist in s6\n";
	}

	set<int>::iterator i3;
	i3 = s6.find(50);

	if (i3 != s6.end()) {
		cout << "50 does\n";
	}
	else {
		cout << "50 does not\n";
	}

	unordered_set<int> us = { 1, 1, 2, 2, 3, 4, 5, 5, 100, 50 };
	unordered_set<int>::const_iterator usit;

	print(us);
	us.insert(55);
	us.insert(99);
	print(us);
	print(us);

	cout << "Printing multiset\n";
	print(ms);

	cout << "multiset size: " << ms.size() << "\n";
	cout << "multiset max size: " << ms.max_size() << endl;

	if (ms.empty()) {
		cout << "multiset is empty\n";
	}

	ms.insert(550);

	print(ms);

	ms.erase(550);
	cout << "550 erased\n";
	print(ms);
	cout << "Number of times 1 appeared in multiset: " << ms.count(1) << endl;
	cout << "number of times 443 appeared in multiset: " << ms.count(443) << endl;

	ms.clear();
	cout << "Cleared multiset\n";

	print(ms);

	list<int> l;
	
	for (int i = 1; i <= 10; i++) {
		l.push_back(i);
	}

	cout << "size: " << l.size() << endl;

	for (auto i = l.cbegin(); i != l.cend(); i++) {
		// cout << l.erase(*i) << endl;
		cout << " " << *i;
	}

	list<list<int>> ll;

	list<int> l1;
	list<int> l2;

	for (int i = 1; i <= 10; i++) {
		l.push_back(i);
	}

	ll.push_back(l1);
	ll.push_back(l2);

	vector<int> v1;
	vector<vector<int>> v;
	v.push_back(v1);

	system("pause");
	return 0;
}
