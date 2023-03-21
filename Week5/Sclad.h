#pragma once
#include "Shoe.h"

class Sclad
{
private:
	int size;
	int maxCapacity;
	Shoe* shop;
	void copy(const Sclad& other);
	void erase();
public:
	Sclad(int maxCapacity);
	Sclad(const Sclad& other);
	Sclad& operator=(const Sclad& other);
	~Sclad();
	void addBrand(const Shoe& other);
	void sellShoe(std::string brand);
	void addShoe(std::string brand, int number) const;
	void changeRaiting(std::string brand, double number);
	void removeElement(std::string brand);

};

