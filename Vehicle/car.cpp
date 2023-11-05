#include "car.h"

Car::Car(std::string make, std::string model, int year, int numDoors, std::string bodyType)
    :Vehicle(make, model, year), numDoors(numDoors), bodyType(bodyType){}

int Car::getNumDoors() const
{
    return numDoors;
}

std::string Car::getBodyType() const
{
    return bodyType;
}

std::string Car::noise() const
{
    return "Vroom!";
}

std::ostream& operator<<(std::ostream& out, const Car& rhs)
{
    out << static_cast<const Vehicle&>(rhs);
    out << "Number of Doors: " << rhs.numDoors << std::endl;
    out << "Body Type: " << rhs.bodyType << std::endl;
    out << "Noise: " << rhs.noise() << std::endl;
    return out;
}
