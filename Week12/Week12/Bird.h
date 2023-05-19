#pragma once
#include "Animal.h"
class Bird: public Animal
{
private:
	std::string resqueCity;
public:
	Bird(char* name, int weight, unsigned age, SleepPlace placeToSleep, Food food, int foodPerDay, std::string resqueCity);

	Animal* clone() const override;
	void print() const override;

};
