//John Manacup 10/12/2018
//A program that takes intervals and get their square, cube, and root	

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

int main() {

	ofstream outputFile;
	outputFile.open("record.txt");

	int max = 75, intTotal, squaredTotal, cubedTotal;
	double sqrtTotal;
	intTotal = squaredTotal = cubedTotal = sqrtTotal = 0;

	cout << fixed << showpoint;

	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "Integer    " << setw(20) << "Squared    " << setw(20) << "Cubed      " << setw(20) << "Square Root" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	
	for (int min = 50; min <= max; min++) {
		
		cout << min << setw(23) << int(pow(min,2)) << setw(20) << int(pow(min,3)) << setw(22) << setprecision(2) << sqrt(min) << endl;

		intTotal += min;
		squaredTotal += int(pow(min, 2));
		cubedTotal += int(pow(min, 3));
		sqrtTotal += sqrt(min);
		
	}

	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << intTotal << setw(23) << squaredTotal << setw(19) << cubedTotal << setw(22) << setprecision(2) << sqrtTotal << endl;

	outputFile << intTotal << setw(23) << squaredTotal << setw(19) << cubedTotal << setw(22) << setprecision(2) << sqrtTotal << endl;

	outputFile.close();

	return 0;
}