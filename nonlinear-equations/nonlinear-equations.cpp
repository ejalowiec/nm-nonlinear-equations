// https://github.com/ejalowiec/nm-nonlinear-equations
#include <iostream>
#include <cmath>
#include <iomanip>

// set the interval
#define A 0.01
#define B 2
#define C 1.4
#define D 1.5
// set precision
#define PRECISION 1e-4

using namespace std;

// define your function and its derivative as a fixed value at the bottom of the file
double nonlinearFunction(double);
double derivativeOfFunction(double);
double differenceQuotient(double, double);
double newtonMethod_ex1(double, double, double);
double newtonMethod_ex2(double, double);
double secantMethod_ex1(double, double, double);
double secantMethod_ex2(double, double);

int main() {
	cout << "Function: 1/3x^3 - 1" << endl;
	cout << "Derivative: x^2" << endl;
	cout << "Interval: a = " << A << ", b = " << B << endl;
	cout << "f(" << A << ") = " << nonlinearFunction(A) << setw(8) << "f(" << B << ") = " << nonlinearFunction(B) << endl << endl;
	cout << "Newton's method:\n\n";
	//cout << "\nValue of F(x): " << newtonMethod_ex1(A, B, PRECISION) << endl;
	//cout << "\nValue of F(x): " << newtonMethod_ex2(A, B) << endl;
	cout << "\nValue of F(x): " << secantMethod_ex1(A, B, PRECISION) << endl;
	//cout << "\nValue of F(x): " << secantMethod_ex2(A, B) << endl;

	cout << endl;
	return 0;
}

double nonlinearFunction(double x) {
	return (pow(x, 3)) / 3 - 1;
}

double derivativeOfFunction(double x) {
	return pow(x, 2);
}

double differenceQuotient(double a, double b) {
	return (nonlinearFunction(b) - nonlinearFunction(a)) / (b - a);
}

double newtonMethod_ex1(double a, double b, double precision) {
	if (nonlinearFunction(a) * nonlinearFunction(b) < 0 and a < b) {
		unsigned int counter = 0, iterations = NULL;
		cout << "Precision: " << precision << endl << endl;
		cout << "Specify the number of iterations: "; cin >> iterations; cout << endl;
		double temp = 0.0;
		while (counter < iterations) {
			a -= nonlinearFunction(a) / derivativeOfFunction(a);
			if (temp == a)
				break;
			temp = a;
			cout << "Iteration " << counter << ": " << setprecision(15) << a << endl;
			counter++;
		}
		return a;
	}
	else
		cerr << "Interval incorrect!" << endl;
	return -1;
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

double secantMethod_ex1(double a, double b, double precision) {
	if (nonlinearFunction(a) * nonlinearFunction(b) < 0 and a < b) {
		unsigned int counter = 0, iterations = NULL;
		cout << "Precision: " << precision << endl << endl;
		cout << "Specify the number of iterations: "; cin >> iterations; cout << endl;
		double temp = 0.0;
		while (counter < iterations) {
			a -= nonlinearFunction(a) / differenceQuotient(a, b);
			if (temp == a)
				break;
			temp = a;
			cout << "Iteration " << counter << ": " << setprecision(15) << a << endl;
			counter++;
		}
		return a;
	}
	else
		cerr << "Interval incorrect!" << endl;
	return -1;
}

double secantMethod_ex2(double a, double b) {
	if (nonlinearFunction(a) * nonlinearFunction(b) < 0 and a < b) {
		unsigned int counter = 0;
		double precision = NULL;
		cout << "Specify the precision: "; cin >> precision; cout << endl;
		while (abs(nonlinearFunction(a)) > precision) {
			a -= nonlinearFunction(a) / differenceQuotient(a, b);
			cout << "Iteration " << counter << ": " << setprecision(9) << a << endl;
			counter++;
		}
		return a;
	}
	else
		cerr << "Interval incorrect!" << endl;
	return -1;
}
