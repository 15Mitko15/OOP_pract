#pragma once
#include "Set.h"

class Finite : public Set
{
private:
	int numbers[100];
	bool checker[100];
public:
	Finite(int size, int* numbers);
	const bool subSet(int beg, int end) const override;
	void eraseElem(int num);
	void addElem(int num);
};