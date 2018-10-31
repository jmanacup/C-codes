//John Manacup 9/12/2018
//A program that computes the wind chill factor and convert necessary units
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

	double velocity, tempCelc, windChill, tempFah, windChillCelc;
	char degrees = char(248);

	//asks the user for velocity and temperature
	cout << "Insert the velocity (kph): ";
	cin >> velocity;
	cout << "Insert the temperature (Celcius): ";
	cin >> tempCelc;

	//convert kilometers to mile
	velocity *= 0.621;

	//convert Celcius to Fahrenheit
	tempFah = (9.0 / 5) * (tempCelc) + 32;

	//computes the windChill factor
	windChill = 35.74 + (0.6215 * tempFah) - (35.75 * pow(velocity, 0.16)) + (0.4275 * tempFah * pow(velocity, 0.16));
	windChillCelc = (5.0 / 9) * (windChill - 32);

	//restricts the decimals into 2
	cout << fixed << showpoint << setprecision(2);

	//output the wind chill factor
	cout << "The wind chill factor is: " << windChill << degrees << "F or " << windChillCelc << degrees << 'C' << endl;

	return 0;
}