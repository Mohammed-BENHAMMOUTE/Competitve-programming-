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
    ll n; cin >> n;
    int m;cin >> m;
    vector<pair<ll, ll>> s;
    for(int i = 0; i<m; i++) 
    {
        ll a,b; cin >> a >> b;
        s.pb(mp(b,a));
    };
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    int sum = 0;
    for(auto x :s) 
    {
        sum += min(n, x.second)*x.first;
        n-=min(n, x.second);
    };
    cout << sum << endl;
};

int main()
{
    fastio();
    solve();

    return 0;
}