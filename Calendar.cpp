//John Manacup 11/1/18
//A program that outputs a full calendar given a year in a file (.txt)

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//function prototype
bool isLeap(int);
int dayOfWeek(int);
int printHeader(int, int, ofstream&);
void printDays(int, int&, ofstream&);

int main() {

	ofstream outFile; //declared an output file

	outFile.open("calendar.txt"); // opened the output file

	int year, month, daysInMonth, dow; //variables used

									   //looping structure that force the users to input correct year
	do {
		cout << "Please enter a year greater than or equal to 1582: ";
		cin >> year;
		if (year < 1582)
			cout << "Year is invalid. Please try again." << endl;
	} while (year < 1582);

	dow = dayOfWeek(year); //set dow to the day of week of Jan 1st

						   //looping structure that will print the header and the corresponding days
	for (month = 1; month <= 12; month++) {
		daysInMonth = printHeader(month, year, outFile);
		printDays(daysInMonth, dow, outFile);
	}

	return 0;
}

/*Precondition : The user has inputted the correct year and it takes it as an argument
Postcondition: It returns a boolean that checks whether the year is a leap year or not
*/
bool isLeap(int year) {

	bool isLeap = false;
	//checks to see if the year is a leap year or not based on the conditions given
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		isLeap = true;

	return isLeap;
}
/*Precondition : The user has inputted the correct year and it takes it as an argument
Postcondition: It returns the day of January of its first week to established correct calendar system
0 representing Sunday and so on.
*/
int dayOfWeek(int year) {

	int janFirst; //variable for storage
	year--;

	/* algorithm that computes the specific day of week of January
	0 - sunday  ----- 6 - saturday */
	janFirst = (1 + year + (year / 4) - (year / 100) + (year / 400)) % 7;

	return janFirst;
}
/*Precondition : The user has inputted the correct year and it takes it as an argument; the outFile has also
been initialized and open and takes as a reference parameter; and takes also
the month as a paramater
Postcondition: It outputs the header of the calendar to the file and return the number of days accordingly to the
month
*/
int printHeader(int month, int year, ofstream& outFile) {

	int days;
	outFile << "=========================" << endl; // top of the header
	switch (month) { //checks to see the cases of the month and set days to theirr corresponding days
	case 1:
		outFile << '#' << setw(12) << "January" << setw(5) << year << setw(7) << '#' << endl;
		days = 31;
		break;
	case 2:
		outFile << '#' << setw(12) << "February" << setw(5) << year << setw(7) << '#' << endl;
		if (isLeap(year))
			days = 29;
		else
			days = 28;
		break;
	case 3:
		outFile << '#' << setw(12) << "March" << setw(5) << year << setw(7) << '#' << endl;
		days = 31;
		break;
	case 4:
		outFile << '#' << setw(12) << "April" << setw(5) << year << setw(7) << '#' << endl;
		days = 30;
		break;
	case 5:
		outFile << '#' << setw(12) << "May" << setw(5) << year << setw(7) << '#' << endl;
		days = 31;
		break;
	case 6:
		outFile << '#' << setw(12) << "June" << setw(5) << year << setw(7) << '#' << endl;
		days = 30;
		break;
	case 7:
		outFile << '#' << setw(12) << "July" << setw(5) << year << setw(7) << '#' << endl;
		days = 31;
		break;
	case 8:
		outFile << '#' << setw(12) << "August" << setw(5) << year << setw(7) << '#' << endl;
		days = 31;
		break;
	case 9:
		outFile << '#' << setw(12) << "September" << setw(5) << year << setw(7) << '#' << endl;
		days = 30;
		break;
	case 10:
		outFile << '#' << setw(12) << "October" << setw(5) << year << setw(7) << '#' << endl;
		days = 31;
		break;
	case 11:
		outFile << '#' << setw(12) << "November" << setw(5) << year << setw(7) << '#' << endl;
		days = 30;
		break;
	case 12:
		outFile << '#' << setw(12) << "December" << setw(5) << year << setw(7) << '#' << endl;
		days = 31;
		break;
	}
	outFile << '#' << setw(3) << 'S' << setw(3) << 'M' << setw(3) << 'T' << setw(3) << 'W' <<
		setw(3) << 'T' << setw(3) << 'F' << setw(3) << 'S' << setw(3) << '#' << endl;
	outFile << "=========================" << endl; //bottom of the header

	return days;
}
/*Precondition : The printHeader function returned the daysInMonth; the dayOfWeek function has also been called; and the
outFile has also been initialized and open
Postcondition: It outputs the days of the month accordingly and change the value of the dayOfWeek
*/
void printDays(int daysInMonth, int& dayOfWeek, ofstream& outFile) {
				   
	outFile << ' '; //space equivalent for the '#' of the header

	if (dayOfWeek > 0) //Check to see if the dayOfWeek would have a space before inputing the days
		outFile << setw(3 * dayOfWeek) << ' '; //put spaces for the first week of the month

	 //looping structure that prints the the days accordingly and changes the value of dayOfWeek

	for (int i = 1; i <= daysInMonth; i++) { //thelooping structure will print all of the days
	
		outFile << setw(3) << i; //this will output the days in the calendar
		dayOfWeek++; //increments dayOfWeek accordingly
		if (dayOfWeek % 7 == 0) {//this will establish the correct endl after the dayOfWeek modulo 7 would be 0
			if(i != daysInMonth)
				outFile << endl << ' ';
			dayOfWeek = 0; //this is to repeat the process over again in the following weeks
		}
	}

	outFile << endl; // spacing for the next month

}