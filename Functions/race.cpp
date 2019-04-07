//John Manacup, Travis Cox, Matt Tacke 12/3/18
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int const MAX = 11; //number of potential bikers
int const DAYS = 6; //numer of days + 1 for the alotted total

using namespace std;

//function prototypes
void loadPrizes(string[], ifstream&);
void loadArray(int, double[][DAYS], string[], ifstream&);
void header(int, int, string[], double[][DAYS], ofstream&);
void winner(int, string[], string[], double[][DAYS], ofstream&);

int main() {
	
	//files needed
	ifstream infile;
	ofstream outfile;
	//files to be opened
	infile.open("racers.txt");
	outfile.open("racereport.txt");

	outfile << fixed << showpoint << setprecision(2);//sets the precision of the double values into 2 decimal places

	int date; // year of the said event
	int numBikers; //number of bikers attended

	infile >> date;
	infile >> numBikers;
	//check to see if the number of bikers is within the limit
	if (numBikers <= 0 || numBikers > 10) {
		outfile << "The number of bikers is invalid." << endl;
		return 1;
	}
		
	//to ignore the first line in the input file
	infile.ignore(40, '\n');

	//arrays needed for the functions
	string prizes[DAYS];
	string name[MAX];
	double arr[MAX][DAYS];

	//get the string prizes from the input file
	loadPrizes(prizes, infile); 
	
	//loads the array with the appropriate values from the input file
	loadArray(numBikers, arr, name, infile);

	//prints the name and their corresponding mileage as well as the start of the report
	header(date, numBikers, name, arr, outfile);

	//prints the daily and grand prize winners of the race
	winner(numBikers,name, prizes, arr, outfile);

	return 0;
}
/*
	Precondition - string array has been initialized; also input file has been opened
   Postcondition - it loads the string array with the corresponding prizes from the input file
*/
void loadPrizes(string prizes[], ifstream& infile) {

	int count = 0;
	while (count < DAYS && getline(infile, prizes[count])) //gets the prizes accordingly
		count++;
	
}
/*
	Precondition - a 2d array has been declared; a string array has been declared and infile has been opened
   Postcondition - it loads the both the 2d array and the string array with their corresponding data from the input file
				   as well as their individual total mileage and total mileage for the corresponding days
*/
void loadArray(int numBikers, double arr[][DAYS], string name[], ifstream& infile) {

	for (int i = 0; i < numBikers; i++) {
		infile >> name[i];
		double totalMileageBiker = 0;
		for (int j = 0; j < DAYS - 1; j++) {
			infile >> arr[i][j];
			totalMileageBiker += arr[i][j]; // gets the total mileage for the individual biker
		}
		arr[i][DAYS-1] = totalMileageBiker; // put the total mileage for each biker in the last column of the 2d array 
	}

	for (int i = 0; i < DAYS; i++) {
		double totalMileageDays = 0;
		for (int j = 0; j < numBikers; j++) {
			totalMileageDays += arr[j][i]; //gets the total of the mileage per day
		}
		arr[numBikers][i] = totalMileageDays; // put the total mileage for each day in the last row of the 2d array
	}
}
/*
	Precondition - a 2d array has been declared; a string array has been declared and an outfile has been opened
   Postcondition - it outputs the name of the biker and their corresponding mileage
*/
void header(int date, int numBikers, string name[], double arr[][DAYS], ofstream& outfile) {
	//column heading
	outfile << setw(45) << "FINAL REPORT FOR THE " << date << " RACE " << endl;
	outfile << "----------------------------------------------------------------------------------------" << endl;
	outfile << left << setw(10) << "Name" << right << setw(13) << "Day 1" << setw(13) << "Day 2" << setw(13)
		<< "Day 3" << setw(13) << "Day 4" << setw(13) << "Day 5" << setw(13) << "Total" << endl;
	outfile << left << setw(10) << "of" << right << setw(13) << "Mileage" << setw(13) << "Mileage" << setw(13)
		<< "Mileage" << setw(13) << "Mileage" << setw(13) << "Mileage" << setw(13) << "Individual" << endl;
	outfile << left << setw(10) << "Biker" << right << setw(78) << "Mileage" << endl;
	outfile << "----------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < numBikers; i++) {
		outfile << left << setw(10) << name[i];
		for (int j = 0; j < DAYS; j++) {
			outfile <<  right << setw(13) << arr[i][j]; //outputs the mileage per day as well as the individual total
		}
		outfile << endl;
	}
	outfile << "----------------------------------------------------------------------------------------" << endl;
	outfile << "TOTAL MILEAGE" << endl << left << setw(10) << "PER DAY";

	for (int i = 0; i < DAYS- 1; i++) //outputs the total mileage per day 
		outfile << right << setw(13) << arr[numBikers][i];

	outfile << endl; // spacing

	//it outputs the total of the last column which was the total mileage of the individual bikers
	outfile << endl << "The total miles biked is: " << arr[numBikers][DAYS-1] << endl;
	outfile << "----------------------------------------------------------------------------------------" << endl;
}
/*
	Precondition - a 2d array has been declared; a string array for the name and prizes has been declared and an outfile has been opened
   Postcondition - it outputs the name of the biker who won the daily mileage and grand winner of the race as well as their corresponding prizes
*/
void winner(int numBikers, string name[], string prizes[], double arr[][DAYS], ofstream& outfile) {

	outfile << endl; //spacing

	for (int i = 0; i < DAYS; i++) { //loop that outputs the daily and grand winner
		double maxNum = arr[i][0]; // sets max as the first index of the 2d array
		int index = 0; //declares index so that it would be different from the last iteration of column
		for (int j = 0; j < numBikers; j++) {
			if (arr[j][i] >= maxNum) {
				maxNum = arr[j][i];
				index = j;
			}
		}

		if (i != DAYS-1) //to output only if they are the daily winners
			outfile << "Day " << i + 1 << " winner is: ";
		else//outputs the grand prize winner
			outfile << endl << "The grand prize winner of the race is: ";

		outfile << name[index] << " garnering " << prizes[i] << endl; //outputs their respective prizes
	}
}