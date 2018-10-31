//John Manacup
//10/24/18
//A program that apply random function library and value returning and void functions to simulate the "Craps" game

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cctype>

using namespace std;

//function prototypes
void printDice(int);
void rulesCrap();
int rollDice();
void rollPoint(int);

int main() {

	srand(unsigned(time(0))); // This is to provide different seed each time you run the program

	rulesCrap(); //outputs the header and the rules of the game

	char reply; // to loop the program again

	do{

		int total = rollDice(); //run rollDice function and takes in total
	

		cout << "The sum of the two dice is: " << total << endl; // initiate the game

		switch (total) { // tests the total according to the rules
		//winning cases
			case 7:
			case 11:
				cout << "Congratulation! You won the game." << endl;
				break;
			//losing cases
			case 2:
			case 3:
			case 12:
				cout << "Craps! You lost the game." << endl;
				break;
			//neither
			default:
				cout << "Your point is: " << total << endl << endl;
				rollPoint(total);
		}

		cout << endl; // spacing

		cout << "Do you want to play again? (y/n): "; // asks the user if he wants to play again
		cin >> reply;
		cin.ignore(40, '\n');
		reply = tolower(reply);

		cout << endl; //spacing

	}while(reply == 'y');
	

	return 0;
}

/* Precondition  : the main function will be the one calling it after printing the 
				   rules of Craps, also srand has been called
   Postcondition : it takes two values of random dice and calls the fuction printDice
				   that will print the graphical representation of the face of the die
				   and it returns the total of the 2 values of the dice for main function to check
*/
int rollDice() {//value returning function that performs the rolling of dice

	//integers used
	char ch; 
	int firstDice, secondDice, total, minValue = 1, maxValue = 6;

	//asks the user to roll a dice
	cout << "Please press Enter once to roll the dice. "; 
	cin.get(ch);

	//put the random values assigned to the dice
	firstDice = rand() % (maxValue-minValue + 1) + 1;
	secondDice = rand() % (maxValue-minValue + 1) + 1;

	//adds the firstDice and secondDice together
	total = firstDice + secondDice;

	//print the dice accordingly to their numbers
	printDice(firstDice);
	printDice(secondDice);
	cout << endl;

	return total; //returns the total of two dice
}

/* Precondition  : it would go through this function assuming that the player did not win
				   or lose in the first throw and takes an int parameter of the player's current point
   Postcondition : it will automatically enters a loop that will call the rollDice function until the 
				   player win or lose the game based on the rules
*/
void rollPoint(int point) {

	int rollAgain = 0; //just to initialize rollAgain

	while (rollAgain != point && rollAgain != 7) { //loop that will continue unless rollAgain will be equal to point or 7
		rollAgain = rollDice();
		cout << "The sum of the two dice is: " << rollAgain << endl;
	}

	cout << endl; // spacing

	if (rollAgain == 7) // check to see if the sum is 7
		cout << "Sorry! You Lost the game." << endl;
	else // check to see if the sum is equal to point
		cout << "Congratulations! You won the game." << endl;


}

/* Precondition  : it will be called by the main function as the starting function of the program
   Postcondition : it outputs the explanations and rules of the game, "Crap" as well as the 
				   heading of the program
*/
void rulesCrap(){ 
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(50) << "WELCOME TO CRAPS GAME" << endl;
	cout << "--------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(47) << "RULES TO FOLLOW" << endl;
	cout << "--------------------------------------------------------------------------------------------------------" << endl << endl;
	cout << "1. A player rolls two dice simultaneously. (In order to roll a dice, you need to press enter)" << endl;
	cout << "2. If the sum is 7 or 11 on the first throw, the player wins." << endl;
	cout << "3. If the sum is 2, 3, or 12 on the first throw, the player loses." << endl;
	cout << "4. If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then that sum becomes the player's point." << endl;
	cout << "5. If you don't win or lose on the first roll, you must continue rolling the dice until you win or lose" << endl;
	cout << "6. If you make your point you win; if you roll a 7 you lose." << endl << endl;
	cout << setw(52) << "ARE YOU READY? LET'S PLAY !!" << endl << endl;
	cout << "--------------------------------------------------------------------------------------------------------" << endl << endl;
}

/* Precondition  : the rollDice function has been called by the main and takes an int parameter of a dice; range has been established
   Postcondition : it prints the rolled dice (one dice face) depending on the taken parameter and outputs
				   its corresponding graphical representation
*/
void printDice(int num) { 
	
	char shade = char(254); //used to indicate the shade

	cout << "-------" << endl; //top portion of dice
	
	switch (num) { //present the graphics of the dice based on their number of their hole accordingly

		case 1: //one die face
			cout << "|     |" << endl;
			cout << "|  " << shade << "  |" << endl;
			cout << "|     |" << endl;
			break;
		case 2: // two die face
			cout << "| " << shade << "   |" << endl;
			cout << "|     |" << endl;
			cout << "|   " << shade << " |" << endl;
			break;
		case 3: // three die face
			cout << "| " << shade << "   |" << endl;
			cout << "|  " << shade << "  |" << endl;
			cout << "|   " << shade << " |" << endl;
			break;
		case 4: //four die face
			cout << "| " << shade << " " << shade << " |" << endl;
			cout << "|     |" << endl;
			cout << "| " << shade << " " << shade << " |" << endl;
			break;
		case 5: //five die face
			cout << "| " << shade << " " << shade << " |" << endl;
			cout << "|  " << shade << "  |" << endl;
			cout << "| " << shade << " " << shade << " |" << endl;
			break;
		case 6: // six die face
			cout << "| " << shade << " " << shade << " |" << endl;
			cout << "| " << shade << " " << shade << " |" << endl;
			cout << "| " << shade << " " << shade << " |" << endl;
			break;
	}
	cout << "-------" << endl; // bottom portion of dice

}
