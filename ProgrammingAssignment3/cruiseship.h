#ifndef _CRUISESHIP_H_
#define _CRUISESHIP_H_

#include <string>
#include "ship.h"

class CruiseShip : public Ship
{
private:
	int maxPassengers;

public:
	//Constructor
	CruiseShip(std::string name, std::string yearBuilt, int maxPassengers);
	//Getter method
	int getMaxPassengers() const;
	//Print override for Cruise Ship
	void print() const override;
	//Make It Go Cruise Ship implementation
	void makeItGo() const override;
};
#endif // !_CRUISESHIP_H_

