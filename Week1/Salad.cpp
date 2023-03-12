#include "Salad.h"
#include <iostream>

void Salad::inputSalad()
{
	std::cin.getline(saladName, 19);
	for (size_t i = 0; i < 3; i++)
	{
		vegetables[i].enterInformation();
	}

	dressing.enterInformation();
	std::cin >> price; 
	std::cin.ignore();
}

double Salad::getWeight()
{
	double sumWeight = 0;
	for (int i = 0; i < 3; i++)
	{
		sumWeight += vegetables[i].weight;
	}
	return sumWeight;
}

void Salad::printAllergen()
{
	std::cout << dressing.allergen;
}
