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
    int n; cin >> n; ll x; cin >> x;
    vector<ll> v(n+1, 0);
    map<ll,ll> mp;
    mp[0]=1;
    ll ans = 0;
    for(int i = 1; i <= n; i++) 
    {
        ll y; cin >> y;
        v[i] = v[i-1]+y;
        ans+=mp[v[i]-x];
        mp[v[i]]++;
    };
    cout << ans <<endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}