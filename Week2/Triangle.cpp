#include "Triangle.h"
#include <cmath>

bool Triangle::isRavnobedren()
{
    return (a == b) || (b == c) || (a == c);
}

double Triangle::surface()
{
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int Triangle::P()
{
    return a + b + c;
}

double Triangle::visochina(int a)
{
    return (surface() * 2) / a;
}
