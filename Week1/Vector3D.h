#ifndef Vecotr3D_H_
#define Vecotr3D_H_
struct Vector3D
{
	double x, y, z;
	double getVectorLength();
	Vector3D plus(Vector3D v);
	void printCoordinates();
};

double getScalarProduct(Vector3D first, Vector3D second);
bool arePerpendicular(Vector3D first, Vector3D second);

#endif