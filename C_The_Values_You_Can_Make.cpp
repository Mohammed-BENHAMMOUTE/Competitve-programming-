#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // Base case handling
    if(n == 1) {
        if(a[0] == k){
            cout << 2 << endl;
            cout << 0 << " " << k << endl;
        } else {
            cout << 1 << endl;
            cout << 0 << endl;
        }
        return;
    }

    // dp[i][j][k] = can we make sum j with subset containing sum k using first i elements
    vector<vector<vector<bool>>> dp(n + 1, 
        vector<vector<bool>>(k + 1, vector<bool>(k + 1, false)));
    
    // Base case
    dp[0][0][0] = true;

    // Fill DP table
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            for(int l = 0; l <= j; l++) {
                // Don't use current coin
                dp[i][j][l] = dp[i-1][j][l];
                
                // Use current coin in j only
                if(j >= a[i-1]) 
                    dp[i][j][l] = dp[i][j][l] |dp[i-1][j-a[i-1]][l];
                
                // Use current coin in both j and l
                if(j >= a[i-1] && l >= a[i-1])
                    dp[i][j][l] = dp[i][j][l] | dp[i-1][j-a[i-1]][l-a[i-1]];
            }
        }
    }

    set<int> ans;
    for(int i = 0; i <= k; i++) {
        if(dp[n][k][i]) ans.insert(i);
    }

    cout << ans.size() << endl;
    for(int x : ans) cout << x << " ";
    cout << endl;
}


int main()
{
    fastio;
    solve();
    return 0;
}