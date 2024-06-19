#include <iostream>
#include <vector>
using namespace std;

int findOptimalX(int n) {
    int maxSum = 0;
    int optimalX = 2;

    for (int x = 2; x <= n; ++x) {
        int k = n / x;
        int sumMultiples = x * (k * (k + 1)) / 2;
        if (sumMultiples > maxSum) {
            maxSum = sumMultiples;
            optimalX = x;
        }
    }

    return optimalX;
}

int main() {
    int t;
    cin >> t;
    vector<int> results(t);

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        results[i] = findOptimalX(n);
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
