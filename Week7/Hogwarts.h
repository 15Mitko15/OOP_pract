#ifndef HOGWARTS_H
#define HOGWARTS_H

#include <iostream>
#include <string>

#include "Power.h"
#include "Student.h"

class Hogwarts {
private:
	Student* school;
	int size;
	int capacity;
	void copy(const Hogwarts& other);
	void erase();
	void resize();
public:
	Hogwarts();
	Hogwarts(const Hogwarts& other);
	Hogwarts(Hogwarts&& other);
	Hogwarts& operator=(const Hogwarts& other);
	Hogwarts& operator=(Hogwarts&& other);
	~Hogwarts();

	friend std::ostream& operator<<(std::ostream& out, const Hogwarts& hogwarts);

	void addStudent(const Student& student);
	void assignHouse(const std::string& studentName, const House& house);
	void givePower(const std::string& name, const Power& power);

	int getHouseStudentsCount(const House& house) const;
	Student* getFirstStudent(const House& house) const;
	const Student* getStudents() const;
	bool removeStudent(const std::string& name);
	Student& studentFight(Student& st1, Student& st2);
	void houseFight(const House& house1, const House& house2);
};

#endif  