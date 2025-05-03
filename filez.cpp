#include "filez.h"
#include "ship.h"

void WriteToFile(string givenString) {
	// open (or create) the file
	ofstream file("file.txt", ios::app);		// ios::app to append to the end of a file, means you don't overwrite every run

	// early return if the file cannot be opened
	if (!file.is_open()) {
		cout << "Could not open file.\n";
		return;
	}
	// write text to the open file
	file << givenString;

	// close the file (which saves it to disk)
	file.close();

}

void ReadFromFile() {
	string fileContents;		// this is where we store the text in the file

	// open the file
	ifstream file("file.txt");

	// check that it's actually open
	if (!file.is_open()) {
		cout << "Could not open the specified file.\n";
	}

	// cout everything in the file
	while (getline(file, fileContents)) {
		cout << fileContents << "\n";
	}

	// close the file
	file.close();
}

void WriteShipToFile(ship givenShip) {
	cout << "Writing " << givenShip.name << " to file.\n";

	ofstream file("ship.txt", ios::app);

	if (!file.is_open()) {
		cout << "Could not open file.\n";
		return;
	}

	file << "The good ship " << givenShip.name << ".\n";			// add the name of the ship to the file as a string
	file << "Has " << givenShip.fuel << " fuel.\n";			// add the fuel of the ship to the file as a string
									// need something to list the type of the ship into the file
	// file << givenShip.type;
	switch (givenShip.type) {
	case FIGHTER: file << "The ship's class is fighter.\n";
		break;
	case FRIGATE: file << "The ship's class is frigate.\n";
		break;
	case FREIGHTER: file << "The ship's class is freighter.\n";
		break;
	case CRUISER: file << "The ship's class is cruiser.\n";
		break;
	default: file << "The ship's class is unknown.\n";
		break;
	}
	

	file.close();

}
