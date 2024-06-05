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
};
ll prevPowerOfTwo(ll n)
{
    //if n is power of two
    if ((n & (n - 1)) == 0) return n;
    return 1 << ((int)log2(n));
}
void solve()
{
    ll l, r; cin >> l >> r;
    ll ans = prevPowerOfTwo(r);
    
    cout << log2(ans) << endl;
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}