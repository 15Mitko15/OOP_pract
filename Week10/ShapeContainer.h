#ifndef SHAPECONTAINER_H_
#define SHAPECONTAINER_H_
#include "Shape.h"
#include <vector>

class ShapeContainer
{
private:
	std::vector<Shape*> shapes;
public:
	void addShape(const Shape& shape);
	void printContainer() const;
	void printShapes() const;
	~ShapeContainer();
};

#endif

