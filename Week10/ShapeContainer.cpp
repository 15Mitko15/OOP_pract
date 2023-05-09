#include "ShapeContainer.h"

void ShapeContainer::addShape(const Shape& shape)
{
	shapes.push_back(shape.copy());
}

void ShapeContainer::printContainer() const
{
	for (size_t i = 0; i < shapes.size(); i++)
	{
		std::cout<<shapes[i]->getPerimeter();
		std::cout << " - ";
		std::cout << shapes[i]->getPerimeter();
		std::cout << '\n';
	}
}

void ShapeContainer::printShapes() const
{
	for (size_t i = 0; i < shapes.size(); i++)
	{
		shapes[i]->print();
		std::cout << '\n';
	}
}

ShapeContainer::~ShapeContainer()
{
	for (size_t i = 0; i < shapes.size(); i++)
	{
		delete shapes[i];
	}
}
