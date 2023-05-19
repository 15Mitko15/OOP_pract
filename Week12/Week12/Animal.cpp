#include "Animal.h"

int animalCount = 1;

void Animal::copy(const Animal& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);
	weight = other.weight;
	placeToSleep = other.placeToSleep;
	food = other.food;
}

void Animal::erase()
{
	delete[] name;
}

Animal::Animal(char* name, int weight, unsigned age, SleepPlace placeToSleep, Food food, int foodPerDay):name(new char[strlen(name) + 1]),
               age(age), placeToSleep(placeToSleep), food(food), weight(weight), foodPerDay(foodPerDay)
{
	strcpy_s(this->name, strlen(name) + 1, name);
	animalCount += 1;
}

Animal::Animal(const Animal& other)
{
	copy(other);
	animalCount += 1;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

Animal::Animal(Animal&& other)
{
	name = other.name;
	weight = other.weight;
	age = other.age;
	placeToSleep = other.placeToSleep;
	food = other.food;

	other.name = nullptr;
	other.weight = 0;
	other.age = 0;
}

Animal& Animal::operator=(Animal&& other)
{
	if (this != &other)
	{
		erase();
		name = other.name;
		weight = other.weight;
		age = other.age;
		placeToSleep = other.placeToSleep;
		food = other.food;

		other.name = nullptr;
		other.weight = 0;
		other.age = 0;
	}
	return *this;
}

Animal::~Animal()
{
	erase();
}

int Animal::eat() const
{
	return foodPerDay;
}

Food Animal::getFood() const
{
	return food;
}
