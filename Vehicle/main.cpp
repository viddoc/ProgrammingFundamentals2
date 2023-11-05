//Tommy Hudson Vehicle program

#include <iostream>
#include <string>

#include "vehicle.h"
#include "car.h"
#include "motorcycle.h"
#include "gokart.h"

int main()
{
	Vehicle v("Generic", "Generic", 2023);
	Car c("Chevrolet", "Corvette", 1965, 2, "Coupe");
	Motorcycle m("Kawasaki", "Ninja", 2023, true, 900);
	Gokart g("Trailmaster", "Blazer", 2022, 2, true);

	std::cout << "Vehicle\n";
	std::cout << v << std::endl;
	std::cout << "Car\n";
	std::cout << c << std::endl;
	std::cout << "Motorcycle\n";
	std::cout << m << std::endl;
	std::cout << "Gokart\n";
	std::cout << g << std::endl;
	


	return 0;
}