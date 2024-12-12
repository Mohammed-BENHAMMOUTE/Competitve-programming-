#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

// Function to compute modular inverse of a under modulo m
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

int main() {
    int n; cin >> n;
    long tot = n * (n + 1) / 2;
    if (tot % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    tot /= 2;
    vector<vector<long>> dp(n + 1, vector<long>(tot + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= tot; k++) {
            dp[i][k] = dp[i - 1][k];
            if (k - i >= 0) {
                (dp[i][k] += dp[i - 1][k - i]) %= MOD;
            }
        }
    }
    cout << (dp[n][tot] * modInverse(2, MOD) +MOD) % MOD << endl;
}