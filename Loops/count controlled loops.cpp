//John Manacup 10/8/2018
//count controlled loops testing

#include <iostream>
#include <iomanip>
using namespace std;


int main() {

	int age, i;
	// initialization

	cout << "Enter your age in years: ";
	cin >> age;

/*	while (i <= age) { // test
		cout << setw(2) << i << ". Happy Birthday! Hooray! " << endl;
		i++; // increment
	} */
	//alternative count controlled loop using for syntax

	for (i = 1; i <= age; i++) 
		cout << setw(2) << i << ". Happy Birthday! Hooray! " << endl;
	

	cout << endl;
	
	if (age < 21)
		cout << "Eat a lot of cake." << endl;
	else
		cout << "Please be responsible." << endl;



	return 0;
}