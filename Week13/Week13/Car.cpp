#include "Car.h"

void Car::copy(const Car& other)
{
	brand = new char(strlen(other.brand) + 1);
	strcpy_s(brand, strlen(other.brand) + 1, other.brand);
}

void Car::erase()
{
	delete[] brand;
	brand = nullptr;
}

Car::Car(std::string owner, bool tangible, char* barnd, int power, int weight):Vehicle(power, weight), Property(owner, tangible)
{
	this->brand = new char(strlen(brand) + 1);
	strcpy_s(this->brand, strlen(brand) + 1, brand);
}

Car::Car(const Car& other):Vehicle(other), Property(other)
{
	copy(other);
}

Car& Car::operator=(const Car& other)
{
	if (this != &other)
	{
		Vehicle::operator=(other);
		Property::operator=(other);
		erase();
		copy(other);
	}
	return *this;
}

Car::Car(Car&& other):Vehicle(other), Property(other)
{
	brand = other.brand;

	other.brand = nullptr;
}

Car& Car::operator=(Car&& other)
{
	if (this != &other)
	{
		Vehicle::operator=(other);
		Property::operator=(other);
		erase();
		brand = other.brand;

		other.brand = nullptr;
	}
	return *this;
}

Car::~Car()
{
	erase();
}

void Car::startEngine() const
{
	int numberOfO = getPower() / 30;
	std::cout << "Vr";
	for (size_t i = 0; i < numberOfO; i++)
	{
		std::cout << 'o';
	}
	std::cout << 'm';
}
