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

	inputFile.open("D:\\working\\digits.txt");

	while(inputFile >> num){

		inRange = num >= 0 && num <= 65535; //initializing range

		if (!inRange) // check to see if the num given is in range
			cout << "The number given is invalid.";

		else {

			cout << "The assigned binary equivalent: ";

			for (int i = 15; i >= 0; i--) {

				if (num >= int(pow(2, i))) {
					cout << 1;
					num -= int(pow(2, i));
				}

				else
					cout << 0;

				if (i % 4 == 0)
					cout << ' ';

			}
		}
			cout << endl; //spacing
	
		}
	

	return 0;
}