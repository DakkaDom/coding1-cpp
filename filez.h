#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "ship.h"		// lets us know what ships are
using namespace std;

void WriteToFile(string givenString);
void ReadFromFile();
void WriteShipToFile(ship givenShip);