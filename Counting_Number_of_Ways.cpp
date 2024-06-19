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
const  int maxn = 1e5 + 5;
const  int mink = 105;
ll dp[mink][maxn];

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


void solve()
{
}

int main()
{
    fastio();
    for(int i =1; i < 101; i++)dp[i][0] = 1;
    for(int i = 1 ; i <= 101 ; i++) {//k
        for(int j =1 ; j <= 10001 ; j++) {//n
            for(int k = 1; k <= min(i,j); k++) {
                dp[i][j] = (dp[i][j] + dp[i][j-k])%MOD;
            }
        }
    }
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        ll n,k;cin >> n >> k;
        cout << dp[k][n]%MOD << endl;
    }

    return 0;
}