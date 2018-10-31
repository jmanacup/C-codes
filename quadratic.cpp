//John Manacup, Seth Staggs,Kain Esteban
//September 24, 2018
//A program that computes the solutions using quadratic formula

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

	//variables to use
	double a, b, c, discrim, sol1, sol2;

	//take in 3 coefficient
	cout << "Insert three coefficients: ";
	cin >> a >> b >> c;

	//Just for spacing
	cout << endl;

	//check for inputs if valid
	if (a == 0) 
		cout << "Not a quadratic function" << endl << endl;
	
	else {

		//prints the general form of equation
		cout << "The general form for the quadratic equation is: " << a << "x^2 + " << b << "x + " << c << endl << endl;

		//establish check to be equal to b^2-4ac
		discrim = pow(b, 2) - (4 * a*c);

		//setprecision to 2
		cout << fixed << showpoint << setprecision(2);

		//testing discrim for a value and solving for solutions
		if (discrim > 0) {

			sol1 = (-b + sqrt(discrim)) / (2 * a);
			sol2 = (-b - sqrt(discrim)) / (2 * a);

			cout << "This polynomial has 2 real solutions. They are x = " << sol1 << " and x = " << sol2 << endl << endl;
		}
		else if (discrim == 0) {

			sol1 = (-b) / (2 * a);
			cout << "This polynomial has one unique solution. The solution is x = " << sol1 << endl << endl;
		}
		else {
			cout << "This polynomial has NO real solutions." << endl << endl;
		}
	}
	return 0;
}