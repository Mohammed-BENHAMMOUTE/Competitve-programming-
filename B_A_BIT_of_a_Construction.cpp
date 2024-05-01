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
    ll n;cin >>n;
    ll k; cin >> k;
    vector<ll> A;

    if(n==1) {
        cout << k << endl;
        return;
    }else {
        ll last = 1;
        while(last*2<=k) {
            last = last*2;
        };
        A.pb(last-1);
        A.pb(k-last+1);
        while(A.size() <= n) {
            A.pb(0);
        }
        for(int i =0; i<n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
        return;
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