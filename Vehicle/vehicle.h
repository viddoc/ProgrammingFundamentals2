#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <string>
#include <iostream>

class Vehicle
{
private:
	std::string make;
	std::string model;
	int year;

public:
	Vehicle(std::string make, std::string model, int year);

	std::string getMake() const;
	std::string getModel() const;
	int getYear() const;

	std::string noise() const;

	friend std::ostream& operator<<(std::ostream& out, const Vehicle& rhs);
};

#endif // !_VEHICLE_H_