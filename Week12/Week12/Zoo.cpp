#include "Zoo.h"

void Zoo::copy(const Zoo& other)
{
	nameOfZoo = other.nameOfZoo;
	allAnimals = new Animal * [other.capacity];
	for (size_t i = 0; i < other.size; i++)
	{
		allAnimals[i] = other.allAnimals[i]->clone();
	}
	size = other.size;
	capacity = other.capacity;
}
