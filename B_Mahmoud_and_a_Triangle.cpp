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
    int n;cin >> n;
    vector<ll> v;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        v.pb(x);
    };
    sort(v.begin(), v.end());
    for(int i = 0 ; i< n-2 ; i++) {
        if(v[i] +v[i+1] > v[i+2]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}

int main()
{
    fastio();
    solve();

    return 0;
}