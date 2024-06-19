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
    vector<ll> a(n+1, 0);
    ll ans = 0;
    map<ll,ll> mp;
    mp[0]++;
    for(int i=1; i<=n; i++) 
    {
        ll x;cin >>x;
        a[i] = (a[i-1]+ x)%n;
        if(a[i] < 0) a[i]+=n;
        ans+=mp[a[i]];
        mp[a[i]]++;
    };
    cout <<ans <<endl;
};
int main()
{
    fastio();
    solve();
    return 0;
}