//John Manacup 9/11/2018
//File handling practice

#include <iostream>
#include <fstream>

using namespace std;

int main() {


	ofstream outputFile;
	outputFile.open("C:\\Users\\johnm\\source\\repos\\workinghome\\workinghome\\sampletext.txt");

	outputFile << "John Manacup \nThis is a test \nwow";

	outputFile.close();






	return 0;
}