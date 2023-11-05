#ifndef _CAR_H_
#define _CAR_H_

#include <string>
#include <iostream>

#include "vehicle.h"

class Car : public Vehicle
{
private:
	int numDoors;
	std::string bodyType;

public:
	Car(std::string make, std::string model, int year, int numDoors, std::string bodyType);

	int getNumDoors() const;
	std::string getBodyType() const;

	std::string noise() const;

	friend std::ostream& operator<<(std::ostream& out, const Car& rhs);
};

#endif // !_CAR_H_
