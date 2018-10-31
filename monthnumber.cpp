//John Manacup
// 10/1/2018
//A program that would output the month and the days of the month

#include <iostream>
#include <cctype>

using namespace std;

int main() {

	//variables used
	int monthNum, year;
	bool inRange;
	char reply;

	do {
	//asks the user for month number
	cout << "Enter a month number: ";
	cin >> monthNum;

		
		//takes the parameter monthNum
		switch (monthNum) {

		case 1:
			cout << "The month is January." << endl;
			cout << "There are 31 days in January." << endl;
			break;
		case 2:
			//takes the year of the user's input
			cout << "Enter the year of the calendar: ";
			cin >> year;

			cout << "The month is February." << endl;

			//to test if the year in february is a leap year or not
			inRange = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

			//check to see if the year is within range
			if (inRange)
				cout << "There are 29 days in February." << endl;
			else
				cout << "There are 28 days in February." << endl;
			break;
		case 3:
			cout << "The month is March." << endl;
			cout << "There are 31 days in March." << endl;
			break;
		case 4:
			cout << "The month is April." << endl;
			cout << "There are 30 days in April." << endl;
			break;
		case 5:
			cout << "The month is May." << endl;
			cout << "There are 31 days in May." << endl;
			break;
		case 6:
			cout << "The month is June." << endl;
			cout << "There are 30 days in June." << endl;
			break;
		case 7:
			cout << "The month is July." << endl;
			cout << "There are 31 days in July." << endl;
			break;
		case 8:
			cout << "The month is August." << endl;
			cout << "There are 31 days in August." << endl;
			break;
		case 9:
			cout << "The month is September." << endl;
			cout << "There are 30 days in September." << endl;
			break;
		case 10:
			cout << "The month is October." << endl;
			cout << "There are 31 days in October." << endl;
			break;
		case 11:
			cout << "The month is November." << endl;
			cout << "There are 30 days in November." << endl;
			break;
		case 12:
			cout << "The month is December." << endl;
			cout << "There are 31 days in December." << endl;
			break;
		default:
			cout << "ERROR! Enter a valid month number (1-12)" << endl;

		}
		//asks if user wants to enter another month number
		cout << "Do you want to enter another month number? (y/n): ";
		cin >> reply;

		//lowercase the reply
		tolower(reply);

	} while (reply == 'y');

	return 0;
}