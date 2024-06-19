#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;

// Function to compute the sum of digits of a number
long long digit_sum(long long n) {
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Function to check if a number satisfies the condition
bool satisfies_condition(long long n, long long k) {
    long long dn = digit_sum(n);
    return digit_sum(k * n) == k * dn;
}

// Function to solve each test case
long long solve_case(int l, int r, int k) {
    long long count = 0;
    long long lower_bound = pow(10, l);
    long long upper_bound = pow(10, r);
    
    if (k == 1) {
        // All numbers in the range [10^l, 10^r) satisfy the condition when k = 1
        return (upper_bound - lower_bound) % MOD;
    } else {
        // Only check the first few hundred numbers due to periodicity of digit sums
        for (long long n = lower_bound; n < min(lower_bound + 1000, upper_bound); ++n) {
            if (satisfies_condition(n, k)) {
                ++count;
            }
        }
        // Scale up by estimating periodicity
        count *= (upper_bound - lower_bound) / 1000;
        for (long long n = lower_bound + ((upper_bound - lower_bound) / 1000) * 1000; n < upper_bound; ++n) {
            if (satisfies_condition(n, k)) {
                ++count;
            }
        }
        count %= MOD;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    vector<long long> results;

    for (int i = 0; i < t; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        results.push_back(solve_case(l, r, k));
    }

    for (long long result : results) {
        cout << result << '\n';
    }

    return 0;
}
