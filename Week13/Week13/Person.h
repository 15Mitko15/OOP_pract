#pragma once
#include "BasePerson.h"

class Person: public BasePerson
{
private:
	static int ID;
	int id;
public:
	Person(const std::string& name);
	BasePerson* clone() const override;
	void display() const override;
};
