#include <iostream>
#include <cmath>

using namespace std;

const double EPSILON = 0.01;

double func(double x) {
	// Define your function here. For example:
	return x*x*x - x*x + 2;
}

void bisection(double a, double b) {
	if (func(a) * func(b) >= 0) {
		cout << "You have not assumed right a and b\n";
		return;
	}

	double c = a;
	while ((b-a) / 2 > EPSILON) {
		c = (a + b) / 2;

		if (func(c) == 0.0)
			break;

		if (func(a) * func(c) < 0)
			b = c;
		else
			a = c;
	}
	cout << "The value of root is : " << c;
}

int main() {
	double a = -200, b = 300;
	bisection(a, b);
	return 0;
}
