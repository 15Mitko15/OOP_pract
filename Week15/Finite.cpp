#include "Finite.h"

Finite::Finite(int size, int* numbers)
{
	for (size_t i = 0; i < size; i++)
	{
		this->numbers[i] = numbers[i];
		checker[i] = 1;
	}
}

const bool Finite::subSet(int beg, int end) const
{
	for (int i = beg; i <= end; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (numbers[j] == i && checker[j] == 1) {
				continue;
			}
			if (j == 99)
			{
				return false;
			}
		}
	}
	return true;
}

void Finite::eraseElem(int num)
{
	for (size_t i = 0; i < 100; i++)
	{
		if (num == numbers[i])
		{
			checker[i] = 0;
		}
	}
}

void Finite::addElem(int num)
{
	for (size_t i = 0; i < 100; i++)
	{
		if (checker[i] == 0) 
		{
			checker[i] = 1;
			numbers[i] = num;
		}
	}
}
