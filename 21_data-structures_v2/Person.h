#pragma once
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Person {
public:
	static int counter;
	string name;
	int id;
	int age;
	void greeting();
	Person();
	Person(int);
	Person(int, int);
	Person(int, string, int);
	~Person();
	Person(const Person&);
	int get_hash_value() const;
};

inline Person::Person(const Person &obj)
{
	cout << "copy constructor" << endl;
	this->name = obj.name;
	this->age = obj.age;
	this->id = 0;
}

int Person::counter = 0;

//const since it doeesnt change the value

inline int  Person::get_hash_value() const
{
	return age + id;
}


inline Person::~Person()
{
	cout << "deleting Person with name: " << name << "	id:	" << id << "	age" << age << endl;
	counter--;
}


inline void Person::greeting()
{
	cout << "Hello my name is:	 " << name << "	id : " << id << "	age" << age << endl;
}

inline Person::Person()
{
	counter++;
	age = 0;
	id = 0;
	name = "";

}

inline Person::Person(int _age)
{
	counter++;
	age = _age;
	id = counter;
	name = "joe mama";
}

inline Person::Person(int _age, int _id)
{
	counter++;
	age = _age;
	id = _id;
	name = "hehehe";
}

inline Person::Person(int _age, string _name, int _id)
{
	counter++;
	age = _age;
	id = _id;
	name = _name;
}