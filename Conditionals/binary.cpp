//John Manacup
//9/26/2018
//A program that takes a decimal form of number and gives its binary form

#include <iostream>

using namespace std;

int main() {

	//variables to use
	int num; 
	bool inRange;

	//ask the user for input
	cout << "Input a value from 0 to 255: ";
	cin >> num; 

	//test to see if the input is between inRange
	inRange = num >= 0 && num <= 255;

	//inputs error if user's input is out of range
	if (!inRange) {	
		cout << "ERROR! Input value is out of range for this program." << endl << endl;
	}
	else {

		cout << "The assigned binary equivalent is: ";

		if (num >= 128) {
			cout << 1;
			num -= 128;
		}
		else 
			cout << 0;
		
		if (num >= 64) {
			cout << 1;
			num -= 64;
		}
		else 
			cout << 0;
		
		if (num >= 32) {
			cout << 1;
			num -= 32;
		}
		else 
			cout << 0;
		
		if (num >= 16) {
			cout << 1 << ' ';
			num -= 16;
		}
		else 
			cout << 0 << ' ';
		
		if (num >= 8) {
			cout << 1;
			num -= 8;
		}
		else 
			cout << 0;
		
		if (num >= 4) {
			cout << 1;
			num -= 4;
		}
		else 
			cout << 0;
		
		if (num >= 2) {
			cout << 1;
			num -= 2;
		}
		else 
			cout << 0;
		
		if (num >= 1) {
			cout << 1;
			num -= 1;
		}
		else 
			cout << 0;
		

		cout << endl << endl;
	}

	return 0;
}