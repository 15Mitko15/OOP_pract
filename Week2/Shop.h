#ifndef SHOP_H_
#define SHOP_H_
#include "Waffle.h"
class Shop
{
private:
	Waffle waffle;
	int currNumber;
	int maxNumber;
	double income;
	double expences;

public:
	void initialize();
	void orderWafers(Waffle waffle, int count);
	void sell();
	void showMoment();
	void printProfit();

};

#endif;

