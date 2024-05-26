#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    ll max_a = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }

    vector<ll> freq(max_a + 1, 0);
    for(int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    vector<ll> dp(max_a + 1, 0);
    dp[0] = 0;
    for(ll i = 1; i <= max_a; i++) {
        if(freq[i] != 0) {
            dp[i] = max(dp[i], 1LL);
        }
        for(ll j = 2 * i; j <= max_a; j += i) {
            if(freq[j] != 0) {
                dp[j] = max(dp[j], dp[i] + freq[j]);
            }
        }
    }

    ll answer = *max_element(dp.begin(), dp.end());
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}