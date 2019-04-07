//John Manacup 10/8/2018
// averaging any number of grades from user

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int num, i, grade, total;
	double avg;
	cout << fixed << showpoint << setprecision(2);

	cout << "Enter the number of grades: ";
	cin >> num;

	i = 1;
	total = 0;

	while (i <= num) {

		cout << "Enter a grade " << setw(2) << i << ": ";
		cin >> grade;

		total += grade; //keeping a running total
		i++;
	}
	if (num > 0) {
		avg = double(total) / num;
		cout << "The average of " << num << " grades is " << avg << endl;
	}
	else 
		cout << "Not enough data to analyze." << endl;
	
	


	return 0;
}