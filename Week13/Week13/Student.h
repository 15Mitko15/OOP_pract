#pragma once
#include "BasePerson.h"

class Student: public BasePerson
{
private:
	int fn;
public:
	Student(const std::string& name, int fn);
	BasePerson* clone() const override;
	void display() const override;

};