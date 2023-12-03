#ifndef _SHIP_H_
#define _SHIP_H_

#include<string>

class Ship
{
private:
	std::string name;
	std::string yearBuilt;

public:
	//Constructor method
	Ship(std::string name, std::string yearBuilt);
	//Getter methods
	std::string getName() const;
	std::string getYearBuilt() const;
	//Print method virtual
	virtual void print() const;
	//Make It Go method pure virtual
	virtual void makeItGo() const = 0;
};
#endif // !_SHIP_H_