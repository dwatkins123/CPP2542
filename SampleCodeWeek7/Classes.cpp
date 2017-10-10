#include "Header.cpp"
/*
	PreCondition:
		accepts two valid numbers greater than 0
	PostCondition:
		returns average of these two numbers
*/

int average(int num1, int num2)
{
	return (num1 + num2) / 2;
}

/*
PreCondition:
accepts two valid numbers greater than 0
PostCondition:
returns average of these two numbers
*/

int divide(int num1, int num2)
{
	return (num1 / num2);
}

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

