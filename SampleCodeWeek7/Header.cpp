#include "Header.h"

Person::Person()
{
	age = 0;
	name = "";
	cout << "Default instructor invoked" << endl;
}

Person::Person(int nAge, string strName)
{
	age = nAge;
	name = strName;
	cout << "constructor invoked" << endl;
}

void Person::setName(string str)
{
	name = str;
}

void Person::setAge(int num)
{
	age = num;
}

string Person::getName() const
{
	return name;
}

int Person::getAge() const
{
	return age;
}

