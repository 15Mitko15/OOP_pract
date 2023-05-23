#include "Teacher.h"
#include <iostream>

void Teacher::copy(const Teacher& other)
{
	catedra = other.catedra;
	size = other.size;
	classes = new std::string[size];
	for (size_t i = 0; i < size; i++)
	{
		classes[i] = other.classes[i];
	}
}

void Teacher::erase()
{
	delete[] classes;
}

Teacher::Teacher(const std::string name, const std::string catedra, const std::string* classes, int size):BasePerson(name)
{
	this->catedra = catedra;
	this->classes = new std::string[size];
	this->size = size;
	for (size_t i = 0; i < size; i++)
	{
		this->classes[i] = classes[i];
	}
}

Teacher::Teacher(const Teacher& other):BasePerson(other)
{
	copy(other);
}

Teacher& Teacher::operator=(const Teacher& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}

	return *this;
}

BasePerson* Teacher::clone() const
{
	return new Teacher(*this);
}

void Teacher::display() const
{
	std::cout << catedra<<std::endl;
	for (size_t i = 0; i < size; i++)
	{
		std::cout << classes[i] << std::endl;
	}
}
