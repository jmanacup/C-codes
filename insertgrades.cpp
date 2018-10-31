//John Manacup 10/11/2018
//A program that collects grades using loops

#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	//variables used
	int grade,low,count,total;
	char letterGrade;
	double avg;

	cout << fixed << showpoint << setprecision(2);

	grade = count = total = 0;  //to set all ints to 0
	low = INT_MAX; // temporary value for evaluating temp

	cout << "Insert a grade (Enter Q to stop): "; //asks the user for grade
	cin >> grade;

	while (cin) {
		if (grade >= 0 && grade <= 100) {
			total += grade;
			count++;

			if (grade <= low) // put lower number to low
				low = grade;

			cout << "Insert a grade (Enter Q to stop): "; //asks the user for grade
			cin >> grade;
		}
		else {
			cout << "The entered number is invalid."<< endl;
			cout << "Insert a grade (Enter Q to stop): ";
			cin >> grade;
		}
	}

	if (count > 1) {
		count--; //to remove the one grade count if there are 2 or more grades
		total -= low;
		avg = double(total) / count; // takes the average
		cout << "The average grade of the inputted grade/s is: " << avg << endl;

	}
	else if (count == 1) {
		avg = grade;
		cout << "The average grade of the inputted grade/s is: " << avg << endl;
	}
	else {
		cout << "No grades to average" << endl;
	}
	
	
	if (count >= 1) {
		//determine the letter grade based on average
		if (avg >= 89.5)
			letterGrade = 'A';
		else if (avg >= 79.5)
			letterGrade = 'B';
		else if (avg >= 69.5)
			letterGrade = 'C';
		else if (avg >= 59.5)
			letterGrade = 'D';
		else
			letterGrade = 'F';

		//outputs the necessary letter grade data
		cout << "The equivalent grade of the average is: " << letterGrade << endl;
	}

	return 0;
}