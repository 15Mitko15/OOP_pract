#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include "Shape.h"

class Triangle : public Shape
{
private:
	double a;
	double b;
	double c;
public:
	Triangle(double a = 1, double b = 1, double c = 1);
	void print() const override;
	Shape* copy() const override;
	double getPerimeter() const override;
};

#endif