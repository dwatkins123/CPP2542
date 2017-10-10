#include <iostream>
#include <string>

using namespace std;

class Person {
	private:
		int age;
		string name;

	public:
		Person()
		{
			age = 0;
			name = "";
			cout << "Default instructor invoked" << endl;
		}

		Person(int nAge, string strName)
		{
			age = nAge;
			name = strName;
			cout << "constructor invoked" << endl;
		}

		void setName(string str)
		{
			name = str;
		}

		void setAge(int num)
		{
			age = num;
		}

		string getName() const
		{
			return name;
		}

		int getAge() const
		{
			return age;
		}
};

int main()
{
	Person person1(20, "John"), *ptr, person2;

	Person person3 = Person(30, "Jack");
	ptr = &person1;
	Person *p = new Person(40, "Murphy");

	cout << "person -- by value " << person1.getAge() << " " << person1.getName() << endl;
	cout << "person -- by ptr" << ptr->getAge() << " " << ptr->getName() << endl;

	for (int i = 0; i < 5; i++) {
		Person *p = new Person();
	}


	system("pause");
	return 0;
}

