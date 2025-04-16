// Dominic Borboa - Coding 1
// Classes and Structures HW

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// class keyword creates a class, name can be whatever but for this instance it will be 'human'
class human {
public:					// anyone can see these and call these etc. etc.

	// set up the member functions/declarations
	human(string givenName, int givenHealth, int givenDamage) {
		name = givenName;
		Health = givenHealth;
		Damage = givenDamage;

		cout << "A human has been formed!\n";
	}
	human() {
		cout << "Using the default human constructor.\n";
	}

	void SayHello() {
		cout << "My name is " << name << ", my health is " << Health << ", and my damage is " << Damage << ".\n";
	}
	
	// SetHealth clamps Health to a range of 0-10
	void SetHealth(int givenHealth) {
		if (givenHealth < 0) {
			Health = 0;
		}
		else if (givenHealth > 100) {
			Health = 100;
		}
		else {
			Health = givenHealth;
		}
	}
	// Allows health to be added to
	void AddToHealth(int by = 1) {
		Health += by;
		SetHealth(Health);		// clamping Health
	}
	// SetDamage clamps Damage to a range of 0-4
	void SetDamage(int givenDamage) {
		if (givenDamage < 0) {
			Damage = 0;
		}
		else if (givenDamage > 4) {
			Damage = 4;
		}
		else {
			Damage = givenDamage;
		}
	}
	// Allows damage to be added to
	void AddToDamage(int by = 1) {
		Damage += by;
		SetDamage(Damage);		// clamping Damage
	}
	void SetName(string givenName) {
		if (givenName.size() < 2) {
			cout << "Name is too short!\n";
			return;				// returns nothing out of a void function to end said function
		}
		else if (givenName.size() > 20) {
			cout << "Name is too long!\n";
			return;
		}
		else {
			name = givenName;
		}
	}
	string GetName() {
		return name;
	}
	int GetHealth() {
		return Health;
	}
	int GetDamage() {
		return Damage;
	}
private:	// only I can see these things

	// the data members
	string name;				// sets up a name call
	int minHealth = 0;			// sets up a minimum Health value
	int maxHealth = 10;			// sets up a maximum Health value
	int Health;
	int minDamage = 0;			// sets up a minimum Damage value
	int maxDamage = 4;			// sets up a maximum Damage value
	int Damage;

protected:
};

int main() {
	cout << "Classes, wahoo!\n";

	human chaderick;
	chaderick.SetName("Chaderick III");
	chaderick.SetHealth(10);
	chaderick.SetDamage(4);

	
	cout << "Look at that guy over there! His name is " << chaderick.GetName() << ".\n";
	cout << "He's not too tough, he only has " << chaderick.GetHealth() << " health.\n";
	cout << "He's not too scary either, he only does " << chaderick.GetDamage() << " damage!\n";

	chaderick.AddToHealth(10);
	cout << "Oh no bro, he just got buff! His health is now " << chaderick.GetHealth() << "!!\n";


	


}