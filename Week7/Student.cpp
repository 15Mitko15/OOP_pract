#include "Student.h"

Student::Student():house(noHouse), health(0)
{
	// Power??

}

Student::Student(const std::string& name): name(name), house(noHouse), health(0)
{
	//Power ??
}

const std::string& Student::getName() const 
{
	return name;
}

const House& Student::getHouse() const
{
	return house;
}

void Student::setHouse(const House& house)
{
	if (this->house != noHouse)
	{
		std::cerr << "This student has a house!";
		return;
	}
	this->house = house;
}

int Student::getHealth() const
{
	return health;
}

void Student::takeDamage(int damage)
{
	health -= damage;
}

void Student::setPower(const Power* power)
{
	power = power;
}

const Power* Student::getPower() const
{
	return power;
}

bool Student::isAlive()
{
	return health > 0;
}

void Student::attack(Student& st)
{
	st.health -= power->getDamage();
}



std::ostream& operator<<(std::ostream& os, const Student& other)
{
	os << other.name << ' ';
	if (other.house == 0)
	{
		os << "Gryffindor";
	}
	else if (other.house == 1)
	{
		os << "Slytherin";
	}
	else if (other.house == 2)
	{
		os << "avenclaw";
	}
	else if (other.house == 3)
	{
		os << "Hufflepuff";
	}
	else
	{
		os << "noHouse";
	}
	os << ' ' << *(other.power) << ' ' << other.health<<std::endl;
}
