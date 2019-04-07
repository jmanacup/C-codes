//John Manacup 10/8/2018
//for loops testing

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int i, j, length, width;
	
	cout << "Enter the height of a rectangle: ";
	cin >> length;

	cout << "Enter the width of a rectagle: ";
	cin >> width;

	for (i = length; i >= 1; i--) {
		for (j = 1; j <= i; j++)
			cout << "*";
		cout << endl;
	}
	
/*	//for fun
	for (int i = 1; i <= length; i++) {
		for (j = 1; j <= width; j++) {
			if (i == 1 || i == length)
				cout << '*';
			else if (j == 1 || j == width)
				cout << '*';
			else
				cout << " ";
		}
			cout << endl;
	}*/

	cout << endl;



	return 0;
}