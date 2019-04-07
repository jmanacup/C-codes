//John Manacup
//9/26/2018
//A program that computes the amount of time a soundwave will travel in selected medium

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>

using namespace std;

int main() {
	
	//variables used
	int counter = 6;
	const int airFeet = 1100, waterFeet = 4900, steelFeet = 16400;
	double feetDistance, finalSec;
	string medium;
	bool check;
	
	//header for menu
	cout << "------------------------------------------------------------" << endl;
	cout << left << setw(30) << "Medium" << setw(30) << "Speed" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << setw(30) << "Air  " << setw(30) << "1,100 feet per second" << endl;
	cout << setw(30) << "Water" << setw(30) << "4,900 feet per second" << endl;
	cout << setw(30) << "Steel" << setw(30) << "16,400 feet per second" << endl;
	cout << "------------------------------------------------------------" << endl << endl;

	//while counter up  to 6 times
	while (counter > 0) {

		//ask for medium
		cout << "Insert a medium to use (as seen on the menu): ";
		cin >> medium;

		//change first letter of medium into lowercase
		medium[0] = tolower(medium[0]);

		//ask for distance
		cout << "Insert distance in feet: ";
		cin >> feetDistance;

		//assign check to conditional statements
		check = feetDistance >= 0 && (medium == "air" || medium == "water" || medium == "steel");

		//check if the input is invalid
		if (!check) 
			cout << "Invalid Selection! Please try again." << endl;
		
		//computes for time with respect to medium
		else {
			if (medium == "air") 
				finalSec = feetDistance / airFeet;
			
			else if (medium == "water") 
				finalSec = feetDistance / waterFeet;
			
			else 
				finalSec = feetDistance / steelFeet;
			
			//change the output
			cout << fixed << showpoint;

			//output the result
			cout << "Through " << medium << ", sound waves travel " << setprecision(1) << feetDistance << " feet in " << setprecision(4) << finalSec << " seconds." << endl << endl;

			//makes the counter minus 1 each time completed
			counter--;
		}

	}
	return 0;
}