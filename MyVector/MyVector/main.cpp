//Tommy Hudson MyVector program

#include <iostream>
#include <string>

#include "vector.h"

void outputVector(cosc1437::Vector<std::string>& vec);

int main()
{
	cosc1437::Vector<std::string> vec;
	std::string stuff[15]{ "Red", "Green", "Blue", "Yellow", "Magenta", "Cyan", "Pink", 
		"Black", "White", "Navy", "Orange", "Purple", "Brown", "Gray", "Tan" };
	int capacity = 0;
	for (int i{ 0 }; i < 15; i++)
	{
		if (capacity != vec.getCapacity())
		{
			capacity = vec.getCapacity();
			std::cout << "Iteration: " << i << ", Size: " << vec.getSize()
				<< ", Capacity: " << vec.getCapacity() << std::endl;
		}
		vec.add(stuff[i]);
	}

	std::cout << std::endl;
	outputVector(vec);
	std::cout << std::endl;


	std::string color;
	std::cout << "Enter a color: ";
	getline(std::cin, color);
	vec.add(color);

	std::cout << std::endl;
	outputVector(vec);
	std::cout << std::endl;

	vec.remove();
	vec.remove();

	outputVector(vec);
	std::cout << std::endl;

	std::cout << "The size of my Vector is " << vec.getSize() << std::endl;
	std::cout << "The capacity of my Vector is " << vec.getCapacity() << std::endl;

	return 0;
}

void outputVector(cosc1437::Vector<std::string>& vec)
{
	int count = 0;
	for (cosc1437::Vector<std::string>::size_type i{ 0 }; i < vec.getSize(); i++)
	{
		std::cout << vec.at(i) << " ";
		count++;
		if (count % 10 == 0)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}
