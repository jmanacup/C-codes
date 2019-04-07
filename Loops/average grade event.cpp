//John Manacup 10/8/2018
// averaging any number of grades from user using event controlled design - using a sentinel value

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int i, grade, total;
	double avg;
	cout << fixed << showpoint << setprecision(2);


	cout << "Enter grades to average. Enter -1 to quit." << endl;

	i = 0;
	total = 0;

	cout << "Enter a grade " << setw(2) << i + 1 << ": ";
	cin >> grade;

	while (grade != -1) {

		total += grade; //keeping a running total
		i++;

		cout << "Enter a grade " << setw(2) << i + 1 << ": ";
		cin >> grade;

	}
	if ( i > 0) {
		avg = double(total) / i;
		cout << "The average of " << i << " grades is " << avg << endl;
	}
	else
		cout << "Not enough data to analyze." << endl;




	return 0;
}