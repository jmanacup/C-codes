#include <iostream>
#include <string>
#include <array>
#include <iomanip>
#include <cmath>
#include <stdio.h>

using namespace std;


//new coefficient solution
static double newCoef(double numCoef, double degree) {
    double outputCoef = numCoef * degree;
    return outputCoef;

}
//new degree solution
static double newDegree(double degree){

    double outputDegree = degree - 1;
    return outputDegree;
}

int main() {
	cout << fixed << showpoint << setprecision(2);

    //intro
    cout << "Derivative Calculator 1.0" << endl;

    //variables used
    string variable;
    string result;
	int count;

    //variable identification
    cout << "Please insert the letter of the variable that you would be using for the expression: ";
    cin >> variable;

    //term count identification
    cout << "How many terms are there in the said expression?: ";
    cin >> count;

	
    //arrays for storage of numbers
    double* arrayNumCoef = new double[count];
    double* arrayDegree = new double[count];
    double* arrayAfterNumCoef = new double[count];
    double* arrayAfterDegree = new double[count];

    //loop for inputs
    for(int i = 0; i < count; i++){
            cout << "What is the numerical coefficient of the [" << i+1 << "] term?: ";
            cin >> arrayNumCoef[i];

            cout << "What is the degree of the ["<< i+1 <<"] term?: ";
            cin >> arrayDegree[i];

        }

    //insertion for new arrays
    for(int j = 0; j < count; j++){
        arrayAfterNumCoef[j] = newCoef(arrayNumCoef[j], arrayDegree[j]);
        arrayAfterDegree[j] = newDegree(arrayDegree[j]);
    }

    for(int l = 0; l < count; l++){
        if(arrayAfterDegree[l] == -1){
        }
        else if(arrayAfterDegree[l] == 0 && arrayAfterNumCoef[l] > 0){
            result += "+" + to_string(arrayAfterNumCoef[l]);
        }
        else if(arrayAfterDegree[l] == 1 && arrayAfterNumCoef[l] > 0){
            result += "+" + to_string(arrayAfterNumCoef[l]) + variable;
        }
        else if(arrayAfterNumCoef[l] > 0){
            result += "+" + to_string(arrayAfterNumCoef[l]) + variable + "^" + to_string(arrayAfterDegree[l]);
        }
        else{
            result +=  to_string(arrayAfterNumCoef[l]) + variable + "^" + to_string(arrayAfterDegree[l]);
        }
    }

	
    cout <<  result;
    return 0;
}


