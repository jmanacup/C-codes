//John Manacup 9/12/2018
//Program that calculates the volume of cicles, spheres, and cones

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

	double rad, height, areaCir, cirCumCir, volSph, surAreaSph, volCon, surAreaCon, slantCon;
	const double PI = 3.1416;
	

	//ask the radius
	cout << "Insert radius in centimeters (cm): ";
	cin >> rad;

	//computes the area and circumference of circle
	areaCir = PI * pow(rad, 2);
	cirCumCir = 2 * PI * rad;

	//setprecision to 2 decimal places
	cout << fixed << showpoint << setprecision(2);

	//output the circumference and area 
	cout << "The circumference of the circle is:             " << setw(10) << cirCumCir << " cm" <<  endl;
	cout << "The area of the circle is:                      " << setw(10) << areaCir << " cm^" << '2' << endl << endl;

	//computes the volume and surface area of sphere
	volSph = 4.0 / 3 * PI * pow(rad, 3);
	surAreaSph = 4 * PI * pow(rad, 2);

	//output for the volume and surface area of sphere
	cout << "The volume of the sphere is:                    " << setw(10) << volSph << " cm^" << '3' << endl;
	cout << "The surface area of the sphere is:              " << setw(10) << surAreaSph << " cm^" << '2' << endl << endl;

	//ask the height
	cout << "Insert height in centimeters (cm): ";
	cin >> height;

	//computes the volume, surface area, slant height of a right circular cone
	slantCon = sqrt(pow(rad, 2) + pow(height, 2));
	volCon = 1.0 / 3 * PI * pow(rad, 2) * height;
	surAreaCon = (PI * pow(rad, 2)) + (PI * rad * slantCon);

	cout << "The slant height of the right circular cone is: " << setw(10) << slantCon << " cm" << endl;
	cout << "The volume of the right circular cone is:       " << setw(10) << volCon << " cm^"  << '3' << endl;
	cout << "The surface area of the right circular cone is: " << setw(10) << surAreaCon << " cm^"  << '2' << endl;

	return 0;
}