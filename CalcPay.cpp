//John Manacup 9/5/2018

// This program calculates the user's pay.

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	double hours, rate, pay;
	cout << fixed << showpoint << setprecision(2); // manage display format for floating point values

	// Get the number of hours worked.
	cout << "How many hours did you work? ";
	cin >> hours;

	// Get the hourly pay rate.
	cout << "How much do you get paid per hour? ";
	cin >> rate;

	if (hours <= 40.0)
		pay = hours * rate;
	else{
	pay = 40 * rate + (hours - 40) * rate*1.5;
	cout << "Overtime Calculated." << endl;
	}
	// Display the pay.
	cout << "You have earned $" << pay << endl << endl << endl;
	return 0;
}