#ifndef _MOTORCYCLE_H_
#define _MOTORCYCLE_H_

#include <string>
#include <iostream>

#include "vehicle.h"

class Motorcycle : public Vehicle
{
private:
	bool streetLegal;
	int engineSize;

public:
	Motorcycle(std::string make, std::string model, int year, bool streetLegal, int engineSize);

	bool getStreetLegal() const;
	int getEngineSize() const;

	std::string noise() const;

	friend std::ostream& operator<<(std::ostream& out, const Motorcycle&);
};


#endif	// !_MOTORCYCLE_H_
