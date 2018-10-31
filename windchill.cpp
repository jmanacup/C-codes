//John Manacup 9/12/2018
//Program that computes the wind chill factor
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

	double velocity, temperature, windChill;
	char degrees = char(248);

	//asks the user for velocity and temperature
	cout << "Insert the velocity (mph): ";
	cin >> velocity;
	cout << "Insert the temperature (Fahrenheit): ";
	cin >> temperature;

	//computes the windChill factor
	windChill = 35.74 + (0.6215 * temperature) - (35.75 * pow(velocity, 0.16)) + (0.4275 * temperature * pow(velocity, 0.16));

	//restricts the decimals into 2
	cout << fixed << showpoint << setprecision(2);

	//output the wind chill factor
	cout << "The wind chill factor is: " << windChill << degrees << 'F' << endl;

	return 0;
}