#pragma once
#include "Set.h"

class Range : public Set
{
private:
	int beg;
	int end;
public:
	Range(int beg, int end);
	const bool validateRange();
	const bool subSet(int beg, int end) const override;
};