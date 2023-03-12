#include "Shop.h"
#include <iostream>

void Shop::initialize()
{
	std::cin >> maxNumber;
	currNumber = 0;
	income = 0;
	expences = 0;
}

void Shop::orderWafers(Waffle waffle, int currNumber)
{
	if (this->currNumber != 0)
	{
		throw std::exception("Still not empty");
	}
	if (maxNumber < currNumber || currNumber < 1)
	{
		throw std::exception("Invalid number");
	}
	this->currNumber = currNumber;
	this->waffle = waffle;
	expences += waffle.startingPrice * currNumber;
}

void Shop::sell()
{
	if (currNumber == 0)
	{
		throw std::exception("No waffles");
	}
	currNumber--;
	income += waffle.clientPrice;
}

void Shop::showMoment()
{
	double allWeight = waffle.weight*currNumber;
	std::cout << currNumber << " " << waffle.brand << " " << allWeight;
}

void Shop::printProfit()
{
	double profit = income - expences;
	std::cout << profit;
}
