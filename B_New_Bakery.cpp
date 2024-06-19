#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

ll maxProfit(ll n, ll a, ll b) {
    // Calculate profit for k = 0
    ll profit_k0 = n * a;

    // Calculate profit for k = 1
    ll profit_k1 = b + (n - 1) * a;

    // Calculate profit for k = min(n, b)
    ll k_max = min(n, b);
    ll profit_k_max = k_max * (b - (k_max - 1) / 2.0) + (n - k_max) * a;

    // Calculate the profit for the vertex of the parabola
    ll k_vertex = (2 * b - 2 * a + 1) / 2;
    if (k_vertex > 0 && k_vertex <= k_max) {
        ll profit_k_vertex = k_vertex * (b - (k_vertex - 1) / 2.0) + (n - k_vertex) * a;
        return max({profit_k0, profit_k1, profit_k_max, profit_k_vertex});
    } else {
        return max({profit_k0, profit_k1, profit_k_max});
    }
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        ll n, a, b;
        cin >> n >> a >> b;
        cout << maxProfit(n, a, b) << endl;
    }
    return 0;
}
