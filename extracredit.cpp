//John Manacup 11/22/18
//A program that generates headlines using random number generator *EXTRA CREDIT*

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

//function prototypes
void header(ofstream&);
int loadArray(string[], ifstream& infile);
void printHeadline(string[], int, ofstream&);

const int MAX = 50; // max size of the array

int main() {

	srand(unsigned int(time(0))); //seeds the RNG accordingly to the system's time

	//variables to store the size of the array
	int count1, count2, count3;

	//3 arrays used to store different parts of the headline
	string headlines1[MAX];
	string headlines2[MAX];
	string headlines3[MAX];

	//files that will be needed in the program
	ifstream infile1, infile2, infile3;
	ofstream outfile;

	//files opened
	infile1.open("headlines1.txt");
	infile2.open("headlines2.txt");
	infile3.open("headlines3.txt");
	outfile.open("headlineoutput.txt");

	header(outfile); //output the header and message of the program

	//load strings in the array from the input files
	count1 = loadArray(headlines1, infile1);
	count2 = loadArray(headlines2, infile2);
	count3 = loadArray(headlines3, infile3);

	outfile << "=====================INTERESTING HEADLINES==========================" << endl << endl;
	for (int i = 1; i <= 10; i++) { //do the looping process 10 times
		outfile << setw(2) << i << ". ";
		printHeadline(headlines1, count1, outfile);
		outfile << " ";
		printHeadline(headlines2, count2, outfile);
		outfile << endl << setw(4) << ' ';
		printHeadline(headlines3, count3, outfile);
		outfile << endl << endl;
	}
	return 0;
}
/*  Precondition: function has been called by the main
   Postcondition: outputs the header and message of the program
*/
void header(ofstream& outfile) {

	outfile << "o==================================================================o" << endl;
	outfile << "|                       THE ARBITRARY DAILY                        |" << endl;
	outfile << "|              Providing nothing but true random news              |" << endl;
	outfile << "o==================================================================o" << endl;

	outfile << endl; // spacing

	outfile << "A message to the reporters: " << endl << endl;
	outfile << "Good day!" << endl;
	outfile << "First and foremost, I want to thank all of you" << endl;
	outfile << "for choosing The Arbitrary Daily. As my token" << endl;
	outfile << "of appreciation, I have prepared some" << endl;
	outfile << "\"interesting\" ideas for all of you to" << endl;
	outfile << "create stories about. I hope you will do your" << endl;
	outfile << "very best in the process and will forever" << endl;
	outfile << "stay in the company....Please.." << endl << endl;
	outfile << "Goodluck and Have Fun." << endl << setw(68) << "-JVM" << endl << endl;
}
/*  Precondition: a string array has been filledand an ifstream file has been
				  established
   Postcondition: loads strings in the arrays and return the count of values accordingly
				  to the input file
*/
int loadArray(string arr[], ifstream& infile) {
	int count = 0;
	string phrase;
	while (count < MAX && getline(infile, phrase)) {
		arr[count] = phrase;
		count++;
	}
	return count;
}
/*  Precondition: a string array has been filled, an ifstream file has been
				  established and, a count has been created;
   Postcondition: it outputs the headlines accordingly
*/
void printHeadline(string arr[], int count, ofstream& outfile) {

	int num1;
	num1 = rand() % count;

	outfile << arr[num1];

}