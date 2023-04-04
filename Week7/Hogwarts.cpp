#include "Hogwarts.h"

void Hogwarts::copy(const Hogwarts& other)
{
	for (size_t i = 0; i < other.size; i++)
	{
		school[i] = other.school[i];
	}
	size = other.size;
	capacity = other.capacity;
}

void Hogwarts::erase()
{
	delete[] school;
}

void Hogwarts::resize()
{
	Student* tempSchool;
	if (capacity == 0)
	{
		tempSchool = new Student[1];
	}
	else
	{
		tempSchool = new Student[capacity * 2];
	}
	for (size_t i = 0; i < size; i++)
	{
		tempSchool[i] = school[i];
	}
	capacity = capacity * 2;
	school = tempSchool;
}

Hogwarts::Hogwarts(): school(new Student[0]), size(0), capacity(0)
{
}

Hogwarts::Hogwarts(const Hogwarts& other)
{
	copy(other);
}

Hogwarts::Hogwarts(Hogwarts&& other)
{
	erase();
	school = other.school;
	size = other.size;
	capacity = other.capacity;

	other.school = nullptr;
	other.size = 0;
	other.capacity = 0;
}

Hogwarts& Hogwarts::operator=(const Hogwarts& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

Hogwarts& Hogwarts::operator=(Hogwarts&& other)
{
	if (this != &other)
	{
		erase();
		school = other.school;
		size = other.size;
		capacity = other.capacity; 

		other.school = nullptr;
		other.size = 0;
		other.capacity = 0;
	}
	return *this;
}

Hogwarts::~Hogwarts()
{
	erase();
}

void Hogwarts::addStudent(const Student& student)
{
	if (size == capacity)
	{
		resize();
	}
	school[size++] = student;
}

void Hogwarts::assignHouse(const std::string& studentName, const House& house)
{
	for (size_t i = 0; i < size; i++)
	{
		if (school[i].getName() == studentName) 
		{
			school[i].setHouse(house);
			return;
		}
	}
}

void Hogwarts::givePower(const std::string& name, const Power& power)
{
	for (size_t i = 0; i < size; i++)
	{
		if (school[i].getName() == name)
		{
			school[i].setPower(&power);
			return;
		}
	}
}

int Hogwarts::getHouseStudentsCount(const House& house) const
{
	int counter = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (school[i].getHouse() == house) {
			counter++;
		}
	}
	return counter;
}

Student* Hogwarts::getFirstStudent(const House& house) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (school[i].getHouse() == house) {
			return &(school[i]);
		}
	}
}

const Student* Hogwarts::getStudents() const
{
	return school;
}

bool Hogwarts::removeStudent(const std::string& name)
{
	for (size_t i = 0; i < size; i++)
	{
		if (school[i].getName() == name) 
		{
			for (size_t i = i; i < size - 1; i++)
			{
				school[i] = school[i + 1];
			}
			return;
		}
	};
}

Student& Hogwarts::studentFight(Student& st1, Student& st2)
{
	std::cout << "Fight between " << st1.getName() << '(' << st1.getHouse() << ')' << " and " << st2.getName() << '(' << st2.getHouse() << ')' << std::endl;
	bool attacker = 0;
	while (st1.isAlive() && st2.isAlive())
	{
		if (!attacker)
		{
			std::cout << st1.getName() << '[' << st1.getHealth() << ']' << '(' << st1.getHouse() << ')' << " attacks " << st2.getName() << '(' << st2.getHouse() << ')' << " with " << st1.getPower()->getName() << " for " << st1.getPower()->getDamage() << " damage " << std::endl;
			st1.attack(st2);
			attacker = 1;
		}
		else
		{
			std::cout << st2.getName() << '[' << st2.getHealth() << ']' << '(' << st2.getHouse() << ')' << " attacks " << st1.getName() << '(' << st1.getHouse() << ')' << " with " << st2.getPower()->getName() << " for " << st2.getPower()->getDamage() << " damage " << std::endl;
			st2.attack(st1);
			attacker = 0;
		}
	}
	return st1.isAlive() ? st1 : st2;
}

void Hogwarts::houseFight(const House& house1, const House& house2)
{
	Student tempStudent1;
	Student tempStudent2;
	for (size_t i = 0; i < size; i++)
	{
		if (school[i].getHouse() == house1)
		{
			tempStudent1 = school[i];
			break;
		}
	}
	for (size_t i = 0; i < size; i++)
	{
		if (school[i].getHouse() == house2)
		{
			tempStudent2 = school[i];
			break;
		}
	}
	removeStudent(studentFight(tempStudent1, tempStudent2).getName());
}

std::ostream& operator<<(std::ostream& out, const Hogwarts& hogwarts)
{
	for (size_t i = 0; i < hogwarts.size; i++)
	{
		out << hogwarts.school[i];
	}
}
