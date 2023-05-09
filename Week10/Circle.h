#ifndef CIRCLE_H_
#define CIRCLE_H_
#include "Shape.h"

class Circle : public Shape
{
private:
	double r;
public:
	Circle(double r = 1);
	void print() const override;
	Shape* copy() const override;
	double getPerimeter() const override;
};

#endif