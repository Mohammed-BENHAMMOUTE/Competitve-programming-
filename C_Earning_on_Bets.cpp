#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

void solve() {
    ll n;
    cin >> n;
    
    vector <ll> k(n);
    for (ll i = 0; i < n; i++) {
        cin >> k[i];
    }
    
    ll z = 1;
    for (ll i = 0; i < n; i++) {
        z = lcm(z, k[i]);
    }
    
    ll suma = 0;
    for (ll i = 0; i < n; i++) {
        suma += z / k[i];
    }
    
    if (suma < z) {
        for (ll i = 0; i < n; i++) {
            cout << z / k[i] << " ";
        }
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}