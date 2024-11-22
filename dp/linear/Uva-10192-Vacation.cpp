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

void solve(string& s1, int pos)
{
    string s2;
    getline(cin, s2);
    int n = s2.size(); 
    int m = s1.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s2[i-1] == s1[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << "Case #" << pos << ": you can visit at most " << dp[n][m] << " cities." << endl;

}


int main()
{
    fastio();
    string t;
    int i =1;
    while(getline(cin, t) && t != "#"){
        solve(t,i++);
    }
    return 0;
}