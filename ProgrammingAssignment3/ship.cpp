#include <iostream>

#include "ship.h"

/* TODO: Code your ship class implementation here */

Ship::Ship(std::string name, std::string yearBuilt)
    :name(name), yearBuilt(yearBuilt){}

std::string Ship::getName() const
{
    return name;
}

std::string Ship::getYearBuilt() const
{
    return yearBuilt;
}

void Ship::print() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Year Built: " << yearBuilt << std::endl;
}

