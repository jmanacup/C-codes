// Paul Roessler
// 11/26/18
// Program using 1D arrays
#include <iostream>
#include <iomanip>
#include <fstream>
const int max = 50;
using namespace std;

void printheader();
int arrayputter(int[], ifstream&);
double aravg(int[], int, int);
void SortArray(int[], int);

int main() {
	double avgtot, avgfirst, avglast;
	int a[max], i;
	ifstream infile;
	infile.open("museumattend.txt");
	if (!infile) {
		cout << "Cannot open input file(s)." << endl;
		return 1;
	}
	i = arrayputter(a, infile);

	/*avgtot = aravg(a, i, 0);
	avgfirst = aravg(a, 3, 0);
	avglast = aravg(a, i, i - 4);
	SortArray(a, i);
	*/
	return 0;
}

int arrayputter(int a[], ifstream& infile) {
	int i = 0;
		while (i < max && infile >> a[i]) {
		
		cout << i << " " << a[i] << endl;
		i++;
		}
		return i;
	}			

double aravg(int a[], int i, int j) {
	int sum;
	double avg;
	sum = 0;
	for (j = 0; j < i; j++)
		sum = sum + a[j];
	avg = double(sum) / i;
	return avg;
}

void SortArray(int a[], int count) {
	int i, j, min;
	int temp;

	for (i = 0; i < count - 1; i++) {
		min = i;
		for (j = i + 1; j < count; j++) {
			if (a[j] < a[min])
				min = j;
		}
		if (min != i) {
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
	cout << "Min: " << a[0] << " Max: " << a[count - 1] << endl;
}