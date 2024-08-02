#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
 
void solve() {
    int n;
    ll m;
    cin >> n >> m;
    vi a(n), c(n);
    for(int &x : a) cin >> x;
    for(int &x : c) cin >> x;
 
    map<int, ll> ch;
    for(int i = 0; i < n; i++) {
        ch[a[i]] += c[i];
    }
 
    ll ans = 0;
    for(auto [x, c_x] : ch) {
        ans = max(ans, min(m / x, c_x) * x);
        if(ch.count(x + 1)) {
            ll c_x1 = ch[x + 1];
            ll k1 = min(m / x, c_x);
            ll pred = x * k1;
            c_x -= k1;
            ll coins = m - pred;
            if(coins >= x + 1) {
                ll k2 = min(coins / (x + 1), c_x1);
                pred += k2 * (x + 1);
                c_x1 -= k2;
                coins = m - pred;
            }
            ans = max(ans, min(m / (x + 1), c_x1));
            pred += min({coins, c_x1, k1});
            ans = max(pred, ans);
        }
    }
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}