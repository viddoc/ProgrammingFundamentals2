#include "vehicle.h"

Vehicle::Vehicle(std::string make, std::string model, int year)
    :make(make), model(model), year(year){}

std::string Vehicle::getMake() const
{
    return make;
}

std::string Vehicle::getModel() const
{
    return model;
}

int Vehicle::getYear() const
{
    return year;
}

std::string Vehicle::noise() const
{
    return std::string();
}

std::ostream& operator<<(std::ostream& out, const Vehicle& rhs)
{
    out << "Make: " << rhs.make << std::endl;
    out << "Model: " << rhs.model << std::endl;
    out << "Year: " << rhs.year << std::endl;
    return out;
}
