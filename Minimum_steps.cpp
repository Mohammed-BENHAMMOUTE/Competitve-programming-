#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int lis(const vector<ll>& a) {
    int n = a.size();
    vector<ll> dp;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        if (it != dp.end()) {
            *it = a[i];
        } else {
            dp.push_back(a[i]);
        }
    }
    return dp.size();
}

int lds(const vector<ll>& a) {
    int n = a.size();
    vector<ll> dp;
    for (int i = 0; i < n; ++i) {
        auto it = upper_bound(dp.begin(), dp.end(), a[i], greater<ll>());
        if (it != dp.end()) {
            *it = a[i];
        } else {
            dp.push_back(a[i]);
        }
    }
    return dp.size();
}

void fastio() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    int n; 
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int m1 = lis(a);
    int m2 = lds(a);
    int pr = max(m1, m2);
    cout << n - pr << endl;
}

int main() {
    fastio();
    solve();
    return 0;
}
