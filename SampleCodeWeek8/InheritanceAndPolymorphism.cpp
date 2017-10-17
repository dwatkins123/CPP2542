#include <iostream>
#include <string>

using namespace std;

class Person
{
	private:
		string m_strName;
		int m_nAge;
		char m_cGender;

	public:
		Person(string strName, int nAge, char cGender)
		{
			m_strName = strName;
			m_nAge = nAge;
			m_cGender = cGender;

			cout << "Parameterized person constructor called\n";
		}

		Person()
		{
			m_strName = "";
			m_nAge = -1;
			m_cGender = ' ';
			cout << "Default person constructor called\n";
		}

		virtual void showType() { cout << "Person " <<  m_strName <<  endl; }
		virtual void myTypes() = 0;
};

class Info
{
	private:
		string m_strAddress;

	public:
		Info() { m_strAddress = ""; }
		Info(string strAddress) { m_strAddress = strAddress; }
		void showType() { cout << "info" << endl; }
		void showAddress() { cout << "address: " << m_strAddress << endl; }

};

class Student : public Person, public Info
{
	private:
		int m_nStudentID;

	public:
		Student(int nStudentID, string strName, int nAge, char cGender, string strAddress) : Person(strName, nAge, cGender), Info(strAddress)
		{
			m_nStudentID = nStudentID;
		}

		Student()
		{
			m_nStudentID = -1;
		}

		void showType() { cout << "Student: " << m_nStudentID << endl; }
		void myTypes() { cout << "This is my concrete class" << endl;  }
};

int main()
{
	Person p("John", 20, 'm');
	Student s(16628, "Jack", 30, 'm', "425 Fawell");

	// Person p2;
	// Student s2;

	Person *p1;

	p1 = &p;
	p1->showType();

	p1 = &s;
	p1->showType();

	system("pause");
	return 0;
}
