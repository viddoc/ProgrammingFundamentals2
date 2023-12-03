#ifndef _ZOO_ANIMALS_H_
#define _ZOO_ANIMALS_H_

#include <string>

#include "animal.h"

//Lion class
class Lion : public Animal
{
private:
	int hunts;

public:
	Lion(std::string name, double weight, int hunts);
	
	int getHunts() const;
	void setHunts(int hunts);

	void displayInfo() const override;
	std::string vocalize() const override;
};
//Zebra class
class Zebra : public Animal
{
private:
	int stripes;

public:
	Zebra(std::string name, double weight, int stripes);

	int getStripes() const;
	void setStripes(int stripes);

	void displayInfo() const override;
	std::string vocalize() const override;
};
//Giraffe class
class Giraffe : public Animal
{
private:
	double neckLength;

public:
	Giraffe(std::string name, double weight, double neckLength);

	double getNeckLength() const;
	void setNeckLength(double neckLength);

	void displayInfo() const override;
	std::string vocalize() const override;
};
//Hippo class
class Hippo : public Animal
{
private:
	double breathDuration;

public:
	Hippo(std::string name, double weight, double breathDuration);

	double getBreathDuration() const;
	void setBreathDuration(double breathDuration);

	void displayInfo() const override;
	std::string vocalize() const override;
};


#endif // !_ZOO_ANIMALS_H_
