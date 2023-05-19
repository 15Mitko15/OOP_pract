#pragma once
#include "Animal.h"

class Mamal: public Animal
{
private:
	char* nameOfCareer;
public:
	void copy(const Mamal& other);
	void erase();
public:
	Mamal(char* name, int weight, unsigned age, SleepPlace placeToSleep, Food food, int foodPerDay, char* nameOfCareer);
	Mamal(const Mamal& other);
	Mamal& operator=(const Mamal& other);
	Mamal(Mamal&& other);
	Mamal& operator=(Mamal&& other);
	virtual ~Mamal();

	Animal* clone() const override;
	void print() const override;
};