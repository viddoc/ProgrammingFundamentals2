#ifndef _GOKART_H_

#include <string>
#include <iostream>

#include "vehicle.h"

class Gokart : public Vehicle
{
private:
	int numSeats;
	bool hasRollBar;

public:
	Gokart(std::string make, std::string model, int year, int numSeats, bool hasRollBar);

	int getNumSeats() const;
	bool getRollBar() const;
	
	std::string noise() const;

	friend std::ostream& operator<<(std::ostream& out, const Gokart& rhs);
};
#endif // !_GOKART_H_
