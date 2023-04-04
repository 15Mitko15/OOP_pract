#include "Power.h"

Power::Power(const std::string& name, int damage): name(name), damage(damage)
{
}

const std::string& Power::getName() const
{
	return name;
}

int Power::getDamage() const
{
	return damage;
}

bool Power::operator<(const Power& other) const 
{
	return damage < other.damage;
}

bool Power::operator>(const Power& other) const
{
	return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Power other)
{
	os << other.name << ' ' << other.damage;
}
