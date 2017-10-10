#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>

using namespace std; 

class Person {
private:
	int age;
	string name;

public:
	Person();
	Person(int nAge, string strName);
	void setName(string str);
	void setAge(int num);
	string getName() const;
	int getAge() const;
};

#endif
