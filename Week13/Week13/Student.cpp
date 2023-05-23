#include "Student.h"
#include <iostream>

Student::Student(const std::string& name, int fn): BasePerson(name), fn(fn)
{
}

BasePerson* Student::clone() const
{
	return new Student(*this);
}

void Student::display() const
{
	std::cout << fn;
}
