#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

ll count_triplets(ll n, ll x) {
    ll result = 0;
    
    for (ll a = 1; a <= min(n, x - 2); a++) {
        ll max_bc = min(n / a, x - a);
        
        for (ll b = 1; b < max_bc; b++) {
            ll max_c = min(max_bc - b, (n - a * b) / (a + b));
            result += max(0LL, max_c);
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        ll n, x;
        cin >> n >> x;
        cout << count_triplets(n, x) << '\n';
    }
    
    return 0;
}