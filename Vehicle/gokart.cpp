#include "gokart.h"

Gokart::Gokart(std::string make, std::string model, int year, int numSeats, bool hasRollBar)
    :Vehicle(make, model, year), numSeats(numSeats), hasRollBar(hasRollBar){}

int Gokart::getNumSeats() const
{
    return numSeats;
}

bool Gokart::getRollBar() const
{
    return hasRollBar;
}

std::string Gokart::noise() const
{
    return "Bap bap bap!";
}

std::ostream& operator<<(std::ostream& out, const Gokart& rhs)
{
    out << static_cast<const Vehicle&>(rhs);
    out << "Number of seats: " << rhs.numSeats << std::endl;
    out << "Has a roll bar: " << (rhs.getRollBar() ? "Yes" : "No") << std::endl;
    out << "Noise: " << rhs.noise() << std::endl;
    return out;
}
