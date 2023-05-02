#include "Employee.h"

Employee::Employee(const char* name, unsigned monthlyPayment): name(name), monthlyPayment(monthlyPayment)
{
}

void Employee::printName(std::ostream& os) const
{
	os << name;
}

std::ostream& operator<<(std::ostream& os, const Employee& other)
{
	os << other.name;
	os << other.monthlyPayment;
	return os;

}
