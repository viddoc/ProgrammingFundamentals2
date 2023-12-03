//Tommy Hudson Zoo program
#include <iostream>
#include <vector>
#include <typeinfo>

#include "animal.h"
#include "zoo_animals.h"

void populateZoo(std::vector<Animal*>& animals);
void rollCall(const std::vector<Animal*>& animals);
void who(Animal* animal);

int main()
{
	std::vector<Animal*> animals;

	populateZoo(animals);
	rollCall(animals);

	std::cout << std::endl;

	for (auto animal : animals)
	{
		who(animal);
	}


	return 0;
}

void populateZoo(std::vector<Animal*>& animals)
{
	animals.push_back(new Lion("Alex", 520, 0));
	animals.push_back(new Zebra("Marty", 825, 78));
	animals.push_back(new Giraffe("Melman", 3895, 71.3 / 12));
	animals.push_back(new Hippo("Gloria", 3217, 317.8));
}

void rollCall(const std::vector<Animal*>& animals)
{
	std::cout << "Roll Call\n";
	for (auto animal : animals)
	{
		animal->displayInfo();
		std::cout << "\nI go " << animal->vocalize() << std::endl << std::endl;
	}
}

void who(Animal* animal)
{
	std::cout << typeid(*animal).name() << std::endl;
	std::cout << typeid(*animal).raw_name() << std::endl;
	if (typeid(*animal) == typeid(Lion))
	{
		std::cout << "I have " << dynamic_cast<Lion*>(animal)->getHunts() << " hunts.\n";
	}
	else if (typeid(*animal) == typeid(Zebra))
	{
		std::cout << "I have " << dynamic_cast<Zebra*>(animal)->getStripes() << " stripes.\n";
	}
	else if (typeid(*animal) == typeid(Giraffe))
	{
		std::cout << "I have a " << dynamic_cast<Giraffe*>(animal)->getNeckLength() << " foot long neck.\n";
	}
	else if (typeid(*animal) == typeid(Hippo))
	{
		std::cout << "I can hold my breath for " << dynamic_cast<Hippo*>(animal)->getBreathDuration() << " seconds.\n";
	}
	else
	{
		std::cout << "Animal not identified.\n";
	}
}
