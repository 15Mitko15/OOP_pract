#ifndef Salad_H_
#define  Salad_H_
#include "Dressing.h"
#include "Vegetable.h"
struct Salad
{
	char saladName[20];
	Vegetable vegetables[3];
	Dressing dressing;
	int price;

	void inputSalad();
	double getWeight();
	void printAllergen();
	//print();

};

#endif
