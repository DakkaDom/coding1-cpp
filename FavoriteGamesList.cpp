// Dominic Borboa, If/ElseIf/Else Favorite Games Project
// Coding 1

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


int main() {
	cout << "Hello user! Let's make a list of your favorite games!\n";
	cout << "Available actions are 'Add', 'Edit', 'Remove', and 'Show'.\n";

	string favGames[10];
	int currentElement = 0;
	string input;

		
	while (input != "Quit") {
		getline(cin, input);
		if (input == "Add") {
			cout << "What would you like to add?\n";
			// Get user to add a game to a list // Done
			// Make sure the list is updated  // Done
			// Do not end program after list is created // Done
			// Ensure list can be interacted with by other actions // Done
			// How to do any of that? No clue, figuring it out
			do {
				getline(cin, input);

				favGames[currentElement++] = input;
			} while (currentElement < 10);
		}
		else if (input == "Edit") {
			cout << "What would you like to edit?\n";
			getline(cin, input);
			for (int i = 0; i < 10; i++) {
				if (input == favGames[i]) {
					cout << "What should it be changed to?\n";
					getline(cin, input);
					favGames[i] = input;
				}
			}
		}
		else if (input == "Remove") {
			cout << "What would you like to remove?\n";
			getline(cin, input);
			for (int i = 0; i < 10; i++) {
				if (input == favGames[i]) {
					cout << "Game has been removed!\n";
					favGames[i] = "";
				}
			}
		}
		else if (input == "Show") {
			for (int i = 0; i < 10; i++) {
				if (favGames[i] == "") {
					continue;
				}
				else {
					cout << favGames[i] << ".\n";
				}
			}
		}
		else {
			cout << "I do not understand,\n";
			break;
		}
	}
		

}