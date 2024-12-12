#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

void solve() {
    int Q, K;
    cin >> Q >> K;
    vector<int> dp(K + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < Q; ++i) {
        char op;
        int x;
        cin >> op >> x;

        if (op == '+') {
            for (int j = K; j >= x; --j) {
                dp[j] = (dp[j] + dp[j - x]) % MOD;
            }
        } else {
            for (int j = x; j <= K; ++j) {
                dp[j] = (dp[j] - dp[j - x] + MOD) % MOD;
            }
        }
        cout << dp[K] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}