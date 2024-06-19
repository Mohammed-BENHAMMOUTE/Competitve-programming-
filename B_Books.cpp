#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define tc     \
    ll tc;     \
    cin >> tc; \
    while (tc--)
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve()
{
    int n; cin >> n;
    ll t; cin >> t;
    vector<ll> v(n+1, 0);
    for(int i = 1; i <= n; i++) 
    {
        int x; cin >> x;
        v[i] = v[i-1] + x;
    }
    
    ll ans = 0;
    for(int i = 0; i < n; i++){
        auto it = upper_bound(v.begin(), v.end(), v[i] + t);
        ll d = distance(v.begin() + i, it) - 1; 
        ans = max(ans, d);
    }
    cout << ans << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
};
