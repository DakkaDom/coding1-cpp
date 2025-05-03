#pragma once

#include <iostream>
#include <string>
using namespace std;

// specifies the different types of ships
enum shipType { FIGHTER, FRIGATE, FREIGHTER, CRUISER };

class ship
{
public:
	string name;
	int fuel;
	shipType type;

	ship();			// this is the constructor
	void status();	// equivalent to our "sayHello" void from other files
};