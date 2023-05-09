#ifndef SHAPE_H_
#define SHAPE_H_
#include <string>
#include <iostream>

class Shape {
private:
	std::string lable;
public:
	virtual const std::string& getLable() const ;
	virtual void print() const = 0;
	virtual Shape* copy() const = 0;
	virtual double getPerimeter() const = 0;
	virtual ~Shape() = 0 {}
};


#endif
