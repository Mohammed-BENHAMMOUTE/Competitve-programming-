#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<ll> cities(n);
    set<ll> towers;
    
    for(int i = 0; i < n; i++) {
        cin >> cities[i];
    }
    for(int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        towers.insert(x);
    }
    
    ll radius = 0;
    for(const ll& city : cities) {
        auto it = towers.lower_bound(city);
        ll rad = LLONG_MAX;
        
        if(it != towers.end()) {
            rad = min(rad, abs(city - *it));
        }        
        if(it != towers.begin()) {
            --it;
            rad = min(rad, abs(city - *it));
        }
        
        radius = max(radius, rad);
    }
    
    cout << radius << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}