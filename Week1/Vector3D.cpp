#include "Vector3D.h"
#include <iostream>

double Vector3D::getVectorLength()
{
    double k = x * x + y * y + z * z;
    return sqrt(k);
}

Vector3D Vector3D::plus(Vector3D v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

void Vector3D::printCoordinates()
{
    std::cout << '(' << x << ", " << y << ", " << z << ')';
}

double getScalarProduct(Vector3D first, Vector3D second)
{
    return (first.x * second.x) + (first.y * second.y) + (first.z * second.z);
}

bool arePerpendicular(Vector3D first, Vector3D second)
{
    return !((first.x * second.x) + (first.y * second.y));
}
