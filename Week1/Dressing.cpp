#include "Dressing.h"
#include <iostream>

void Dressing::enterInformation()
{
	
	std::cin.getline(name, 19);
	std::cin >> quantity; 
	std::cin.ignore();
	std::cin.getline(allergen, 19);
}
