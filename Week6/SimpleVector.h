#ifndef SIMPLEVECTOR_H_
#define SIMPLEVECTOR_H_
#include <iostream>
#include <vector>
class SimpleVector
{
	private:
		int size;
		int data[10];
	public:

		SimpleVector& operator+(const SimpleVector&);
		SimpleVector& operator-(const SimpleVector&);
		SimpleVector& operator*(const SimpleVector&);
		SimpleVector& operator/(const SimpleVector&);

		friend std::ostream& operator<<(std::ostream&, SimpleVector&);
		friend std::istream& operator>>(std::istream&, SimpleVector&);
		void readBinaryFile();
		void writeBinaryFile();
		void readTextFile();
		void writeTextFile();
	};

#endif

