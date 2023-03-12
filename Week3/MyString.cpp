#include "MyString.h"

void MyString::copy(const MyString& other)
{
	this->size = other.size;
	char* str = new char[strlen(other.string) + 1];
	strcpy_s(str, other.size + 1, string);
}

void MyString::erase()
{
	delete[] string;
}

MyString::MyString(const char* str): string(new char[strlen(str) + 1]), size(strlen(str))
{
	strcpy_s(string, size + 1, str);
}

MyString::MyString(const MyString& obj)
{
	copy(obj);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		delete[] string;
		copy(other);
	}

	return *this;
}

MyString::~MyString()
{
	erase();
}

int MyString::length() const
{
	return size;
}

char& MyString::at(unsigned index) const
{
	if (index > size || index < 0)
	{
		throw std::exception();
	}

	return string[index];
}

int MyString::find(char c, unsigned startPos) const
{
	for (size_t i = startPos; i < size; i++)
	{
		if (string[i] == c)
		{
			return i;
		}
	}

	return - 1;
}

bool MyString::empty() const
{
	return size == 0;
}

MyString MyString::substr(unsigned pos, unsigned n)
{
	if (pos < 0 || pos > size)
	{
		throw std::exception("Invalid index");
	}
	MyString other(*this);

	if (pos + n > size)
	{
		for (size_t i = pos; i < size; i++)
		{
			other.string[i - pos] = string[i];
		}
		other.string[pos + n] = '\0';
		other.size = size - pos;
	}
	else
	{
		for (size_t i = pos; i < pos + n; i++)
		{
			other.string[i - pos] = string[i];
		}
		other.string[pos + n] = '\0';
		other.size = n;
	}

	return other;
}

void MyString::append(const MyString& str)
{
	char* tempStr = new char[size + str.size + 1];
	strcpy_s(tempStr, size + 1, string);
	strcat_s(tempStr, str.size + 1, str.string);
	erase();
	string = tempStr;
}

void MyString::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << string[i];
	}
}
