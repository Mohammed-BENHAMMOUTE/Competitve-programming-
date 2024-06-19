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
    int n; cin>>n;
    vector<ll> a(n+1);
    vector<ll> dp1(n+1,0);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp1[i] = dp1[i-1] + a[i];
    };
    vector<ll> dp2(n+1,0);
    dp2[n] = a[n];
    for(int i = n-1; i >= 1; --i) {
        dp2[i] = dp2[i+1] + a[i];
    };
    ll mn = 100000000;
    bool done = false;
    for(int i = 1; i <= n-1; i++){
        if(dp1[i] <= dp2[i+1]){
            mn = min(mn,abs(dp1[i]-dp2[i+1]));
            done = true;
        }
    };
    if(!done){
        cout << -1 << endl;
        return;
    }
    cout << mn << endl;
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