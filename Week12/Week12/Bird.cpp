#include "Bird.h"

Bird::Bird(char* name, int weight, unsigned age, SleepPlace placeToSleep, Food food, int foodPerDay, std::string resqueCity):
           Animal(name, weight, age, placeToSleep, food, foodPerDay), resqueCity(resqueCity)
{
}

Animal* Bird::clone() const
{
    return new Bird(*this);
}

void Bird::print() const
{
    std::cout << name << ' ' << weight << ' ' << age<< ' ' << placeToSleep << ' ' << food << ' ' << foodPerDay << ' ' << resqueCity;
}
