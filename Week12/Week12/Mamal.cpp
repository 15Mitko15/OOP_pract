#include "Mamal.h"

void Mamal::copy(const Mamal& other)
{
	nameOfCareer = new char[strlen(other.nameOfCareer) + 1];
	strcpy_s(nameOfCareer, strlen(other.nameOfCareer) + 1, other.nameOfCareer);
}

void Mamal::erase()
{
	delete[] nameOfCareer;
}

Mamal::Mamal(char* name, int weight, unsigned age, SleepPlace placeToSleep, Food food, int foodPerDay, char* nameOfCareer):
	         Animal(name,weight, age, placeToSleep, food, foodPerDay)
{
	this->nameOfCareer = new char[strlen(nameOfCareer) + 1];
	strcpy_s(this->nameOfCareer, strlen(nameOfCareer) + 1, nameOfCareer);
}

Mamal::Mamal(const Mamal& other):Animal(other)
{
	copy(other);
}

Mamal& Mamal::operator=(const Mamal& other)
{
	if (this != &other)
	{
		erase();
		Animal::operator=(other);
		copy(other);
	}
	return *this;
}

Mamal::Mamal(Mamal&& other):Animal(other)
{
	nameOfCareer = other.nameOfCareer;

	other.nameOfCareer = nullptr;
}

Mamal& Mamal::operator=(Mamal&& other)
{
	if (this != &other)
	{
		erase();
		Animal::operator=(other);
		nameOfCareer = other.nameOfCareer;

		other.nameOfCareer = nullptr;
	}
	return *this;
}

Mamal::~Mamal()
{
	erase();
}

Animal* Mamal::clone() const
{
	return new Mamal(*this);
}

void Mamal::print() const
{
	std::cout << name << ' ' << weight << ' ' << age << ' ' << placeToSleep << ' ' << food << ' ' << foodPerDay << ' ' << nameOfCareer;
}


