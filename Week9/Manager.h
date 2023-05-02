#ifndef MANAGER_H_
#define MANAGER_H_
#include <string>
#include "Employee.h"
#include "TeamLeader.h"
#include <vector>


class Manager:public Employee
{
private:
	std::vector<TeamLeader> teamLeaders;
public:
	Manager(const char* name, unsigned monthlyPayment, const std::vector<TeamLeader> teamLeaders);
	const int getMonthlyRazhody() const;
	friend std::ostream& operator <<(std::ostream& os, const Manager& other);
};


#endif
