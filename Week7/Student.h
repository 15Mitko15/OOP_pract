#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>

#include "Power.h"

enum House
{
	Gryffindor, Slytherin, Ravenclaw, Hufflepuff, noHouse
};

class Student {
private:
	std::string name;
	House house;
	const Power* power;
	unsigned health;
public:
	Student();
	Student(const std::string& name);

	const std::string& getName() const;
	const House& getHouse() const;
	void setHouse(const House& house);
	int getHealth() const;
	void takeDamage(int damage);
	void setPower(const Power* power);
	const Power* getPower() const;
	bool isAlive();
	void attack(Student& st);
	friend std::ostream& operator<<(std::ostream& os, const Student& other);
};

#endif // STUDENT_H
