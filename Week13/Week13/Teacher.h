#pragma once
#include <string>
#include "BasePerson.h"

class Teacher:public BasePerson
{
private:
	int size;
	std::string catedra;
	std::string* classes;
	void copy(const Teacher& other);
	void erase();
public:
	Teacher(const std::string name, const std::string catedra, const std::string* classes, int size);
	Teacher(const Teacher& other);
	Teacher& operator=(const Teacher& other);

	BasePerson* clone() const override;
	void display() const override;
};