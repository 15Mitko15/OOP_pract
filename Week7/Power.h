#ifndef POWER_H_
#define POWER_H_
#include <string>
#include <iostream>

class Power {
private:
	std::string name;
	int damage;
public:
	Power(const std::string& name, int damage);

	const std::string& getName() const;
	int getDamage() const;

	bool operator<(const Power& other) const;
	bool operator>(const Power& other) const;
	friend std::ostream& operator <<(std::ostream& os, const Power other);
};

#endif  