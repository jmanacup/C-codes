#include <iostream>

using namespace std;
//return an int that represents the index value
int findNum(int[], int, int);

int main() {

	int arr[6] = { 2, 5, 8, 9, 11, 14 };
	int size, find, answer;

	size = 6;
	find = 7;

	answer = findNum(arr, size, find);
	cout << "The index of the number is: " << answer << endl;
	return 0;
}

int findNum(int arr[], int size, int find) {

	bool check = false;
	int position = -1, key = 0, mid = -1;

	while (check == false && key != mid) {

		mid = (size + key) / 2;

		if (arr[mid] == find) {
			check = true;
			position = mid;
		}
		else if (arr[mid] < find) {
			key = mid + 1;
		}
		else {
			size = mid - 1;
		}
	}
	return position;
}