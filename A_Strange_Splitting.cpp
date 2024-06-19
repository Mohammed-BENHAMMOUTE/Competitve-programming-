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
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (a[0] == a[n - 1]) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    string result(n, 'R');
    int med = n/2;
    if(n%2 == 0) {
        med--;
    };
    result[med] = 'B';
    
    cout << result << endl;
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
