#pragma once
#include <string>

class Property
{
private:
	std::string owner;
	bool tangible;
public:
	Property(std::string owner, bool tangible): owner(owner), tangible(tangible){}
	virtual std::string getOwner() const
	{
		return owner;
	}
	virtual bool getTangible() const
	{
		return tangible;
	}

	virtual ~Property(){};
};