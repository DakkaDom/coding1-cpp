// Dominic Borboa, Coding 1
// Adventure 2: Functions!

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int health = 25;
int totalGold;

void story(string storyText = "You awake in a forest...") {
	cout << storyText << "\n";
	cout << "You have " << health << " health.\n";			// Tells player their starting health value
}

bool yesOrNo() {
	string input;								// Storing player input for the question
	
	cout << "Adventure? (yes/no).\n";
	getline(cin, input);						// Asks for player input

	if (input == "yes")							// Ensures that "yes" triggers an adventure call
		return true;							// Something in here is breaking and accepting all input, I'm not sure what
	else										// Testing if this returns false as intended
		return false;							// Else the program ends (not working? Literally the only thing not working as intended, will have to learn in class why this is)
}

int rollDie(int minRoll = 1, int maxRoll = 20) {
	int range = (maxRoll - minRoll) + 1;		// Setting up the range of the die roll, classic D20 because I wanted the game to be a little riskier
	return rand() % range + minRoll;			// This should result in a roll of 1-20 to determine attack, block, or gold gained
}

void ending(string endingText = "You've come to the end of your journey.") {
	cout << endingText << "\n";
	cout << "You left with " << totalGold << " gold.\n";
}

void adventure() {
	int damage = rollDie();										// Roll for damage to player
	int block = rollDie();										// Roll for player block value
	int gainedGold = rollDie();									// Roll for player gold gain

	if (damage > block) {
		cout << "You took " << damage - block << " damage, but managed to get away with " << gainedGold << " gold.\n";
	}
	else if (damage <= block) {
		cout << "You successfully blocked the damage and got away with " << gainedGold << " gold.\n";
	}
	
	// subtract taken damage from global health value
		// create separate "takenDamage" value?
	int takenDamage = damage - block;
	if (takenDamage > 0) {
		health = health - takenDamage;
	}
		// health = totalHealth (can I just use health here? I don't think so (I totally can apparently!)) - takenDamage
	// add gainedGold to totalGold value
	if (gainedGold > 0) {
		totalGold = totalGold + gainedGold;
	}
}



int main() {
	srand(time(0));								// Random numbers should now work

	do {
		story();									// Calls story to introduce the player to their situation

		yesOrNo();									// Calls yesOrNo to determine if the player goes on an adventure
		if (yesOrNo) {								// If yesOrNo is true
			adventure();							// Call adventure
		}
	} while (health > 0);
	if (health <= 0) {
		ending();
	}


}

// Putting this at the end here for organization purposes
// Program runs - Check
// Player can begin the adventure - Check
// Player can decline the adventure - Not done // Extra Note: This is the only thing that doesn't work, no clue why
// Player rolls dice to determine damage, block, and gold gain - Check
// Player is told their health before beginning another adventure - Check
// Player ends the adventure if they have 0 or less health - Check
// Player is told how much gold they have gained over the course of their adventures - Check
// Overall, success??? No clue why the yesOrNo boolean is always true, will have to ask about it.