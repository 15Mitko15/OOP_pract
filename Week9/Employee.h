#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <string>
#include <iostream>


class Employee
{
private:
	std::string name;
	unsigned monthlyPayment;
public:
	Employee(const char* name, unsigned monthlyPayment);
	void printName(std::ostream& os) const;
	friend std::ostream& operator <<(std::ostream& os, const Employee& other);
	unsigned getMonthlyPayment() const
	{
		return monthlyPayment;
	}
};


#endif