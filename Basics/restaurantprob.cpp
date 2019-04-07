// John Manacup 9/10/2018
//Program to compute a bill for a customer at a restaurant

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	double mealAmount, taxAmount, tipAmount, total;

	//header of the program
	cout << "Welcome to Papa John's Restaurant!" << endl;
	cout << "Server name is: John Manacup " << endl;
	cout << "Today is 9/10/2018" << endl;
	cout << "========================================================" << endl;
	cout << "Input the meal charge: ";
	
	//input the meal charge
	cin >> mealAmount;

	//computations
	taxAmount = mealAmount * 0.0825;
	tipAmount = (mealAmount + taxAmount) * 0.15;
	total = mealAmount + taxAmount + tipAmount;

	//to fix decimal places
	cout << fixed << showpoint << setprecision(2);
	
	//output of the program with the corresponding widths
	cout << left << setw(27) << "The Meal Charge amount is: " << right << setw(7) << mealAmount << endl;
	cout << left << setw(27) << "The tax (8.25%) is: " << right << setw(7) << taxAmount << endl;
	cout << left << setw(27) << "The tip (15%) is: " << right << setw(7) << tipAmount << endl;
	cout << "========================================================" << endl;
	cout << left << setw(27) << "The total amount is: " << right << setw(7) <<total << endl;

	return 0;
}