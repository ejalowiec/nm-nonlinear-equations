// https://github.com/ejalowiec/nm-nonlinear-equations
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// define your function and its derivative as a fixed value at the bottom of the file
double nonlinearFunction(double);
double derivativeOfFunction(double);
double newtonMethod_ex2(double, double);

int main() {
	// set the interval
	double a = 0.01, b = 2;
	// double precision = 1e-4;

	cout << "Function: 1/3x^3 - 1" << endl;
	cout << "Derivative: x^2" << endl;
	cout << "Interval: a = 0.01, b = 2" << endl;
	cout << "f(" << a << ") = " << nonlinearFunction(a) << setw(8) << "f(" << b << ") = " << nonlinearFunction(b) << endl << endl;
	cout << "Newton's method:\n\n";
	cout << "\nF(x) = 0 <=> x = " << newtonMethod_ex2(a, b) << endl;

	cout << endl;
	return 0;
}

double nonlinearFunction(double x) {
	return (pow(x, 3)) / 3 - 1;
}

double derivativeOfFunction(double x) {
	return pow(x, 2);
}

double newtonMethod_ex2(double a, double b) {
	if (nonlinearFunction(a) * nonlinearFunction(b) < 0 and a < b) {
		unsigned int counter = 0;
		double precision = NULL;
		cout << "Specify the precision: "; cin >> precision; cout << endl;
		while (abs(nonlinearFunction(a)) > precision) {
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
