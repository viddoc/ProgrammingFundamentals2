#include <iostream>
#include "cruiseship.h"

/* TODO: Code your CruiseShip class implementation here */

CruiseShip::CruiseShip(std::string name, std::string yearBuilt, int maxPassengers)
:Ship(name, yearBuilt), maxPassengers(maxPassengers){}

int CruiseShip::getMaxPassengers() const
{
    return maxPassengers;
}

void CruiseShip::print() const
{
    Ship::print();
    std::cout << "Maximum passengers: " << maxPassengers << std::endl;
}

void CruiseShip::makeItGo() const
{
    std::cout << "The cruise ship goes woo woo!";
}
