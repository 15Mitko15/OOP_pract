#include "Manager.h"

Manager::Manager(const char* name, unsigned monthlyPayment, const std::vector<TeamLeader> teamLeaders) :
	Employee(name, monthlyPayment), teamLeaders(teamLeaders)
{
}

const int Manager::getMonthlyRazhody() const
{
	int sum = 0;
	sum += Employee::getMonthlyPayment();
	for (size_t i = 0; i < teamLeaders.size(); i++)
	{
		sum+=teamLeaders[i].getTeamSalaty();
	}
	return sum;
}

std::ostream& operator<<(std::ostream& os, const Manager& other)
{
	os << (Employee&)other;
	os << '\n';
	for (size_t i = 0; i < other.teamLeaders.size(); i++)
	{
		other.teamLeaders[i].printWithoutSalary(os);
	}
	return os;
}
