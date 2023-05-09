#include "Circle.h"

Circle::Circle(double r): r(r)
{
}

void Circle::print() const
{
	std::cout << "   -"<<'\n';
	std::cout << " /   \\"<<'\n';
	std::cout << "|     |" << '\n';
	std::cout << " \\   /" << '\n';
	std::cout << "   -" << '\n';
}

Shape* Circle::copy() const
{
	return new Circle(*this);
}

double Circle::getPerimeter() const
{
	return 2*3.14*r;
}
