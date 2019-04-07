//John Manacup 10/22/2018
// averaging any number of grades from an input file
//input until end of file
//output will be sent to a file

#include <iostream>
#include <iomanip>
#include <fstream> //needed for adding files

using namespace std;

int main() {

	int i, grade, total;
	double avg;

	ifstream infile; //input file declaration
	ofstream outfile; //output file declaration

	infile.open("grades.txt"); // opening an actual file to the stream and input file must already exist

	if (!infile) {
		cout << "Cannot open input file. Aborted.";
		return 1;
	}

	outfile.open("graderesult.txt"); //create a file if there's none or erase a file existed 

	outfile << fixed << showpoint << setprecision(2);

	i = 0;
	total = 0;

	outfile << "Averaging these grades: " << endl;

	while (infile >> grade) { //using input shortcut to both input and input check

		outfile << setw(4) << grade << endl;
		total += grade; //keeping a running total
		i++;

	}

	if ( i > 0) {
		avg = double(total) / i;
		outfile << "The average of " << i << " grades is " << avg << endl;
	}
	else
		outfile << "Not enough data to analyze." << endl;

	return 0;
}