#pragma once
#include "Car.h"

class ElectricCar:public Car
{
public:
	void startEngine() const override;
};