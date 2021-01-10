// https://github.com/ejalowiec/nm-nonlinear-equations
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// define your function and its derivative as a fixed value at the bottom of the file
double nonlinearFunction(double);
double derivativeOfFunction(double);
double newtonMethod(double, double, double);

int main() {
	// set the interval
	double a = 0.01, b = 2;
	double errorValue = 1e-7;

	cout << "Function: 1/3x^3 - 1" << endl;
	cout << "Derivative: x^2" << endl;
	cout << "Interval: a=0.01, b=2" << endl;
	cout << "f(" << a << ")=" << nonlinearFunction(a) << setw(8) << "f(" << b << ")=" << nonlinearFunction(b) << endl << endl;
	cout << "\nResult: " << newtonMethod(a, b, errorValue);


	cout << endl;
	return 0;
}

double nonlinearFunction(double x) {
	return (pow(x, 3)) / 3 - 1;
}

double derivativeOfFunction(double x) {
	return pow(x, 2);
}

double newtonMethod(double a, double b, double error) {
	if (nonlinearFunction(a) * nonlinearFunction(b) < 0 and a < b) {
		unsigned int counter = 0;
		while (abs(nonlinearFunction(a)) > error) {
			a -= nonlinearFunction(a) / derivativeOfFunction(a);
			cout << "Iteration " << counter << ": " << setprecision(9) << a << endl;
			counter++;
		}
		return a;
	}
	else
		cerr << "Interval incorrect!" << endl;
	return -1;
}
