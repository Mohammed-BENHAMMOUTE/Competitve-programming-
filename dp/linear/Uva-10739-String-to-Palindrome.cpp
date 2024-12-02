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

int lcs(string s, string rs){
    int n = s.size();
    int m = rs.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n ; i++){
        for(int j =1; j <=m ;j++){
            if(s[i-1] == rs[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

void solve(int i)
{
    string s; cin >> s;
    string rs = s;
    int n = s.size();
    reverse(rs.begin() , rs.end());
    int res = (n - lcs(s, rs))/2;
    cout << "Case "<<i<<": " << res<<endl;
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}