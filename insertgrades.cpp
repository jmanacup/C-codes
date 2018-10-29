//John Manacup 10/11/2018
//A program that collects grades using loops

#include <iostream>

using namespace std;

int main(){

	//variables used
	int grade,temp,low,count, total;
	char letterGrade;
	double avg;

	grade = count = total = 0;  //to set all ints to 0
	low = INT_MAX; // temporary value for evaluating temp

	while (grade >= 0) {

		//asks the user for grade
		cout << "Insert a grade (Insert -1 to stop): ";
		cin >> grade;

		if (grade == -1 && count == 0) {
			cout << "There is no grade entered. Try again." << endl;
			grade = 0;
		}
		else if (grade != -1) {
			temp = grade; //used to compare it to low

			if (temp <= low) // put lower number to low
				low = temp;

			total += grade;
			count++;
		}
	}

	cout << endl;

	if (count != 1) {
		count--; //to remove the one grade count if there are 2 or more grades
		total -= low;
	}

	avg = double(total) / count; // takes the average
	

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

	//outputs the necessary data
	cout << "The average grade of the inputted grade/s is: " << avg << endl;
	cout << "The equivalent grade of the average is: " << letterGrade << endl;

	return 0;

}