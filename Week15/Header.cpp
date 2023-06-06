#include "Range.h"
#include <exception>

Range::Range(int beg, int end):Set(), beg(beg), end(end)
{
	if (!(validateRange()))
	{
		throw std::exception("Not cool bro!");
	}
}

const bool Range::validateRange()
{
	return beg < end;
}

const bool Range::subSet(int beg, int end) const
{
	return beg > this->end || end < this->beg;
}
