#pragma once
#include <vector>

template <typename T>
class ZooSector
{
private:
	std::vector<T> animals;
	int x;
	int y;
public:
	void printAnimals() const;
	void addAnimal(const T& animal);
};

template<typename T>
inline void ZooSector<T>::printAnimals() const
{
	for (size_t i = 0; i < animals.size(); i++)
	{
		animals[i].print();
	}
}

template<typename T>
inline void ZooSector<T>::addAnimal(const T& animal)
{
	animals.push_back(animal);
}
