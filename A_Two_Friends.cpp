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
    vector<int> v;
    for(int i = 0; i< n ; i++) {
        int x; cin >> x;
        v.pb(x);
    };
    bool f = false;
    for(int i = 0; i < n; i++) {
        if(i+1 == v[v[i] - 1]){
            cout << 2 << endl;
            return;
        }
    }
    cout << 3 << endl;
    return;
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