#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

long long maxGrossValue(const vector<int>& arr) {
    int n = arr.size();
    vector<long long> P(n + 2, 0);
    P[1] = 0;
    for (int i = 1; i <= n; i++) {
        P[i + 1] = P[i] + arr[i - 1];
    }
    vector<long long> A(n + 2, numeric_limits<long long>::min());
    A[1] = P[1];
    for (int i2 = 2; i2 <= n + 1; i2++) {
        A[i2] = max(A[i2 - 1], P[i2 - 1]);
    }
    vector<long long> B(n + 2, numeric_limits<long long>::min());
    B[n + 1] = numeric_limits<long long>::min(); 
    for (int i2 = n; i2 >= 1; i2--) {
        B[i2] = max(P[i2 + 1], B[i2 + 1]);
    }
    
    long long best = numeric_limits<long long>::min();
    for (int i2 = 2; i2 <= n; i2++) {
        long long candidate = A[i2] - P[i2] + B[i2];
        best = max(best, candidate);
    }
    return 2LL * best - P[n + 1];
}


int main() {
    vector<int> arr = {-5, 3, 9,4};
    cout << maxGrossValue(arr) << endl;
    return 0;
}