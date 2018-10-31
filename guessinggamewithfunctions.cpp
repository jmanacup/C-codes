//John Manacup 10/29/18
//Program using void and VR functions
//This is a guessing game using c++ RNG Random Number Generator

#include <iostream>
#include <iomanip>
#include <cstdlib> //needed for the RNG function
#include <ctime> //needed for seed number to start for RNG function

using namespace std;

void printLines(int, char, int); // the function prototype with data types 
void setSecret(int&, int&);
bool guessOne(int, int);

int main() {
	//variables used
	int secret, high, count;
	bool done;
	char reply;

	//seed it only once
	srand(unsigned int(time(0))); //call to the void function srand
								 //argument is curent time in second

	count = 0;

	setSecret(secret, high);   // void function, 2 reference parameters

	do {
		done = guessOne(secret, high); // VR function, 2 value parameters 
		count++;
	} while (!done);

	printLines(2, '#', 50); 
	cout << "The secret number was: " << secret << endl;
	cout << "You used " << count << " guesses." << endl;
	printLines(2, '#', 50);

	return 0;
}

//function definition for setSecret
//Preconditions: RNG has already been seeded
//Postconditions: secret number and high value are set and returned thru the reference paramenters

void setSecret(int& secret, int& high){

	do {
		cout << "What is the high value for the range?" << endl;
		cin >> high;
	} while (high < 10 || high > 32000);
	
	secret = rand() % high + 1;
}
//function to handle ONE guess
//Preconditions: secret number and high number are already set 
//Postconditions: user has been informed if high, low, correct
//					function return true if correct, false otherwise
bool guessOne(int secret, int high) {

	int guess;

	cout << "Guess my secret number between 1 and " << high << ": ";
	cin >> guess;

	if (guess < secret) {
		printLines(1, '-', 50);
		cout << "TOO LOW!" << endl << endl;
	}
	else if (guess > secret) {
		printLines(1, '+', 50);
		cout << "TOO HIGH!" << endl << endl;
	}
	else
		cout << "You guessed it! DAB DAB DAB " << endl;

	return guess == secret;

}
void printLines(int lines, char symbol, int numsyms) { // formal parameter list

	int i, num; // local variables

	for (i = 1; i <= lines; i++) {
		for (num = 1; num <= 45; num++)
			cout << symbol;
		cout << endl;
	}

}