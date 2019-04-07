//John Manacup 11/14/18
//This program works with 1D arrays. 
//An array is ALWAYS passed as a REFERENCE parameter in C++, but
//you do NOT put & in the prototype or the function header

#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX = 50; // global constant

using namespace std;

int LoadArray(int[], ifstream&); // function prototype
void PrintArray(int[], int);
int SumValues(int[], int);
void sortArray(int[], int);

int main() {
	//arrays
	int list1[MAX];
	int list2[MAX];
	int count1, count2;

	ifstream infile1, infile2; //input file stream

	//opening the file
	infile1.open("array1.txt");
	infile2.open("array2.txt");

	//check to see the if the file opens correctly
	if (!infile1 || !infile2) {
		cout << "Cannot open input file/s" << endl;
		return 1;
	}

	//An array in C++ is ALWAYS passed as a REFERENCE parameter
	count1 = LoadArray(list1, infile1);
	count2 = LoadArray(list2, infile2);

	//output each array's values
	cout << "Values from list 1 in original order: " << endl;
	PrintArray(list1, count1);
	cout << "Values from list1 in ascending order: " << endl;
	sortArray(list1, count1);
	PrintArray(list1, count1);
	cout << "Sum of values: " << SumValues(list1, count1) << endl;
	
	cout << "Values from list 2 in original order: " << endl;
	PrintArray(list2, count2);
	cout << "Values from list 2 in ascending order: " << endl;
	sortArray(list2, count2);
	PrintArray(list2, count2);
	cout << "Sum of values: " << SumValues(list2, count2) << endl;

	return 0;
}
/*  Precondition: infile has been opened successfully
   Postcondition: array a is filled with count values. funcion returns count
*/
int LoadArray(int a[], ifstream& infile) {
	int count = 0;

	while (count < MAX && infile >> a[count]) {
		count++;
	}

	return count; 
}
/*  Precondition: array a is filled with count values
   Postcondition: values have been displayed
*/
void PrintArray(int a[], int count) {
	int i;
	for (i = 0; i < count; i++) {
		cout << setw(2) << i+1 << '.' << setw(4) << a[i] << endl;
	}
}
/*  Precondition: array a is filled with count values
Postcondition: sum of all values is returned
*/
int SumValues(int a[], int count) {
	int i, sum = 0;
	for (i = 0; i < count; i++)
		sum += a[i];

	return sum;
}
/*
		Precondition: array a is filled with count values
		Postcondtion: elements of the array are arranged in ascending order
		an array is always sent as a reference parameter, so the function
		will be able to change it.
*/
void sortArray(int a[], int count) {

	int i, j, min; //these hold index values, will always be int
	int temp; // data type MUST be same as array data type

	for (i = 0; i < count - 1; i++) {
		min = i; 
		//go through of list and find index of lowest value
		for (j = i + 1; j < count; j++) {
			if (a[j] < a[min])
				min = j;
		}
		//swap the lowest value wih the "top" of list
		if (min != i) {
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}//end of outside for loop
}//end of function