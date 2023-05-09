#ifndef SQUARE_H_
#define SQUARE_H_
#include "Shape.h"

class Square : public Shape
{
private:
	double a;
	double b;
public:
	Square(double a = 1, double b = 1);
	void print() const override;
	Shape* copy() const override;
	double getPerimeter() const override;
};

#endif

