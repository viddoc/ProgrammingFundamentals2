#ifndef _CARGOSHIP_H_
#define _CARGOSHIP_H_

#include<string>
#include "ship.h"

class CargoShip : public Ship
{
private:
	int tonnage;

public:
	//Constructor
	CargoShip(std::string name, std::string yearBuilt, int tonnage);
	//Getter
	int getTonnage() const;
	//Print override
	void print() const override;
	//Make It Go Cargo Ship implementation
	void makeItGo() const override;
};
#endif // !_CARGOSHIP_H_

