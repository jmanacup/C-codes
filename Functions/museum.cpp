//John Manacup 11/15/18
//A program that produces a report about overall attendance in an exhibit

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//function prototypes
void printHeader(ofstream&);
void printAttendance(int[], ofstream&);
int loadArray(ifstream&, int[]);
double averageValues(int[],int, int);
void maxAndMin(int[], ofstream&);

const int SIZE = 15; // so that the index would start from 1 up until 14

int main() {

	ifstream infile;
	ofstream outfile;
	int storeValues[SIZE], totalAttendance;
	double average14, averageFirst3, averageLast3;

	//setting precision into 1 decimal places
	outfile << fixed << showpoint << setprecision(1);

	// opens the needed files
	infile.open("museumattend.txt"); 
	outfile.open("museumattendoutput.txt");

	//it checks to see if the file has been opened successfully
	if (!infile) {
		outfile << "Program cannot open the specified file." << endl;
		return 1;
	}

	printHeader(outfile); // outputs the header name, date, and title

	// loads values in the file and store in in an array and returns the total
	totalAttendance = loadArray(infile, storeValues);
	outfile << setw(70) << "The total attendance of the exhibit was:     " << setw(13) << totalAttendance <<endl;

	//average for all the 14 days
	average14 = averageValues(storeValues, 1, SIZE);
	outfile << setw(70) << "The average attendance for all 14 days was:  " << setw(13) << average14 << endl;

	//outputs the max and min day 
	maxAndMin(storeValues, outfile);

	//average for the first three days
	averageFirst3 = averageValues(storeValues, 1, 4);
	outfile << setw(73) << "The average attendance for the first 3 days was:" << setw(10) << averageFirst3 << endl;

	//average for the last three days
	averageLast3 = averageValues(storeValues, SIZE - 3, SIZE);
	outfile << setw(73) << "The average attendance for the last 3 days was: " << setw(10) << averageLast3 << endl;

	//prints the attendance with their corresponding day
	printAttendance(storeValues, outfile);

	return 0;
}

/*
	Precondition: It assumes that the file has been loaded successfully
   Postcondition: It displays the name, date, and the title of the program
*/
void printHeader(ofstream& outfile) {

	outfile << setw(74) << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
	outfile << setw(74) <<"Created by: John Vernon L. Manacup" << endl;
	outfile << setw(61) << "11/15/18" << endl << endl;
	outfile << setw(74) << "TEXAS TECH MUSEUM EXHIBIT REPORT" << endl;
	outfile << setw(74) << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl << endl << endl;
}
/*
	Precondition: It assumes that the file has been loaded successfully
   Postcondition: It stores the values from the input file and put it in an array
				  and returns the total of the values
*/
int loadArray(ifstream& infile, int storeValues[]) {
	int total = 0;
	for (int i = 1; i < SIZE; i++) { //loop that stores value in the array and takes the sum of all values
		infile >> storeValues[i]; //stores values in the array starting in index 1
		total += storeValues[i]; //adds the values in the array
	}
	return total;
}
/*
	Precondition: It assumes a definite size of an array has been established; 
				  an array has also been established
   Postcondition: It returns an average of the values of an array given the first and last day
*/
double averageValues(int storeValues[], int start, int end) {

	double average, total = 0;

	// looping structure that takes the value in the specified range to sum them all up
	for (int i = start; i < end; i++) { 
		total += storeValues[i];
	}
	
	average = total / (end-start);

	return average;

}
/*
	Precondition: an array has been established
   Postcondition: It returns the maximum and minimum attendance and the day it occured respectively
*/
void maxAndMin(int storeValues[], ofstream& outfile) {

	int max = INT_MIN, min = INT_MAX, minDay, maxDay; // setting variables to their opposite for comparison

	for (int i = 1; i < SIZE; i++) { // searching for min and max and storing them respectively
		if (max <= storeValues[i]) {
			max = storeValues[i];
			maxDay = i;
		}
		if (min >= storeValues[i]) {
			min = storeValues[i];
			minDay = i;
		}
	}
	//outputs the max and min attendance with their respective day
	outfile << setw(59)<< "The maximum daily attendance was: " << setw(24) << max << endl
		 << setw(48) << "The day it occured was " << setw(35) << maxDay << endl;
	outfile << setw(59)<< "The minimum daily attendance was: " << setw(24) << min << endl
		 << setw(48) << "The day it occured was " << setw(35) << minDay << endl;
}
/*
	Precondition: an array has been established
   Postcondition: It returns the number of attendance together with its corresponding days
*/
void printAttendance(int storeValues[] , ofstream& outfile) {
	for (int i = 1; i < SIZE; i++) { //outputs the no. of attendance with day
		outfile << setw(57) << "The number of attendance in day " << setw(2) << i << " was: " << setw(18) << storeValues[i] << endl;
	}

	outfile << endl;
}