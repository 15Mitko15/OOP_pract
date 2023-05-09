#include "Shape.h"
#include "ShapeContainer.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"

int main()
{
	ShapeContainer obj;
	Triangle t(1, 2, 3);
	Square s(1, 2);
	Circle c(2);
	obj.addShape(t);
	obj.addShape(s);
	obj.addShape(c);
	obj.printContainer();
	obj.printShapes();

}