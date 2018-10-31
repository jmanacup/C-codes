//John Manacup 10/24/18
//Program that uses void functions

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
void printLines(int, char, int); // the function prototype with data types 

int main() {

	string name;
	int length;

	printLines(2,'=', 45);// the function call with arguments
	
	cout << "Enter your first name: ";
	cin >> name;

	length = name.size();

	printLines((length+2)*3, name[0], 55); //arguments 

	if (name < "M")
		cout << "A tall stranger will give you a package." << endl;
	else
		cout << "Watch for an exciting text message." << endl;

	printLines(2, '=' , 45);

	return 0;
}

//function definition for printLines

void printLines(int lines, char symbol, int numsyms) { // formal parameter list

	int i, num; // local variables

	for (i = 1; i <= lines; i++) {
		for (num = 1; num <= 45; num++)
			cout << symbol;
		cout << endl;
	}

}