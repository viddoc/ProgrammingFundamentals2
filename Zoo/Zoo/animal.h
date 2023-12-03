#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <string>

//Animal will be an abstract base class (ABC)
class Animal
{
private:
	std::string name;
	double weight;

public:
	Animal(std::string name, double weight);

	std::string getName() const;
	double getWeight() const;
	void setWeight(double weight);

	virtual void displayInfo() const;
	virtual std::string vocalize() const = 0;
};


#endif // !_ANIMAL_H_