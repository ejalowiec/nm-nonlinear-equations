// https://github.com/ejalowiec/nm-nonlinear-equations
#include <iostream>
#include <cmath>

using namespace std;

// define your function and its derivative as a fixed value at the bottom of the file
double nonlinearFunction(double);
double derivativeOfFunction(double);

int main() {

	cout << "Function: x^3 - 1" << endl;
	cout << "Derivative: 3x^2" << endl;




}

double nonlinearFunction(double x) {
	return pow(x, 3) - 1;
}

double derivativeOfFunction(double x) {
	return pow(x, 2);
}