#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        
        dp[1][0] = 0;
        
        for (int screen = 1; screen <= n; screen++) {
            for (int clipboard = 0; clipboard <= n; clipboard++) {
                if (dp[screen][clipboard] == INT_MAX) continue;
                
                if (screen <= n) {
                    dp[screen][screen] = min(dp[screen][screen], 
                                           dp[screen][clipboard] + 1);
                }
                
                if (clipboard > 0 && screen + clipboard <= n) {
                    dp[screen + clipboard][clipboard] = min(dp[screen + clipboard][clipboard], 
                                                          dp[screen][clipboard] + 1);
                }
            }
        }
        
        int result = INT_MAX;
        for (int j = 0; j <= n; j++) {
            if (dp[n][j] != INT_MAX) {
                result = min(result, dp[n][j]);
            }
        }
        return result;
    }
};