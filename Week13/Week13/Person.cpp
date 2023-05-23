#include "Person.h"
#include <iostream>

int Person::ID = 1;
Person::Person(const std::string& name):BasePerson(name)
{
	id = ID++;
}

BasePerson* Person::clone() const
{
	return new Person(*this);
}

void Person::display() const
{
	std::cout << id;
}
