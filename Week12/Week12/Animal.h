#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <string>
#include "Food.h"
#include <iostream>

class Animal
{
protected:
	char* name;
	int weight;
	unsigned age;
	int foodPerDay;
	SleepPlace placeToSleep;
	Food food;
	void copy(const Animal& other);
	void erase();
public:
	static int animalCount;
	Animal(char* name, int weight, unsigned age, SleepPlace placeToSleep, Food food, int foodPerDay);
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	Animal(Animal&& other);
	Animal& operator=(Animal&& other);
	virtual ~Animal();

	virtual void print() const = 0;
	virtual int eat() const;
	Food getFood() const;
	virtual Animal* clone() const = 0;
};

#endif
