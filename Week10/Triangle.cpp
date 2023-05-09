#include "Triangle.h"

Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c)
{
}

void Triangle::print() const
{
	std::cout << "  /\\" << '\n';
	std::cout << " /  \\" << '\n';
	std::cout << " ----";
}

Shape* Triangle::copy() const
{
	return new Triangle(*this);
}

double Triangle::getPerimeter() const
{
	return a + b + c;
}
