//John Manacup 10/12/2018
//A program that takes a decimal and convert it to binary

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {

	//integers used
	int num;
	bool inRange;
	ifstream inputFile;
	ofstream outFile;

	inputFile.open("digits.txt");
	outFile.open("digitsresult.txt");
	while(inputFile >> num){

		inRange = num >= 0 && num <= 65535; //initializing range
		outFile << "The base 10 number is: " << num << endl;
		if (!inRange) // check to see if the num given is in range
			outFile << "The number given is out of range.";

		else {

			outFile << "The assigned binary equivalent: ";

			for (int i = 15; i >= 0; i--) {

				if (num >= int(pow(2, i))) {
					outFile << 1;
					num -= int(pow(2, i));
				}

				else
					outFile << 0;

				if (i % 4 == 0)
					outFile << ' ';

			}
		}
			outFile << endl << endl; //spacing
	
		}
	

	return 0;
}