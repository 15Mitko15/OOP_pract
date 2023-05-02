#ifndef TEAMLEADER_H_
#define TEAMLEADER_H_
#include <string>
#include "Employee.h"
#include <vector>


class TeamLeader:public Employee
{
private:
	std::string projectName;
	std::vector<Employee> team;
public:
	TeamLeader(const char* name, unsigned monthlyPayment, const char* projectName, const std::vector<Employee> team);
	const void printWithoutSalary(std::ostream& os) const;
	const int getTeamSalaty() const;
	friend std::ostream& operator <<(std::ostream& os, const TeamLeader& other);
};


#endif