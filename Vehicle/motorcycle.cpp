#include "motorcycle.h"

Motorcycle::Motorcycle(std::string make, std::string model, int year, bool streetLegal, int engineSize)
    :Vehicle(make, model, year), streetLegal(streetLegal), engineSize(engineSize){}

bool Motorcycle::getStreetLegal() const
{
    return streetLegal;
}

int Motorcycle::getEngineSize() const
{
    return engineSize;
}

std::string Motorcycle::noise() const
{
    return "Brrappp!";
}

std::ostream& operator<<(std::ostream& out, const Motorcycle& rhs)
{
    out << static_cast<const Vehicle&>(rhs);
    out << "Street Legal: " << (rhs.getStreetLegal() ? "Yes" : "No") << std::endl;
    out << "Engine Size: " << rhs.engineSize << std::endl;
    out << "Noise: " << rhs.noise() << std::endl;

    return out;
}
