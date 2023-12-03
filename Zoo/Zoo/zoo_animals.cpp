#include <iostream>

#include "zoo_animals.h"

Lion::Lion(std::string name, double weight, int hunts)
	:Animal(name, weight), hunts(hunts){}

int Lion::getHunts() const
{
	return hunts;
}

void Lion::setHunts(int hunts)
{
	this->hunts = hunts;
}

void Lion::displayInfo() const
{
	Animal::displayInfo();
	std::cout << "\nI am a lion with " << hunts << " hunts.";
}

std::string Lion::vocalize() const
{
	return "Rawr!";
}

Zebra::Zebra(std::string name, double weight, int stripes)
	:Animal(name, weight), stripes(stripes) {}

int Zebra::getStripes() const
{
	return stripes;
}

void Zebra::setStripes(int stripes)
{
	this->stripes = stripes;
}

void Zebra::displayInfo() const
{
	Animal::displayInfo();
	std::cout << "\nI am a zebra with " << stripes << " stripes.";
}

std::string Zebra::vocalize() const
{
	return "Neigh!";
}

Giraffe::Giraffe(std::string name, double weight, double neckLength)
	:Animal(name, weight), neckLength(neckLength) {}

double Giraffe::getNeckLength() const
{
	return neckLength;
}

void Giraffe::setNeckLength(double neckLength)
{
	this->neckLength = neckLength;
}

void Giraffe::displayInfo() const
{
	Animal::displayInfo();
	std::cout << "\nI am a giraffe with a neck length of " << neckLength << " feet.";
}

std::string Giraffe::vocalize() const
{
	return "Hum!";
}

Hippo::Hippo(std::string name, double weight, double breathDuration)
	:Animal(name, weight), breathDuration(breathDuration){}

double Hippo::getBreathDuration() const
{
	return breathDuration;
}

void Hippo::setBreathDuration(double breathDuration)
{
	this->breathDuration = breathDuration;
}

void Hippo::displayInfo() const
{
	Animal::displayInfo();
	std::cout << "\nI am a hippo with a breath duration of " << breathDuration << " seconds.";
}

std::string Hippo::vocalize() const
{
	return "Hungh!";
}
