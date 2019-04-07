//John Manacup 11/21/2018
//A program that sort the strings in an input file (Selection sort) and search specific string
//from an input file

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//function prototypes
int loadArray(string[], ifstream&);
void printArray(string[], int, ofstream&);
void sortArr(string[], int);
int searchArr(string[], int, string);

const int MAX = 50; // max size of the array 

int main() {
	//files to be needed 
	ifstream infile1, infile2, infile3;
	ofstream outfile;
	//files to be opened
	infile1.open("word1.txt");
	infile2.open("word2.txt");
	infile3.open("searchvalues.txt");
	outfile.open("searchoutput.txt");

	//check to see if he infiles work properly
	if (infile1 || infile2 || infile3)
		outfile << "File/s cannot be properly opened. Please try again." << endl;

	string word1[MAX], word2[MAX]; //arrays to be stored strings from infile1 and infile2
	string check;
	int entries1, entries2; // valid entries of infile1 and infile2

	entries1 = loadArray(word1, infile1); //loads array word1
	entries2 = loadArray(word2, infile2); //loads array word2

	//prints word1 and word2 strings accordingly
	outfile << "Strings from word1 in original order: " << endl;
	printArray(word1, entries1, outfile);
	outfile << "Strings from word2 in original order: " << endl;
	printArray(word2, entries2, outfile);

	//sorts both of the array
	sortArr(word1, entries1);
	sortArr(word2, entries2);

	//prints sorted word1 and word2 strings accordingly
	outfile << "Stings from word1 in sorted order: " << endl;
	printArray(word1, entries1, outfile);
	outfile << "Strings from word2 in sorted order: " << endl;
	printArray(word2, entries2, outfile);

	outfile << endl; 

	while (infile3 >> check) {
		//variables used
		int position1, position2;//set position of the word in their respective variables
		
		position1 = searchArr(word1, entries1, check);
		position2 = searchArr(word2, entries2, check);
		
		outfile << "The word " << check;

		if (position1 != -1) 
			outfile << " was found in array 1 at position " << position1 + 1<< " and ";
		
		else 
			outfile << " was not found in array 1 and ";
		
		if (position2 != -1) 
			outfile << "was found in array 2 at position " << position2 + 1 << '.';
		
		else 
			outfile << "was not found in array 2. ";
		
		outfile << endl;
	}
	return 0;
}
/* Precondition: an array has been established and its max size; an ifstream file 
				 has also been declared and opened
  Postcondition: it places strings in the array from the infile and 
				 returns valid entries of the array
*/
int loadArray(string arr[], ifstream& infile) {
	int count = 0;
	while (count < MAX && infile >> arr[count])
		count++;
	return count;
}
/* Precondition: an array has been loaded with strings and entries has been made;
				 an ofstream file has also been declared and opened
  Postcondition: it prints string in the array to the outfile
*/
void printArray(string arr[], int entries, ofstream& outfile) {
	for (int i = 0; i < entries; i++)
		outfile << right << setw(2) << i + 1 << ". " << left << setw(12) << arr[i] << endl;
}
/* Precondition: an array has been loaded with strings and entries has been made;
				 
  Postcondition: it sorts the array using selection sort
*/
void sortArr(string arr[], int entries) {
	//variables used
	int low;
	string temp;

	for (int i = 0; i < entries - 1; i++) {
		low = i; // sets low value to i each time
		for (int j = i + 1; j < entries; j++) {
			if (arr[j] < arr[low]) //compares low to every preceeding iteration of strings in the array
				low = j; //sets low to j if the condition is true 
		}
		if (low != i) { //switches the string in arr[i] to the lowest one and goes to the loop again
			temp = arr[i]; 
			arr[i] = arr[low];
			arr[low] = temp;
		}

	}
}
/*
	Precondition: an array has been loaded with strings and entries has been made;
				  desired word has also been created to find in the array

   Postcondition: checks to see if the desired word is in the array and if it is, it will return the 
				  index position of the word. If not, it will return -1			
*/
int searchArr(string arr[], int entries, string find) {
	int position = -1, first = 0, last = entries-1, middle; //variables used; middle is just set to a random value
	bool found = false;

	while (!found && first <= last) { //first != middle is needed so that the loop will cancel if there is no such string found
		middle = (first + last) / 2;  //takes the middle from the first up to the entries
		if (arr[middle] == find) { //check to see if the middle is equal to the string that is needed to be found
			position = middle; //set position to middle
			found = true; //set found to true
		}
		else if (arr[middle] < find) 
			first = middle + 1; // sets the first value to the greater half of the array
		else 
			last = middle - 1; //sets the max size to the lower half of the array
	}
	return position;
}