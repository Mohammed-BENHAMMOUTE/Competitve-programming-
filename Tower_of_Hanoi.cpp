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
    vector<pair<ll,ll>> a(n);
    for(int i = 0; i<n; i++)
    {
        ll x,y; cin >> x >> y;
        a[i] = {x,y};
    }

    sort(a.begin(), a.end(),greater<pair<ll,ll>>());
    vector<ll> dp(n, 0);
    for(int i = 0; i < n; i++) {
        dp[i] = a[i].second;
        for(int j = 0; j < i; j++) 
        {
            if(a[j].first > a[i].first && a[j].second > a[i].second && dp[i] < dp[j] + a[i].second){
                dp[i] = dp[j] + a[i].second;
            }
        }
    };

    cout << *max_element(dp.begin(), dp.end()) << endl;
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