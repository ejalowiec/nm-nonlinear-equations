// https://github.com/ejalowiec/nm-nonlinear-equations
#include <iostream>
#include <cmath>
#include<iomanip>

using namespace std;

// define your function and its derivative as a fixed value at the bottom of the file
double nonlinearFunction(double);
double derivativeOfFunction(double);

int main() {
	// set the interval
	double a = 0, b = 2;

	cout << "Function: 1/3x^3 - 1" << endl;
	cout << "Derivative: x^2" << endl;
	cout << "Interval: a=0, b=2" << endl;
	cout << "f(" << a << ")=" << nonlinearFunction(a) << setw(8) << "f(" << b << ")=" << nonlinearFunction(b) << endl;

	cout << endl;
	return 0;
}

double nonlinearFunction(double x) {
	return (pow(x, 3)) / 3 - 1;
}

double derivativeOfFunction(double x) {
	return pow(x, 2);
}