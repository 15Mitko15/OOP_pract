#include "Vegetable.h"
#include <iostream>

void Vegetable::enterInformation()
{
	std::cin.getline(name, 19);
	std::cin >> weight; 
	std::cin.ignore();
}
