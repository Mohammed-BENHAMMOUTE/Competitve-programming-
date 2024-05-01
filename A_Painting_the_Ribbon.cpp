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
    ll n, m , k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    int c =0 ;
    n%m == 0 ? c = n/m : c = n/m + 1;
    int res = n - c;
    if( k>= res){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
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