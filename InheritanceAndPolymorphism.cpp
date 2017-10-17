#include <iostream>
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

		void showType() { cout << "Person" << endl; }
};

class Info
{
	private:
		string m_strAddress;

	public:
		Info() { m_strAddress = ""; }
		Info(string strAddress) { m_strAddress = strAddress; }
		void showType() { cout << "info" << endl; }
		void showAddress() { cout << "address" << endl; }

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

		void showType() { cout << "Student" << endl; }
};

int main()
{
	Person p("John", 20, 'm');
	Student s(16628, "Jack", 30, 'm', "425 Fawell");

	Person p2;
	Student s2;

	s2.showType();
	
	s.showType();

	system("pause");
	return 0;
}
