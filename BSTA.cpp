#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

// UVa 11935 through the desert
bool can(double x){
	// Define your function here. For example:
	// return x > 5000.0;
	// This is a placeholder. You should replace it with your actual implementation.
	return true;
}

int main() {
	// Binary search the answer then simulate 
	double lo = 0.0, hi = 10000.0;
	for (int i = 0; i < 50; i++){
		double mid = (lo + hi) / 2.0;   // this is because the number of iteration is 43
		can(mid) ? hi = mid : lo = mid; // log2(10000/1e-9) = 43.
	}
	cout << fixed << setprecision(3) << hi << "\n";
	return 0;
}