#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <iostream>
#include "../../../../UP-and-OOP 2021-2023/Initializations/Class_String/Class_String/String.h"
class MyString
{
private:
	char* string;
	int size;
	void copy(const MyString& other);
	void erase();
public:
	MyString(const char* str = "\0");
	MyString(const MyString& obj);
	MyString& operator = (const MyString&);
	~MyString();
	int length() const;
	char& at(unsigned index) const;
	int find(char c, unsigned startPos = 0) const;
	bool empty() const;
	MyString substr(unsigned pos = 0, unsigned n = 0);
	void append(const MyString& str);
	void print() const;

};

#endif

