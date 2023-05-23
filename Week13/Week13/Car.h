#pragma once
#include "Property.h"
#include "Vehicle.h"
#include <iostream>

class Car: public Property, public Vehicle
{
private:
	char* brand;
	void copy(const Car& other);
	void erase();
public:
	Car(std::string owner, bool tangible, char* barnd, int power = 0, int weight = 0);
	Car(const Car& other);
	Car& operator=(const Car& other);

	Car(Car&& other);
	Car& operator=(Car&& other);
	~Car();

	void startEngine() const override;

};