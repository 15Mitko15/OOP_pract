#pragma once

class Vehicle
{
private:
	int power;
	int weight;
public:
	Vehicle(int power = 0, int weight = 0):power(power), weight(weight){}

	virtual int getPower() const
	{
		return power;
	}

	virtual int getWeight() const
	{
		return weight;
	}

	virtual void startEngine() const = 0;
	virtual ~Vehicle(){}
};
