// to solve this problem, you dont need to find some combination of coins that have the least difference, 
// what you can do instead is check all possible sums using those coins , and then iterate over all possible sums
// and find the one with the least diff, you just need one sum, and find the minimum of total - 2*sum, which will give 
// the needed difference.
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
    int m; cin >> m;
    vector<int> coins;
    int total = 0;
    for(int i = 0; i < m ; i++) {
        int x; cin >> x;
        coins.push_back(x);
        total+=x;
    };

    vector<bool> dp(total+1, false);
    dp[0] = true;

    for(int i =0; i < m ; i++) {
        for(int j = total; j >= coins[i]; j--){
            if(dp[j -coins[i]]){
                dp[j] = true;
            }
        }
    };

    int mindiff = total;
    for(int sum = 0; sum <= total/2 ; sum++){
        if(dp[sum]){
            mindiff= min(mindiff , total - 2*sum);
        }
    }
    cout << mindiff << endl;
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