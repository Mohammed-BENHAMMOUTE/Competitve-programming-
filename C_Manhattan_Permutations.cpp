#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void fastio() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    if (k == 0) {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    ll max_s = 0;
    for (int i = 0; i < n; i++) {
        max_s += abs((n - 1) - i - i);
    }

    if (k % 2 != 0 || k > max_s) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
    vector<int> p(n);
    k /= 2;
    iota(p.begin(), p.end(), 1);
    for (int i = 0; k > 0; i++) {
        if (k >= n - 1 - 2 * i) {
            swap(p[i], p[n - 1 - i]);
            k -= (n - 1 - 2 * i);
        } else {
            swap(p[i], p[i + k]);
            k = 0;
        }
    };
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}