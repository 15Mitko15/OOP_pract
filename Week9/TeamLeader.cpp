#include "TeamLeader.h"

TeamLeader::TeamLeader(const char* name, unsigned monthlyPayment, const char* projectName, std::vector<Employee> team) :
	Employee(name, monthlyPayment), projectName(projectName), team(team)
{
}

const void TeamLeader::printWithoutSalary(std::ostream& os) const 
{
	printName(os);
	os << '\n';
	for (size_t i = 0; i < team.size(); i++)
	{
		team[i].printName(os);
	}
}

const int TeamLeader::getTeamSalaty() const
{
	int sum = 0;
	sum += Employee::getMonthlyPayment();
	for (size_t i = 0; i < team.size(); i++)
	{
		sum += team[i].getMonthlyPayment();
	}
	return sum;
}

std::ostream& operator<<(std::ostream& os, const TeamLeader& other)
{
	os << (Employee&) other;
	os << '\n';
	for (size_t i = 0; i < other.team.size(); i++)
	{
		other.team[i].printName(os);
	}
	return os;
}
