#include "Sclad.h"

void Sclad::copy(const Sclad& other)
{
	maxCapacity = other.maxCapacity;
	size = other.size;
	shop = new Shoe[maxCapacity];
	for (size_t i = 0; i < size; i++)
	{
		shop[i] = other.shop[i];
	}
}

void Sclad::erase()
{
	delete[] shop;
}

Sclad::Sclad(int maxCapacity): maxCapacity(maxCapacity), size(0), shop(new Shoe[maxCapacity])
{

}

Sclad::Sclad(const Sclad& other)
{
	copy(other);
}

Sclad& Sclad::operator=(const Sclad& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

Sclad::~Sclad()
{
	erase();
}

void Sclad::addBrand(const Shoe& other) 
{
	for (size_t i = 0; i < size; i++)
	{
		if (shop[i].getBrand() == other.getBrand()) {
			throw std::exception();
		}
		shop[++size] = other;
	}
}

void Sclad::sellShoe(std::string brand)
{
	for (size_t i = 0; i < size; i++)
	{
		if (shop[i].getBrand() == brand) 
		{
			shop[i].setNumberOfShoes(size - 1);
			if (!(shop[i].getNumberOfShoes()))
			{
				for (size_t j = i + 1; j < size; j++)
				{
					shop[j - 1] = shop[j];
				}
				size--;
			}
			break;
		}
	}
}

void Sclad::addShoe(std::string brand, int number) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (shop[i].getBrand() == brand)
		{
			shop[i].setNumberOfShoes(number + shop[i].getNumberOfShoes());
			return;
		}
	}

	throw std::exception();
}

void Sclad::changeRaiting(std::string brand, double number)
{
	for (size_t i = 0; i < size; i++)
	{
		if (shop[i].getBrand() == brand)
		{
			shop[i].setRaiting(number);
			break;
		}
	}

}

void Sclad::removeElement(std::string brand)
{
	for (size_t i = 0; i < size; i++)
	{
		if (shop[i].getBrand() == brand)
		{
				for (size_t j = i + 1; j < size; j++)
				{
					shop[j - 1] = shop[j];
				}

				size--;

			break;
		}
	}
}


