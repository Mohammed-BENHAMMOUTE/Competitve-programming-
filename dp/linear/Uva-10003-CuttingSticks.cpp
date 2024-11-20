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



int main()
{
    fastio();
   int sz;
   vector<int> cuts;
   
   while(true){
    cin >> sz;
    if(sz == 0){
        return 0;
    };
    cuts.clear();
    cuts.push_back(0);
    int n; cin >> n;
    for(int i =0 ;i < n; i++){
        int x; cin >>x;
        cuts.push_back(x);
    };
    cuts.push_back(sz);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(n+2,vector<int>(n+2 , 0));
    for(int len = 2 ; len <= n+1; len++){
        for(int start =0 ; start +len <= n+1; start++){
            int end = start + len;
            dp[start][end] = INT_MAX;
            for(int firstCut  = start+1; firstCut < end ; firstCut++){
                dp[start][end] =min(dp[start][end], dp[start][firstCut]+dp[firstCut][end] + cuts[end]-cuts[start]); 
            } 
        }
    }
    cout << "The minimum cutting is " << dp[0][n + 1] << "." << endl;
   }
    return 0;
}