// John Manacup 9/10/2018
//Program to change Fahrenheit temps to Celcius

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	
	double celcius, fahrenheit;

	cout << "Enter a Fahrenheit temperature: ";
	cin >> fahrenheit;

	celcius = (5.0 / 9) * (fahrenheit - 32);

	cout << fixed << showpoint << setprecision(2);
	cout << "The degree Celcius equivalent of " << fahrenheit << " degree Fahrenheit is: " << celcius << endl << endl << endl;















	return 0;
}
