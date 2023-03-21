#pragma once
#include <string>
class Shoe
{
private:
	std::string factory;
	std::string brand;
	double price;
	double raiting;
	int numberOfShoes;
public:
	std::string getBrand() const
	{
		return brand;
	}
	void setNumberOfShoes(int number)
	{
		numberOfShoes = number;
	}
	int getNumberOfShoes() const
	{
		return numberOfShoes;
	}
	void setRaiting(double number)
	{
		raiting = number;
	}
};

