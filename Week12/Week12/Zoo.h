#pragma once
#include <string>
#include "Animal.h"
class Zoo
{
private:
	std::string nameOfZoo;
	Animal** allAnimals;
	int size;
	int capacity;
	void copy(const Zoo& other);
public:
};

