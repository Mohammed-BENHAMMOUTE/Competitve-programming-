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

ll dp[200001];
ll pref[200001];

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
};


void solve()
{
    int l, r; cin >> l >>r;
    cout << pref[r] - pref[l-1] + dp[l]<<endl;
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    dp[0] = 0;
    pref[0]= 0;
    ll cc;
    for(int i =1; i < 200001;i=i){
        cc = i*3;
        dp[i] = dp[i/3]+1;
        pref[i]= pref[i-1] + dp[i];
        i++;
        while(i < cc && i <200001){
            dp[i] = dp[i-1];
            pref[i]= pref[i-1] + dp[i];
            i++;
        }
    }
    for (ll i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}