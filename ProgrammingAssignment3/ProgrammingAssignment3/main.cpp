/******************************
  Tommy Hudson
  11/22/2023
   main.cpp
   Output information about ships
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#include "ship.h"
#include "cruiseship.h"
#include "cargoship.h"

// Global variables
const int NAME_LENGTH = 30;
const int YEAR_LENGTH = 5;
const string FILENAME = "ship.dat";

struct ShipRecord {
	char shipType;	// C for cargo or L for cruise
	char shipName[NAME_LENGTH];
	char year[YEAR_LENGTH];
	int data;		// passengers or tonnage
};

// Function declarations
void loadShips(vector<Ship*>& vShip, string fileName);

int main() {
	vector<Ship*> ships;
	loadShips(ships, FILENAME);
	

	// Print out the ships
	for (Ship* s : ships) {
		s->makeItGo();
		cout << endl;
		s->print();
		cout << endl;
	}    
    
	//	Make sure we place the end message on a new line
    cout << endl;
	
    return 0;
}

void loadShips(vector<Ship*>& vShip, string fileName) {
	ofstream outFile("ships.txt");

	fstream file(fileName, ios::in | ios::binary);
	if (!file) {
		cout << "Problem opening file " << fileName << endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}

	ShipRecord sr;	// temp holding for a ship record
	while (file.read(reinterpret_cast<char*>(&sr), sizeof(sr))) {
		if (sr.shipType == 'L')	{ 
			// it is a cruise ship
			vShip.push_back(new CruiseShip(sr.shipName, sr.year, sr.data));
			
		}
		else { 
			// it is a cargo ship
			vShip.push_back(new CargoShip(sr.shipName, sr.year, sr.data));
			
		}
		cout << sr.shipType << "," << sr.shipName << "," << sr.year << "," << sr.data << endl;
		outFile << sr.shipType << "," << sr.shipName << "," << sr.year << "," << sr.data << endl;
	}

	outFile.close();
	file.close();

}
