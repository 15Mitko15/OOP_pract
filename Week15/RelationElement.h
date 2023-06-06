#pragma once
#include <string>
#include <iostream>

template <typename T>
class RelationElement {
private:
	T subject;
	T object;
	std::string relation;
public:
	RelationElement(const T& subject, const T& object, const std::string& relation);

	void print() const;

};

template <>
class RelationElement<int> {
private:
	int subject;
	int object;
	std::string relation;
public:
	RelationElement(const int& subject, const int& object, const std::string& relation) :
		subject(subject), object(object), relation(relation){}

	void print() const
	{
		std::cout << subject << ", " << relation << " " << object;
	}

	RelationElement<int> operator*(const RelationElement<int>& other)
	{
		int tempSub = subject;
		int tempObject = other.object;
		std::string tempRelation = relation;
		tempRelation += " ";
		tempRelation += std::to_string(object);
		tempRelation += ", which is ";
		tempRelation += other.relation;
		RelationElement<int> tempObj(tempSub, tempObject, tempRelation);
		return tempObj;
	}

};

template<typename T>
inline RelationElement<T>::RelationElement(const T& subject, const T& object, const std::string& relation) :
	subject(subject), object(object), relation(relation)
{
}

template<typename T>
inline void RelationElement<T>::print() const
{
	{
		std::cout << subject << ", " << relation << " " << object;
	}
}

