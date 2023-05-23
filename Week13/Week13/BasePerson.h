#pragma once
#include <string>
class BasePerson
{
private:
	std::string name;
protected:
	BasePerson(const std::string& name) :name(name) {}
public:
	virtual BasePerson* clone() const = 0;
	virtual void display() const = 0;
	virtual ~BasePerson() {}
};