#include <iostream>
#include "cargoship.h"

/* TODO: Code your CargoShip class implementation here */

CargoShip::CargoShip(std::string name, std::string yearBuilt, int tonnage)
:Ship(name, yearBuilt), tonnage(tonnage){}

int CargoShip::getTonnage() const
{
    return tonnage;
}

void CargoShip::print() const
{
    Ship::print();
    std::cout << "Cargo capacity: " << tonnage << std::endl;
}

void CargoShip::makeItGo() const
{
    std::cout << "The cargo ship goes toot toot!";
}
