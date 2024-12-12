#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<int> dp(k + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= h[i]; j--) {
            dp[j] = max(dp[j], dp[j - h[i]] + p[i]);
        }
    }
    cout << dp[k] << endl;
    return 0;
}