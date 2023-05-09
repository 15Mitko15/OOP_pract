#include "Square.h"

Square::Square(double a, double b): a(a), b(b)
{
}

void Square::print() const
{
	std::cout << "   ____" << '\n';
	std::cout << "  |    |" << '\n';
	std::cout << "  |    |" << '\n';
	std::cout << "   ---- " << '\n';
}

Shape* Square::copy() const
{
	return new Square(*this);
}

double Square::getPerimeter() const
{
	return 2*a + 2*b;
}
