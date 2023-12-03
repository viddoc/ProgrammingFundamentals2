#include <iostream>

#include "animal.h"

Animal::Animal(std::string name, double weight)
	:name(name), weight(weight){}

std::string Animal::getName() const
{
	return name;
}

double Animal::getWeight() const
{
	return weight;
}

void Animal::setWeight(double weight)
{
	this->weight = weight;
}

void Animal::displayInfo() const
{
	std::cout << "Name: " << name;
	std::cout << "\nWeight: " << weight;
}
