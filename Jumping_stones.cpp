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
    ll n, k; cin >> n >> k;
    vector<ll> dp(n+1,0);
    dp[0] =0;
    dp[1] =1;
    for(int i = 2; i <= n;i++) {
        for(int j =1; j <=k && i>=j; j++){
            dp[i]= (dp[i]+dp[i-j])%MOD;
        };
    };

    cout << dp[n] << endl;
}

int main()
{
    fastio();
    solve();

    return 0;
}