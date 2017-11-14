#include <iostream>
#include <string>
using namespace std;

class MyObj {
private:
	string m_strName;
	int m_nAge;

public:
	MyObj() {
		m_strName = "";
		m_nAge = 0;
	}

	MyObj(string strName, int nAge) {
		this->m_strName = strName;
		this->m_nAge = nAge;
	}

	MyObj(const MyObj& obj) {
		m_strName = obj.m_strName;
		m_nAge = obj.m_nAge;
	}

	void setName(string strName) {
		this->m_strName = strName;
	}

	void setAge(int nAge) {
		this->m_nAge = nAge;
	}

	string getName() {
		return m_strName;
	}

	int getAge() {
		return m_nAge;
	}

	const MyObj operator= (const MyObj& obj) {
		m_strName = obj.m_strName;
		m_nAge = obj.m_nAge;
		return *this;
	}

	bool operator < (const MyObj& obj) {
		return m_nAge < obj.m_nAge;
	}

	bool operator > (const MyObj& obj) {
		return m_nAge > obj.m_nAge;
	}

	bool operator == (const MyObj& obj) {
		return m_nAge == obj.m_nAge;
	}

	friend istream& operator >> (istream& is, MyObj& obj) {
		cout << "enter name: ";
		is >> obj.m_strName;
		cout << "enter age: ";
		is >> obj.m_nAge;
		return is;
	}

	friend ostream& operator << (ostream& os, MyObj& obj) {
		os << "Name was: " << obj.m_strName << "\n";
		os << "Age was: " << obj.m_nAge << "\n";
		return os;
	}
};

int main()
{
	MyObj obj;
	MyObj obj2("Jake", 10), obj5("Don", 20);

	int i;

	// cin >> i;
	cin >> obj;

	// cout << "Name was: " << obj.getName() << ", age was: " << obj.getAge() << endl;
	cout << obj;


	MyObj obj3(obj);
	cout << "copy constructor: ";
	cout << obj3 << "\n";

	MyObj obj4 = obj2;
	cout << "= operator : ";
	cout << obj4 << "\n";

	if (obj2 < obj5) {
		cout << "Obj2 is less than obj5.\n";
	}
	else if (obj2 > obj5) {
		cout << "Obj2 is greater than obj5.\n";
	}
	else if (obj2 == obj5) {
		cout << "Obj2 equals obj5.\n";
	}

	system("pause");
	return 0;
}
